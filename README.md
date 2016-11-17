#Spider

##Introduction
Le principe du **`Spider`** est de créer un système de *keylogging* distribué. Un nombre arbitraire de `Client` connecté à un `Server` qui enregistre les différents inputs de l'utilisateur. 

##Protocole

###Terminologie

Terme		|  Définition | Unité Protobuf
------------|--------------
Message     | Un `Message` correspond à l'unité envoyé sur le réseau. | Non
Enveloppe   | Une `Enveloppe` est le contenu d'un `Message`. Elle contient aussi l'identité de l'expéditeur du message ou de sa destination. | Oui
Payload		| Un `Payload` correspond à la charge utile d'une `Enveloppe`. Il contient l'information  que le `Client`/`Serveur` souhaite transmettre. | Oui

###Protocol Buffer

Les `Client` et `Serveur` s'exécutant dans des environnement hétérogènes, il est nécessaire de sérialiser les donnée à envoyer pour prévenir des incompatibilités d'architectures. Par exemple les *Endianness*.

**`Protocol Buffer`** de Google, à été retenu pour ses performances, sa fiabilité et sa documentation extrêmement fournie et soignée.

En quelque mots : [**`Protocol Buffer`**](https://developers.google.com/protocol-buffers/) permet de créer des objets `C++` *sérialisable* et *dé-sérialisable*. Il fonctionne à partir de **`data-contract,`** sous forme *`.proto`* qui représentent les données. Ces fichiers sont ensuite compilé en classe natives `C++`. Ensuite, il est très simple de sérialiser/désérialiser ces objets.

> Un `Message` est composé d'un identifiant et d'une `Enveloppe`. Une `Enveloppe` est un conteneur pour le résultat de la  sérialisation d'un message via `ProtoBuf`.

###Identification

Chaque Client de vra être uniquement identifiable sur le réseau. En outre, le serveur devra pouvoir distinguer un client d'un autre et faire persister les donnée qui concernent un Client en particulier.

Chaque `Client` devra générer un ***UUID* de 16 bytes** et l'incluera dans toutes les enveloppes qu'il enverra sur le réseau. En l'absence d'identification valide, le serveur rejettera la demande/connexion.

###Authentification

Les Clients et le Serveur implémente `TLS` via la librairie `Curves`. Chaque Client devra effectuer le handshake et l'échange de clé publique décris dans le [RFC de la lib curves](https://rfc.zeromq.org/spec:26/CURVEZMQ/). 
Le serveur ignorera toute connection manquant à ce principes.

###Persitence

Le serveur utilise une base de donnée pour persister les données de Keylog. Ainsi, une `CLI` peut acceder aux donnée alors même qu'un client n'est pas connecté sur le réseau de keylogging.

Toute les requêtes via CLI se base sur le UUID d'un client. Cf. CLI.

### Format d'une `Enveloppe`

Une `Enveloppe` est le résultat de la sérialisation d'un contrat `Protobuf` de type `SpiderEnveloppe`.
Une enveloppe  se définit via le contrat *`.proto`* suivant :

```proto
message SpiderEnveloppe {
	required string ClientID = 1;
	required string PayloadType = 2;
	required google.protobuf.Any Payload = 3;
}
```

Element		|  Type  | Requis | Commentaire
------------|--------------
ClientID    | `string` | Oui | Si le `Message` est envoyé par le `Serveur`, alors `ClientID` contient l'ID du `Client` destinataire. Sinon `ClientID` contient l'ID du `Client` émetteur.
PayloadType | `string` | Oui | Content une string représentant le type final du `Payload` contenu par l'enveloppe. `C++` n'ayant pas de réflexion, ceci est nécessaire pour dé-sérialiser le payload dans le bon format.
Payload		| `Any`    | Oui | La charge utile de l'enveloppe, contenant la donnée que le `Client`/`Serveur` souhaite partager avec le `Serveur`/`Client`. 

##Payloads

###Payloads envoyé par le `Client`

#### `SpiderKeyLoggingPayload`

``` proto
message SpiderKeyLoggingPayload {
	message SpiderKeyLoggingContextPayload {
		required string ProcessName = 1;
		required string WindowsName = 2;
	}
	required string PlaintextKeylog = 1;
	SpiderKeyLoggingContextPayload Context = 2;
}
```

`SpiderKeyLoggingPayload` :
Element		|  Type  | Requis | Commentaire
------------|--------------
PlaintextKeylog    | `string` | Oui | Représente le keylog de l'utilisateur. La longueur de la string est arbitraire. Les touches spéciales sont formaté via la forme "[KEY]". Exemple : `"Hippolyte est le meilleur [CRTL] C"`.
Context | `SpiderKeyLoggingContextPayload` | Non | Représente se contexte dans lequel le keylog a été capturé.

`SpiderKeyLoggingContextPayload`:
Element		|  Type  | Requis | Commentaire
------------|--------------
ProcessName | `string` | Oui | Contient le nom du processus courant dans lequel l'input à été capturé.
WindowsName | `string` | Oui | Contient le nom de la fenêtre du processus dans lequel le keylog à été capturé.

####`SpiderMouseEvent`

```proto
message SpiderMouseEvent {
    enum MouseEventType {
        RBUTTON_CLICK = 0;
        LBUTTON_CLICK = 1;
        MBUTTON_CLICK = 4;
        MBUTTON_UP = 2;
        MBUTTON_DOWN = 3;
    }
    MouseEventType type = 1;
    uint32 X = 2;
    uint32 Y = 3;
}
```
Element		|  Type  | Requis | Commentaire
------------|--------------
type | `MouseEventType` | Oui | Contient l'événement de la souris qui à été capturé.
X | `string` | Oui | Coordonnées X de la souris
Y | `string` | Oui | Coordonnées Y de la souris

### Payloads envoyé par le `Serveur`

#### `SpiderStartKeylogCommandPayload`
Demande au `Client` de commencer son écoute des interactions utilisateur.

```
message SpiderStartKeylogCommandPayload {
}
```

#### `SpiderStopKeylogCommandPayload`
Demande au `Client` de stopper son écoute des interactions utilisateur.

```
message SpiderStopKeylogCommandPayload {
}
```

##Exemple de code

### Envois d'un `Message` de keylog par le `Client`

```cpp
SpiderKeyLoggingPayload payload;
payload.set_PlaintextKeylog("Ceci est un KeyLog [ALT][TAB]");

SpiderKeyLoggingPayload::SpiderKeyLoggingContextPayload context;
context.set_ProcessName("notepad.exe");
context.set_WindowsName("Sans titre - Bloc-notes");

payload.set_Context(&context);

SpiderEnveloppe enveloppe;
enveloppe.set_ClientID("6Uy9ZRdd1W9qnKuM");
enveloppe.set_PayloadType("SpiderKeyLoggingPayload");
enveloppe.set_Payload(&payload);

std::string enveloppe_data;
enveloppe.SerializeToString(&enveloppe_data);

//enveloppe_data contient maintenant notre enveloppe. Il suffit de rajouter l'identification en début de string pour obtenir un `Message` prêt à être envoyé sur le socket.
```

###Reception et parsing d'un `Message`  de keylog sur le `Serveur`

```cpp
std::string enveloppe_data; //Ici on part du principe que le message à été reçus sur un socket.

SpiderEnveloppe enveloppe;
enveloppe.ParseFromString(enveloppe_data);

if (enveloppe.PayloadType() == "SpiderKeyLoggingPayload" && enveloppe.Payload().Is<SpiderKeyLoggingPayload>()) {
	SpiderKeyLoggingPayload payload;
	enveloppe.Payload().UnpackTo(&payload);

	cout << "Client keylogged \"" + payload.PlaintextKeylog() + "\"."
	//Ici je ne dé-sérialize pas `SpiderKeyLoggingContextPayload`, je pense que vous avez compris le principe...
}
else {...}

```

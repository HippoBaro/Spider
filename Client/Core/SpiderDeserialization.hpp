#ifndef SPIDER_SERVER_SPIDERSERIALIZER_HPP
#define SPIDER_SERVER_SPIDERSERIALIZER_HPP

#include <string>
#include "SpiderEnveloppe.pb.h"

class SpiderSerializer {
public:
	static SpiderEnveloppe CreateFromPayload(std::string destinatorClientId, google::protobuf::Message &payload) {
		SpiderEnveloppe enveloppe;
		enveloppe.set_clientid(destinatorClientId);
		std::string test = payload.GetTypeName();
		enveloppe.set_payloadtype(test);
		enveloppe.mutable_payload()->PackFrom(payload);

		return enveloppe;
	}

	static SpiderEnveloppe CreateResponseFromPayload(std::string destinatorClientId, google::protobuf::Message &payload) {
		auto innerPayload = CreateFromPayload(destinatorClientId, payload);
		return CreateFromPayload(destinatorClientId, innerPayload);
	}
};

#endif
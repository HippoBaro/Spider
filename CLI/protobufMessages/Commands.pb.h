// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Commands.proto

#ifndef PROTOBUF_Commands_2eproto__INCLUDED
#define PROTOBUF_Commands_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_Commands_2eproto();
void protobuf_AssignDesc_Commands_2eproto();
void protobuf_ShutdownFile_Commands_2eproto();

class ClientList;
class ClientStatus;
class GetClientLog;
class KillClient;
class SetClientDelay;
class StartKeylogging;
class StopKeylogging;

// ===================================================================

class GetClientLog : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:GetClientLog) */ {
 public:
  GetClientLog();
  virtual ~GetClientLog();

  GetClientLog(const GetClientLog& from);

  inline GetClientLog& operator=(const GetClientLog& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GetClientLog& default_instance();

  void Swap(GetClientLog* other);

  // implements Message ----------------------------------------------

  inline GetClientLog* New() const { return New(NULL); }

  GetClientLog* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GetClientLog& from);
  void MergeFrom(const GetClientLog& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(GetClientLog* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 limit = 1;
  void clear_limit();
  static const int kLimitFieldNumber = 1;
  ::google::protobuf::int32 limit() const;
  void set_limit(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:GetClientLog)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::int32 limit_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_Commands_2eproto();
  friend void protobuf_AssignDesc_Commands_2eproto();
  friend void protobuf_ShutdownFile_Commands_2eproto();

  void InitAsDefaultInstance();
  static GetClientLog* default_instance_;
};
// -------------------------------------------------------------------

class ClientList : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ClientList) */ {
 public:
  ClientList();
  virtual ~ClientList();

  ClientList(const ClientList& from);

  inline ClientList& operator=(const ClientList& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ClientList& default_instance();

  void Swap(ClientList* other);

  // implements Message ----------------------------------------------

  inline ClientList* New() const { return New(NULL); }

  ClientList* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ClientList& from);
  void MergeFrom(const ClientList& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ClientList* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:ClientList)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_Commands_2eproto();
  friend void protobuf_AssignDesc_Commands_2eproto();
  friend void protobuf_ShutdownFile_Commands_2eproto();

  void InitAsDefaultInstance();
  static ClientList* default_instance_;
};
// -------------------------------------------------------------------

class ClientStatus : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ClientStatus) */ {
 public:
  ClientStatus();
  virtual ~ClientStatus();

  ClientStatus(const ClientStatus& from);

  inline ClientStatus& operator=(const ClientStatus& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ClientStatus& default_instance();

  void Swap(ClientStatus* other);

  // implements Message ----------------------------------------------

  inline ClientStatus* New() const { return New(NULL); }

  ClientStatus* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ClientStatus& from);
  void MergeFrom(const ClientStatus& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ClientStatus* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:ClientStatus)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_Commands_2eproto();
  friend void protobuf_AssignDesc_Commands_2eproto();
  friend void protobuf_ShutdownFile_Commands_2eproto();

  void InitAsDefaultInstance();
  static ClientStatus* default_instance_;
};
// -------------------------------------------------------------------

class StartKeylogging : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:StartKeylogging) */ {
 public:
  StartKeylogging();
  virtual ~StartKeylogging();

  StartKeylogging(const StartKeylogging& from);

  inline StartKeylogging& operator=(const StartKeylogging& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const StartKeylogging& default_instance();

  void Swap(StartKeylogging* other);

  // implements Message ----------------------------------------------

  inline StartKeylogging* New() const { return New(NULL); }

  StartKeylogging* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const StartKeylogging& from);
  void MergeFrom(const StartKeylogging& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(StartKeylogging* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:StartKeylogging)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_Commands_2eproto();
  friend void protobuf_AssignDesc_Commands_2eproto();
  friend void protobuf_ShutdownFile_Commands_2eproto();

  void InitAsDefaultInstance();
  static StartKeylogging* default_instance_;
};
// -------------------------------------------------------------------

class StopKeylogging : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:StopKeylogging) */ {
 public:
  StopKeylogging();
  virtual ~StopKeylogging();

  StopKeylogging(const StopKeylogging& from);

  inline StopKeylogging& operator=(const StopKeylogging& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const StopKeylogging& default_instance();

  void Swap(StopKeylogging* other);

  // implements Message ----------------------------------------------

  inline StopKeylogging* New() const { return New(NULL); }

  StopKeylogging* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const StopKeylogging& from);
  void MergeFrom(const StopKeylogging& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(StopKeylogging* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:StopKeylogging)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_Commands_2eproto();
  friend void protobuf_AssignDesc_Commands_2eproto();
  friend void protobuf_ShutdownFile_Commands_2eproto();

  void InitAsDefaultInstance();
  static StopKeylogging* default_instance_;
};
// -------------------------------------------------------------------

class KillClient : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:KillClient) */ {
 public:
  KillClient();
  virtual ~KillClient();

  KillClient(const KillClient& from);

  inline KillClient& operator=(const KillClient& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const KillClient& default_instance();

  void Swap(KillClient* other);

  // implements Message ----------------------------------------------

  inline KillClient* New() const { return New(NULL); }

  KillClient* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const KillClient& from);
  void MergeFrom(const KillClient& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(KillClient* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:KillClient)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_Commands_2eproto();
  friend void protobuf_AssignDesc_Commands_2eproto();
  friend void protobuf_ShutdownFile_Commands_2eproto();

  void InitAsDefaultInstance();
  static KillClient* default_instance_;
};
// -------------------------------------------------------------------

class SetClientDelay : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:SetClientDelay) */ {
 public:
  SetClientDelay();
  virtual ~SetClientDelay();

  SetClientDelay(const SetClientDelay& from);

  inline SetClientDelay& operator=(const SetClientDelay& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SetClientDelay& default_instance();

  void Swap(SetClientDelay* other);

  // implements Message ----------------------------------------------

  inline SetClientDelay* New() const { return New(NULL); }

  SetClientDelay* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SetClientDelay& from);
  void MergeFrom(const SetClientDelay& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(SetClientDelay* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 delay = 1;
  void clear_delay();
  static const int kDelayFieldNumber = 1;
  ::google::protobuf::int32 delay() const;
  void set_delay(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:SetClientDelay)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::int32 delay_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_Commands_2eproto();
  friend void protobuf_AssignDesc_Commands_2eproto();
  friend void protobuf_ShutdownFile_Commands_2eproto();

  void InitAsDefaultInstance();
  static SetClientDelay* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// GetClientLog

// optional int32 limit = 1;
inline void GetClientLog::clear_limit() {
  limit_ = 0;
}
inline ::google::protobuf::int32 GetClientLog::limit() const {
  // @@protoc_insertion_point(field_get:GetClientLog.limit)
  return limit_;
}
inline void GetClientLog::set_limit(::google::protobuf::int32 value) {
  
  limit_ = value;
  // @@protoc_insertion_point(field_set:GetClientLog.limit)
}

// -------------------------------------------------------------------

// ClientList

// -------------------------------------------------------------------

// ClientStatus

// -------------------------------------------------------------------

// StartKeylogging

// -------------------------------------------------------------------

// StopKeylogging

// -------------------------------------------------------------------

// KillClient

// -------------------------------------------------------------------

// SetClientDelay

// optional int32 delay = 1;
inline void SetClientDelay::clear_delay() {
  delay_ = 0;
}
inline ::google::protobuf::int32 SetClientDelay::delay() const {
  // @@protoc_insertion_point(field_get:SetClientDelay.delay)
  return delay_;
}
inline void SetClientDelay::set_delay(::google::protobuf::int32 value) {
  
  delay_ = value;
  // @@protoc_insertion_point(field_set:SetClientDelay.delay)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Commands_2eproto__INCLUDED

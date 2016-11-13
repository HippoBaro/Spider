// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Proto/SpiderAuthenticationPayload.proto

#ifndef PROTOBUF_Proto_2fSpiderAuthenticationPayload_2eproto__INCLUDED
#define PROTOBUF_Proto_2fSpiderAuthenticationPayload_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3001000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3001000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
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
void protobuf_AddDesc_Proto_2fSpiderAuthenticationPayload_2eproto();
void protobuf_InitDefaults_Proto_2fSpiderAuthenticationPayload_2eproto();
void protobuf_AssignDesc_Proto_2fSpiderAuthenticationPayload_2eproto();
void protobuf_ShutdownFile_Proto_2fSpiderAuthenticationPayload_2eproto();

class SpiderAuthenticationPayload;

// ===================================================================

class SpiderAuthenticationPayload : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:SpiderAuthenticationPayload) */ {
 public:
  SpiderAuthenticationPayload();
  virtual ~SpiderAuthenticationPayload();

  SpiderAuthenticationPayload(const SpiderAuthenticationPayload& from);

  inline SpiderAuthenticationPayload& operator=(const SpiderAuthenticationPayload& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SpiderAuthenticationPayload& default_instance();

  static const SpiderAuthenticationPayload* internal_default_instance();

  void Swap(SpiderAuthenticationPayload* other);

  // implements Message ----------------------------------------------

  inline SpiderAuthenticationPayload* New() const { return New(NULL); }

  SpiderAuthenticationPayload* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SpiderAuthenticationPayload& from);
  void MergeFrom(const SpiderAuthenticationPayload& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
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
  void InternalSwap(SpiderAuthenticationPayload* other);
  void UnsafeMergeFrom(const SpiderAuthenticationPayload& from);
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

  // @@protoc_insertion_point(class_scope:SpiderAuthenticationPayload)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_Proto_2fSpiderAuthenticationPayload_2eproto_impl();
  friend void  protobuf_AddDesc_Proto_2fSpiderAuthenticationPayload_2eproto_impl();
  friend void protobuf_AssignDesc_Proto_2fSpiderAuthenticationPayload_2eproto();
  friend void protobuf_ShutdownFile_Proto_2fSpiderAuthenticationPayload_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<SpiderAuthenticationPayload> SpiderAuthenticationPayload_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// SpiderAuthenticationPayload

inline const SpiderAuthenticationPayload* SpiderAuthenticationPayload::internal_default_instance() {
  return &SpiderAuthenticationPayload_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Proto_2fSpiderAuthenticationPayload_2eproto__INCLUDED

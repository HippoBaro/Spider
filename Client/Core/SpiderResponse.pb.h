// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Proto/SpiderResponse.proto

#ifndef PROTOBUF_Proto_2fSpiderResponse_2eproto__INCLUDED
#define PROTOBUF_Proto_2fSpiderResponse_2eproto__INCLUDED

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
#include "SpiderEnveloppe.pb.h"
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_Proto_2fSpiderResponse_2eproto();
void protobuf_InitDefaults_Proto_2fSpiderResponse_2eproto();
void protobuf_AssignDesc_Proto_2fSpiderResponse_2eproto();
void protobuf_ShutdownFile_Proto_2fSpiderResponse_2eproto();

class SpiderResponse;

// ===================================================================

class SpiderResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:SpiderResponse) */ {
 public:
  SpiderResponse();
  virtual ~SpiderResponse();

  SpiderResponse(const SpiderResponse& from);

  inline SpiderResponse& operator=(const SpiderResponse& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SpiderResponse& default_instance();

  static const SpiderResponse* internal_default_instance();

  void Swap(SpiderResponse* other);

  // implements Message ----------------------------------------------

  inline SpiderResponse* New() const { return New(NULL); }

  SpiderResponse* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SpiderResponse& from);
  void MergeFrom(const SpiderResponse& from);
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
  void InternalSwap(SpiderResponse* other);
  void UnsafeMergeFrom(const SpiderResponse& from);
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

  // optional .SpiderEnveloppe enveloppe = 1;
  bool has_enveloppe() const;
  void clear_enveloppe();
  static const int kEnveloppeFieldNumber = 1;
  const ::SpiderEnveloppe& enveloppe() const;
  ::SpiderEnveloppe* mutable_enveloppe();
  ::SpiderEnveloppe* release_enveloppe();
  void set_allocated_enveloppe(::SpiderEnveloppe* enveloppe);

  // @@protoc_insertion_point(class_scope:SpiderResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::SpiderEnveloppe* enveloppe_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_Proto_2fSpiderResponse_2eproto_impl();
  friend void  protobuf_AddDesc_Proto_2fSpiderResponse_2eproto_impl();
  friend void protobuf_AssignDesc_Proto_2fSpiderResponse_2eproto();
  friend void protobuf_ShutdownFile_Proto_2fSpiderResponse_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<SpiderResponse> SpiderResponse_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// SpiderResponse

// optional .SpiderEnveloppe enveloppe = 1;
inline bool SpiderResponse::has_enveloppe() const {
  return this != internal_default_instance() && enveloppe_ != NULL;
}
inline void SpiderResponse::clear_enveloppe() {
  if (GetArenaNoVirtual() == NULL && enveloppe_ != NULL) delete enveloppe_;
  enveloppe_ = NULL;
}
inline const ::SpiderEnveloppe& SpiderResponse::enveloppe() const {
  // @@protoc_insertion_point(field_get:SpiderResponse.enveloppe)
  return enveloppe_ != NULL ? *enveloppe_
                         : *::SpiderEnveloppe::internal_default_instance();
}
inline ::SpiderEnveloppe* SpiderResponse::mutable_enveloppe() {
  
  if (enveloppe_ == NULL) {
    enveloppe_ = new ::SpiderEnveloppe;
  }
  // @@protoc_insertion_point(field_mutable:SpiderResponse.enveloppe)
  return enveloppe_;
}
inline ::SpiderEnveloppe* SpiderResponse::release_enveloppe() {
  // @@protoc_insertion_point(field_release:SpiderResponse.enveloppe)
  
  ::SpiderEnveloppe* temp = enveloppe_;
  enveloppe_ = NULL;
  return temp;
}
inline void SpiderResponse::set_allocated_enveloppe(::SpiderEnveloppe* enveloppe) {
  delete enveloppe_;
  enveloppe_ = enveloppe;
  if (enveloppe) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:SpiderResponse.enveloppe)
}

inline const SpiderResponse* SpiderResponse::internal_default_instance() {
  return &SpiderResponse_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Proto_2fSpiderResponse_2eproto__INCLUDED
// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Proto/SpiderContextChangedEvent.proto

#ifndef PROTOBUF_Proto_2fSpiderContextChangedEvent_2eproto__INCLUDED
#define PROTOBUF_Proto_2fSpiderContextChangedEvent_2eproto__INCLUDED

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
void protobuf_AddDesc_Proto_2fSpiderContextChangedEvent_2eproto();
void protobuf_InitDefaults_Proto_2fSpiderContextChangedEvent_2eproto();
void protobuf_AssignDesc_Proto_2fSpiderContextChangedEvent_2eproto();
void protobuf_ShutdownFile_Proto_2fSpiderContextChangedEvent_2eproto();

class SpiderContextChangedEvent;

// ===================================================================

class SpiderContextChangedEvent : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:SpiderContextChangedEvent) */ {
 public:
  SpiderContextChangedEvent();
  virtual ~SpiderContextChangedEvent();

  SpiderContextChangedEvent(const SpiderContextChangedEvent& from);

  inline SpiderContextChangedEvent& operator=(const SpiderContextChangedEvent& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SpiderContextChangedEvent& default_instance();

  static const SpiderContextChangedEvent* internal_default_instance();

  void Swap(SpiderContextChangedEvent* other);

  // implements Message ----------------------------------------------

  inline SpiderContextChangedEvent* New() const { return New(NULL); }

  SpiderContextChangedEvent* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SpiderContextChangedEvent& from);
  void MergeFrom(const SpiderContextChangedEvent& from);
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
  void InternalSwap(SpiderContextChangedEvent* other);
  void UnsafeMergeFrom(const SpiderContextChangedEvent& from);
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

  // optional bytes ProcessName = 1;
  void clear_processname();
  static const int kProcessNameFieldNumber = 1;
  const ::std::string& processname() const;
  void set_processname(const ::std::string& value);
  void set_processname(const char* value);
  void set_processname(const void* value, size_t size);
  ::std::string* mutable_processname();
  ::std::string* release_processname();
  void set_allocated_processname(::std::string* processname);

  // optional bytes WindowTitle = 2;
  void clear_windowtitle();
  static const int kWindowTitleFieldNumber = 2;
  const ::std::string& windowtitle() const;
  void set_windowtitle(const ::std::string& value);
  void set_windowtitle(const char* value);
  void set_windowtitle(const void* value, size_t size);
  ::std::string* mutable_windowtitle();
  ::std::string* release_windowtitle();
  void set_allocated_windowtitle(::std::string* windowtitle);

  // @@protoc_insertion_point(class_scope:SpiderContextChangedEvent)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr processname_;
  ::google::protobuf::internal::ArenaStringPtr windowtitle_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_Proto_2fSpiderContextChangedEvent_2eproto_impl();
  friend void  protobuf_AddDesc_Proto_2fSpiderContextChangedEvent_2eproto_impl();
  friend void protobuf_AssignDesc_Proto_2fSpiderContextChangedEvent_2eproto();
  friend void protobuf_ShutdownFile_Proto_2fSpiderContextChangedEvent_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<SpiderContextChangedEvent> SpiderContextChangedEvent_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// SpiderContextChangedEvent

// optional bytes ProcessName = 1;
inline void SpiderContextChangedEvent::clear_processname() {
  processname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SpiderContextChangedEvent::processname() const {
  // @@protoc_insertion_point(field_get:SpiderContextChangedEvent.ProcessName)
  return processname_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SpiderContextChangedEvent::set_processname(const ::std::string& value) {
  
  processname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:SpiderContextChangedEvent.ProcessName)
}
inline void SpiderContextChangedEvent::set_processname(const char* value) {
  
  processname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:SpiderContextChangedEvent.ProcessName)
}
inline void SpiderContextChangedEvent::set_processname(const void* value, size_t size) {
  
  processname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:SpiderContextChangedEvent.ProcessName)
}
inline ::std::string* SpiderContextChangedEvent::mutable_processname() {
  
  // @@protoc_insertion_point(field_mutable:SpiderContextChangedEvent.ProcessName)
  return processname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SpiderContextChangedEvent::release_processname() {
  // @@protoc_insertion_point(field_release:SpiderContextChangedEvent.ProcessName)
  
  return processname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SpiderContextChangedEvent::set_allocated_processname(::std::string* processname) {
  if (processname != NULL) {
    
  } else {
    
  }
  processname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), processname);
  // @@protoc_insertion_point(field_set_allocated:SpiderContextChangedEvent.ProcessName)
}

// optional bytes WindowTitle = 2;
inline void SpiderContextChangedEvent::clear_windowtitle() {
  windowtitle_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SpiderContextChangedEvent::windowtitle() const {
  // @@protoc_insertion_point(field_get:SpiderContextChangedEvent.WindowTitle)
  return windowtitle_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SpiderContextChangedEvent::set_windowtitle(const ::std::string& value) {
  
  windowtitle_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:SpiderContextChangedEvent.WindowTitle)
}
inline void SpiderContextChangedEvent::set_windowtitle(const char* value) {
  
  windowtitle_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:SpiderContextChangedEvent.WindowTitle)
}
inline void SpiderContextChangedEvent::set_windowtitle(const void* value, size_t size) {
  
  windowtitle_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:SpiderContextChangedEvent.WindowTitle)
}
inline ::std::string* SpiderContextChangedEvent::mutable_windowtitle() {
  
  // @@protoc_insertion_point(field_mutable:SpiderContextChangedEvent.WindowTitle)
  return windowtitle_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SpiderContextChangedEvent::release_windowtitle() {
  // @@protoc_insertion_point(field_release:SpiderContextChangedEvent.WindowTitle)
  
  return windowtitle_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SpiderContextChangedEvent::set_allocated_windowtitle(::std::string* windowtitle) {
  if (windowtitle != NULL) {
    
  } else {
    
  }
  windowtitle_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), windowtitle);
  // @@protoc_insertion_point(field_set_allocated:SpiderContextChangedEvent.WindowTitle)
}

inline const SpiderContextChangedEvent* SpiderContextChangedEvent::internal_default_instance() {
  return &SpiderContextChangedEvent_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Proto_2fSpiderContextChangedEvent_2eproto__INCLUDED

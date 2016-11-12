// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Proto/SpiderKeyLoggingPayload.proto

#ifndef PROTOBUF_Proto_2fSpiderKeyLoggingPayload_2eproto__INCLUDED
#define PROTOBUF_Proto_2fSpiderKeyLoggingPayload_2eproto__INCLUDED

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
void protobuf_AddDesc_Proto_2fSpiderKeyLoggingPayload_2eproto();
void protobuf_InitDefaults_Proto_2fSpiderKeyLoggingPayload_2eproto();
void protobuf_AssignDesc_Proto_2fSpiderKeyLoggingPayload_2eproto();
void protobuf_ShutdownFile_Proto_2fSpiderKeyLoggingPayload_2eproto();

class SpiderKeyLoggingPayload;
class SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload;

// ===================================================================

class SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:SpiderKeyLoggingPayload.SpiderKeyLoggingContextPayload) */ {
 public:
  SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload();
  virtual ~SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload();

  SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload(const SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload& from);

  inline SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload& operator=(const SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload& default_instance();

  static const SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload* internal_default_instance();

  void Swap(SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload* other);

  // implements Message ----------------------------------------------

  inline SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload* New() const { return New(NULL); }

  SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload& from);
  void MergeFrom(const SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload& from);
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
  void InternalSwap(SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload* other);
  void UnsafeMergeFrom(const SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload& from);
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

  // optional string ProcessName = 1;
  void clear_processname();
  static const int kProcessNameFieldNumber = 1;
  const ::std::string& processname() const;
  void set_processname(const ::std::string& value);
  void set_processname(const char* value);
  void set_processname(const char* value, size_t size);
  ::std::string* mutable_processname();
  ::std::string* release_processname();
  void set_allocated_processname(::std::string* processname);

  // optional string WindowsName = 2;
  void clear_windowsname();
  static const int kWindowsNameFieldNumber = 2;
  const ::std::string& windowsname() const;
  void set_windowsname(const ::std::string& value);
  void set_windowsname(const char* value);
  void set_windowsname(const char* value, size_t size);
  ::std::string* mutable_windowsname();
  ::std::string* release_windowsname();
  void set_allocated_windowsname(::std::string* windowsname);

  // @@protoc_insertion_point(class_scope:SpiderKeyLoggingPayload.SpiderKeyLoggingContextPayload)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr processname_;
  ::google::protobuf::internal::ArenaStringPtr windowsname_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_Proto_2fSpiderKeyLoggingPayload_2eproto_impl();
  friend void  protobuf_AddDesc_Proto_2fSpiderKeyLoggingPayload_2eproto_impl();
  friend void protobuf_AssignDesc_Proto_2fSpiderKeyLoggingPayload_2eproto();
  friend void protobuf_ShutdownFile_Proto_2fSpiderKeyLoggingPayload_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload> SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload_default_instance_;

// -------------------------------------------------------------------

class SpiderKeyLoggingPayload : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:SpiderKeyLoggingPayload) */ {
 public:
  SpiderKeyLoggingPayload();
  virtual ~SpiderKeyLoggingPayload();

  SpiderKeyLoggingPayload(const SpiderKeyLoggingPayload& from);

  inline SpiderKeyLoggingPayload& operator=(const SpiderKeyLoggingPayload& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SpiderKeyLoggingPayload& default_instance();

  static const SpiderKeyLoggingPayload* internal_default_instance();

  void Swap(SpiderKeyLoggingPayload* other);

  // implements Message ----------------------------------------------

  inline SpiderKeyLoggingPayload* New() const { return New(NULL); }

  SpiderKeyLoggingPayload* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SpiderKeyLoggingPayload& from);
  void MergeFrom(const SpiderKeyLoggingPayload& from);
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
  void InternalSwap(SpiderKeyLoggingPayload* other);
  void UnsafeMergeFrom(const SpiderKeyLoggingPayload& from);
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

  typedef SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload SpiderKeyLoggingContextPayload;

  // accessors -------------------------------------------------------

  // optional bytes PlaintextKeylog = 1;
  void clear_plaintextkeylog();
  static const int kPlaintextKeylogFieldNumber = 1;
  const ::std::string& plaintextkeylog() const;
  void set_plaintextkeylog(const ::std::string& value);
  void set_plaintextkeylog(const char* value);
  void set_plaintextkeylog(const void* value, size_t size);
  ::std::string* mutable_plaintextkeylog();
  ::std::string* release_plaintextkeylog();
  void set_allocated_plaintextkeylog(::std::string* plaintextkeylog);

  // optional .SpiderKeyLoggingPayload.SpiderKeyLoggingContextPayload Context = 2;
  bool has_context() const;
  void clear_context();
  static const int kContextFieldNumber = 2;
  const ::SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload& context() const;
  ::SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload* mutable_context();
  ::SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload* release_context();
  void set_allocated_context(::SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload* context);

  // @@protoc_insertion_point(class_scope:SpiderKeyLoggingPayload)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr plaintextkeylog_;
  ::SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload* context_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_Proto_2fSpiderKeyLoggingPayload_2eproto_impl();
  friend void  protobuf_AddDesc_Proto_2fSpiderKeyLoggingPayload_2eproto_impl();
  friend void protobuf_AssignDesc_Proto_2fSpiderKeyLoggingPayload_2eproto();
  friend void protobuf_ShutdownFile_Proto_2fSpiderKeyLoggingPayload_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<SpiderKeyLoggingPayload> SpiderKeyLoggingPayload_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload

// optional string ProcessName = 1;
inline void SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload::clear_processname() {
  processname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload::processname() const {
  // @@protoc_insertion_point(field_get:SpiderKeyLoggingPayload.SpiderKeyLoggingContextPayload.ProcessName)
  return processname_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload::set_processname(const ::std::string& value) {
  
  processname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:SpiderKeyLoggingPayload.SpiderKeyLoggingContextPayload.ProcessName)
}
inline void SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload::set_processname(const char* value) {
  
  processname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:SpiderKeyLoggingPayload.SpiderKeyLoggingContextPayload.ProcessName)
}
inline void SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload::set_processname(const char* value, size_t size) {
  
  processname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:SpiderKeyLoggingPayload.SpiderKeyLoggingContextPayload.ProcessName)
}
inline ::std::string* SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload::mutable_processname() {
  
  // @@protoc_insertion_point(field_mutable:SpiderKeyLoggingPayload.SpiderKeyLoggingContextPayload.ProcessName)
  return processname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload::release_processname() {
  // @@protoc_insertion_point(field_release:SpiderKeyLoggingPayload.SpiderKeyLoggingContextPayload.ProcessName)
  
  return processname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload::set_allocated_processname(::std::string* processname) {
  if (processname != NULL) {
    
  } else {
    
  }
  processname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), processname);
  // @@protoc_insertion_point(field_set_allocated:SpiderKeyLoggingPayload.SpiderKeyLoggingContextPayload.ProcessName)
}

// optional string WindowsName = 2;
inline void SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload::clear_windowsname() {
  windowsname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload::windowsname() const {
  // @@protoc_insertion_point(field_get:SpiderKeyLoggingPayload.SpiderKeyLoggingContextPayload.WindowsName)
  return windowsname_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload::set_windowsname(const ::std::string& value) {
  
  windowsname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:SpiderKeyLoggingPayload.SpiderKeyLoggingContextPayload.WindowsName)
}
inline void SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload::set_windowsname(const char* value) {
  
  windowsname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:SpiderKeyLoggingPayload.SpiderKeyLoggingContextPayload.WindowsName)
}
inline void SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload::set_windowsname(const char* value, size_t size) {
  
  windowsname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:SpiderKeyLoggingPayload.SpiderKeyLoggingContextPayload.WindowsName)
}
inline ::std::string* SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload::mutable_windowsname() {
  
  // @@protoc_insertion_point(field_mutable:SpiderKeyLoggingPayload.SpiderKeyLoggingContextPayload.WindowsName)
  return windowsname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload::release_windowsname() {
  // @@protoc_insertion_point(field_release:SpiderKeyLoggingPayload.SpiderKeyLoggingContextPayload.WindowsName)
  
  return windowsname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload::set_allocated_windowsname(::std::string* windowsname) {
  if (windowsname != NULL) {
    
  } else {
    
  }
  windowsname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), windowsname);
  // @@protoc_insertion_point(field_set_allocated:SpiderKeyLoggingPayload.SpiderKeyLoggingContextPayload.WindowsName)
}

inline const SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload* SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload::internal_default_instance() {
  return &SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload_default_instance_.get();
}
// -------------------------------------------------------------------

// SpiderKeyLoggingPayload

// optional bytes PlaintextKeylog = 1;
inline void SpiderKeyLoggingPayload::clear_plaintextkeylog() {
  plaintextkeylog_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SpiderKeyLoggingPayload::plaintextkeylog() const {
  // @@protoc_insertion_point(field_get:SpiderKeyLoggingPayload.PlaintextKeylog)
  return plaintextkeylog_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SpiderKeyLoggingPayload::set_plaintextkeylog(const ::std::string& value) {
  
  plaintextkeylog_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:SpiderKeyLoggingPayload.PlaintextKeylog)
}
inline void SpiderKeyLoggingPayload::set_plaintextkeylog(const char* value) {
  
  plaintextkeylog_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:SpiderKeyLoggingPayload.PlaintextKeylog)
}
inline void SpiderKeyLoggingPayload::set_plaintextkeylog(const void* value, size_t size) {
  
  plaintextkeylog_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:SpiderKeyLoggingPayload.PlaintextKeylog)
}
inline ::std::string* SpiderKeyLoggingPayload::mutable_plaintextkeylog() {
  
  // @@protoc_insertion_point(field_mutable:SpiderKeyLoggingPayload.PlaintextKeylog)
  return plaintextkeylog_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SpiderKeyLoggingPayload::release_plaintextkeylog() {
  // @@protoc_insertion_point(field_release:SpiderKeyLoggingPayload.PlaintextKeylog)
  
  return plaintextkeylog_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SpiderKeyLoggingPayload::set_allocated_plaintextkeylog(::std::string* plaintextkeylog) {
  if (plaintextkeylog != NULL) {
    
  } else {
    
  }
  plaintextkeylog_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), plaintextkeylog);
  // @@protoc_insertion_point(field_set_allocated:SpiderKeyLoggingPayload.PlaintextKeylog)
}

// optional .SpiderKeyLoggingPayload.SpiderKeyLoggingContextPayload Context = 2;
inline bool SpiderKeyLoggingPayload::has_context() const {
  return this != internal_default_instance() && context_ != NULL;
}
inline void SpiderKeyLoggingPayload::clear_context() {
  if (GetArenaNoVirtual() == NULL && context_ != NULL) delete context_;
  context_ = NULL;
}
inline const ::SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload& SpiderKeyLoggingPayload::context() const {
  // @@protoc_insertion_point(field_get:SpiderKeyLoggingPayload.Context)
  return context_ != NULL ? *context_
                         : *::SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload::internal_default_instance();
}
inline ::SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload* SpiderKeyLoggingPayload::mutable_context() {
  
  if (context_ == NULL) {
    context_ = new ::SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload;
  }
  // @@protoc_insertion_point(field_mutable:SpiderKeyLoggingPayload.Context)
  return context_;
}
inline ::SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload* SpiderKeyLoggingPayload::release_context() {
  // @@protoc_insertion_point(field_release:SpiderKeyLoggingPayload.Context)
  
  ::SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload* temp = context_;
  context_ = NULL;
  return temp;
}
inline void SpiderKeyLoggingPayload::set_allocated_context(::SpiderKeyLoggingPayload_SpiderKeyLoggingContextPayload* context) {
  delete context_;
  context_ = context;
  if (context) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:SpiderKeyLoggingPayload.Context)
}

inline const SpiderKeyLoggingPayload* SpiderKeyLoggingPayload::internal_default_instance() {
  return &SpiderKeyLoggingPayload_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Proto_2fSpiderKeyLoggingPayload_2eproto__INCLUDED

// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Command.proto

#ifndef PROTOBUF_Command_2eproto__INCLUDED
#define PROTOBUF_Command_2eproto__INCLUDED

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
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_util.h>
// @@protoc_insertion_point(includes)

namespace Cmd {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_Command_2eproto();
void protobuf_AssignDesc_Command_2eproto();
void protobuf_ShutdownFile_Command_2eproto();

class ReqAccountOperation;
class ReqLoginGameServer;
class RetAccountOperation;

enum AccountAction {
  AccountAction_None = 0,
  AccountAction_Create = 1,
  AccountAction_Rename = 2,
  AccountAction_Delete = 3,
  AccountAction_Login = 4
};
bool AccountAction_IsValid(int value);
const AccountAction AccountAction_MIN = AccountAction_None;
const AccountAction AccountAction_MAX = AccountAction_Login;
const int AccountAction_ARRAYSIZE = AccountAction_MAX + 1;

enum AccountErrorCode {
  AccountErrorCode_None = 0,
  AccountErrorCode_CreateSucessed = 1,
  AccountErrorCode_NameRepeated = 2,
  AccountErrorCode_UserCantFind = 3,
  AccountErrorCode_PasswordError = 4,
  AccountErrorCode_LoginSucessed = 5
};
bool AccountErrorCode_IsValid(int value);
const AccountErrorCode AccountErrorCode_MIN = AccountErrorCode_None;
const AccountErrorCode AccountErrorCode_MAX = AccountErrorCode_LoginSucessed;
const int AccountErrorCode_ARRAYSIZE = AccountErrorCode_MAX + 1;

// ===================================================================

class ReqAccountOperation : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:Cmd.ReqAccountOperation) */ {
 public:
  ReqAccountOperation();
  virtual ~ReqAccountOperation();

  ReqAccountOperation(const ReqAccountOperation& from);

  inline ReqAccountOperation& operator=(const ReqAccountOperation& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::std::string& unknown_fields() const {
    return _unknown_fields_.GetNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }

  inline ::std::string* mutable_unknown_fields() {
    return _unknown_fields_.MutableNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }

  static const ReqAccountOperation& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const ReqAccountOperation* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(ReqAccountOperation* other);

  // implements Message ----------------------------------------------

  inline ReqAccountOperation* New() const { return New(NULL); }

  ReqAccountOperation* New(::google::protobuf::Arena* arena) const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const ReqAccountOperation& from);
  void MergeFrom(const ReqAccountOperation& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ReqAccountOperation* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _arena_ptr_;
  }
  inline ::google::protobuf::Arena* MaybeArenaPtr() const {
    return _arena_ptr_;
  }
  public:

  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required .Cmd.AccountAction action = 1;
  bool has_action() const;
  void clear_action();
  static const int kActionFieldNumber = 1;
  ::Cmd::AccountAction action() const;
  void set_action(::Cmd::AccountAction value);

  // required string user = 2;
  bool has_user() const;
  void clear_user();
  static const int kUserFieldNumber = 2;
  const ::std::string& user() const;
  void set_user(const ::std::string& value);
  void set_user(const char* value);
  void set_user(const char* value, size_t size);
  ::std::string* mutable_user();
  ::std::string* release_user();
  void set_allocated_user(::std::string* user);

  // required string password = 3;
  bool has_password() const;
  void clear_password();
  static const int kPasswordFieldNumber = 3;
  const ::std::string& password() const;
  void set_password(const ::std::string& value);
  void set_password(const char* value);
  void set_password(const char* value, size_t size);
  ::std::string* mutable_password();
  ::std::string* release_password();
  void set_allocated_password(::std::string* password);

  // @@protoc_insertion_point(class_scope:Cmd.ReqAccountOperation)
 private:
  inline void set_has_action();
  inline void clear_has_action();
  inline void set_has_user();
  inline void clear_has_user();
  inline void set_has_password();
  inline void clear_has_password();

  // helper for ByteSize()
  int RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
  ::google::protobuf::Arena* _arena_ptr_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr user_;
  ::google::protobuf::internal::ArenaStringPtr password_;
  int action_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_Command_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_Command_2eproto();
  #endif
  friend void protobuf_AssignDesc_Command_2eproto();
  friend void protobuf_ShutdownFile_Command_2eproto();

  void InitAsDefaultInstance();
  static ReqAccountOperation* default_instance_;
};
// -------------------------------------------------------------------

class RetAccountOperation : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:Cmd.RetAccountOperation) */ {
 public:
  RetAccountOperation();
  virtual ~RetAccountOperation();

  RetAccountOperation(const RetAccountOperation& from);

  inline RetAccountOperation& operator=(const RetAccountOperation& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::std::string& unknown_fields() const {
    return _unknown_fields_.GetNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }

  inline ::std::string* mutable_unknown_fields() {
    return _unknown_fields_.MutableNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }

  static const RetAccountOperation& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const RetAccountOperation* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(RetAccountOperation* other);

  // implements Message ----------------------------------------------

  inline RetAccountOperation* New() const { return New(NULL); }

  RetAccountOperation* New(::google::protobuf::Arena* arena) const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const RetAccountOperation& from);
  void MergeFrom(const RetAccountOperation& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(RetAccountOperation* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _arena_ptr_;
  }
  inline ::google::protobuf::Arena* MaybeArenaPtr() const {
    return _arena_ptr_;
  }
  public:

  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required .Cmd.AccountErrorCode error = 1;
  bool has_error() const;
  void clear_error();
  static const int kErrorFieldNumber = 1;
  ::Cmd::AccountErrorCode error() const;
  void set_error(::Cmd::AccountErrorCode value);

  // required string password = 2;
  bool has_password() const;
  void clear_password();
  static const int kPasswordFieldNumber = 2;
  const ::std::string& password() const;
  void set_password(const ::std::string& value);
  void set_password(const char* value);
  void set_password(const char* value, size_t size);
  ::std::string* mutable_password();
  ::std::string* release_password();
  void set_allocated_password(::std::string* password);

  // required int32 accountid = 3;
  bool has_accountid() const;
  void clear_accountid();
  static const int kAccountidFieldNumber = 3;
  ::google::protobuf::int32 accountid() const;
  void set_accountid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Cmd.RetAccountOperation)
 private:
  inline void set_has_error();
  inline void clear_has_error();
  inline void set_has_password();
  inline void clear_has_password();
  inline void set_has_accountid();
  inline void clear_has_accountid();

  // helper for ByteSize()
  int RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
  ::google::protobuf::Arena* _arena_ptr_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr password_;
  int error_;
  ::google::protobuf::int32 accountid_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_Command_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_Command_2eproto();
  #endif
  friend void protobuf_AssignDesc_Command_2eproto();
  friend void protobuf_ShutdownFile_Command_2eproto();

  void InitAsDefaultInstance();
  static RetAccountOperation* default_instance_;
};
// -------------------------------------------------------------------

class ReqLoginGameServer : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:Cmd.ReqLoginGameServer) */ {
 public:
  ReqLoginGameServer();
  virtual ~ReqLoginGameServer();

  ReqLoginGameServer(const ReqLoginGameServer& from);

  inline ReqLoginGameServer& operator=(const ReqLoginGameServer& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::std::string& unknown_fields() const {
    return _unknown_fields_.GetNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }

  inline ::std::string* mutable_unknown_fields() {
    return _unknown_fields_.MutableNoArena(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }

  static const ReqLoginGameServer& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const ReqLoginGameServer* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(ReqLoginGameServer* other);

  // implements Message ----------------------------------------------

  inline ReqLoginGameServer* New() const { return New(NULL); }

  ReqLoginGameServer* New(::google::protobuf::Arena* arena) const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const ReqLoginGameServer& from);
  void MergeFrom(const ReqLoginGameServer& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ReqLoginGameServer* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _arena_ptr_;
  }
  inline ::google::protobuf::Arena* MaybeArenaPtr() const {
    return _arena_ptr_;
  }
  public:

  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 accountid = 1;
  bool has_accountid() const;
  void clear_accountid();
  static const int kAccountidFieldNumber = 1;
  ::google::protobuf::int32 accountid() const;
  void set_accountid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Cmd.ReqLoginGameServer)
 private:
  inline void set_has_accountid();
  inline void clear_has_accountid();

  ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
  ::google::protobuf::Arena* _arena_ptr_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int32 accountid_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_Command_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_Command_2eproto();
  #endif
  friend void protobuf_AssignDesc_Command_2eproto();
  friend void protobuf_ShutdownFile_Command_2eproto();

  void InitAsDefaultInstance();
  static ReqLoginGameServer* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// ReqAccountOperation

// required .Cmd.AccountAction action = 1;
inline bool ReqAccountOperation::has_action() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ReqAccountOperation::set_has_action() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ReqAccountOperation::clear_has_action() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ReqAccountOperation::clear_action() {
  action_ = 0;
  clear_has_action();
}
inline ::Cmd::AccountAction ReqAccountOperation::action() const {
  // @@protoc_insertion_point(field_get:Cmd.ReqAccountOperation.action)
  return static_cast< ::Cmd::AccountAction >(action_);
}
inline void ReqAccountOperation::set_action(::Cmd::AccountAction value) {
  assert(::Cmd::AccountAction_IsValid(value));
  set_has_action();
  action_ = value;
  // @@protoc_insertion_point(field_set:Cmd.ReqAccountOperation.action)
}

// required string user = 2;
inline bool ReqAccountOperation::has_user() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ReqAccountOperation::set_has_user() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ReqAccountOperation::clear_has_user() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ReqAccountOperation::clear_user() {
  user_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_user();
}
inline const ::std::string& ReqAccountOperation::user() const {
  // @@protoc_insertion_point(field_get:Cmd.ReqAccountOperation.user)
  return user_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ReqAccountOperation::set_user(const ::std::string& value) {
  set_has_user();
  user_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Cmd.ReqAccountOperation.user)
}
inline void ReqAccountOperation::set_user(const char* value) {
  set_has_user();
  user_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Cmd.ReqAccountOperation.user)
}
inline void ReqAccountOperation::set_user(const char* value, size_t size) {
  set_has_user();
  user_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Cmd.ReqAccountOperation.user)
}
inline ::std::string* ReqAccountOperation::mutable_user() {
  set_has_user();
  // @@protoc_insertion_point(field_mutable:Cmd.ReqAccountOperation.user)
  return user_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ReqAccountOperation::release_user() {
  // @@protoc_insertion_point(field_release:Cmd.ReqAccountOperation.user)
  clear_has_user();
  return user_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ReqAccountOperation::set_allocated_user(::std::string* user) {
  if (user != NULL) {
    set_has_user();
  } else {
    clear_has_user();
  }
  user_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), user);
  // @@protoc_insertion_point(field_set_allocated:Cmd.ReqAccountOperation.user)
}

// required string password = 3;
inline bool ReqAccountOperation::has_password() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ReqAccountOperation::set_has_password() {
  _has_bits_[0] |= 0x00000004u;
}
inline void ReqAccountOperation::clear_has_password() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void ReqAccountOperation::clear_password() {
  password_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_password();
}
inline const ::std::string& ReqAccountOperation::password() const {
  // @@protoc_insertion_point(field_get:Cmd.ReqAccountOperation.password)
  return password_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ReqAccountOperation::set_password(const ::std::string& value) {
  set_has_password();
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Cmd.ReqAccountOperation.password)
}
inline void ReqAccountOperation::set_password(const char* value) {
  set_has_password();
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Cmd.ReqAccountOperation.password)
}
inline void ReqAccountOperation::set_password(const char* value, size_t size) {
  set_has_password();
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Cmd.ReqAccountOperation.password)
}
inline ::std::string* ReqAccountOperation::mutable_password() {
  set_has_password();
  // @@protoc_insertion_point(field_mutable:Cmd.ReqAccountOperation.password)
  return password_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ReqAccountOperation::release_password() {
  // @@protoc_insertion_point(field_release:Cmd.ReqAccountOperation.password)
  clear_has_password();
  return password_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ReqAccountOperation::set_allocated_password(::std::string* password) {
  if (password != NULL) {
    set_has_password();
  } else {
    clear_has_password();
  }
  password_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), password);
  // @@protoc_insertion_point(field_set_allocated:Cmd.ReqAccountOperation.password)
}

// -------------------------------------------------------------------

// RetAccountOperation

// required .Cmd.AccountErrorCode error = 1;
inline bool RetAccountOperation::has_error() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void RetAccountOperation::set_has_error() {
  _has_bits_[0] |= 0x00000001u;
}
inline void RetAccountOperation::clear_has_error() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void RetAccountOperation::clear_error() {
  error_ = 0;
  clear_has_error();
}
inline ::Cmd::AccountErrorCode RetAccountOperation::error() const {
  // @@protoc_insertion_point(field_get:Cmd.RetAccountOperation.error)
  return static_cast< ::Cmd::AccountErrorCode >(error_);
}
inline void RetAccountOperation::set_error(::Cmd::AccountErrorCode value) {
  assert(::Cmd::AccountErrorCode_IsValid(value));
  set_has_error();
  error_ = value;
  // @@protoc_insertion_point(field_set:Cmd.RetAccountOperation.error)
}

// required string password = 2;
inline bool RetAccountOperation::has_password() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void RetAccountOperation::set_has_password() {
  _has_bits_[0] |= 0x00000002u;
}
inline void RetAccountOperation::clear_has_password() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void RetAccountOperation::clear_password() {
  password_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_password();
}
inline const ::std::string& RetAccountOperation::password() const {
  // @@protoc_insertion_point(field_get:Cmd.RetAccountOperation.password)
  return password_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RetAccountOperation::set_password(const ::std::string& value) {
  set_has_password();
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Cmd.RetAccountOperation.password)
}
inline void RetAccountOperation::set_password(const char* value) {
  set_has_password();
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Cmd.RetAccountOperation.password)
}
inline void RetAccountOperation::set_password(const char* value, size_t size) {
  set_has_password();
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Cmd.RetAccountOperation.password)
}
inline ::std::string* RetAccountOperation::mutable_password() {
  set_has_password();
  // @@protoc_insertion_point(field_mutable:Cmd.RetAccountOperation.password)
  return password_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* RetAccountOperation::release_password() {
  // @@protoc_insertion_point(field_release:Cmd.RetAccountOperation.password)
  clear_has_password();
  return password_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RetAccountOperation::set_allocated_password(::std::string* password) {
  if (password != NULL) {
    set_has_password();
  } else {
    clear_has_password();
  }
  password_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), password);
  // @@protoc_insertion_point(field_set_allocated:Cmd.RetAccountOperation.password)
}

// required int32 accountid = 3;
inline bool RetAccountOperation::has_accountid() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void RetAccountOperation::set_has_accountid() {
  _has_bits_[0] |= 0x00000004u;
}
inline void RetAccountOperation::clear_has_accountid() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void RetAccountOperation::clear_accountid() {
  accountid_ = 0;
  clear_has_accountid();
}
inline ::google::protobuf::int32 RetAccountOperation::accountid() const {
  // @@protoc_insertion_point(field_get:Cmd.RetAccountOperation.accountid)
  return accountid_;
}
inline void RetAccountOperation::set_accountid(::google::protobuf::int32 value) {
  set_has_accountid();
  accountid_ = value;
  // @@protoc_insertion_point(field_set:Cmd.RetAccountOperation.accountid)
}

// -------------------------------------------------------------------

// ReqLoginGameServer

// required int32 accountid = 1;
inline bool ReqLoginGameServer::has_accountid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ReqLoginGameServer::set_has_accountid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ReqLoginGameServer::clear_has_accountid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ReqLoginGameServer::clear_accountid() {
  accountid_ = 0;
  clear_has_accountid();
}
inline ::google::protobuf::int32 ReqLoginGameServer::accountid() const {
  // @@protoc_insertion_point(field_get:Cmd.ReqLoginGameServer.accountid)
  return accountid_;
}
inline void ReqLoginGameServer::set_accountid(::google::protobuf::int32 value) {
  set_has_accountid();
  accountid_ = value;
  // @@protoc_insertion_point(field_set:Cmd.ReqLoginGameServer.accountid)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Cmd

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::Cmd::AccountAction> : ::google::protobuf::internal::true_type {};
template <> struct is_proto_enum< ::Cmd::AccountErrorCode> : ::google::protobuf::internal::true_type {};

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Command_2eproto__INCLUDED

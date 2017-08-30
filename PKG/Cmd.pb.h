// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Cmd.proto

#ifndef PROTOBUF_Cmd_2eproto__INCLUDED
#define PROTOBUF_Cmd_2eproto__INCLUDED

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
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_util.h>
// @@protoc_insertion_point(includes)

namespace Cmd {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_Cmd_2eproto();
void protobuf_AssignDesc_Cmd_2eproto();
void protobuf_ShutdownFile_Cmd_2eproto();


enum CLIENTID {
  RQLoginCenter = 100,
  RQAccountOperation = 300,
  RQLoginGame = 400,
  RQCreateRole = 500,
  RQEnterGame = 600
};
bool CLIENTID_IsValid(int value);
const CLIENTID CLIENTID_MIN = RQLoginCenter;
const CLIENTID CLIENTID_MAX = RQEnterGame;
const int CLIENTID_ARRAYSIZE = CLIENTID_MAX + 1;

enum SERVERID {
  RTLoginCenter = 100,
  RTAccountOperation = 300,
  RTLoginGame = 400,
  RTCreateRole = 500,
  RTMainUser = 600
};
bool SERVERID_IsValid(int value);
const SERVERID SERVERID_MIN = RTLoginCenter;
const SERVERID SERVERID_MAX = RTMainUser;
const int SERVERID_ARRAYSIZE = SERVERID_MAX + 1;

// ===================================================================


// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace Cmd

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::Cmd::CLIENTID> : ::google::protobuf::internal::true_type {};
template <> struct is_proto_enum< ::Cmd::SERVERID> : ::google::protobuf::internal::true_type {};

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Cmd_2eproto__INCLUDED

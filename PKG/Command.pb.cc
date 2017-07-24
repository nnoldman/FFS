// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Command.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Command.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Cmd {

namespace {

const ::google::protobuf::Descriptor* Duration_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Duration_reflection_ = NULL;
const ::google::protobuf::Descriptor* RTGameServer_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RTGameServer_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_Command_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_Command_2eproto() {
  protobuf_AddDesc_Command_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Command.proto");
  GOOGLE_CHECK(file != NULL);
  Duration_descriptor_ = file->message_type(0);
  static const int Duration_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Duration, seconds_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Duration, nanos_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Duration, name_),
  };
  Duration_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      Duration_descriptor_,
      Duration::default_instance_,
      Duration_offsets_,
      -1,
      -1,
      -1,
      sizeof(Duration),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Duration, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Duration, _is_default_instance_));
  RTGameServer_descriptor_ = file->message_type(1);
  static const int RTGameServer_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RTGameServer, ip_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RTGameServer, port_),
  };
  RTGameServer_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      RTGameServer_descriptor_,
      RTGameServer::default_instance_,
      RTGameServer_offsets_,
      -1,
      -1,
      -1,
      sizeof(RTGameServer),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RTGameServer, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RTGameServer, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Command_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Duration_descriptor_, &Duration::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      RTGameServer_descriptor_, &RTGameServer::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Command_2eproto() {
  delete Duration::default_instance_;
  delete Duration_reflection_;
  delete RTGameServer::default_instance_;
  delete RTGameServer_reflection_;
}

void protobuf_AddDesc_Command_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_Command_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rCommand.proto\022\003Cmd\"8\n\010Duration\022\017\n\007seco"
    "nds\030\001 \001(\003\022\r\n\005nanos\030\002 \001(\005\022\014\n\004name\030\003 \001(\t\"("
    "\n\014RTGameServer\022\n\n\002ip\030\001 \001(\t\022\014\n\004port\030\002 \001(\005"
    "B|\n\023com.google.protobufB\rDurationProtoP\001"
    "Z*github.com/golang/protobuf/ptypes/dura"
    "tion\240\001\001\242\002\003GPB\252\002\036Google.Protobuf.WellKnow"
    "nTypesb\006proto3", 254);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Command.proto", &protobuf_RegisterTypes);
  Duration::default_instance_ = new Duration();
  RTGameServer::default_instance_ = new RTGameServer();
  Duration::default_instance_->InitAsDefaultInstance();
  RTGameServer::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Command_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Command_2eproto {
  StaticDescriptorInitializer_Command_2eproto() {
    protobuf_AddDesc_Command_2eproto();
  }
} static_descriptor_initializer_Command_2eproto_;

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Duration::kSecondsFieldNumber;
const int Duration::kNanosFieldNumber;
const int Duration::kNameFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Duration::Duration()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Cmd.Duration)
}

void Duration::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

Duration::Duration(const Duration& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Cmd.Duration)
}

void Duration::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  seconds_ = GOOGLE_LONGLONG(0);
  nanos_ = 0;
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

Duration::~Duration() {
  // @@protoc_insertion_point(destructor:Cmd.Duration)
  SharedDtor();
}

void Duration::SharedDtor() {
  name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void Duration::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Duration::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Duration_descriptor_;
}

const Duration& Duration::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Command_2eproto();
  return *default_instance_;
}

Duration* Duration::default_instance_ = NULL;

Duration* Duration::New(::google::protobuf::Arena* arena) const {
  Duration* n = new Duration;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Duration::Clear() {
// @@protoc_insertion_point(message_clear_start:Cmd.Duration)
  seconds_ = GOOGLE_LONGLONG(0);
  nanos_ = 0;
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

bool Duration::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Cmd.Duration)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 seconds = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &seconds_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_nanos;
        break;
      }

      // optional int32 nanos = 2;
      case 2: {
        if (tag == 16) {
         parse_nanos:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &nanos_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_name;
        break;
      }

      // optional string name = 3;
      case 3: {
        if (tag == 26) {
         parse_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "Cmd.Duration.name"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Cmd.Duration)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Cmd.Duration)
  return false;
#undef DO_
}

void Duration::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Cmd.Duration)
  // optional int64 seconds = 1;
  if (this->seconds() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->seconds(), output);
  }

  // optional int32 nanos = 2;
  if (this->nanos() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->nanos(), output);
  }

  // optional string name = 3;
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "Cmd.Duration.name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->name(), output);
  }

  // @@protoc_insertion_point(serialize_end:Cmd.Duration)
}

::google::protobuf::uint8* Duration::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Cmd.Duration)
  // optional int64 seconds = 1;
  if (this->seconds() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->seconds(), target);
  }

  // optional int32 nanos = 2;
  if (this->nanos() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->nanos(), target);
  }

  // optional string name = 3;
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "Cmd.Duration.name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->name(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:Cmd.Duration)
  return target;
}

int Duration::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:Cmd.Duration)
  int total_size = 0;

  // optional int64 seconds = 1;
  if (this->seconds() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->seconds());
  }

  // optional int32 nanos = 2;
  if (this->nanos() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->nanos());
  }

  // optional string name = 3;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->name());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Duration::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Cmd.Duration)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const Duration* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const Duration>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Cmd.Duration)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Cmd.Duration)
    MergeFrom(*source);
  }
}

void Duration::MergeFrom(const Duration& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Cmd.Duration)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.seconds() != 0) {
    set_seconds(from.seconds());
  }
  if (from.nanos() != 0) {
    set_nanos(from.nanos());
  }
  if (from.name().size() > 0) {

    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
}

void Duration::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Cmd.Duration)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Duration::CopyFrom(const Duration& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Cmd.Duration)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Duration::IsInitialized() const {

  return true;
}

void Duration::Swap(Duration* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Duration::InternalSwap(Duration* other) {
  std::swap(seconds_, other->seconds_);
  std::swap(nanos_, other->nanos_);
  name_.Swap(&other->name_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Duration::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Duration_descriptor_;
  metadata.reflection = Duration_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Duration

// optional int64 seconds = 1;
void Duration::clear_seconds() {
  seconds_ = GOOGLE_LONGLONG(0);
}
 ::google::protobuf::int64 Duration::seconds() const {
  // @@protoc_insertion_point(field_get:Cmd.Duration.seconds)
  return seconds_;
}
 void Duration::set_seconds(::google::protobuf::int64 value) {
  
  seconds_ = value;
  // @@protoc_insertion_point(field_set:Cmd.Duration.seconds)
}

// optional int32 nanos = 2;
void Duration::clear_nanos() {
  nanos_ = 0;
}
 ::google::protobuf::int32 Duration::nanos() const {
  // @@protoc_insertion_point(field_get:Cmd.Duration.nanos)
  return nanos_;
}
 void Duration::set_nanos(::google::protobuf::int32 value) {
  
  nanos_ = value;
  // @@protoc_insertion_point(field_set:Cmd.Duration.nanos)
}

// optional string name = 3;
void Duration::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& Duration::name() const {
  // @@protoc_insertion_point(field_get:Cmd.Duration.name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void Duration::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Cmd.Duration.name)
}
 void Duration::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Cmd.Duration.name)
}
 void Duration::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Cmd.Duration.name)
}
 ::std::string* Duration::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:Cmd.Duration.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* Duration::release_name() {
  // @@protoc_insertion_point(field_release:Cmd.Duration.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void Duration::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:Cmd.Duration.name)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int RTGameServer::kIpFieldNumber;
const int RTGameServer::kPortFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

RTGameServer::RTGameServer()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Cmd.RTGameServer)
}

void RTGameServer::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

RTGameServer::RTGameServer(const RTGameServer& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Cmd.RTGameServer)
}

void RTGameServer::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  ip_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  port_ = 0;
}

RTGameServer::~RTGameServer() {
  // @@protoc_insertion_point(destructor:Cmd.RTGameServer)
  SharedDtor();
}

void RTGameServer::SharedDtor() {
  ip_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void RTGameServer::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RTGameServer::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RTGameServer_descriptor_;
}

const RTGameServer& RTGameServer::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Command_2eproto();
  return *default_instance_;
}

RTGameServer* RTGameServer::default_instance_ = NULL;

RTGameServer* RTGameServer::New(::google::protobuf::Arena* arena) const {
  RTGameServer* n = new RTGameServer;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void RTGameServer::Clear() {
// @@protoc_insertion_point(message_clear_start:Cmd.RTGameServer)
  ip_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  port_ = 0;
}

bool RTGameServer::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Cmd.RTGameServer)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string ip = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_ip()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->ip().data(), this->ip().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "Cmd.RTGameServer.ip"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_port;
        break;
      }

      // optional int32 port = 2;
      case 2: {
        if (tag == 16) {
         parse_port:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &port_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Cmd.RTGameServer)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Cmd.RTGameServer)
  return false;
#undef DO_
}

void RTGameServer::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Cmd.RTGameServer)
  // optional string ip = 1;
  if (this->ip().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->ip().data(), this->ip().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "Cmd.RTGameServer.ip");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->ip(), output);
  }

  // optional int32 port = 2;
  if (this->port() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->port(), output);
  }

  // @@protoc_insertion_point(serialize_end:Cmd.RTGameServer)
}

::google::protobuf::uint8* RTGameServer::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Cmd.RTGameServer)
  // optional string ip = 1;
  if (this->ip().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->ip().data(), this->ip().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "Cmd.RTGameServer.ip");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->ip(), target);
  }

  // optional int32 port = 2;
  if (this->port() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->port(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:Cmd.RTGameServer)
  return target;
}

int RTGameServer::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:Cmd.RTGameServer)
  int total_size = 0;

  // optional string ip = 1;
  if (this->ip().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->ip());
  }

  // optional int32 port = 2;
  if (this->port() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->port());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void RTGameServer::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Cmd.RTGameServer)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const RTGameServer* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const RTGameServer>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Cmd.RTGameServer)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Cmd.RTGameServer)
    MergeFrom(*source);
  }
}

void RTGameServer::MergeFrom(const RTGameServer& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Cmd.RTGameServer)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.ip().size() > 0) {

    ip_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.ip_);
  }
  if (from.port() != 0) {
    set_port(from.port());
  }
}

void RTGameServer::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Cmd.RTGameServer)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RTGameServer::CopyFrom(const RTGameServer& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Cmd.RTGameServer)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RTGameServer::IsInitialized() const {

  return true;
}

void RTGameServer::Swap(RTGameServer* other) {
  if (other == this) return;
  InternalSwap(other);
}
void RTGameServer::InternalSwap(RTGameServer* other) {
  ip_.Swap(&other->ip_);
  std::swap(port_, other->port_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata RTGameServer::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RTGameServer_descriptor_;
  metadata.reflection = RTGameServer_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// RTGameServer

// optional string ip = 1;
void RTGameServer::clear_ip() {
  ip_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& RTGameServer::ip() const {
  // @@protoc_insertion_point(field_get:Cmd.RTGameServer.ip)
  return ip_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void RTGameServer::set_ip(const ::std::string& value) {
  
  ip_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Cmd.RTGameServer.ip)
}
 void RTGameServer::set_ip(const char* value) {
  
  ip_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Cmd.RTGameServer.ip)
}
 void RTGameServer::set_ip(const char* value, size_t size) {
  
  ip_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Cmd.RTGameServer.ip)
}
 ::std::string* RTGameServer::mutable_ip() {
  
  // @@protoc_insertion_point(field_mutable:Cmd.RTGameServer.ip)
  return ip_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* RTGameServer::release_ip() {
  // @@protoc_insertion_point(field_release:Cmd.RTGameServer.ip)
  
  return ip_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void RTGameServer::set_allocated_ip(::std::string* ip) {
  if (ip != NULL) {
    
  } else {
    
  }
  ip_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ip);
  // @@protoc_insertion_point(field_set_allocated:Cmd.RTGameServer.ip)
}

// optional int32 port = 2;
void RTGameServer::clear_port() {
  port_ = 0;
}
 ::google::protobuf::int32 RTGameServer::port() const {
  // @@protoc_insertion_point(field_get:Cmd.RTGameServer.port)
  return port_;
}
 void RTGameServer::set_port(::google::protobuf::int32 value) {
  
  port_ = value;
  // @@protoc_insertion_point(field_set:Cmd.RTGameServer.port)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace Cmd

// @@protoc_insertion_point(global_scope)

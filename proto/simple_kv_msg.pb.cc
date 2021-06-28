// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/simple_kv_msg.proto

#include "proto/simple_kv_msg.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace KvMsg {
constexpr Request::Request(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : key_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , val_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , op_type_(0)
{}
struct RequestDefaultTypeInternal {
  constexpr RequestDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~RequestDefaultTypeInternal() {}
  union {
    Request _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT RequestDefaultTypeInternal _Request_default_instance_;
constexpr Response::Response(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : data_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , code_(0){}
struct ResponseDefaultTypeInternal {
  constexpr ResponseDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~ResponseDefaultTypeInternal() {}
  union {
    Response _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT ResponseDefaultTypeInternal _Response_default_instance_;
}  // namespace KvMsg
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_proto_2fsimple_5fkv_5fmsg_2eproto[2];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_proto_2fsimple_5fkv_5fmsg_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_proto_2fsimple_5fkv_5fmsg_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_proto_2fsimple_5fkv_5fmsg_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::KvMsg::Request, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::KvMsg::Request, key_),
  PROTOBUF_FIELD_OFFSET(::KvMsg::Request, val_),
  PROTOBUF_FIELD_OFFSET(::KvMsg::Request, op_type_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::KvMsg::Response, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::KvMsg::Response, code_),
  PROTOBUF_FIELD_OFFSET(::KvMsg::Response, data_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::KvMsg::Request)},
  { 8, -1, sizeof(::KvMsg::Response)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::KvMsg::_Request_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::KvMsg::_Response_default_instance_),
};

const char descriptor_table_protodef_proto_2fsimple_5fkv_5fmsg_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\031proto/simple_kv_msg.proto\022\005KvMsg\"g\n\007Re"
  "quest\022\013\n\003key\030\001 \001(\t\022\013\n\003val\030\002 \001(\t\022&\n\007op_ty"
  "pe\030\003 \001(\0162\025.KvMsg.Request.OpType\"\032\n\006OpTyp"
  "e\022\007\n\003GET\020\000\022\007\n\003PUT\020\001\"&\n\010Response\022\014\n\004code\030"
  "\001 \001(\005\022\014\n\004data\030\002 \001(\tb\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_proto_2fsimple_5fkv_5fmsg_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2fsimple_5fkv_5fmsg_2eproto = {
  false, false, 187, descriptor_table_protodef_proto_2fsimple_5fkv_5fmsg_2eproto, "proto/simple_kv_msg.proto", 
  &descriptor_table_proto_2fsimple_5fkv_5fmsg_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_proto_2fsimple_5fkv_5fmsg_2eproto::offsets,
  file_level_metadata_proto_2fsimple_5fkv_5fmsg_2eproto, file_level_enum_descriptors_proto_2fsimple_5fkv_5fmsg_2eproto, file_level_service_descriptors_proto_2fsimple_5fkv_5fmsg_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_proto_2fsimple_5fkv_5fmsg_2eproto_getter() {
  return &descriptor_table_proto_2fsimple_5fkv_5fmsg_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_proto_2fsimple_5fkv_5fmsg_2eproto(&descriptor_table_proto_2fsimple_5fkv_5fmsg_2eproto);
namespace KvMsg {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Request_OpType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_proto_2fsimple_5fkv_5fmsg_2eproto);
  return file_level_enum_descriptors_proto_2fsimple_5fkv_5fmsg_2eproto[0];
}
bool Request_OpType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr Request_OpType Request::GET;
constexpr Request_OpType Request::PUT;
constexpr Request_OpType Request::OpType_MIN;
constexpr Request_OpType Request::OpType_MAX;
constexpr int Request::OpType_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)

// ===================================================================

class Request::_Internal {
 public:
};

Request::Request(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:KvMsg.Request)
}
Request::Request(const Request& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  key_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_key().empty()) {
    key_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_key(), 
      GetArenaForAllocation());
  }
  val_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_val().empty()) {
    val_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_val(), 
      GetArenaForAllocation());
  }
  op_type_ = from.op_type_;
  // @@protoc_insertion_point(copy_constructor:KvMsg.Request)
}

inline void Request::SharedCtor() {
key_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
val_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
op_type_ = 0;
}

Request::~Request() {
  // @@protoc_insertion_point(destructor:KvMsg.Request)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Request::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  key_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  val_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Request::ArenaDtor(void* object) {
  Request* _this = reinterpret_cast< Request* >(object);
  (void)_this;
}
void Request::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Request::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Request::Clear() {
// @@protoc_insertion_point(message_clear_start:KvMsg.Request)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  key_.ClearToEmpty();
  val_.ClearToEmpty();
  op_type_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Request::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string key = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_key();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "KvMsg.Request.key"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string val = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_val();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "KvMsg.Request.val"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .KvMsg.Request.OpType op_type = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_op_type(static_cast<::KvMsg::Request_OpType>(val));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Request::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:KvMsg.Request)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string key = 1;
  if (!this->_internal_key().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_key().data(), static_cast<int>(this->_internal_key().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "KvMsg.Request.key");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_key(), target);
  }

  // string val = 2;
  if (!this->_internal_val().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_val().data(), static_cast<int>(this->_internal_val().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "KvMsg.Request.val");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_val(), target);
  }

  // .KvMsg.Request.OpType op_type = 3;
  if (this->_internal_op_type() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      3, this->_internal_op_type(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:KvMsg.Request)
  return target;
}

size_t Request::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:KvMsg.Request)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string key = 1;
  if (!this->_internal_key().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_key());
  }

  // string val = 2;
  if (!this->_internal_val().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_val());
  }

  // .KvMsg.Request.OpType op_type = 3;
  if (this->_internal_op_type() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_op_type());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Request::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Request::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Request::GetClassData() const { return &_class_data_; }

void Request::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<Request *>(to)->MergeFrom(
      static_cast<const Request &>(from));
}


void Request::MergeFrom(const Request& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:KvMsg.Request)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_key().empty()) {
    _internal_set_key(from._internal_key());
  }
  if (!from._internal_val().empty()) {
    _internal_set_val(from._internal_val());
  }
  if (from._internal_op_type() != 0) {
    _internal_set_op_type(from._internal_op_type());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Request::CopyFrom(const Request& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:KvMsg.Request)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Request::IsInitialized() const {
  return true;
}

void Request::InternalSwap(Request* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &key_, GetArenaForAllocation(),
      &other->key_, other->GetArenaForAllocation()
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &val_, GetArenaForAllocation(),
      &other->val_, other->GetArenaForAllocation()
  );
  swap(op_type_, other->op_type_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Request::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_proto_2fsimple_5fkv_5fmsg_2eproto_getter, &descriptor_table_proto_2fsimple_5fkv_5fmsg_2eproto_once,
      file_level_metadata_proto_2fsimple_5fkv_5fmsg_2eproto[0]);
}

// ===================================================================

class Response::_Internal {
 public:
};

Response::Response(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:KvMsg.Response)
}
Response::Response(const Response& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  data_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_data().empty()) {
    data_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_data(), 
      GetArenaForAllocation());
  }
  code_ = from.code_;
  // @@protoc_insertion_point(copy_constructor:KvMsg.Response)
}

inline void Response::SharedCtor() {
data_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
code_ = 0;
}

Response::~Response() {
  // @@protoc_insertion_point(destructor:KvMsg.Response)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Response::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  data_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Response::ArenaDtor(void* object) {
  Response* _this = reinterpret_cast< Response* >(object);
  (void)_this;
}
void Response::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Response::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Response::Clear() {
// @@protoc_insertion_point(message_clear_start:KvMsg.Response)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  data_.ClearToEmpty();
  code_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Response::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 code = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          code_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string data = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_data();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "KvMsg.Response.data"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Response::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:KvMsg.Response)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 code = 1;
  if (this->_internal_code() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_code(), target);
  }

  // string data = 2;
  if (!this->_internal_data().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_data().data(), static_cast<int>(this->_internal_data().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "KvMsg.Response.data");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_data(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:KvMsg.Response)
  return target;
}

size_t Response::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:KvMsg.Response)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string data = 2;
  if (!this->_internal_data().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_data());
  }

  // int32 code = 1;
  if (this->_internal_code() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_code());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Response::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Response::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Response::GetClassData() const { return &_class_data_; }

void Response::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<Response *>(to)->MergeFrom(
      static_cast<const Response &>(from));
}


void Response::MergeFrom(const Response& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:KvMsg.Response)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_data().empty()) {
    _internal_set_data(from._internal_data());
  }
  if (from._internal_code() != 0) {
    _internal_set_code(from._internal_code());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Response::CopyFrom(const Response& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:KvMsg.Response)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Response::IsInitialized() const {
  return true;
}

void Response::InternalSwap(Response* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &data_, GetArenaForAllocation(),
      &other->data_, other->GetArenaForAllocation()
  );
  swap(code_, other->code_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Response::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_proto_2fsimple_5fkv_5fmsg_2eproto_getter, &descriptor_table_proto_2fsimple_5fkv_5fmsg_2eproto_once,
      file_level_metadata_proto_2fsimple_5fkv_5fmsg_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace KvMsg
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::KvMsg::Request* Arena::CreateMaybeMessage< ::KvMsg::Request >(Arena* arena) {
  return Arena::CreateMessageInternal< ::KvMsg::Request >(arena);
}
template<> PROTOBUF_NOINLINE ::KvMsg::Response* Arena::CreateMaybeMessage< ::KvMsg::Response >(Arena* arena) {
  return Arena::CreateMessageInternal< ::KvMsg::Response >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>

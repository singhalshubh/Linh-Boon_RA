// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: kvcomm.proto

#include "kvcomm.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace kv {
class commandDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<command>
      _instance;
} _command_default_instance_;
}  // namespace kv
namespace protobuf_kvcomm_2eproto {
static void InitDefaultscommand() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::kv::_command_default_instance_;
    new (ptr) ::kv::command();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::kv::command::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_command =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultscommand}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_command.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::kv::command, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::kv::command, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::kv::command, comm_type_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::kv::command, sender_type_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::kv::command, sender_address_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::kv::command, job_id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::kv::command, unique_job_id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::kv::command, data_center_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::kv::command, unique_task_id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::kv::command, task_info_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::kv::command, compute_task_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::kv::command, exec_time_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::kv::command, waiting_time_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::kv::command, rtt_time_total_),
  0,
  1,
  2,
  6,
  3,
  7,
  4,
  5,
  11,
  8,
  9,
  10,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 17, sizeof(::kv::command)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::kv::_command_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "kvcomm.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\014kvcomm.proto\022\002kv\"\207\002\n\007command\022\021\n\tcomm_t"
      "ype\030\001 \002(\t\022\023\n\013sender_type\030\002 \001(\t\022\026\n\016sender"
      "_address\030\003 \001(\t\022\016\n\006job_id\030\004 \001(\005\022\025\n\runique"
      "_job_id\030\005 \001(\t\022\023\n\013data_center\030\006 \001(\005\022\026\n\016un"
      "ique_task_id\030\007 \001(\t\022\021\n\ttask_info\030\010 \001(\t\022\024\n"
      "\014compute_task\030\t \001(\005\022\021\n\texec_time\030\n \001(\001\022\024"
      "\n\014waiting_time\030\013 \001(\001\022\026\n\016rtt_time_total\030\014"
      " \001(\001"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 284);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "kvcomm.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_kvcomm_2eproto
namespace kv {

// ===================================================================

void command::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int command::kCommTypeFieldNumber;
const int command::kSenderTypeFieldNumber;
const int command::kSenderAddressFieldNumber;
const int command::kJobIdFieldNumber;
const int command::kUniqueJobIdFieldNumber;
const int command::kDataCenterFieldNumber;
const int command::kUniqueTaskIdFieldNumber;
const int command::kTaskInfoFieldNumber;
const int command::kComputeTaskFieldNumber;
const int command::kExecTimeFieldNumber;
const int command::kWaitingTimeFieldNumber;
const int command::kRttTimeTotalFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

command::command()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_kvcomm_2eproto::scc_info_command.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:kv.command)
}
command::command(const command& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  comm_type_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_comm_type()) {
    comm_type_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.comm_type_);
  }
  sender_type_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_sender_type()) {
    sender_type_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.sender_type_);
  }
  sender_address_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_sender_address()) {
    sender_address_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.sender_address_);
  }
  unique_job_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_unique_job_id()) {
    unique_job_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.unique_job_id_);
  }
  unique_task_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_unique_task_id()) {
    unique_task_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.unique_task_id_);
  }
  task_info_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_task_info()) {
    task_info_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.task_info_);
  }
  ::memcpy(&job_id_, &from.job_id_,
    static_cast<size_t>(reinterpret_cast<char*>(&compute_task_) -
    reinterpret_cast<char*>(&job_id_)) + sizeof(compute_task_));
  // @@protoc_insertion_point(copy_constructor:kv.command)
}

void command::SharedCtor() {
  comm_type_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  sender_type_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  sender_address_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  unique_job_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  unique_task_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  task_info_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&job_id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&compute_task_) -
      reinterpret_cast<char*>(&job_id_)) + sizeof(compute_task_));
}

command::~command() {
  // @@protoc_insertion_point(destructor:kv.command)
  SharedDtor();
}

void command::SharedDtor() {
  comm_type_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  sender_type_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  sender_address_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  unique_job_id_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  unique_task_id_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  task_info_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void command::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* command::descriptor() {
  ::protobuf_kvcomm_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_kvcomm_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const command& command::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_kvcomm_2eproto::scc_info_command.base);
  return *internal_default_instance();
}


void command::Clear() {
// @@protoc_insertion_point(message_clear_start:kv.command)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 63u) {
    if (cached_has_bits & 0x00000001u) {
      comm_type_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      sender_type_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000004u) {
      sender_address_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000008u) {
      unique_job_id_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000010u) {
      unique_task_id_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000020u) {
      task_info_.ClearNonDefaultToEmptyNoArena();
    }
  }
  if (cached_has_bits & 192u) {
    ::memset(&job_id_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&data_center_) -
        reinterpret_cast<char*>(&job_id_)) + sizeof(data_center_));
  }
  if (cached_has_bits & 3840u) {
    ::memset(&exec_time_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&compute_task_) -
        reinterpret_cast<char*>(&exec_time_)) + sizeof(compute_task_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool command::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:kv.command)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string comm_type = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_comm_type()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->comm_type().data(), static_cast<int>(this->comm_type().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "kv.command.comm_type");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string sender_type = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_sender_type()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->sender_type().data(), static_cast<int>(this->sender_type().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "kv.command.sender_type");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string sender_address = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_sender_address()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->sender_address().data(), static_cast<int>(this->sender_address().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "kv.command.sender_address");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 job_id = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {
          set_has_job_id();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &job_id_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string unique_job_id = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(42u /* 42 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_unique_job_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->unique_job_id().data(), static_cast<int>(this->unique_job_id().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "kv.command.unique_job_id");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 data_center = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(48u /* 48 & 0xFF */)) {
          set_has_data_center();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &data_center_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string unique_task_id = 7;
      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(58u /* 58 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_unique_task_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->unique_task_id().data(), static_cast<int>(this->unique_task_id().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "kv.command.unique_task_id");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string task_info = 8;
      case 8: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(66u /* 66 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_task_info()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->task_info().data(), static_cast<int>(this->task_info().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "kv.command.task_info");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 compute_task = 9;
      case 9: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(72u /* 72 & 0xFF */)) {
          set_has_compute_task();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &compute_task_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional double exec_time = 10;
      case 10: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(81u /* 81 & 0xFF */)) {
          set_has_exec_time();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &exec_time_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional double waiting_time = 11;
      case 11: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(89u /* 89 & 0xFF */)) {
          set_has_waiting_time();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &waiting_time_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional double rtt_time_total = 12;
      case 12: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(97u /* 97 & 0xFF */)) {
          set_has_rtt_time_total();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &rtt_time_total_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:kv.command)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:kv.command)
  return false;
#undef DO_
}

void command::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:kv.command)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string comm_type = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->comm_type().data(), static_cast<int>(this->comm_type().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "kv.command.comm_type");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->comm_type(), output);
  }

  // optional string sender_type = 2;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->sender_type().data(), static_cast<int>(this->sender_type().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "kv.command.sender_type");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->sender_type(), output);
  }

  // optional string sender_address = 3;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->sender_address().data(), static_cast<int>(this->sender_address().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "kv.command.sender_address");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->sender_address(), output);
  }

  // optional int32 job_id = 4;
  if (cached_has_bits & 0x00000040u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->job_id(), output);
  }

  // optional string unique_job_id = 5;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->unique_job_id().data(), static_cast<int>(this->unique_job_id().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "kv.command.unique_job_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->unique_job_id(), output);
  }

  // optional int32 data_center = 6;
  if (cached_has_bits & 0x00000080u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(6, this->data_center(), output);
  }

  // optional string unique_task_id = 7;
  if (cached_has_bits & 0x00000010u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->unique_task_id().data(), static_cast<int>(this->unique_task_id().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "kv.command.unique_task_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      7, this->unique_task_id(), output);
  }

  // optional string task_info = 8;
  if (cached_has_bits & 0x00000020u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->task_info().data(), static_cast<int>(this->task_info().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "kv.command.task_info");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      8, this->task_info(), output);
  }

  // optional int32 compute_task = 9;
  if (cached_has_bits & 0x00000800u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(9, this->compute_task(), output);
  }

  // optional double exec_time = 10;
  if (cached_has_bits & 0x00000100u) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(10, this->exec_time(), output);
  }

  // optional double waiting_time = 11;
  if (cached_has_bits & 0x00000200u) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(11, this->waiting_time(), output);
  }

  // optional double rtt_time_total = 12;
  if (cached_has_bits & 0x00000400u) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(12, this->rtt_time_total(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:kv.command)
}

::google::protobuf::uint8* command::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:kv.command)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string comm_type = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->comm_type().data(), static_cast<int>(this->comm_type().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "kv.command.comm_type");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->comm_type(), target);
  }

  // optional string sender_type = 2;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->sender_type().data(), static_cast<int>(this->sender_type().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "kv.command.sender_type");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->sender_type(), target);
  }

  // optional string sender_address = 3;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->sender_address().data(), static_cast<int>(this->sender_address().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "kv.command.sender_address");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->sender_address(), target);
  }

  // optional int32 job_id = 4;
  if (cached_has_bits & 0x00000040u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->job_id(), target);
  }

  // optional string unique_job_id = 5;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->unique_job_id().data(), static_cast<int>(this->unique_job_id().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "kv.command.unique_job_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->unique_job_id(), target);
  }

  // optional int32 data_center = 6;
  if (cached_has_bits & 0x00000080u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, this->data_center(), target);
  }

  // optional string unique_task_id = 7;
  if (cached_has_bits & 0x00000010u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->unique_task_id().data(), static_cast<int>(this->unique_task_id().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "kv.command.unique_task_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        7, this->unique_task_id(), target);
  }

  // optional string task_info = 8;
  if (cached_has_bits & 0x00000020u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->task_info().data(), static_cast<int>(this->task_info().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "kv.command.task_info");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        8, this->task_info(), target);
  }

  // optional int32 compute_task = 9;
  if (cached_has_bits & 0x00000800u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(9, this->compute_task(), target);
  }

  // optional double exec_time = 10;
  if (cached_has_bits & 0x00000100u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(10, this->exec_time(), target);
  }

  // optional double waiting_time = 11;
  if (cached_has_bits & 0x00000200u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(11, this->waiting_time(), target);
  }

  // optional double rtt_time_total = 12;
  if (cached_has_bits & 0x00000400u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(12, this->rtt_time_total(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:kv.command)
  return target;
}

size_t command::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:kv.command)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // required string comm_type = 1;
  if (has_comm_type()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->comm_type());
  }
  if (_has_bits_[0 / 32] & 254u) {
    // optional string sender_type = 2;
    if (has_sender_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->sender_type());
    }

    // optional string sender_address = 3;
    if (has_sender_address()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->sender_address());
    }

    // optional string unique_job_id = 5;
    if (has_unique_job_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->unique_job_id());
    }

    // optional string unique_task_id = 7;
    if (has_unique_task_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->unique_task_id());
    }

    // optional string task_info = 8;
    if (has_task_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->task_info());
    }

    // optional int32 job_id = 4;
    if (has_job_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->job_id());
    }

    // optional int32 data_center = 6;
    if (has_data_center()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->data_center());
    }

  }
  if (_has_bits_[8 / 32] & 3840u) {
    // optional double exec_time = 10;
    if (has_exec_time()) {
      total_size += 1 + 8;
    }

    // optional double waiting_time = 11;
    if (has_waiting_time()) {
      total_size += 1 + 8;
    }

    // optional double rtt_time_total = 12;
    if (has_rtt_time_total()) {
      total_size += 1 + 8;
    }

    // optional int32 compute_task = 9;
    if (has_compute_task()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->compute_task());
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void command::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:kv.command)
  GOOGLE_DCHECK_NE(&from, this);
  const command* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const command>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:kv.command)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:kv.command)
    MergeFrom(*source);
  }
}

void command::MergeFrom(const command& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:kv.command)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 255u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_comm_type();
      comm_type_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.comm_type_);
    }
    if (cached_has_bits & 0x00000002u) {
      set_has_sender_type();
      sender_type_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.sender_type_);
    }
    if (cached_has_bits & 0x00000004u) {
      set_has_sender_address();
      sender_address_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.sender_address_);
    }
    if (cached_has_bits & 0x00000008u) {
      set_has_unique_job_id();
      unique_job_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.unique_job_id_);
    }
    if (cached_has_bits & 0x00000010u) {
      set_has_unique_task_id();
      unique_task_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.unique_task_id_);
    }
    if (cached_has_bits & 0x00000020u) {
      set_has_task_info();
      task_info_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.task_info_);
    }
    if (cached_has_bits & 0x00000040u) {
      job_id_ = from.job_id_;
    }
    if (cached_has_bits & 0x00000080u) {
      data_center_ = from.data_center_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  if (cached_has_bits & 3840u) {
    if (cached_has_bits & 0x00000100u) {
      exec_time_ = from.exec_time_;
    }
    if (cached_has_bits & 0x00000200u) {
      waiting_time_ = from.waiting_time_;
    }
    if (cached_has_bits & 0x00000400u) {
      rtt_time_total_ = from.rtt_time_total_;
    }
    if (cached_has_bits & 0x00000800u) {
      compute_task_ = from.compute_task_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void command::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:kv.command)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void command::CopyFrom(const command& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:kv.command)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool command::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  return true;
}

void command::Swap(command* other) {
  if (other == this) return;
  InternalSwap(other);
}
void command::InternalSwap(command* other) {
  using std::swap;
  comm_type_.Swap(&other->comm_type_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  sender_type_.Swap(&other->sender_type_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  sender_address_.Swap(&other->sender_address_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  unique_job_id_.Swap(&other->unique_job_id_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  unique_task_id_.Swap(&other->unique_task_id_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  task_info_.Swap(&other->task_info_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(job_id_, other->job_id_);
  swap(data_center_, other->data_center_);
  swap(exec_time_, other->exec_time_);
  swap(waiting_time_, other->waiting_time_);
  swap(rtt_time_total_, other->rtt_time_total_);
  swap(compute_task_, other->compute_task_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata command::GetMetadata() const {
  protobuf_kvcomm_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_kvcomm_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace kv
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::kv::command* Arena::CreateMaybeMessage< ::kv::command >(Arena* arena) {
  return Arena::CreateInternal< ::kv::command >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

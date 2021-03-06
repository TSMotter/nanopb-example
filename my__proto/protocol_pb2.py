# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: protocol.proto
"""Generated protocol buffer code."""
from google.protobuf.internal import enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


import nanopb_pb2 as nanopb__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='protocol.proto',
  package='',
  syntax='proto3',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\x0eprotocol.proto\x1a\x0cnanopb.proto\"\xdd\x02\n\nuart_frame\x12\x13\n\x06my_sof\x18\x01 \x01(\x0cH\x00\x88\x01\x01\x12-\n\x06my_cmd\x18\x04 \x01(\x0b\x32\x18.uart_frame.uart_commandH\x01\x88\x01\x01\x12\x13\n\x06my_crc\x18\x03 \x01(\x0cH\x02\x88\x01\x01\x12\x13\n\x06my_eof\x18\x02 \x01(\x0cH\x03\x88\x01\x01\x1a\xb4\x01\n\x0cuart_command\x12\x17\n\x02Id\x18\x01 \x01(\x0e\x32\x06.Id_enH\x01\x88\x01\x01\x12\"\n\tSubId_led\x18\x02 \x01(\x0e\x32\r.LED_SubId_enH\x00\x12\"\n\tSubId_rtc\x18\x03 \x01(\x0e\x32\r.RTC_SubId_enH\x00\x12\x13\n\x06\x41\x63tion\x18\x04 \x01(\rH\x02\x88\x01\x01\x12\x13\n\x04\x44\x61ta\x18\x05 \x01(\x0c\x42\x05\x92?\x02\x08\x32\x42\x07\n\x05SubIdB\x05\n\x03_IdB\t\n\x07_ActionB\t\n\x07_my_sofB\t\n\x07_my_cmdB\t\n\x07_my_crcB\t\n\x07_my_eof*\'\n\x05Id_en\x12\x0e\n\nLED_MSG_Id\x10\x00\x12\x0e\n\nRTC_MSG_Id\x10\x01*F\n\x0cLED_SubId_en\x12\x11\n\rLED_OFF_SubId\x10\x00\x12\x10\n\x0cLED_ON_SubId\x10\x01\x12\x11\n\rLED_PWM_SubId\x10\x02*\'\n\x0cRTC_SubId_en\x12\x17\n\x13RTC_SET_ALARM_SubId\x10\x00\x62\x06proto3'
  ,
  dependencies=[nanopb__pb2.DESCRIPTOR,])

_ID_EN = _descriptor.EnumDescriptor(
  name='Id_en',
  full_name='Id_en',
  filename=None,
  file=DESCRIPTOR,
  create_key=_descriptor._internal_create_key,
  values=[
    _descriptor.EnumValueDescriptor(
      name='LED_MSG_Id', index=0, number=0,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='RTC_MSG_Id', index=1, number=1,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=384,
  serialized_end=423,
)
_sym_db.RegisterEnumDescriptor(_ID_EN)

Id_en = enum_type_wrapper.EnumTypeWrapper(_ID_EN)
_LED_SUBID_EN = _descriptor.EnumDescriptor(
  name='LED_SubId_en',
  full_name='LED_SubId_en',
  filename=None,
  file=DESCRIPTOR,
  create_key=_descriptor._internal_create_key,
  values=[
    _descriptor.EnumValueDescriptor(
      name='LED_OFF_SubId', index=0, number=0,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='LED_ON_SubId', index=1, number=1,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='LED_PWM_SubId', index=2, number=2,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=425,
  serialized_end=495,
)
_sym_db.RegisterEnumDescriptor(_LED_SUBID_EN)

LED_SubId_en = enum_type_wrapper.EnumTypeWrapper(_LED_SUBID_EN)
_RTC_SUBID_EN = _descriptor.EnumDescriptor(
  name='RTC_SubId_en',
  full_name='RTC_SubId_en',
  filename=None,
  file=DESCRIPTOR,
  create_key=_descriptor._internal_create_key,
  values=[
    _descriptor.EnumValueDescriptor(
      name='RTC_SET_ALARM_SubId', index=0, number=0,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=497,
  serialized_end=536,
)
_sym_db.RegisterEnumDescriptor(_RTC_SUBID_EN)

RTC_SubId_en = enum_type_wrapper.EnumTypeWrapper(_RTC_SUBID_EN)
LED_MSG_Id = 0
RTC_MSG_Id = 1
LED_OFF_SubId = 0
LED_ON_SubId = 1
LED_PWM_SubId = 2
RTC_SET_ALARM_SubId = 0



_UART_FRAME_UART_COMMAND = _descriptor.Descriptor(
  name='uart_command',
  full_name='uart_frame.uart_command',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='Id', full_name='uart_frame.uart_command.Id', index=0,
      number=1, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='SubId_led', full_name='uart_frame.uart_command.SubId_led', index=1,
      number=2, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='SubId_rtc', full_name='uart_frame.uart_command.SubId_rtc', index=2,
      number=3, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='Action', full_name='uart_frame.uart_command.Action', index=3,
      number=4, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='Data', full_name='uart_frame.uart_command.Data', index=4,
      number=5, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value=b"",
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=b'\222?\002\0102', file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
    _descriptor.OneofDescriptor(
      name='SubId', full_name='uart_frame.uart_command.SubId',
      index=0, containing_type=None,
      create_key=_descriptor._internal_create_key,
    fields=[]),
    _descriptor.OneofDescriptor(
      name='_Id', full_name='uart_frame.uart_command._Id',
      index=1, containing_type=None,
      create_key=_descriptor._internal_create_key,
    fields=[]),
    _descriptor.OneofDescriptor(
      name='_Action', full_name='uart_frame.uart_command._Action',
      index=2, containing_type=None,
      create_key=_descriptor._internal_create_key,
    fields=[]),
  ],
  serialized_start=158,
  serialized_end=338,
)

_UART_FRAME = _descriptor.Descriptor(
  name='uart_frame',
  full_name='uart_frame',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='my_sof', full_name='uart_frame.my_sof', index=0,
      number=1, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value=b"",
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='my_cmd', full_name='uart_frame.my_cmd', index=1,
      number=4, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='my_crc', full_name='uart_frame.my_crc', index=2,
      number=3, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value=b"",
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='my_eof', full_name='uart_frame.my_eof', index=3,
      number=2, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value=b"",
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[_UART_FRAME_UART_COMMAND, ],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
    _descriptor.OneofDescriptor(
      name='_my_sof', full_name='uart_frame._my_sof',
      index=0, containing_type=None,
      create_key=_descriptor._internal_create_key,
    fields=[]),
    _descriptor.OneofDescriptor(
      name='_my_cmd', full_name='uart_frame._my_cmd',
      index=1, containing_type=None,
      create_key=_descriptor._internal_create_key,
    fields=[]),
    _descriptor.OneofDescriptor(
      name='_my_crc', full_name='uart_frame._my_crc',
      index=2, containing_type=None,
      create_key=_descriptor._internal_create_key,
    fields=[]),
    _descriptor.OneofDescriptor(
      name='_my_eof', full_name='uart_frame._my_eof',
      index=3, containing_type=None,
      create_key=_descriptor._internal_create_key,
    fields=[]),
  ],
  serialized_start=33,
  serialized_end=382,
)

_UART_FRAME_UART_COMMAND.fields_by_name['Id'].enum_type = _ID_EN
_UART_FRAME_UART_COMMAND.fields_by_name['SubId_led'].enum_type = _LED_SUBID_EN
_UART_FRAME_UART_COMMAND.fields_by_name['SubId_rtc'].enum_type = _RTC_SUBID_EN
_UART_FRAME_UART_COMMAND.containing_type = _UART_FRAME
_UART_FRAME_UART_COMMAND.oneofs_by_name['SubId'].fields.append(
  _UART_FRAME_UART_COMMAND.fields_by_name['SubId_led'])
_UART_FRAME_UART_COMMAND.fields_by_name['SubId_led'].containing_oneof = _UART_FRAME_UART_COMMAND.oneofs_by_name['SubId']
_UART_FRAME_UART_COMMAND.oneofs_by_name['SubId'].fields.append(
  _UART_FRAME_UART_COMMAND.fields_by_name['SubId_rtc'])
_UART_FRAME_UART_COMMAND.fields_by_name['SubId_rtc'].containing_oneof = _UART_FRAME_UART_COMMAND.oneofs_by_name['SubId']
_UART_FRAME_UART_COMMAND.oneofs_by_name['_Id'].fields.append(
  _UART_FRAME_UART_COMMAND.fields_by_name['Id'])
_UART_FRAME_UART_COMMAND.fields_by_name['Id'].containing_oneof = _UART_FRAME_UART_COMMAND.oneofs_by_name['_Id']
_UART_FRAME_UART_COMMAND.oneofs_by_name['_Action'].fields.append(
  _UART_FRAME_UART_COMMAND.fields_by_name['Action'])
_UART_FRAME_UART_COMMAND.fields_by_name['Action'].containing_oneof = _UART_FRAME_UART_COMMAND.oneofs_by_name['_Action']
_UART_FRAME.fields_by_name['my_cmd'].message_type = _UART_FRAME_UART_COMMAND
_UART_FRAME.oneofs_by_name['_my_sof'].fields.append(
  _UART_FRAME.fields_by_name['my_sof'])
_UART_FRAME.fields_by_name['my_sof'].containing_oneof = _UART_FRAME.oneofs_by_name['_my_sof']
_UART_FRAME.oneofs_by_name['_my_cmd'].fields.append(
  _UART_FRAME.fields_by_name['my_cmd'])
_UART_FRAME.fields_by_name['my_cmd'].containing_oneof = _UART_FRAME.oneofs_by_name['_my_cmd']
_UART_FRAME.oneofs_by_name['_my_crc'].fields.append(
  _UART_FRAME.fields_by_name['my_crc'])
_UART_FRAME.fields_by_name['my_crc'].containing_oneof = _UART_FRAME.oneofs_by_name['_my_crc']
_UART_FRAME.oneofs_by_name['_my_eof'].fields.append(
  _UART_FRAME.fields_by_name['my_eof'])
_UART_FRAME.fields_by_name['my_eof'].containing_oneof = _UART_FRAME.oneofs_by_name['_my_eof']
DESCRIPTOR.message_types_by_name['uart_frame'] = _UART_FRAME
DESCRIPTOR.enum_types_by_name['Id_en'] = _ID_EN
DESCRIPTOR.enum_types_by_name['LED_SubId_en'] = _LED_SUBID_EN
DESCRIPTOR.enum_types_by_name['RTC_SubId_en'] = _RTC_SUBID_EN
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

uart_frame = _reflection.GeneratedProtocolMessageType('uart_frame', (_message.Message,), {

  'uart_command' : _reflection.GeneratedProtocolMessageType('uart_command', (_message.Message,), {
    'DESCRIPTOR' : _UART_FRAME_UART_COMMAND,
    '__module__' : 'protocol_pb2'
    # @@protoc_insertion_point(class_scope:uart_frame.uart_command)
    })
  ,
  'DESCRIPTOR' : _UART_FRAME,
  '__module__' : 'protocol_pb2'
  # @@protoc_insertion_point(class_scope:uart_frame)
  })
_sym_db.RegisterMessage(uart_frame)
_sym_db.RegisterMessage(uart_frame.uart_command)


_UART_FRAME_UART_COMMAND.fields_by_name['Data']._options = None
# @@protoc_insertion_point(module_scope)

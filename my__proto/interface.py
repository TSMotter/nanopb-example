import binascii
import protocol_pb2

local_data = "AB"
local_hex = b"\x41\x42"

msg_enc = protocol_pb2.uart_frame()
msg_enc.my_cmd.Id = protocol_pb2.Id_en.RTC_MSG_Id
msg_enc.my_cmd.SubId_led = protocol_pb2.LED_SubId_en.LED_PWM_SubId
#msg_enc.my_cmd.Data.append(local_hex)
rc_enc = msg_enc.SerializeToString()


print('\nmsg_enc: ', msg_enc)
print('\nmsg_enc.SerializeToString(): ', rc_enc)
print(binascii.hexlify(bytearray(msg_enc.SerializeToString())))

msg_dec = protocol_pb2.uart_frame()
rc_dec = msg_dec.ParseFromString(msg_enc.SerializeToString())
print('\nmsg_dec: ', msg_dec)
print('\nmock_decoded: ', rc_dec)

print(binascii.hexlify(bytearray(msg_dec.SerializeToString())))
print('\nmsg_dec.SerializeToString(): ', len(msg_dec.SerializeToString()), msg_dec.SerializeToString())


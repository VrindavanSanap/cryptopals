#!/usr/bin/python3
import base64

hex_string = "49276d206b696c6c696e6720796f757220627261696e20\
          6c696b65206120706f69736f6e6f7573206d757368726f6f6d"
expted_base64string = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIG\
                        EgcG9pc29ub3VzIG11c2hyb29t"

byte_form = bytes.fromhex(hex_string)
base64_form = base64.b64encode(byte_form)

for i in (byte_form):
  print(i)
print(base64_form)


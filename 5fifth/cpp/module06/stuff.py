import sys
 
def check_endianess():
    i = 1
    c = bytearray(i.to_bytes(4, sys.byteorder))
 
    if c[0]:
        print("Little endian")
    else:
        print("Big endian")
 
# Driver code
check_endianess()
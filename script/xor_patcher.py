#!/usr/bin/python
import sys
import subprocess

def patch():
    target = sys.argv[1]
    symbol = sys.argv[2]
    #offset = int(sys.argv[2], 16)
    #length = int(sys.argv[3], 16)
    key = sys.argv[3].decode('hex')

    cmd = 'objdump -t %s | grep %s' % (target, symbol)
    ret = subprocess.check_output(cmd, shell=True)
    print ret
    offset = int(ret.split()[0], 16)
    length = int(ret.split()[4], 16)
    
    print "Symbol: %s" % ret.split()[5]
    print "Offset: 0x%x" % offset
    print "Length: 0x%x" % length

    data = open(target, 'rb').read()
    
    patched_data = ''
    
    patched_data += data[:offset]

    for i in xrange(length):
        patched_data += chr( ord( data[offset+i] ) ^ ord( key[i % len(key)] ) )

    patched_data += data[offset+length:]

    open(target, 'wb').write(patched_data)

if __name__ == "__main__":
    
    if len(sys.argv) != 4:
        print 'Usage : %s [ target ] [ symbol ] [ hex-encoded key ]' % sys.argv[0]

    else:
        patch()

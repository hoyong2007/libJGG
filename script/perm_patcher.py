import sys
import subprocess

def patch():
	target = sys.argv[1]
	symbol = sys.argv[2]
	key = [2, 5, 3, 6, 1, 0, 4]

	# objdump를 이용해 target에서 symbol에 해당하는 함수의 offset과 length를 가져온다.
	cmd = 'objdump -t %s | grep %s' % (target, symbol)
	ret = subprocess.check_output(cmd, shell=True)
	offset = int(ret.split()[0], 16)
	length = int(ret.split()[4], 16)
    
	print "Symbol: %s" % ret.split()[5]
	print "Offset: 0x%x" % offset
	print "Length: 0x%x" % length

	# 앞서 찾은 영역에 대해 permutation encryption을 수행한다.
	data = open(target, 'rb').read()

	patched_data = ''
	
	patched_data += data[:offset]

	to_perm = length / len(key)
    
	for i in xrange(to_perm):
		for j in xrange(len(key)):
			patched_data += data[offset + i*7 + key[j]]

	patched_data += data[offset+(to_perm*7):]

	open(target, 'wb').write(patched_data)

if __name__ == "__main__":
    
	if len(sys.argv) != 3:
		print 'Usage : %s [ target ] [ symbol ]' % sys.argv[0]

	else:
		patch()

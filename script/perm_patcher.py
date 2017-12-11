#-*- coding: utf-8 -*-
#!/usr/bin/python
import sys
import subprocess

def patch(symbol, offset, length):
	key = [2, 5, 3, 6, 1, 0, 4]

	print "Symbol: %s" % symbol
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
		target = sys.argv[1]
		symbol = sys.argv[2]
	
		# objdump를 이용해 target에서 symbol에 해당하는 함수의 offset과 length를 가져온다.
		cmd = 'objdump -t %s | grep %s' % (target, symbol)
		ret = subprocess.check_output(cmd, shell=True).split('\n')
		for r in ret:
			r = r.split()
			if r[3] == ".text":
				symbol = r[5]
				offset = int(r[0], 16)
				length = int(r[4], 16)
				patch(symbol, offset, length)
				break

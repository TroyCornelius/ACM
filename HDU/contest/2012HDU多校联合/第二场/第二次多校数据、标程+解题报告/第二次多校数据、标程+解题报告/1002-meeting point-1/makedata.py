import random

def main():
	fpo = open('meeting point-2-small.in', 'w')
	T = 4
	fpo.write(str(T) + '\n')
	#fpo.write('\n')
	XY_RANGE = 5
	while(T > 0):
		T -= 1
		if(T == 0):n = 10
		else: n = random.randint(4, 8)
		fpo.write(str(n) + '\n')
		#fpo.write('\n')
		while(n > 0):
			n -= 1
			x = random.randint(-XY_RANGE, XY_RANGE)
			y = random.randint(-XY_RANGE, XY_RANGE)
			fpo.write(str(x) + ' ' + str(y) + '\n')
			#fpo.write(' ')
		#fpo.write('\n')
	
if __name__ == '__main__': main()
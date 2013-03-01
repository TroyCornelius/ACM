import random

def main():
	fpo = open('matrix.in', 'w')
	T = 10
	fpo.write(str(T) + '\n')
	while(T > 0):
		T -= 1
		if(T == 0):n = 100000
		else: n = random.randint(100, 10000)
		k = random.randint(2, n)
		fpo.write(str(n) + ' ' + str(k) + '\n')
		
		for i in range(1,n):
			a = random.randint(0, i-1)
			b = i
			c = random.randint(0, 1000000)
			line = "%d %d %d\n" % (a,b,c)
			fpo.write(line)
		
		ls = range(n)
		random.shuffle(ls)
		ls = ls[0:k]
		line = '\n'.join(str(x) for x in ls)
		fpo.write(line + '\n')
	
if __name__ == '__main__': main()
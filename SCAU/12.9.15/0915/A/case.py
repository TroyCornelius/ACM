import sys
import random
sys.stdout = open("A.in", "w")

for i in range(1, 1001): print i
for i in range(1, 1001): print 10 ** 15 - i
for i in range(1, 8001):
	print random.randint(10 ** 3, 10 ** 13)
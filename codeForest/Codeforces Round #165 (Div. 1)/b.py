from bisect import *
n=int(raw_input().split()[0])
f=[10**10]*5020
#print f
for i in range(n):
    x=int(raw_input().split()[0])
    #print x, bisect_right(f, x)
    f[bisect_right(f,x)]=x
    print f[:10]
print bisect_left(f, 10**10)
print n-bisect_left(f,10**10)


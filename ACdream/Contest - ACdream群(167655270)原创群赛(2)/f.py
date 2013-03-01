T = map(int, raw_input().split())
ans = 0
mod = 10000000007L
while (T > 0):
    n, k = map(long, raw_input().split())
    for j in xrange(0, n):
        val = map(long, raw_input().split())
    print val
    for j in range(0, n):
        print val[j]
        ans = (ans + pow(val[j], k, mod) + mod) % mod
    print "%d\n" %(ans % mod)
    T -= 1
 
    


n, k = map(int, raw_input().split())
if k * 3 > n:
    print -1
else:
    a = [0]*n
    p = 0
    q = n - k
    for i in xrange(1, k+1, 1):
        a[p] = i
        a[p+1] = i
        a[q] = i
        p += 2
        q += 1
    for i in xrange(p, n-k, 1):
        if (a[i] == 0):
            a[i] = 1
    print a
    print a[0],
    for _ in xrange(1, n, 1):
        print a[_],
    

n, k = map(int, raw_input().split())
if k * 3 > n:
    print -1
else:
    a = [0]*n
    now = 1
    p = 0
    flag = 0
    while now <= k and p < n:
        if flag == 0:
            a[p] = now
            a[p+1] = now
            a[p+3] = now
            flag = 1
            p = p + 2
        else:
            a[p] = now
            a[p+2] = now
            a[p+3] = now
            flag = 0
            p = p + 4
        now += 1
    for i in xrange(p, n, 1):
        if (a[i] == 0):
            a[i] = 1
    print a[0],
    for _ in xrange(1, n, 1):
        print a[_],
            
    

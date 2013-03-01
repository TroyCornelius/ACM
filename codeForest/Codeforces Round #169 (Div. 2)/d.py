def calc_h(x):
    ret = 0
    while x > 0:
        x >>= 1
        ret += 1
    return ret

l, r = map(int, raw_input().split())
h1 = calc_h(l)
h2 = calc_h(r)
if (h2 > h1):
    print 2**h2 - 1
else:
    for i in xrange(h2-1, -1, -1):
        if (r & (2**i)) > 0 and (l & (2**i))==0:
            print 2**(i+1)-1
            exit()
    print 0
            
        


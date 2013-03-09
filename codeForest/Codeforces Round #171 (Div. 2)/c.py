n, m = map(int, raw_input().split())
a = map(int, raw_input().split())

mark = [0] * n 
vis = [0] * n
tot = 0
flag = False
for i in xrange(1, n):
    #print a[i]
    if a[i] > a[i-1] and flag == True:
        tot += 1
        mark[i] = tot
        vis[i-1] = 1
        flag = False
    elif a[i] >= a[i-1] and flag == False:
        mark[i] = tot
    elif a[i] < a[i-1] and flag == False:
        flag = True
        mark[i] = tot
    else: mark[i] = tot
#print vis
#print mark
for _ in xrange(m):
    l, r = map(int, raw_input().split())
    if (mark[l-1] == mark[r-1]):print "Yes"
    elif vis[l-1] == 1 and mark[l] == mark[r-1]:
        print "Yes"
    else: print "No"
        
    

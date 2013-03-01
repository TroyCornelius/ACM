n, k = map(int, raw_input().split())
a = []
for _ in xrange(n):
    f, t = map(int, raw_input().split())
    a.append([f, t])

ans = -2**60
for f, t in a:
    if t <= k:
        ans = max(ans, f)
    else:
        ans = max(ans, f - t + k)
print ans
    
    

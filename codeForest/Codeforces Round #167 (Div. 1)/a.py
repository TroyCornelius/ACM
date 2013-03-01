n = int(raw_input())
a = map(int, raw_input().split())
mx = 0
for _ in xrange(int(raw_input())):
    w, h = map(int, raw_input().split())
    mx = max(mx, a[w-1])
    print mx
    mx += h

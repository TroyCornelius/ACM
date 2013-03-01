n, t = map(int, raw_input().split())
s = list(raw_input())

while (t > 0):
    t -= 1
    i = 0
    while (i < n-1):
        if (s[i] == 'B' and s[i+1] == 'G'):
            s[i] = 'G'
            s[i+1] = 'B'
            i += 2
        else:
            i += 1
print ''.join(s)

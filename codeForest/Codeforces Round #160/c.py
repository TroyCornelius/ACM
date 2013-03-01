import math
n, t = map(int, raw_input().split())

for i in range(55):
    comb = [[0]*55 for _ in range(55)]
for i in range(55):
    for j in range(i+1):
        if (i == 0 or j == 0): comb[i][j] = 1
        else:
            comb[i][j] = comb[i-1][j] + comb[i-1][j-1]

def gao(m, k):
    ret = 0
    while m > 0:
        p = int(math.log(m, 2))
        ret += comb[p][k]
        k -= 1
        m -= 2**p
        if m == 0:
            if k == 0:
                ret += 1
            break
        if k < 0:
            break
    return ret

tmp = 0
num = t
while (num > 0):
    if (num % 2 == 1):
        tmp += 1
    num /= 2
    if (tmp > 1):
        break
if (tmp > 1):
    print 0
else:
    k = int(math.log(t, 2))
    ans = gao(n+1, k+1)
    if t == 1:
        ans -= 1
    print ans

n, m = map(int, raw_input().split())

x = 0
y = 1
ans = []
while x <= n and y <= m:
    ans.append([x, y])
    x += 1
    y += 1

import math
eps = 1e-8
def check(nx, ny):
    for j in range(len(ans)):
        a = abs(nx - ans[j][0])
        b = abs(ny - ans[j][1])
        if (math.sqrt(a**2+b**2)-(int)(math.sqrt(a**2+b**2)) < eps):
            return 0
    return 1
flag = 0
if (x <= n and y > m):
    for tx in range(x, n+1, 1):
        if (check(tx, 0)):
            ans.append([tx, 0])
            flag = 1
            break
if (flag == 0):
    for i in range(len(ans)):
        a = abs(x - ans[i][0])
        b = abs(y - ans[i][1])
        if (math.sqrt(a**2+b**2)-(int)(math.sqrt(a**2+b**2)) < eps):
            if (i == 0):swap(ans[i][1], ans[i+1][1])
            else:swap(ans[i][1], ans[i-1][1])
    ans.append([x, 0])
print len(ans)
for i in range(len(ans)):
    print ans[i][0], ans[i][1]

n = int(input())
p = []
for _ in range(n):
    tmp = map(int, raw_input().split())
    p.append(tmp)

ans = 0
for i in range(n):
    for j in range(i):
        if p[i][0] == p[j][1]: ans += 1
        if (p[i][1] == p[j][0]): ans += 1

print ans
    

n = int(raw_input())
ans = n
for i in range(1, n+1, 1):
    ans += (n- i) * i
print ans

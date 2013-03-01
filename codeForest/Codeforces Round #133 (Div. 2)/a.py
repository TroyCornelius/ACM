a,b,c=map(int, raw_input().split())
d = a + b - 1
h = min(a,b)+c-1
ans = 0
for i in range (0, d/2):
    ans += c
    if c < h:
        c += 1
ans *= 2;
if d % 2 != 0 :
    ans += c
print ans

n = int(raw_input())
import math
def calc(x):
    ret = 0
    tmp = 1
    while True:
        tmp *= 4
        ret += 1
        if (tmp >= x):
            return ret
ans = 0
for _ in xrange(n):
    k, a = map(int, raw_input().split())
    ans = max(ans, k + calc(a))
print ans
    

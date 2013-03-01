for i in range(5):
    num = map(int, raw_input().split())
    for j in range(5):
        if (num[j] == 1):
            x = i
            y = j
ans = abs(2-x)+abs(2-y)
print ans

n, m = map(int, raw_input().split())
mi = min(n, m) + 1
print mi

for x in range(mi):
    print x, mi-x-1

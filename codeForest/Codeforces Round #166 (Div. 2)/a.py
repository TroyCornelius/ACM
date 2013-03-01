n = int(raw_input())
def check(x):
    b = [0]*11
    while x > 0:
        if a[x % 10] == 1:return False
        else:a[x%10]=1
        x /= 10;
    return True
while True:
    if check(n) == True:
        print n
        exit()
    n += 1

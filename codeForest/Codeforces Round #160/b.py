n = int(raw_input())
a = map(int, raw_input().split())
p = int(raw_input())

if sum(a) <= p :
    print n
else:
    for i in range(55):
        comb = [[0.0]*55 for _ in range(55)]
    for i in range(55):
        for j in range(i+1):
            if (i == 0 or j == 0): comb[i][j] = 1.0
            else:
                comb[i][j] = comb[i-1][j] + comb[i-1][j-1]
    
    dp = [[[0]*(p+5) for i in range(55)] for _ in range(55)]
    dp[0][0][0] = 1
    
    for i in range(1, n+1, 1):
        for j in range(0, n+1, 1):
            for k in range(0, p+1, 1):
                dp[i][j][k] += dp[i-1][j][k];
                if (j > 0 and k - a[i-1] >= 0):
                    dp[i][j][k] += dp[i-1][j-1][k-a[i-1]]
    
    ans = 0.0
    for j in range(1, n+1, 1):
        s = 0.0
        for k in range(p+1):
            s += dp[n][j][k]
        s /= comb[n][j]
        ans += s
    print "%.9f" % (ans)


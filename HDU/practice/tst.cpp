int n;
int dp[11][N][N][N];
 
void initDP() {
 
    memset(dp, 0, sizeof(dp));
    //dp[l][i][j][k]表示前l位和为i模j的结果为k的数的个数
    for(int i = 0; i <= 9; i++) {
        for(int j = 1; j < N; j++) {
            dp[1][i][j][i % j]++;
        }
    }
 
    for(int l = 1; l <= 8; l++) {
        for(int i = 0; i < N; i++) {
            for(int j = 1; j < N; j++) {
                for(int k = 0; k < N; k++) {
                    for(int x = 0; x <= 9 && i + x < N; x++)
                        dp[l + 1][i + x][j][(k * 10 + x) % j] += dp[l][i][j][k];
                }
            }
        }
    }
}
 
int cx[N], ten[11];
int countBits(int x) {
    int bits = 0;
    memset(cx, 0, sizeof(cx));
 
    while(x) {
        cx[bits++] = x % 10;
        x /= 10;
    }
    return bits;
}
 
int call(int X) {
    if(X == 0)
        return 0;
    int bits = countBits(X);
    reverse(cx, cx + bits);
    int ans = 0, frontv , sum, tsum = accumulate(cx, cx + bits, 0);
 
    for(int y = 1; y <= 9 * bits; y++) {
        if(y > X)
            break;
        sum = y;
        frontv = 0;
        for(int i = 0; i + 1 < bits; i++) {
            for(int j = 0; j < cx[i] && j <= sum; j++) {
                for(int mod = 0; mod < y; mod++) {
                    //dp[l][i][j][k]表示前l位和为i模j的结果为k的数的个数
                    if( (frontv + j * ten[bits - i - 1] + mod) % y == 0 ) {
                        ans += dp[bits - i - 1][sum - j][y][mod];
                    }
                }
            }
            sum -= cx[i];
            frontv += cx[i] * ten[bits - i - 1];
        }
    }
 
    while(true) {
        if(X % tsum == 0)
            ans++;
        if(X % 10 == 0)
            break;
        X--;
        tsum--;
    }
    return ans;
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
 
    ten[0] = 1;
    for(int i = 1; i < 10; i++)
        ten[i] = ten[i - 1] * 10;
    initDP();
    int cas, pcas = 1, L, R;
    scanf("%d", &cas);
    while(cas--) {
        scanf("%d%d", &L, &R);
        printf("Case %d: %d\n", pcas++, call(R) - call(L - 1));
    }
    return 0;
}


#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int CompareString(char *s1, char *s2) {
	int dp[15][15];
	memset(dp, 0, sizeof(dp));

	int m = strlen(s1),
	    n = strlen(s2),
	    i = 0, j = 0;

	for (i = 0; i<= m; ++i) {
		dp[i][0] = i;
	}
	for (j = 0; j <= n; ++j) {
		dp[0][j] = j;
	}
	int cost = 0;
	for (i = 1;i <= m; ++i) {
		for (j=1;j<=n;++j) {
			if (s1[i-1] == s2[j-1]) {
				cost = 0;
			} else {
				cost = 1;
			}
			dp[i][j]= min(min(dp[i-1][j-1] + cost, dp[i-1][j] + 1), dp[i][j-1] + 1);
		}
	}
	return dp[m][n];
}

char dic[1510][20];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output_.txt", "w", stdout);
    int n, m;
    char line[32];
    int cs;
    scanf("%d", &cs);
    for (int c = 1; c <= cs; c++)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%s", dic[i]);
        }
        printf ("Case #%d:\n", c);
        int dis;
        for (int i = 0; i < m; i++) {
            scanf("%s%d", line, &dis);
            int ans = 0;
            for (int j = 0;  j < n; j++) {
                if (CompareString(dic[j], line) <= dis) {
                    ans++;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

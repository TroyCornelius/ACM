#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cctype>
#include <queue>
#include <functional>
using namespace std;

typedef long long LLD;

LLD DX[507][507],DY[507][507],D[507][507];
LLD CX[507][507],CY[507][507],C[507][507];
int g[507][507];

int main() {
	int var = 0;
	int t;
	int n,m,d;

	scanf("%d", &t);
	while (t -- ) {
		scanf("%d%d%d", &n, &m, &d);
		for (int i = 0 ; i <= n ; i ++ ) {
			for (int j = 0 ; j <= m ; j ++ ) {
				DX[i][j] = DY[i][j] = D[i][j] = 0;
			}
		}
		char ch;
		for (int i = 1 ; i <= n ; i ++ ) {
			for (int j = 1 ; j <= m ; j ++ ) {
				while (!isdigit(cin.peek())) {
					cin.get();
				}
				ch = cin.get();
				g[i][j] = ch - '0';
				DX[i][j] = (LLD)(d + g[i][j]) * i;
				DY[i][j] = (LLD)(d + g[i][j]) * j;
				CX[i][j] = DX[i][j];
				CY[i][j] = DY[i][j]; 
				D[i][j] = (d + g[i][j]);
				C[i][j] = D[i][j];
			}
		}
		for (int i = 1 ; i <= n ; i ++ ) {
			for (int j = 1 ; j <= m ; j ++ ) {
				DX[i][j] += DX[i][j-1];
				DY[i][j] += DY[i][j-1];
				D[i][j] += D[i][j-1];
			}
		}
		for (int j = 1 ; j <= m ; j ++ ) {
			for (int i = 1 ; i <= n ; i ++ ) {
				DX[i][j] += DX[i-1][j];
				DY[i][j] += DY[i-1][j];
				D[i][j] += D[i-1][j];
			}
		}
		int ans = 0;
		for (int i = 1 ; i <= n ; i ++ ) {
			for (int j = 1 ; j <= m ; j ++ ) {
				//printf("%lld ", D[i][j]);
				//左上角
				int len = min(n-i, m-j);//真实长度len+1
				//右下角(i+len,j+len)
				while (len+1 >= 3) {
					LLD ddx = DX[i+len][j+len] + DX[i-1][j-1] - DX[i-1][j+len] - DX[i+len][j-1] 
					- CX[i][j] - CX[i][j+len] - CX[i+len][j] - CX[i+len][j+len];
					LLD ddy = DY[i+len][j+len] + DY[i-1][j-1] - DY[i-1][j+len] - DY[i+len][j-1] 
					- CY[i][j] - CY[i][j+len] - CY[i+len][j] - CY[i+len][j+len];
					LLD dd = D[i+len][j+len] + D[i-1][j-1] - D[i-1][j+len] - D[i+len][j-1] 
					- C[i][j] - C[i][j+len] - C[i+len][j] - C[i+len][j+len];
					if (len & 1) {
						ddx *= 2;
						ddy *= 2;
						int x = (i + i + len);
						int y = (j + j + len);
						if (ddx - dd * x == 0LL && ddy - dd *y == 0LL) {
							ans = max(ans, len+1);
						}
					} else {
						int x = (i + i + len) / 2;
						int y = (j + j + len) / 2;
						if (ddx - dd * x == 0LL && ddy - dd *y == 0LL) {
							ans = max(ans, len+1);
						}
					}
					len --;
				}
			}
			//puts("");
		}
		printf("Case #%d: ", ++var);
		if (ans >= 3) printf("%d\n", ans);
		else puts("IMPOSSIBLE");
	}
	return 0;
}
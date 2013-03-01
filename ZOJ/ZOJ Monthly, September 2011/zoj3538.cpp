#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;

#define PB push_back
#define MP make_pair

int N = 4;
const int MOD = 1000000007;

struct mat{
	long long data[4][4];
}b, c;

void mul(mat& c, const mat& a, const mat& b){
	int i, j, k;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			for(c.data[i][j] = k = 0; k < N; k++){
				c.data[i][j] = (c.data[i][j] + a.data[i][k] * b.data[k][j]) % MOD;
			}
		}
	}
}

void gao(mat& c, const mat& a, int l){
	int i, j, k;
	mat e, f;
	if(l == 1){
		c = a;
		return;
	}
	k = l % 2;
	int u;
	u = l / 2;
	if(k){
		gao(e, a, u);
		mul(f, e, e);
		mul(c, f, a);
	}else{
		gao(f, a, u);
		mul(c, f, f);
	}
	return;
}

pair<int, int> a[12];

int main(){
	int i, j, k, m, n;
	char s[10];
	while(scanf("%d%d", &n, &m) != EOF){
		assert(1 <= n && n <= 10000000);
		assert(0 <= m && m <= 10);
		long long ans = 1, t = 0;
		for(i = 0; i < m; i++){
			scanf("%d%s", &a[i].first, s);
			assert(1 <= a[i].first && a[i].first <= n);
			assert(s[1] == 0 && 'A' <= s[0] && s[i] <= 'D');
			for(j = 0; j < i; j++) assert(a[i].first != a[j].first);
			a[i].second = s[0] - 'A';
		}
		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++)
				b.data[i][j] = (i == j) ? 0 : 1;
		if(m == 0){
			if(n > 1){
				gao(c, b, n - 1);
				t = 0;
				for(i = 0; i < 4; i++)
					for(j = 0; j < 4; j++)
						t = (t + c.data[i][j]) % MOD;
				printf("%lld\n", t);
			}else{
				puts("4");
			}
			continue;
		}
		sort(a, a + m);
		if(a[0].first > 1){
			gao(c, b, a[0].first - 1);
			t = 0;
			for(j = 0; j < 4; j++){
				t = (t + c.data[j][a[0].second]) % MOD;
			}
			ans = (ans * t) % MOD;
		}
		for(i = 1; i < m; i++){
			gao(c, b, a[i].first - a[i - 1].first);
			ans = (ans * c.data[a[i].second][a[i - 1].second]) % MOD;
		}
		if(a[m - 1].first < n){
			gao(c, b, n - a[m - 1].first);
			t = 0;
			for(j = 0; j < 4; j++)
				t = (t + c.data[a[m - 1].second][j]) % MOD;
			ans = (ans * t) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

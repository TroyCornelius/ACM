//Sample solution for the Food Review problem in NCPC 2012 by Per Austrin
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
typedef vector<int> vi;

int R, N;
int deg[30];
int cost[30][30];

int comp[30], odd[30];
vi radj[30];

typedef pair<int, int> pii;

int best[21][1<<20];

int Best(int S, int T) {
	if (!(S | T)) return 0;
	int s = 0;
	for (int i = 1; i <= N; ++i) 
		if (deg[i] && (comp[i] & ~S) == 0)
			s = i;
	int &r = best[s][(S|T)>>1];
	if (r == -1) {
		r = 1<<28;
		for (int i = 1; !s && i <= N; ++i)
			if (S & (1<<i))
				s = i;
		if (s) {
			for (int j = 1; j <= N; ++j)
				if (((S|T) & (1<<j)) && j != s) {
					int C = comp[j];
					if (S & (1<<j))
						r = min(r, cost[s][j] + Best(S ^ (1<<s) ^ (1<<j), T));
					else
						r = min(r, cost[s][j] + Best((S+odd[j]) ^ (1<<s) ^ (1<<j), T & ~C));
				}
		} else {
			for (int i = 1; i <= N; ++i)
				if ((i == 1 || deg[i]) && (~T & (1<<i)))
					for (int j = 1; j <= N; ++j)
						if (T & (1<<j)) {
							int C = comp[j];
							r = min(r, cost[i][j] + 
									Best((1<<i) + (odd[j] ^ (1<<j)), T & ~C));
						}
		}
		//		printf("best %d %d = %d\n", S, T, r);
	}
	return r;
}

int dfs(int v, int &seen) {
	seen |= (1<<v);
	int res = 1<<v;
	for (vi::iterator it = radj[v].begin(); it != radj[v].end(); ++it)
		if (!(seen & (1<<*it))) res |= dfs(*it, seen);
	return res;
}

int main(void) {
	scanf("%d%d", &N, &R);
	memset(cost, 0x1f, sizeof(cost));
	int base = 0;
	for (int i = 0; i < R; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		cost[a][b] = min(cost[a][b], c);
		cost[b][a] = min(cost[b][a], c);
		radj[a].push_back(b);
		radj[b].push_back(a);
		base += c;
		++deg[a];
		++deg[b];
	}
	int F;
	scanf("%d", &F);
	for (int i = 0; i < F; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c); 
		cost[a][b] = min(cost[a][b], c);
		cost[b][a] = min(cost[b][a], c);
	}
	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
	int seen = 0, all = 0, allodd = 0, c1 = 0;
	for (int k = 1; k <= N; ++k)
		if (deg[k] && !(seen & (1<<k))) {
			int C = dfs(k, seen);
			c1 = C;
			for (int i = 1; i <= N; ++i)
				if (C & (1<<i)) {
					comp[i] = C;
					all |= (1<<i);
					if (deg[i] % 2) allodd |= (1<<i);
				}
		}
	for (int i = 1; i <= N; ++i) odd[i] = comp[i] & allodd;
	memset(best, -1, sizeof(best));
	int ans = 1<<28;
	if (deg[1]) ans = Best(c1 & allodd, all & ~c1);
	else {
		for (int i = 1; i <= N; ++i)
			if (deg[i]) {
				int x = Best(odd[i] ^ (1<<i) ^ (1<<1), all & ~comp[i]);
				//				printf("conn %d to %d => %d + %d\n", 1, i, cost[1][i], x);
				ans = min(ans, 
						  cost[1][i] + Best(odd[i] ^ (1<<i) ^ (1<<1), all & ~comp[i]));
			}
	}
	printf("%d\n", base + ans);
	return 0;
}

//Sample solution for the Juice problem in NCPC 2012 by Per Austrin
#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;

struct edge {
	int dest, cap;
	vi best;
	edge(int d, int c): dest(d), cap(c) {
		best = vi(110, -1);
	}
};

int r[1010];
vector<edge> adj[1010];

int Best(int v, int e, int c) {
	if (e >= adj[v].size()) return c >= r[v];
	if (adj[v][e].best[c] != -1) return adj[v][e].best[c];
	int &r = adj[v][e].best[c];
	if (r == -1) {
		r = 0;
		for (int cc = 0; cc <= c && cc <= adj[v][e].cap; ++cc)
			r = max(r, Best(adj[v][e].dest, 0, cc) + Best(v, e+1, c-cc));
		//		printf("best %d %d %d = %d\n", v, e, c, r);
	}
	return r;
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int p, c;
		scanf("%d%d%d", &p, r+i, &c);
		adj[p].push_back(edge(i, c));
	}
	int r = 0;
	for (int i = 0; i < adj[0].size(); ++i) {
		r += Best(adj[0][i].dest, 0, adj[0][i].cap);
		//		printf("%d: %d\n", i, r);
	}
	printf("%d\n", r);
	return 0;
}

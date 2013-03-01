//Sample solution for the Horror List problem in NCPC 2012 by Per Austrin
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main(void) {
	int N, H, L;
	int bad[20000];
	vi sim[20000];
	queue<int> Q;

	scanf("%d%d%d", &N, &H, &L);
	memset(bad, 0x1f, sizeof(bad));
	for (int i = 0; i < H; ++i) {
		int x; scanf("%d", &x);
		bad[x] = 0;
		Q.push(x);
	}
	for (int i = 0; i < L; ++i) {
		int a, b;
		scanf("%d%d", &a, &b); 
		sim[a].push_back(b);
		sim[b].push_back(a);
	}
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (vi::iterator it = sim[u].begin(); it != sim[u].end(); ++it)
			if (bad[*it] > 2*N) {
				Q.push(*it);
				bad[*it] = bad[u] + 1;
			}
	}
	int best = 0;
	for (int i = 0; i < N; ++i) best = max(best, bad[i]);
	for (int i = 0; i < N; ++i) 
		if (bad[i] == best) {
			printf("%d\n", i);
			break;
		}
	return 0;
}

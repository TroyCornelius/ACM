//Sample solution for the Kindergarten problem in NCPC 2012 by Per Austrin
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef vector<int> vi;

int n;
int group[500], cur[500];
vi adj[500];
vi rest[500];

bool search(int v, int T, int g) {
	group[v] = g;
	//	printf(" %d -> %d\n", v, g);
	for (int i = 0; i < rest[v].size(); ++i) {
		int w = rest[v][i];
		//		printf("   (%d,%d)\n", v, w);
		if (group[w] == g) return false;
		if (group[w] != -1) continue;
		if (g != cur[w]) {
			if (!search(w, T, 3-g-cur[w])) return false;
		}
	}
	return true;
}

bool poss(int T) {
	int ogroup[500];
	memset(group, -1, sizeof(group));
	//	printf("poss %d?\n", T);
	for (int i = 1; i <= n; ++i) rest[i].clear();
	for (int i = 1; i <= n; ++i)
		for (int j = T; j < n-1; ++j) {
			rest[i].push_back(adj[i][j]);
			rest[adj[i][j]].push_back(i);
		}
	for (int i = 1; i <= n; ++i)
		if (group[i] == -1) {
			memcpy(ogroup, group, sizeof(group));
			if (!search(i, T, (cur[i]+1)%3)) {
				memcpy(group, ogroup, sizeof(group));
				if (!search(i, T, (cur[i]+2)%3)) {
					return false;
				}
			}
		}
	return true;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", cur+i);
		for (int j = 0; j < n-1; ++j) {
			int v; scanf("%d", &v);
			adj[i].push_back(v);
		}
	}
	int lo = -1, hi = n-1;
	while (hi-lo > 1) {
		int m = (hi+lo)/2;
		(poss(m) ? hi : lo) = m;
	}
	printf("%d\n", hi);
	return 0;
}

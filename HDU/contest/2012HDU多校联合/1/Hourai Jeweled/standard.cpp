#include <iostream> 
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
const int N = 1000100;

ll ans, num[N], cnt[N], key[N];
vector<pair<int, int> > tree[N];

void dfs(int v, int pa, int pac) {
	ll last_num, last_cnt, now_num, now_cnt;
	int i, last_color;
	num[v] = key[v]; cnt[v] = 1;
	last_num = 0; last_cnt = 0;
	now_num = 0; now_cnt = 0;

	last_color = -1;
	for (i=0; i<tree[v].size(); i++) if (tree[v][i].second != pa) {
		dfs(tree[v][i].second, v, tree[v][i].first);

		if (tree[v][i].first != last_color) {
			last_num = now_num; last_cnt = now_cnt;
		}
		last_color = tree[v][i].first;
		//printf("from %d to %d: %lld %lld\n", v, tree[v][i].second, last_num, last_cnt);
		//printf("%lld %lld %lld\n", last_num * cnt[tree[v][i].second], last_cnt * num[tree[v][i].second], last_cnt * cnt[tree[v][i].second] * key[v]);
		ans += last_num * cnt[tree[v][i].second];
		ans += last_cnt * num[tree[v][i].second];
		ans += last_cnt * cnt[tree[v][i].second] * key[v];
		now_num += num[tree[v][i].second];
		now_cnt += cnt[tree[v][i].second];

		if (pac != tree[v][i].first) {
			cnt[v] += cnt[tree[v][i].second];
			num[v] += num[tree[v][i].second];
			num[v] += cnt[tree[v][i].second] * key[v];
		}
	}
	if (v != 1) {
		ans += cnt[v] * key[pa];
		ans += num[v];
		//printf("$ %d %lld %lld \n", v, cnt[v] * key[pa], num[v]);
	}
	//printf("--%d %lld %lld\n",v, num[v], cnt[v]);
}
int main() {
	int n,i,a,b,c;
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	
	while (~ scanf("%d", &n)) {
		for (i = 1; i<=n; i++) scanf("%lld", &key[i]);
		for (i = 1; i<=n; i++) tree[i].clear();
		for (i = 1; i<n; i++) {
			scanf("%d%d%d", &a, &b, &c);
			tree[a].pb(mp(c, b));
			tree[b].pb(mp(c, a));
		}
		for (i = 1; i<=n; i++) sort(tree[i].begin(), tree[i].end());
		ans = 0;
		dfs(1, 0, -1);
		printf("%lld\n", ans);
	}
}

/*
4
4 2 3 5
1 2 1
1 3 2
1 4 1
6
6 2 3 7 1 4
1 2 1
1 3 2
1 4 3
2 5 1
2 6 2
*/
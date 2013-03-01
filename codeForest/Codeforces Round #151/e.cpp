#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define ll long long
#define sf scanf
#define pf printf
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
map<string, int> id;
vi roots;
vi g[Maxn];
map<pii, int> ans;
int maxdep, tot;
int nameid[Maxn], L[Maxn], R[Maxn], depth[Maxn];
bool vis[Maxn];
vi node[Maxn];

void dfs(int u, int dep) {
    node[dep].pb(u);
    depth[u] = dep;
    maxdep = max(maxdep, dep);
    L[u] = tot++;
    REP(i, g[u].size()) dfs(g[u][i], dep+1);
    R[u] = tot++;
    return;
}
int bsearch(int bound, int dep) {
    int lo = 0, hi = (int)node[dep].size() - 1, ret = node[dep].size();
    while (lo <= hi) {
        int mid = (lo + hi) >>1;
        if (L[node[dep][mid]] > bound) hi = mid-1, ret = mid;
        else lo = mid+1;
    }
    return ret;
}
map<pair<int, pii>, int> memory;
int query(int v, int dep) {
    if (dep > maxdep) return 0;
    int lo = bsearch(L[v], dep);
    int hi = bsearch(R[v], dep);
    if (lo >= hi) return 0;
    
    pair<int, pii> tmp = mp(dep, mp(lo, hi));
    if (memory.find(tmp) != memory.end()) return memory[tmp];
    int ret = 0;
    FOR(i, lo, hi) {
        if (!vis[nameid[node[dep][i]]]) {
            vis[nameid[node[dep][i]]] = true;
            ret++;
        }
    }
    FOR(i, lo, hi) {
            vis[nameid[node[dep][i]]] = false;
    }
    memory[tmp] = ret;
    return ret;
}
void solve() {
    maxdep = 0;
    tot = 0;
    memset(vis, false, sizeof(vis));
    REP(i, roots.size()) dfs(roots[i], 0);
    int v, k;
    cin >>m;
    REP(i, m) {
        cin >>v >>k;
        int ans = query(v, depth[v] + k);
        cout <<ans <<endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >>n;
    string tname;
    int u;
    FOR(i, 1, n+1) {
        cin >>tname >>u;
        if (u == 0) roots.pb(i);
        else g[u].pb(i);
        if (id.find(tname) == id.end()) id[tname] = id.size();
        nameid[i] = id[tname];
    }
    solve();
    return 0;
}


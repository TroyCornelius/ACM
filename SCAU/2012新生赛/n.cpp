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
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>

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
#define Maxn 1111
#define Maxm 100010
using namespace std;
const int maxint = -1u>>1;
const ll linf = 1LL<<60;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, k;

struct Edge{
    int v, w, id;
    Edge() {}
    Edge(int _v, int _w, int _id)
    :v(_v), w(_w), id(_id){}
};
vector<Edge> g[Maxn];
map<pii, ll> dist;
set<pii> hash;
int node[Maxnm];
void init() {
    dist.clear();
    hash.clear();
    for (int i = 1; i <= n; i++) g[i].clear();
    REP(i, m) sf("%d", &node[i]);
    int w;
    for (int i = 1; i < m; i++) {
        sf("%d", &w);
        g[node[i-1]].pb(Edge(node[i], w, i));
    }
}
ll spfa() {
    queue<pii> que;
    que.push(mp(1, 0));
    dist[mp(1, 0)] = 0;
    ll ret = linf;
    while (!que.empty()) {
        pii now = que.front();
        que.pop();
        hash.erase(hash.find(now));
        REP(i, g[now.fi].size()) {
            
        }
    }
}
int main() {
    int ca = 0;
    while (~sf("%d%d%d", &n, &m, &k)) {
        init();
        ll ans = spfa();
        cout <<"Case #" <<++ca <<": " <<ans <<endl;
    }
    return 0;
}


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
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u >> 1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

#define maxn 150050
const int inf = 999999999;
//int dp[maxn][310];
int n, k;
int eh[maxn], tot;
struct Edge {
    int v, next;
}et[3*maxn];

void init() {
    tot = 0;
    memset(eh, -1, sizeof(eh));
}

void addedge(int u, int v) {
    Edge e = {v, eh[u]};
    et[tot] = e;
    eh[u] = tot++;
}

int val[maxn];

struct aa {
    int dp[310], sum;
};

/*void getsum(int u)
{
    if (eh[u] == -1) 
    {
        sum[u] = 1;
        return;
    }
    sum[u] = 1;
    for (int i = eh[u]; i != -1; i = et[i].next)
    {
        int v = et[i].v;
        getsum(v);
        sum[u] += sum[v];
    }
    return;
}*/
aa dfs(int u) {
    aa ret;
    ret.dp[0] = 0;
    ret.sum = 1;
    for(int i = 1; i <= k; i++) {
        ret.dp[i] = -inf;
    }
    
    int tot = 1;
    for(int i = eh[u]; i != -1; i = et[i].next) {
        int v = et[i].v;
        aa nxt = dfs(v);
        tot += nxt.sum;
        for(int j = min(tot, k); j >= 1; j--) 
            for(int kk = j; kk >= 0; kk--)
            {
                //if (j + kk > k) break;
                ret.dp[j] = max(ret.dp[j], nxt.dp[kk] + ret.dp[j-kk]);
            }
    }
    ret.dp[1] = max(ret.dp[1], val[u]);
    ret.sum = tot;
    return ret;
}

int getint() {
    char c = getchar();
    int t = 0;
    while(c < '0' || c > '9') {
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        t = t * 10 + c - '0';
        c = getchar();
    }
    return t;
}

int main() {
    freopen("family.in", "r", stdin);
    freopen("my.out", "w", stdout);
    int st = clock();
    while(~sf("%d%d", &n, &k)) {
        init();
        val[0] = 0;
        for(int v = 1; v <= n; v++) {
            int u;
            u = getint();
            val[v] = getint();
            addedge(u, v);
        }
        //getsum(0);
        aa ret = dfs(0);
        if(ret.dp[k] <= 0) printf("impossible\n");
        else printf("%d\n", ret.dp[k]);
    }
    cout <<(clock() - st) / CLOCKS_PER_SEC <<endl;
    return 0;
}


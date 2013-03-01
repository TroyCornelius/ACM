#pragma comment(linker,"/STACK:102400000,102400000")
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
#define Maxn 100110
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

//vi g[Maxn];
int n, k, num[Maxn];
int ans[Maxn];
struct QTnode
{
    pii ti;
    int id;
    bool operator<(const QTnode &bb) const
    {
        return ti.se < bb.ti.se;
    }
}q[Maxn];
pii pti[Maxn];
int tot;
struct Edge
{
    int v,next;
}et[Maxn+Maxn];
int cnt, eh[Maxn], t[Maxn+100];
void init()
{
    cnt = 0;
    memset(eh, -1, sizeof(eh));
}
void addedge(int u, int v)
{
    Edge tmp = {v,eh[u]};
    et[cnt] = tmp;
    eh[u] = cnt++;
}

inline int getint()
{
    char c = getchar();
    int ret = 0;
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9')
   {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
void update(int idx, int val)
{
    for (;idx<=n+5;idx+=idx&-idx) t[idx] += val;
}
int query(int idx)
{
    int ret = 0;
    for (;idx; idx-=idx&-idx) ret += t[idx];
    return ret;
}
int val[Maxn];
void dfs(int u, int fa)
{
    pti[u].fi = pti[u].se = ++tot;
    val[tot] = num[u];
    //cout <<tot <<" "<<val[tot]<<" "<<num[u] <<" "<<u <<endl; 
    for (int i = eh[u]; i != -1; i = et[i].next)
    {
        int v = et[i].v;
        if (v == fa) continue;
        dfs(v, u);
        pti[u].se = pti[v].se;
    }
    return;
}
vi rec[Maxn];
int main() 
{
    int T;
    int b[Maxn];
    int Q, u, v, ca = 0;
    //sf("%d", &T);
    T = getint();
    while (T--)
    {
        //sf("%d%d", &n, &k);
        n = getint(); k = getint();
        init();
        FOR(i, 1, n+1) 
        {
            num[i] = getint();//sf("%d", &num[i]);
            b[i] = num[i];
        }
        
        sort(b+1, b+n+1);
        int nn = unique(b+1, b+n+1) - b; 
        FOR(i, 1, n+1) num[i] = lower_bound(b+1, b+nn, num[i]) - b; 
        //FOR(i, 1, n+1) cout <<num[i] <<"-";
        //cout <<endl;
        
        REP(i, n-1)
        {
            //sf("%d%d", &u, &v);
            u = getint(); v = getint();
            addedge(u, v);
            addedge(v, u);
        }
        FOR(i, 1, n+1) ans[i] = 0;
        tot = 0;
        dfs(1, -1);
        //sf("%d", &q);
        Q = getint();
        pf("Case #%d:\n", ++ca);
        //while (q--)
        REP(i, Q)
        {
            //sf("%d", &u);
            u = getint();
            q[i].ti = pti[u];
            q[i].id = i;
            //pf("%d\n", ans[u]);
        }
        sort(q, q+Q);
        //cout <<nn <<endl;
        //FOR(i, 1, n+1) cout <<val[i] <<" - ";
        //cout <<endl;
        FOR(i, 1, nn)
        {
            rec[i].clear();
            rec[i].pb(0);
        }
        int now = 0;
        //FOR(i, 1, n+1) cout <<val[i] <<" ";
        //cout <<tot <<"! " <<endl;
        memset(t, 0, sizeof(t));
        FOR(i, 1, n+1)
        {
            int vv = val[i];
            rec[vv].pb(i);
            //if (vv >= nn)
            int siz = rec[vv].size() - 1;
            if (rec[vv].size() == 0) cout <<111 <<endl;
            if (siz >= k)
            {
                if (siz > k)
                {
                    update(rec[vv][siz-k-1]+1,-1);
                    update(rec[vv][siz-k]+1, 1);
                }
                update(rec[vv][siz-k]+1, 1);
                update(rec[vv][siz-k+1]+1, -1);
                //cout <<i <<" : " <<vv <<" "<<rec[vv][siz-k] <<" "<<rec[vv][siz-k+1] <<endl;
            }
            while (q[now].ti.se == i)
            {
                ans[q[now].id] = query(q[now].ti.fi);
                //cout <<"Query : " <<q[now].id <<" "<<q[now].ti.fi <<"-"<<q[now].ti.se <<" "<<query(q[now].ti.fi)  <<endl;
                now++;
                
            }
        }
        REP(i, Q) pf("%d\n", ans[i]);
        
        
        if (T > 0) puts("");
    }
    return 0;
}



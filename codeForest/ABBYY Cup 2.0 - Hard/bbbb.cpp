#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vp;
typedef vector<vi> vvi;

const int N = 100010;
const int M = 10010;
const int K = 510;
const int LIT = 2500;
const ll INF = 1LL << 60;

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

int n, m, q;
vi r[N], nr[N];
vp qr[N];
int output[N], col[N];

//------------------------
bool vis[N]; //邻接表和访问标志
set<pii> brige;
int cut[N]; //割顶度,即去掉这点，有多少连通块
int deep[N], ans[N]; //深度和访问的最小主先

void dfs(int idx, int fa, int d)
{
    deep[idx] = ans[idx] = d;
    vis[idx] = 1;
    int s = r[idx].size();
    for(int i = 0; i < s; i++)
    {
        int v = r[idx][i];
        
        if(v == fa) continue;
        if(vis[v])
        {
            ans[idx] = min(ans[idx], deep[v]);
            continue;
        }
        dfs(v, idx, d+1);
        ans[idx] = min(ans[idx], ans[v]);
        if(ans[v] > d)
        {
            int a = min(idx, v), b = max(idx, v);
            brige.insert(mp(a, b));
        }
        if(ans[v] >= d) cut[idx]++;
    }
    if(fa != -1) cut[idx]++;
}

//------------------------
int cc;

void dfs2(int u, int c)
{
    vis[u] = 1; col[u] = c;
    int s = r[u].size();
    for(int i = 0; i < s; i++)
    {
        int v = r[u][i];
        if(vis[v]) continue;
        
        int a = min(u, v), b = max(u, v);
        //printf("%d %d %d\n", a, b, brige.count(mp(a, b)));
        if(brige.count(mp(a, b)))
        {
            cc++;
            nr[c].pb(cc);
            nr[cc].pb(c);
            dfs2(v, cc);
        }
        else dfs2(v, c);
    }
}

void dfs3(int u, int d)
{
    vis[u] = 1; deep[u] = d;
    int s = nr[u].size();
    for(int i = 0; i < s; i++)
    {
        int v = nr[u][i];
        if(vis[v]) continue;
        dfs3(v, d + 1);    
    }
}

//------------------------------------------LCA

int check[N], fa[N];

int sea(int a)
{
     int mid = N - 1;
     while(1)
     {
         if(!fa[a]) return a;
         fa[mid] = fa[a];
         mid = a;
         a = fa[a];
     }
}

void uni(int a,int b)
{
    a = sea(a);
    b = sea(b);
    if(a == b) return ;
    fa[b] = a;
}

void LCA(int u, int fa)
{
    int s = nr[u].size();
    for(int i = 0; i < s; i++)
    {
        int v = nr[u][i];
        if(v == fa) continue;
        LCA(v, u);
        uni(u, v);
    }
    
    check[u] = 1;
    s = qr[u].size();
    for(int i = 0; i < s; i++)
    {
        int v = qr[u][i].fst, p = qr[u][i].snd;
        if(!check[v]) continue;
        int lca = sea(v);
        int res = deep[u] + deep[v] - deep[lca] * 2;
        output[p] = res;
    }
}

//------------------------------------------LCA

void init()
{
    memset(col, 0, sizeof(col));
    memset(vis, 0, sizeof(vis));
    memset(cut, 0, sizeof(cut));
    memset(ans, 0, sizeof(ans));
    memset(deep, 0, sizeof(deep));
    brige.clear();
    
    for(int i = 0; i <= n; i++) 
    {
        r[i].clear(), qr[i].clear();
        nr[i].clear();
    }
    
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        r[a].pb(b);
        r[b].pb(a);
    }
    dfs(1, -1, 0);
    
    cc = 1;
    memset(vis, 0, sizeof(vis));
    dfs2(1, cc);
    
    /*for(int i = 1; i <= n; i++) printf("%d ", col[i]); printf("\n");
    for(int i = 1; i <= n; i++)
    {
        cout<<i<<": ";
        for(int j = 0; j < nr[i].size(); j++) printf("%d ", nr[i][j]);   
        printf("\n");
    }*/
    
    memset(vis, 0, sizeof(vis));
    memset(deep, 0, sizeof(deep));
    dfs3(1, 1);
    
    cin>>q;
    for(int i = 1; i <= q; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        a = col[a], b = col[b];
        qr[a].pb(mp(b, i));
        qr[b].pb(mp(a, i));
    }
    
    memset(fa, 0, sizeof(fa));
    memset(check, 0, sizeof(check));
    LCA(1, -1);
}

void solve()
{
    for(int i = 1; i <= q; i++)
    {
        printf("%d\n", output[i]);
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    
    while(cin>>n>>m)
    {
        init();
        solve();
    }
    //while(1);
}

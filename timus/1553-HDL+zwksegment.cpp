#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstring>
#include <set>
#define Maxn 100100
#define Maxm 400020
#define inf 999999999
#define pb push_back
using namespace std;

int tot, res, dep, total, anc[Maxm*2];
int head[Maxn], next_h[Maxm], node[Maxm], order[Maxm];
int size[Maxn], father[Maxn], pos[Maxn], level[Maxn];
int stk_lv[Maxn], stk_x[Maxn], stk_fa[Maxn], h[Maxn];
bool vis[Maxn], used[Maxn], stk_flag[Maxn];
pair<int, int> p[Maxn];
struct segmenttree
{
    int size, dep, res;
    int start;
    vector<int> tree;
    void clr() {size = 0;}
    segmenttree() {clr();}
    void insert(int x)
    {
        if (!size) start = x;
        used[x] = true;
        p[x].first = total;
        p[x].second = ++size; 
       }
       void build()
       {
            for (dep=0; (1<<dep) < (size<<1); dep++);
            res = (1<<dep-1)-1;
            tree.resize(1<<dep|1);
            for (int i=0; i<=(1<<dep); i++) tree[i] = 0;  
       }
       void modify(int x, int val)
       {
            x+=res;
            tree[x]+=val;
            for (x>>=1; x; x>>=1) tree[x] = max(tree[x<<1], tree[x<<1|1]);
       }
       int query(int l, int r)
       {
           int ret = 0;
           l += res;  r += res;
           if (l > r) swap(l, r);
           if (l == r) return tree[l];
           l == res+1?ret=max(ret, tree[l]):l--;
           r == res+size?ret=max(ret, tree[r]):r++;
           for (;l^r^1;l>>=1,r>>=1)
           {
               if (~l&1) ret = max(ret, tree[l^1]);
               if (r&1) ret = max(ret, tree[r^1]);
           }
           return ret;
       }
}_st;
vector<segmenttree> st;
void addedge(int a, int b)
{
    node[++tot] = b;
    next_h[tot] = head[a];
    head[a] = tot;
}
void dfs(int x, int fa, int lev)
{
    memset(vis, false, sizeof(vis));
    memset(pos, 0, sizeof(pos));
    memcpy(h, head, sizeof(head));
    int top, y;
    tot = 0;  top = 1;
    stk_x[1] = x; stk_fa[1] = fa; stk_lv[1] = lev;     
    while (top)
    {
        x=stk_x[top]; fa=stk_fa[top]; lev=stk_lv[top];
        vis[x] = true;
        order[++tot] = x;
        if (!pos[x])
        {
            size[x] = 1;
            father[x] = fa;
            level[x] = lev;
            pos[x] = tot;
        }
        y = node[h[x]];
        if (h[x] && vis[y] && (y != father[x])) size[x] += size[y];
        for (;h[x]&&vis[node[h[x]]]; h[x] = next_h[h[x]]);
        if (!h[x]) --top;
        else
        {
            y = node[h[x]];
            stk_x[++top] = y; stk_fa[top] = x; stk_lv[top] = lev+1;
        }     
    }
    level[0] = inf;
}
void subdiv(int x, bool flag)
{
    int top, y, w, i, maxs;
    total=-1; top=1;
    memset(vis, false, sizeof(vis));
    memset(used, false, sizeof(used));
    memcpy(h, head, sizeof(head));
    stk_x[1] = x; stk_flag[1] = flag;
    while (top)
    {
        x = stk_x[top]; flag = stk_flag[top];
        vis[x] = true;
        if (!used[x])
        {
            if (flag) {++total; _st.clr();}
            _st.insert(x);
            if ((!next_h[head[x]]) && (node[head[x]] == father[x]))
            {
                st.pb(_st); --top;
                continue;                                  
            }
            for (maxs=0, i=head[x]; i; i=next_h[i])
            {
                y = node[i];
                if (vis[y]) continue;
                if (size[y] > maxs) {maxs = size[y]; w = y;}
            }
            stk_x[++top] = w; stk_flag[top] = false;    
        }
        else
        {
            for (;h[x]&&vis[node[h[x]]]; h[x] = next_h[h[x]]);
            if (!h[x]) --top;
            else 
            {
                stk_x[++top] = node[h[x]]; stk_flag[top] = true;  
            }
        }
    }
}
void init()
{
    int n, a, b, m;
    scanf("%d", &n);
    tot = 0;
    memset(head, 0, sizeof(head));
    memset(anc, 0, sizeof(anc));
    memset(size, 0, sizeof(size));
    for (int i=0; i<n-1; i++)
    {
        scanf("%d%d", &a, &b);
        addedge(a, b);
        addedge(b, a);         
    }
    dfs(1, 0, 1);
    for (dep=0; (1<<dep) < (tot<<1); dep++);
    res = (1<<(dep-1))-1;
    for (int i=1; i<=tot; i++) anc[i+res] = order[i];
    for (--dep; dep; dep--)
        for (int i=(1<<(dep-1)); i<(1<<dep); i++)
            anc[i] = level[anc[i<<1]] < level[anc[i<<1|1]] ? anc[i<<1] : anc[i<<1|1];
    st.clear();
    for (int i=0; i<=n; i++) p[i].first = p[i].second = -1;
    subdiv(1, true);
    for (int i=0; i<=total; i++) st[i].build();          
}
int lca(int l, int r)
{
    l = pos[l] + res;  r = pos[r] + res;
    if (l == r) return anc[l];
    if (l > r) swap(l, r);
    int ret_anc = 0;

    if (l == res+1 && level[anc[l]] < level[ret_anc]) ret_anc = anc[l];
    else l--;
    if (r == res+tot && level[anc[r]] < level[ret_anc]) ret_anc = anc[r];
    else r++;
    for (;r^l^1; r>>=1, l>>=1)
    {
        if ((~l&1) && (level[anc[l^1]] < level[ret_anc])) ret_anc = anc[l^1];
        if ((r&1) && (level[anc[r^1]] < level[ret_anc])) ret_anc = anc[r^1];
    }
    return ret_anc;
}
int find(int x, int fa)
{
    int ret = 0, y;
    for (;x&&(level[x]>=level[fa]);x=father[y])
    {
        y = st[p[x].first].start;
        if (level[y] < level[fa]) ret = max(ret, st[p[x].first].query(p[x].second, p[fa].second));
        else ret = max(ret, st[p[x].first].query(p[x].second, p[y].second));  
    }
    return ret;
}
void solve()
{
    int m, u, v, fa, ans;
    char op;
    scanf("%d%*c", &m);
    for (int i=0; i<m; i++)
    {
        scanf("%c%d%d%*c", &op, &u, &v);
        if (op == 'I') st[p[u].first].modify(p[u].second, v);
        else
        {
            fa = lca(u, v);
            ans = st[p[fa].first].query(p[fa].second, p[fa].second);
            ans = max(ans, max(find(u, fa), find(v, fa)));
            printf("%d\n", ans);
        }         
    }
}
int main(){
    init();
    solve();
    return 0;
}

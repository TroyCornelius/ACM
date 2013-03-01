#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int maxn=100010,maxm=(maxn<<1),INF=0x7FFFFFFF;
int tot,dep,res,total,anc[maxm<<2];
int head[maxn],node[maxm],next_h[maxm],order[maxm];
int pos[maxn],size[maxn],level[maxn],father[maxn];
int h[maxn],stk_x[maxn],stk_fa[maxn],stk_lvl[maxn];
bool vis[maxn],used[maxn],stk_flag[maxn];
pair<int,int> P[maxn];
class segmenttree
{
    private:
    vector<int> tree;
    int res,dep,size;
    public:
    void clear()  {  size=0;  }
    segmenttree()  {  clear();  }
    int start;
    void insert(int x)
    {
        if (!size)  start=x;
        used[x]=true;
        P[x].first=total;  // on which list
        P[x].second=++size;   //the idx of the list
    }
    void build()
    {
        int i;
        for (dep=0;(1<<dep)<(size<<1);++dep);
        res=(1<<dep-1)-1;
        tree.resize(1<<dep|1);
        for (i=0;i<=(1<<dep);++i)  tree[i]=0;
    }
    void modify(int x,int delta)
    {
        x+=res;
        tree[x]+=delta;
        for (x>>=1;x;x>>=1)
            tree[x]=max(tree[x<<1],tree[x<<1|1]);
    }
    int ask(int l,int r)
    {
        int tmp=0;
        l+=res,r+=res;
        if (l > r)  swap(l,r);
        if (l == r)  return tree[l];
        l==res+1?tmp=max(tmp,tree[l]):--l;
        r==res+size?tmp=max(tmp,tree[r]):++r;
        for (;l^r^1;l>>=1,r>>=1)
        {
            if (~l&1)  tmp=max(tmp,tree[l^1]);
            if (r&1)  tmp=max(tmp,tree[r^1]);
        }
        return tmp;
    }
}_st;
vector<segmenttree> st;
void addedge(int a,int b)
{
    node[++tot]=b;
    next_h[tot]=head[a];
    head[a]=tot;
}
void dfs(int x,int fa,int lvl)  //find father & level by dfs
{
    int top,y;
    memset(pos,0,sizeof(pos));
    memset(vis,false,sizeof(vis));
    memcpy(h,head,sizeof(head));
    tot=0,top=1; //tot is the amount of nodes, top is the stack
    stk_x[1]=x,stk_fa[1]=fa,stk_lvl[1]=lvl;
    while (top)
    {
        x=stk_x[top],lvl=stk_lvl[top];
        vis[x]=true;
        order[++tot]=x;
        if (!pos[x])
        {
            size[x]=1;
            pos[x]=tot;
            father[x]=stk_fa[top];
            level[x]=lvl;
        }
        y=node[h[x]];
        if (h[x] && vis[y] && (y != father[x]))  size[x]+=size[y];
        for (;h[x]&&vis[node[h[x]]];h[x]=next_h[h[x]]);
        if (!h[x])  --top;
        else
        {
            y=node[h[x]];
            stk_x[++top]=y,stk_fa[top]=x,stk_lvl[top]=lvl+1;
        }
    }
    level[0]=INF;
}
void subdiv(int x,int flag)
{
    int top,y,i,w,maxs;
    memset(vis,false,sizeof(vis));
    memset(used,false,sizeof(used));
    memcpy(h,head,sizeof(head));
    total=-1,top=1;
    stk_x[1]=x,stk_flag[1]=flag;
    while (top)
    {
        x=stk_x[top],flag=stk_flag[top];
        vis[x]=true;
        if (!used[x])
        {
            if (flag)  ++total,_st.clear();
            _st.insert(x);
            if ((!next_h[head[x]]) && (node[head[x]] == father[x]))
            {
                st.push_back(_st);
                --top;
                continue;
            }
            for (maxs=0,i=head[x];i;i=next_h[i])
            {
                y=node[i];
                if (vis[y])  continue;
                if (size[y] > maxs)  maxs=size[y],w=y;
            }
            stk_x[++top]=w,stk_flag[top]=false;
        }
        else
        {
            for (;h[x]&&vis[node[h[x]]];h[x]=next_h[h[x]]);
            if (!h[x])  --top;
            else  stk_x[++top]=node[h[x]],stk_flag[top]=true;
        }
    }
}
void init()
{
    int i,n,u,v;
    scanf("%d",&n);
    tot=0;
    memset(head,0,sizeof(head));
    memset(size,0,sizeof(size));
    memset(anc,0,sizeof(anc));
    for (i=1;i<n;++i)
    {
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    dfs(1,0,1);
    for (dep=0;(1<<dep)<(tot<<1);++dep);
    res=(1<<dep-1)-1;
    for (i=1;i<=tot;++i)  anc[i+res]=order[i];
    for (--dep;dep;--dep)
        for (i=(1<<dep-1);i<(1<<dep);++i)
            if (level[anc[i<<1]] < level[anc[i<<1|1]])
                anc[i]=anc[i<<1];
            else
                anc[i]=anc[i<<1|1];
    st.clear();
    for (i=0;i<=n;++i)  P[i].first=P[i].second=-1;
    subdiv(1,true);
    for (i=0;i<=total;++i)  st[i].build();  //init for every heavy edge
}
int lca(int l,int r)
{
    int co_anc=0;
    l=pos[l]+res,r=pos[r]+res;
    if (r < l)  swap(l,r);
    if (l == r)  return anc[l];
    if (l == res+1)
    {
        if (level[anc[l]] < level[co_anc])
            co_anc=anc[l];
    }
    else  --l;
    if (r == res+tot)
    {
        if (level[anc[r]] < level[co_anc])
            co_anc=anc[r];
    }
    else  ++r;
    for (;l^r^1;l>>=1,r>>=1)
    {
        if (~l&1)
            if (level[anc[l^1]] < level[co_anc])
                co_anc=anc[l^1];
        if (r&1)
            if (level[anc[r^1]] < level[co_anc])
                co_anc=anc[r^1];
    }
    return co_anc;
}
int count(int x,int fa)
{
    int tmp=0,y;
    for (;x&&(level[x]>=level[fa]);x=father[y])   //skip the list
    {
        y=st[P[x].first].start;
        if (level[y] < level[fa])
            tmp=max(tmp,st[P[x].first].ask(P[x].second,P[fa].second));
        else
            tmp=max(tmp,st[P[x].first].ask(P[x].second,P[y].second));
    }
    return tmp;
}
void solve()
{
    int i,Q,u,v,fa,ans;
    char ch;
    scanf("%d%*c",&Q);
    for (i=1;i<=Q;++i)
    {
        scanf("%c%d%d%*c",&ch,&u,&v);
        if (ch == 'I')  st[P[u].first].modify(P[u].second,v);
        else
        {
            fa=lca(u,v);
            ans=st[P[fa].first].ask(P[fa].second,P[fa].second);
            ans=max(ans,count(u,fa));
            ans=max(ans,count(v,fa));
            printf("%d\n",ans);
        }
    }
}
int main()
{
    init();
    solve();
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
const int MAXM = 2000010;
int a[MAXN],b[MAXN],r[MAXN],mp[MAXN];
struct Tree {
    Tree *l,*r;
    int sz;
} seg[MAXM],*root[MAXM];
int tcnt=0;
Tree *build(int id,int l,int r) {
    Tree *next=seg+(tcnt++);
    next->sz=0;
    if (l==r) return next;
    int mid=(l+r)>>1;
    next->l=build(id*2,l,mid);
    next->r=build(id*2+1,mid+1,r);
    return next;
}
Tree *insert(Tree *p,int L,int R,int id) {
    Tree *next=seg+(tcnt++);
    *next=*p;
    if (L==R) {
        next->sz++;
        return next;
    }
    int mid=(L+R)>>1;
    if (id<=mid) next->l=insert(p->l,L,mid,id);
    else next->r=insert(p->r,mid+1,R,id);
    next->sz=next->l->sz+next->r->sz;
    return next;
}
struct Edge {
    int v,pre;
};
Edge e[2*MAXN];
int hh[MAXN],ecnt;
void addEdge(int u,int v) {
    e[ecnt].v=v;
    e[ecnt].pre=hh[u];
    hh[u]=ecnt++;
}
bool cmp(int x,int y) {
    return b[x]<b[y];
}
int init(int n)
{
    tcnt=0;
    for (int i=0; i<n; i++) {
        scanf("%d",&b[i]);
        r[i]=i;
    }
    sort(r,r+n,cmp);
    int now=-1;
    for (int i=0; i<n; i++) {
        if (i==0||b[r[i-1]]!=b[r[i]]) now++;
        a[r[i]+1]=now;
        mp[now]=b[r[i]];
    }
    memset(hh,-1,sizeof(hh));
    ecnt=0;
    return now;
}
int dep[MAXN],fa[MAXN][18],now;
void dfs(int x,int px) {
    root[x]=insert(root[px],0,now,a[x]);
    dep[x]=dep[px]+1;
    fa[x][0]=px;
    for (int i=1;i<=17;i++)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for (int i=hh[x];i!=-1;i=e[i].pre) {
        int v=e[i].v;
        if (v==px) continue;
        dfs(v,x);
    }
}
int lca(int x,int y) {
    if (dep[x]<dep[y]) swap(x,y);
    int delta=dep[x]-dep[y];
    for (int i=17;i>=0;i--)
        if (delta&(1<<i))
        {
            x=fa[x][i];
            delta-=1<<i;
        }
    if (x==y) return x;
    for (int i=17;i>=0;i--)
        if (fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int query(Tree *x,Tree *y,Tree *z,int id,int L,int R,int k) {
    if (L==R) return L;
    int sz=x->l->sz+y->l->sz-z->l->sz*2;
    int mid=(L+R)>>1;
    if (a[id]<=mid&&a[id]>=L) sz++;
    if (k<=sz) return query(x->l,y->l,z->l,id,L,mid,k);
    else return query(x->r,y->r,z->r,id,mid+1,R,k-sz);
}
int main() {
    int n,m;
    while (scanf("%d%d",&n,&m)==2) {
        now=init(n);
        for (int i=0;i<n-1;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
            addEdge(v,u);
        }
        root[0]=build(1,0,now);
        dep[0]=0;
        dfs(1,0);
        while (m--) {
            int u,v,k;
            scanf("%d%d%d",&u,&v,&k);
            int p=lca(u,v);
            printf("%d\n",mp[query(root[u],root[v],root[p],p,0,now,k)]);
        }
    }
    return 0;
}


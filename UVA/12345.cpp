#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
set<int>bst[2000000];
set<int>::iterator it;
int n,m,ss,ans,ll,rr,rl,lr;
int num[2000000],l[2000000],r[2000000],ls[2000000],rs[2000000],id[2000000],sum[2000000],g[2000000],f[2000000],a[2000000];
int mid[2000000],v[2000000];
void updata(int x) {sum[x]=sum[l[x]]+sum[r[x]]+g[x];}
int left(int x,int y) {r[x]=l[y],l[y]=x,updata(x);return y;}
int right(int x,int y){l[x]=r[y],r[y]=x,updata(x);return y;}
void lconnect(int x) {if (!ll) ll=x;else r[lr]=x;ls[++ls[0]]=lr=x;}
void rconnect(int x) {if (!rr) rr=x;else l[rl]=x;rs[++rs[0]]=rl=x;}
void splay(int &mid,int x) {
    int y;
    ll=rr=ls[0]=rs[0]=lr=rl=0;
    for (;mid && num[mid]!=x;) {
        if (x<num[mid]) {
            if (l[mid] && x<num[l[mid]]) mid=right(mid,l[mid]);
            rconnect(mid);y=l[mid],l[mid]=0,mid=y;
        }
        else {
            if (r[mid] && x>num[r[mid]]) mid=left(mid,r[mid]);
            lconnect(mid);y=r[mid],r[mid]=0,mid=y;
        }
    }
    if (!mid) mid=++ss,num[mid]=x;
    if (r[mid]) rconnect(r[mid]),rs[0]--;
    if (l[mid]) lconnect(l[mid]),ls[0]--;
  for (;ls[0];ls[0]--) updata(ls[ls[0]]);
  for (;rs[0];rs[0]--) updata(rs[rs[0]]);
  l[mid]=ll,r[mid]=rr;
  updata(mid);
}
void change(int x,int y,int w) {
    for (;x<=n;x+=(x & -x)) {
        splay(mid[x],y);
        g[mid[x]]+=w;
        sum[mid[x]]+=w;
    }
}
int ask(int x,int y) {
    int ans=0;
    for (;x;x-=(x & -x)) {
        splay(mid[x],y);
        ans+=sum[l[mid[x]]];
    }
    return ans;
}
void link(int z,int x) {
    change(z,f[z],-1);
    f[z]=x;
    change(z,f[z],1);
}
void make(int x,int y) {
    int z;
    it=bst[a[x]].upper_bound(x);
    if (it!=bst[a[x]].end()) link(*it,f[x]);
    bst[a[x]].erase(x);
    a[x]=y;
    bst[a[x]].insert(x);
    it=bst[a[x]].upper_bound(x);
    if (it!=bst[a[x]].end()) {
        z=*it;
        link(x,f[z]);
        link(z,x);
    }
    else {
        it=bst[a[x]].lower_bound(x);
        if (it!=bst[a[x]].begin()) {
            it--;
            link(x,*it);
        }
        else link(x,0);
    }
}
void init() {
    int i,l,r,x,y;
    char ch;
    scanf("%d%d\n",&n,&m);
    // origin();
    ss=0;
    for (i=1;i<=n;i++) scanf("%d",&a[i]),bst[a[i]].insert(i);
    for (i=1;i<=n;i++) {
        f[i]=v[a[i]];
        v[a[i]]=i;
        change(i,f[i],1);
    }
    scanf("\n");
    for (i=1;i<=m;i++) {
        scanf("%c",&ch);
        if ('Q'==ch) {
            scanf("%d%d\n",&l,&r);l++;
            ans=ask(r,l);
            printf("%d\n",ans-(l-1));
        }
        else {
            scanf("%d%d\n",&x,&y);x++;
            make(x,y);
        }
    }
}
int main() {
    init();
    return 0;
}


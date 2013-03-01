#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define SIZE_N 105
#define SIZE_M 1005
#define ll long long
using namespace std;
typedef struct {
    int v,t;
    int weight;
}SEdge;
SEdge eg[SIZE_M];
int n,m,mod;
int fa[SIZE_N],ka[SIZE_N],vis[SIZE_N];
ll gk[SIZE_N][SIZE_N],tmp[SIZE_N][SIZE_N];
ll ans;
vector<int>gra[SIZE_N];
bool cmp(const SEdge &a, const SEdge &b) {
    return a.weight < b.weight;
}
int findFa(int a) {
    if (fa[a] == a) return a;
    else return fa[a] = findFa(fa[a]);
}
int findKa(int a)
{
    if (ka[a] == a) return a;
    else return ka[a] = findKa(ka[a]);
}
ll det(ll a[][SIZE_N], int n) {//生成树计数{
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            a[i][j]%=mod;
        }
    }
    ll ret=1;
    for(int i=1; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            while(a[j][i]) {
                ll t=a[i][i]/a[j][i];
                for(int k=i; k<n; k++)
                    a[i][k]=(a[i][k]-a[j][k]*t)%mod;
                for(int k=i; k<n; k++)
                    swap(a[i][k],a[j][k]);
                ret=-ret;
            }
        }
        if(a[i][i]==0)return 0;
        ret=ret*a[i][i]%mod;
    }
    return (ret+mod)%mod;
}
int main() {
    int i,pre;
    while(scanf("%d%d%d",&n,&m,&mod), n||m||mod) {
        for(i=0; i<m; i++){
            scanf("%d%d%d",&eg[i].v,&eg[i].t,&eg[i].weight);
        }
        memset(gk, 0, sizeof(gk));
        memset(vis, 0, sizeof(vis));
        for(i = 1;i <= n;i ++) {
            fa[i] = ka[i] = i;
        }
        sort(eg, eg+m, cmp);
        ans = 1;
        pre = eg[0].weight;
        for(i = 0;i <= m;i ++) {
            if(eg[i].weight != pre || i == m) {
                for(int j = 1;j <= n;j ++) {
                    if(vis[j]) {
                        vis[j] = 0;
                        int par = findKa(j);
                        gra[par].push_back(j);
                    }
                }
                for(int j = 1;j <= n;j ++) {
                    int len;
                    if((len = gra[j].size()) > 1) {
                        memset(tmp, 0, sizeof(tmp));
                        for(int k = 0;k < len;k ++) {
                            for(int l = k+1;l < len;l ++) {
                                int la = gra[j][k];
                                int lb = gra[j][l];
                                tmp[k][l] = tmp[l][k] -= gk[la][lb];
                                tmp[k][k] += gk[la][lb];
                                tmp[l][l] += gk[la][lb];
                            }
                        }
                        ll ret = det(tmp, len);
                        ans = (ans*ret) % mod;
                        gra[j].clear();
                    }
                }
                for(int j = 1;j <= n;j ++) {
                    fa[j] = findKa(j);
                }
                if(i == m) {
                    break;
                }
                pre = eg[i].weight;
            }
            int parV = findFa(eg[i].v);
            int parT = findFa(eg[i].t);
            if(parV == parT) continue;
            vis[parV] = vis[parT] = 1;
            ka[findKa(parV)] = ka[findKa(parT)];
            gk[parV][parT] ++;
            gk[parT][parV] ++;
        }
        int num = 0;
        for(i = 1;i <= n;i ++) 
            if(fa[i] == i) num ++;
        ans %= mod;
        if(num > 1) ans = 0;
        printf("%I64d\n",ans);
    }
    return 0;
}

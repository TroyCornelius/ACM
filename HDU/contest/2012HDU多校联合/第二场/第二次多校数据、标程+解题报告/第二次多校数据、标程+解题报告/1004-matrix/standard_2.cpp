#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 100010
int fa[maxn];
int flag[maxn];
int ff[maxn];
struct Edge
{
    int u,v,w;
    bool operator<(const Edge &e)const
    {
        return w > e.w;
    }
    void get()
    {
        scanf("%d%d%d",&u,&v,&w);
    }
}edge[maxn];
int find(int k)
{
    if(fa[k] == k)
    {
        if(flag[k] == 1)
            ff[k] = 1;
        return k;
    }
    else
    {
        fa[k] = find(fa[k]);
        if(ff[fa[k]] == 1)
            ff[k] = 1;
        return fa[k];
    }
}
int T,N,K;
int main()
{
    int i,k,k1,k2;
    __int64 ans;
//    freopen("data.in","r",stdin);
 //   freopen("data2.out","w",stdout);
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            scanf("%d%d",&N,&K);
            for(i = 0; i < N - 1; i++){
                edge[i].get();
            }
            for(i = 0; i < N; i++)
                fa[i] = i;
            sort(edge,edge+N-1);
            memset(flag,0,sizeof(flag));
            for(i = 0; i < K; i++)
            {
                scanf("%d",&k);
                flag[k] = 1;
            }
            ans = 0;
            memset(ff,0,sizeof(ff));
            for(i = 0; i < N -1; i++)
            {
                k1 = find(edge[i].u);
                k2 = find(edge[i].v);
                if(ff[k1] == 1 && ff[k2] == 1)
                    ans = ans + (__int64)edge[i].w;
                else
                {
                    fa[k1] = k2;
                    if(ff[k1] == 1)
                        ff[k2] = 1;
                }
            }
            printf("%I64d\n",ans);
        }
    }
    return 0;
}

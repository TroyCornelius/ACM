#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define N 300
using namespace std;
struct Node
{
    int x,y,v,t;
} f[N];
bool operator<(Node a,Node b)
{
    if(a.y*b.x==a.x*b.y)return a.x*a.x+a.y*a.y<b.x*b.x+b.y*b.y;
    return a.y*b.x<a.x*b.y;
}
struct node
{
    int v,t;
} g[N];
vector<node> v[N];
int dp[50000];
int n,t;
int main()
{
 //   freopen("data.in","r",stdin);
 //   freopen("data.out","w",stdout);
    int cas=0;
    while(scanf("%d %d",&n,&t)==2)
    {
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++)
            scanf("%d %d %d %d",&f[i].x,&f[i].y,&f[i].t,&f[i].v);
        sort(f,f+n);
        for(int i=0;i<N;i++)
            v[i].clear();
        int num=0;
        node tmp;
        tmp.v=f[0].v,tmp.t=f[0].t;
        v[0].push_back(tmp);
        for(int i=1;i<n;i++)
            if(f[i].x*f[i-1].y==f[i].y*f[i-1].x)
            {
                tmp.v+=f[i].v,tmp.t+=f[i].t;
                v[num].push_back(tmp);
            }else
            {
                tmp.v=f[i].v,tmp.t=f[i].t;
                v[++num].push_back(tmp);
            }
        memset(dp,0,sizeof(dp));
        for(int k=0;k<=num;k++)
            for(int V=t;V>=0;V--)
                for(int i=0;i<v[k].size();i++)
                    if(v[k][i].t<=V)
                        dp[V]=max(dp[V],dp[V-v[k][i].t]+v[k][i].v);
        printf("Case %d: %d\n",++cas,dp[t]);
    }
    return 0;
}

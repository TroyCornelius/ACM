#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,m,ans=(1<<29),cu=0,cv=0,dist[101],Q[10001];
int d[101][101],map[101][101],pre[101]={0};
bool InQ[101]={false};
int min(int a,int b)
{
    if (a > b)  return b;
    return a;
}
int max(int a,int b)
{
    if (a > b)  return a;
    return b;
}
void updata(int u,int v)
{
    int D=0,t,p=(u!=v);
    for (int i=1;i<=n;++i)
    {
        t=min(d[u][i],d[v][i]);
        D=max(D,(t<<1)+p);
    }
    if (D < ans)  ans=D,cu=u,cv=v;
}
void spfa()
{
    int l=0,r=0;
    memset(dist,44,sizeof(dist));
    InQ[Q[++r]=cu]=true;
    dist[cu]=0;
    InQ[Q[++r]=cv]=true;
    dist[cv]=0;
    while (l < r)
    {
        int u=Q[++l];
        for (int v=1;v<=n;++v)
            if (dist[u]+map[u][v] < dist[v])
            {
                dist[v]=dist[u]+map[u][v];
                pre[v]=u;
                if (!InQ[v])
                    InQ[Q[++r]=v]=true;
            }
        InQ[u]=false;
    }
}
int main()
{
    int a,b;
    scanf("%d%d",&n,&m);
    memset(d,44,sizeof(d));
    for (int i=1;i<=n;++i)  d[i][i]=1;
    for (int i=1;i<=m;++i)
    {
        scanf("%d%d",&a,&b);
        d[a][b]=d[b][a]=1;
    }
    memcpy(map,d,sizeof(d));
    for (int k=1;k<=n;++k)
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            if (map[i][j] < (1<<29))
                updata(i,j);
    spfa();
    for (int i=1;i<=n;++i)
        if (pre[i])
            printf("%d %d\n",i,pre[i]);
    if (cu != cv)  printf("%d %d\n",cu,cv);
    return 0;
}

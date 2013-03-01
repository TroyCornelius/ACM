#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int mm=1111;
int f[mm][mm],g[mm][mm],h[mm],l[mm],r[mm];
char s[mm];
int i,j,k,n,m,ans,t,cs=0;
void dp(int c)
{
    int i,j,lm,rm;
    for(i=1;i<=m;++i)h[i]=0,l[i]=1,r[i]=m;
    for(i=1;i<=n;++i)
    {
        lm=1,rm=m;
        for(j=1;j<=m;++j)
            if(c-g[i][j])
            {
                ++h[j];
                if(l[j]<lm)l[j]=lm;
            }
            else h[j]=0,lm=j+1,l[j]=1,r[j]=m;
        for(j=m;j>0;--j)
            if(h[j])
            {
                if(r[j]>rm)r[j]=rm;
                ans=max(ans,(h[j]+r[j]-l[j]+1)*2);
            }
            else rm=j-1;
    }
}
int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;++i)
        {
            scanf("%s",s);
            for(j=0;j<m;++j)
                g[i][j+1]=(s[j]=='B');
        }
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
            {
                f[i][j]=1;
                if(g[i][j-1]!=g[i][j]&&g[i-1][j]!=g[i][j])
                {
                    k=min(f[i][j-1],f[i-1][j]);
                    if(f[i][j-1]==f[i-1][j]&&g[i-k][j-k]!=g[i][j]);
                    else ++k;
                    f[i][j]=max(f[i][j],k);
                }
            }
        ans=0;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                ans=max(ans,f[i][j]*4);
        dp(0);
        dp(1);
        printf("Case #%d: %d\n",++cs,ans);
    }
}


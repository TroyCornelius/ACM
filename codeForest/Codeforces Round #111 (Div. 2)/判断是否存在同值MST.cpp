#include<cstdio>
#include<cstdlib>
using namespace std;
struct arr{
       int x,y,c;
}e[300010];
struct brr{
       int fa,fa1;
}f[100010];
int ans,T,n,m,i,j;
void qsort(int l,int r)
{
     int i,j,mid;
     arr x;
     i=l;j=r;mid=e[(i+j)>>1].c;
     while(i<=j)
     {
       while(e[i].c<mid)i++;
       while(e[j].c>mid)j--;
       if(i<=j)
       {
         x=e[i];e[i]=e[j];e[j]=x;
         i++;j--;
       }
     }
     if(l<j)qsort(l,j);
     if(i<r)qsort(i,r);
}
int find(int x)
{
    if(x!=f[x].fa)f[x].fa=find(f[x].fa);
    return f[x].fa;
}
int find1(int x)
{
    if(x!=f[x].fa1)f[x].fa1=find1(f[x].fa1);
    return f[x].fa1;
}
inline bool work()
{
     int i,j,sum=1,now,u,v;
     for(i=1;i<=n;i++)f[i].fa=f[i].fa1=i;i=1;
     while(sum<n)
     {
       now=e[i].c;
       while(now==e[i].c)
       {
         u=find(e[i].x);v=find(e[i].y);
         if(u!=v)
         {
           now=e[i].c;
           f[u].fa=v;
           ans+=now;
           sum++;
         }
         else
         {
           u=find1(e[i].x);v=find1(e[i].y);
           if(u!=v)return 0;
         }
         i++;
       }
       for(j=1;j<=n;j++)f[j].fa1=f[j].fa;
     }
     return 1;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
      scanf("%d%d",&n,&m);ans=0;
      for(i=1;i<=m;i++)scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].c);
      qsort(1,m);
      if(work()==0)printf("Not Unique!\n");
      else printf("%d\n",ans);
    }
    return 0;
}
 


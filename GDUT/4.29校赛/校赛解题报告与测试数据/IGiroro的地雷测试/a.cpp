#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define INF (1<<30)
using namespace std;

int n,y,d;
struct node
{
       int x,y,r;
       void scan()
       {
            scanf("%d%d%d",&x,&y,&r);
       }
}a[205],now;
queue <node> q;
bool f[205];

double dis(node a,node b)
{
       return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}
int main()
{
    char s1[10]="a0.in",s2[10]="a0.out";
    int t=0;
    for (t=0;t<=9;t++)
    {
        int i;
        s1[1]=s2[1]=t+'0';
        freopen(s1,"r",stdin);
        freopen(s2,"w",stdout);
        while (scanf("%d%d%d",&n,&y,&d)!=EOF)
        {
              while (!q.empty()) q.pop();
              memset(f,0,sizeof(f));
              for (i=1;i<=n;i++)
              {
                  a[i].scan();
                  if ( abs(a[i].y-y)<=d )
                  {
                       q.push(a[i]);
                       f[i]=true;
                  }
              }
              while (!q.empty())
              {
                    now=q.front();
                    q.pop();
                    for (i=1;i<=n;i++)
                        if (!f[i] && dis(now,a[i])<=now.r)
                        {
                           f[i]=true;
                           q.push(a[i]);
                        }
              }
              int ans=0;
              for (i=1;i<=n;i++) ans+=f[i];
              printf("%d\n",ans);
          }
    }
    //system("pause");
}

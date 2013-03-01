#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cctype>
#include <assert.h>

using namespace std;

#define maxn 20010
#define maxm 60010
#define maxq 300010

int val[maxn],query[maxq][3],n,m,cmd;

int pre[maxn];

multiset<pair<int,int> >edges;
multiset<int>num[maxn];

int find_set(int x)
{
if(x!=pre[x])
   pre[x]=find_set(pre[x]);
return pre[x];
}

void union_set(int x,int y)
{
int a=find_set(x);
int b=find_set(y);
if (a==b)
{
   return ;
}
if(num[a].size()>num[b].size())swap(a,b);
pre[a]=b;
num[b].insert(num[a].begin(),num[a].end());
num[a].clear();
//
}

int main() 
{
int i,j;
int u,v,cases = 0;
char str[5];
double cnt,sum;
while(scanf("%d %d %d", &n,&m,&cmd) != EOF) 
{
   cases++;
   cnt = 0;
   sum = 0;
   edges.clear();
   for (i=1;i<=n;i++)
   {
    scanf("%d",val+i);
    num[i].clear();
    pre[i] = i;
   }
   for (i=0;i<m;i++)
   {
    scanf("%d %d",&u,&v);
    if (u>v)swap(u,v);
    edges.insert(pair<int,int>(u,v));
   }
   for (i=0;i<cmd;i++)
   {
    scanf("%s",str);
    scanf("%d %d",&query[i][1],&query[i][2]);
    query[i][0] = str[0];
    multiset<pair<int,int> >::iterator it;
    if (str[0]=='F')//A)
    {
     continue;
    } 
    else if (str[0]=='U')//B)
    {
     swap(val[query[i][1]],query[i][2]);
    } 
    else//C)
    {
     if (query[i][1]>query[i][2])
     {
      swap(query[i][1],query[i][2]);
     }
     it = edges.find(pair<int,int>(query[i][1],query[i][2]));
     if (it!=edges.end())edges.erase(it);
    }
   }
   for (i=1;i<=n;i++) num[i].insert(val[i]);
   for (multiset<pair<int,int> >::iterator it = edges.begin();it!=edges.end();it++)
   {
    union_set(it->first,it->second);
   }
   for (i=cmd-1;i>=0;i--)
   {
    if (query[i][0]=='F')
    {
     cnt+=1;
     u = find_set(query[i][1]);
     multiset<int>::iterator it = num[u].lower_bound(query[i][2]);
     if(it!=num[u].end())sum+=*it;
    } 
    else if (query[i][0]=='U')
    {
     u = find_set(query[i][1]);
     num[u].erase(num[u].find(val[query[i][1]]));
     num[u].insert(query[i][2]);
     val[query[i][1]] = query[i][2];
    } 
    else
    {
     union_set(query[i][1],query[i][2]);
    }
   }
   printf("Case %d: %.3lf\n",cases,sum/cnt);
}
}

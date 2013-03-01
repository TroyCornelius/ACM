#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define fi first
#define se second
#define mp make_pair
using namespace std;

struct Tnode
{
       int x, y;
       bool operator<(const Tnode &b)const
       {
          return (x > b.x) || (x==b.x && y>b.y);     
       }
       };
int n, k, sn;
Tnode a[Maxn], d[Maxn];
int head, tail, que[Maxn];
int main()
{
    while (~scanf("%d%d", &n, &k))
    {
          for (int i=0; i<n; i++) scanf("%d%d", &a[i].x, &a[i].y);
          sort(a, a+n);
          sn = 1;
          d[1] = a[0];
          for (int i=1; i<n; i++)
          {
              if (a[i].x<=d[sn].x && a[i].y<=d[sn].y) continue;
              d[++sn] = a[i];              
          }
          
          for (int i=1; i<=k; i++)
          {
              
              
              
              
          }
                    
          
    }
    
    return 0;
    }

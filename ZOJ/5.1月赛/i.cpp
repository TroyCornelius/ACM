#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int n, m, ans;
struct Tnode
{
       int x, y;
       }hum[2510];
int w[40010];
bool cmp(const Tnode &a, const Tnode &b)
{
     if (a.x != b.x) return a.x < b.x;
     else return a.y < b.y;
     }
int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
       for (int i=0; i<n; i++) scanf("%d%d", &hum[i].x, &hum[i].y);
       for (int i=0; i<m; i++) scanf("%d", &w[i]);
       sort(w, w+m, less<int>());
       sort(hum, hum+n, cmp);
       int p1=0, p2 = 0;
       ans = 0;
       while (p1 < n && p2 < m)
       {
          if (hum[p1].x <= w[p2] && hum[p1].y >= w[p2])
          {
             ans++; p1++; p2++;                        
          }
          else
          if (hum[p1].x > w[p2]) p2++;
          else
          if (hum[p1].y < w[p2]) p1++;             
       }
       printf("%d\n", ans);
    }
    return 0;
    }

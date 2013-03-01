#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
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
bool cmp2(int a, int b)
{
     return hum[a].y > hum[b].y;
     }
vector<int> h;
int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
       for (int i=0; i<n; i++) scanf("%d%d", &hum[i].x, &hum[i].y);
       for (int i=0; i<m; i++) scanf("%d", &w[i]);
       sort(w, w+m, less<int>());
       sort(hum, hum+n, cmp);
       h.clear();
       make_heap(h.begin(), h.end(), cmp2);
       int p1=0;
       ans = 0;
       for (int i=0; i<m; i++)
       {
           while (hum[p1].x <= w[i] && p1 < n)
           {
              if (hum[p1].y < w[i]) p1++;
              else
              {
                  h.push_back(p1);
                  push_heap(h.begin(), h.end(), cmp2);
                  p1++;                  
              }                 
           }
           while (h.size() != 0 && hum[h[0]].y < w[i])
           {
              pop_heap(h.begin(), h.end(), cmp2);
              h.pop_back();                 
           }
           if (h.size() != 0)
           {
              ans++;
              pop_heap(h.begin(), h.end(), cmp2);
              h.pop_back();                        
           }
       }
       printf("%d\n", ans);   
    }
       
    return 0;
    }

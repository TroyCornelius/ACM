#include <iostream>
#include <cstdio>
using namespace std;

int T, n, ans;
struct Tnode
{
       int x, y;
       };
Tnode d[5050];
bool vis[5050];
bool cmp(const Tnode &a, const Tnode &b)
{
     if (a.x != b.x) return a.x < b.x;
     else return a.y < b.y;
     }
int main()
{
    cin >>T;
    for (;T>0;T--)
    {
        scanf("%d", &n);
        for (int i=0; i<n; i++)  scanf("%d%d", &d[i].x, &d[i].y);
        sort(d, d+n, cmp);
        memset(vis, false, sizeof(vis));
        ans = 0;
        int lst;
        for (int i=0; i<n; i++)
        if (!vis[i])
        {
           ans++;
           lst = i;
           for (int j=i+1; j<n; j++)
           if (vis[j]) continue;
           else
           {
               if (d[j].x>= d[lst].x && d[j].y>=d[lst].y)
               {
                   vis[j] = true;
                   lst = j;             
               }               
           }
        }
        cout <<ans <<endl;
        
    }
    system("pause");
    return 0;
    }

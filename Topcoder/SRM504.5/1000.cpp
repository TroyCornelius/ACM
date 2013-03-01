#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
using namespace std;
struct Tnode
{
       vector<int> num;
       double rat;       
       int go;
       Tnode(vector<int>a, double b=0, int c=0)
       {
         num = a;
         rat = b; go = c;                           
       }
       };
queue<Tnode> q;
class TheTicketsDivTwo
{
      
      public:
      double find(int n, int m, int k)
      {
          double ans = 0.0;
          vector<int> t;
          t.clear();
          for (int i=1; i<=n; i++) t.push_back(i);
          while (!q.empty()) q.pop();
          q.push(Tnode(t, 1, 0));
          while (!q.empty())
          {
                Tnode now = q.front();
                q.pop();
             //   printf("%.2lf  %d\n", now.rat, now.go);
                if (now.go >= k)
                {
                   if (now.num[0] == m) ans += now.rat;    
                   continue;                       
                }
                else
                {
                for (int i=1; i<=6; i++)
                {
                   if (i == 4)
                   {
                      if (now.num[0] == m) ans += now.rat * (1.0/6.0);
                   }
                   else
                   if (int(now.num.size())==1)
                   {
                      if (now.num[0] == m) ans += now.rat * (1.0/6.0);                                     
                   }
                   else
                   if (i%2==1)
                   {
                      int tmp = now.num[0];
                      t = now.num;
                      t.erase(t.begin());
                      t.push_back(tmp);
                      q.push(Tnode(t, now.rat*(1.0/6.0), now.go+1));
                   }
                   else
                   if (i%2==0)
                   {
                      t = now.num;
                      t.erase(t.begin());
                      q.push(Tnode(t, now.rat*(1.0/6.0), now.go+1));
                   }
                    
                }
                }
          }
          return ans;
             
      }
      
      
      }d;
int main()
{
    int a, b, c;
    while (cin >>a >>b >>c)
    {
       printf("%.2lf\n",d.find(a, b, c));   
    }
    
    
    }

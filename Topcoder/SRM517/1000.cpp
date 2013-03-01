#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define Maxn 5000
#define inf 1<<30
#define pb push_back
#define mp make_pair
using namespace std;

struct Tnode
{
       int val, id;
       Tnode(){}
       Tnode(int _a, int _b)
       :val(_a),id(_b){}
       bool operator< (const Tnode &b) const
       {
           return val < b.val;    
       }
       };
class CuttingGrass
{
      public:
      priority_queue<Tnode> q;
      vector<Tnode> d;
      bool vis[100];
      int theMin(vector <int> init, vector <int> grow, int H)
      {
          int sum = 0, ans = 0;
          while (!q.empty()) q.pop();
          memset(vis, false, sizeof(vis));
          for (int i=0; i<init.size(); i++)
          {
               sum += init[i];
               d.pb(Tnode(init[i]+grow[i], i));
               q.push(d[i]);
          }            
          while (sum > H && !q.empty())
          {
             //   cout <<sum <<" :";
                sum = 0;
                d.clear();
                ans++;
                while (!q.empty())
                {
                   //   cout <<q.top().val <<" ";                    
                      d.pb(q.top());
                      q.pop();  
                }
                d[0].val = 0;
            //    if (!vis[d[0].id]) vis[d[0].id] = true;
             //   else return -1;
                if (ans > 100000) return -1;
             //   for (int i=0; i<d.size(); i++) cout <<d[i].val <<" ";
             //   cout <<endl;
                
                for (int i=0; i<d.size(); i++) sum+= d[i].val;
              //  cout <<"--"<<sum <<endl;
                if (sum <= H) return ans;
                for (int i=0; i<d.size(); i++) 
                {
                    d[i].val += grow[d[i].id];
                    q.push(Tnode(d[i].val, d[i].id));
                }             
          }
          if (q.empty()) return -1;
          else return ans;
      }
      
      }test;

int main()
{
    int n, m, t, h;
    vector<int> a, b;
    scanf("%d%d%d", &n, &m, &h);
    for (int i=0; i<n; i++)
    {
        cin >>t;
        a.pb(t);        
    }
    for (int i=0; i<m; i++) 
    {
        cin >>t;
        b.pb(t);        
    }
    cout <<test.theMin(a, b, h)<<endl;
    
    system("pause");
    
    
    return 0;
    }

    


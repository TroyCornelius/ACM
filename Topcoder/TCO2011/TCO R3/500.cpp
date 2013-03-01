#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <cctype>
#include <algorithm>
#include <functional>

using namespace std;

struct Tnode
{
       int ne, gi;
       Tnode (int a=0, int b=0)
       {
          ne = a;  gi = b;
       }
       };
vector <Tnode> d;
bool cmp(const Tnode &x, const Tnode &y)
{
     if ((x.ne-x.gi) != (y.ne-y.gi)) return (x.ne-x.gi) < (y.ne-y.gi);
     else return x.ne < y.ne;
     }
class CoinMachinesGame
{
      public:      
      int maxGames(int coins, vector <int> need, vector <int> give)
      {
          for (int i=0; i<need.size(); i++) d.push_back(Tnode(need[i], give[i]));
          sort(d.begin(), d.end(), cmp);
          
          int ans = 0, tmp;
          for (int i=0; i<d.size(); i++)
          {
             while (coins/d[i].ne != 0)
             {
                tmp = coins/d[i].ne;
                ans += tmp;
                coins %= d[i].ne;
                coins += tmp*d[i].gi;                   
             }              
          }
          return ans;          
      }
      };
int main()
{
    
    return 0;   
}

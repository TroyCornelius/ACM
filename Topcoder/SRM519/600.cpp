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
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define inf 1<<30
using namespace std;

typedef pair<int,int> pii;
pair<int,int> tp[3];
map<pii, int> id;
int cnt;
vector<pii> point;
struct Tnode
{
       int next, len;
       Tnode(){}
       Tnode(int _a, int _b)
       :next(_a),len(_b){}
       };
vector<Tnode> g[10];
int dis[10];
bool hash[10];
class ThreeTeleports
{
      public :      
      int get_dis(pii a, pii b)
      {
          return abs(a.fi - b.fi) + abs(a.se - b.se);   
      }
      int spfa()
      {
           for (int i=0; i<=cnt+1; i++) dis[i] = inf;
           dis[0] = 0;
           memset(hash, false, sizeof(hash));
           queue<int> q;
           q.push(0);
           while (!q.empty())
           {
                 int now = q.front();
                 hash[now] = false;                 
                 q.pop();
                 for (int i=0; i<g[now].size(); i++)
                 {
                     if (dis[now] + g[now][i].len < dis[g[now][i].next])
                     {
                         dis[g[now][i].next]  = dis[now] + g[now][i].len ;
                         if (!hash[g[now][i].next])       
                         {
                            hash[g[now][i].next] = true;
                            q.push(g[now][i].next);
                         }
                     }                     
                 }                 
           }
           return dis[cnt+1];
           
      }
      int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> tel)
      {
          cnt = 0;
          point.pb(mp(xMe, yMe));
          for (int i=0; i<tel.size(); i++)
          {
              int num[5], tot = 0;
              int loc = 0, nxt;
              string st;
              while ((loc < tel[i].length()) && ((nxt = tel[i].find(" ", loc)) != string::npos))
              {
                    st = tel[i].substr(loc, nxt-loc);
                    num[tot++] = atoi(st.c_str());
                    loc = nxt+1;                    
              }
              nxt = tel[i].length();
              st = tel[i].substr(loc, nxt-loc);
              num[tot++] = atoi(st.c_str());
              pii ta = mp(num[0], num[1]);
              pii tb = mp(num[2], num[3]);       
              if (id[ta] == 0) {id[ta] = ++cnt; point.pb(ta); }
              if (id[tb] == 0) {id[tb] = ++cnt; point.pb(tb);}
              g[id[ta]].pb(Tnode(id[tb], 10));
              g[id[tb]].pb(Tnode(id[ta], 10));  

          }
          point.pb(mp(xHome, yHome));
       //   for (int c=0; c<=cnt+1; c++) cout <<point[c].fi<<" "<<point[c].se <<endl;
          for (int i=0; i<=cnt+1; i++) 
          for (int j=0; j<=cnt+1; j++)
          if (i != j) g[i].pb(Tnode(j, get_dis(point[i], point[j])));

          int ans = spfa();
          return ans;
      }
      }test;

int main()
{
    int xx, yy, xe, ye;
    vector<string> pp;
    pp.pb("3 10 5200 4900");
    pp.pb("12212 8699 9999 30011");
    pp.pb("12200 8701 5203 4845");
    cin >> xx >>yy>>xe>>ye;
    cout <<test.shortestDistance(xx,yy,xe,ye, pp) <<endl;
    system("pause");
    
    
    return 0;
    }

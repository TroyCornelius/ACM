#include <set>
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
#define mp make_pair
#define fi first
#define se second
#define Maxn 20010
#define Maxq 300010
//#define pii pair<int,int> 
//#define spi multiset<pii>::iterator 
//#define si multiset<int>::iterator 
using namespace std;

typedef pair<int,int> pii;
typedef multiset<pii>::iterator spi;
typedef multiset<int>::iterator si;

multiset<int> vcnt[Maxn]; 
multiset<pii> edge;
int n, m, Q, val[Maxn];
int fa[Maxn], que[Maxq][2];
char op[Maxq];
inline int find_fa(int x)
{
    if (fa[x] == x) return fa[x];
    else return fa[x] = find_fa(fa[x]);
    }
void union_set(int x, int y)
{
     int a = find_fa(x);
     int b = find_fa(y);
     if (a == b) return;
     if (vcnt[a].size() > vcnt[b].size()) swap(a, b);
     fa[a] = b;
     vcnt[b].insert(vcnt[a].begin(), vcnt[a].end());
     vcnt[a].clear();
     }
int main()
{
    int a, b, sum, tot, ca=0, u;
    char cmd[3];
    while (scanf("%d %d %d", &n, &m, &Q) != EOF)
    {
          sum = 0; tot = 0;
          edge.clear();
          for (int i=1; i<=n; i++) 
          {
              scanf("%d", val+i);
              fa[i] = i;
              vcnt[i].clear();              
          }
          for (int i=0; i<m; i++)
          {
              scanf("%d %d", &a, &b);
              if (a > b) swap(a, b);
              edge.insert(pii(a,b));    
          }
          for (int i=0; i<Q; i++)
          {
              scanf("%s", cmd);
              scanf("%d %d", &que[i][0], &que[i][1]);            
              op[i] = cmd[0];
              if (cmd[0] =='U') swap(val[que[i][0]], que[i][1]);
              else
              if (cmd[0] =='E')
              {
                  if (que[i][0] > que[i][1]) swap(que[i][0], que[i][1]);
                  spi p = edge.find(pii(que[i][0], que[i][1]));
                  if (p != edge.end()) edge.erase(p);
              }       
          }
          for (int i=1; i<=n; i++) vcnt[i].insert(val[i]);
          for (spi p=edge.begin(); p!=edge.end(); p++) union_set(p->fi, p->se);

          for (int i=Q-1; i>=0; i--)
          {
              if (op[i]=='F')
              {
                  tot++;
                  u = find_fa(que[i][0]);
                  si p = vcnt[u].lower_bound(que[i][1]);
                  if (p != vcnt[u].end()) sum += *p;   
              }
              else
              if (op[i] == 'E') union_set(que[i][0], que[i][1]);
              else
              {
                  u = find_fa(que[i][0]);
                  vcnt[u].erase(vcnt[u].find(val[que[i][0]]));
                  vcnt[u].insert(que[i][1]);
                  val[que[i][0]] = que[i][1]; 
              }              
          }
          printf("Case %d: %.3lf\n", ++ca, 1.0*sum/(1.0*tot));
    }   
   // system("pause");
    return 0;
    }

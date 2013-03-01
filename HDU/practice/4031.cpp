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
#define Maxn 20100
#define Maxm 2100
#define inf 1<<30
#define pb push_back
#define mp make_pair
using namespace std;

int n, Q, t;
int que[Maxn][2];
class bit_tree
{
      public:
      int b[Maxn], c[Maxn];
      void init(){memset(b,0,sizeof(b));memset(c,0,sizeof(c));}
      inline int lowbit(int x){return x&(-x);}
      void insert1(int idx, int val)
      {
           for (;idx && idx<=n+2; idx+=lowbit(idx)) b[idx]+=val;           
      }
      void insert2(int idx, int val)
      {
           for (; idx; idx-=lowbit(idx)) c[idx]+=val;
      }
      int query1(int idx)
      {
          int s = 0;
          for (;idx;idx-=lowbit(idx)) s+=b[idx];
          return s;          
      }
      int query2(int idx)
      {
          int s = 0;
          for (;idx<=n+2; idx+=lowbit(idx)) s+=c[idx];
          return s;          
      }
      void _insert(int p, int val)
      {
           insert1(p, p*val);
           insert2(p-1, val);           
      }
      int _query(int p)
      {
          return query1(p) + query2(p) * p;    
      }
      void insert_seg(int l, int r, int val)
      {
           _insert(r, val);
           _insert(l-1, -val); 
      }
      int find_sum(int l, int r)
      {
          return _query(r) - _query(l-1);       
      }      
      }seg;
struct BIT
{
       int tree[Maxn];
       void init()
       {
            memset(tree, 0, sizeof(tree));            
       }
void updata(int idx, int val)
{
     for (;idx; idx-=idx&-idx) tree[idx]+=val;     
     }
int query(int idx)
{
     int ret = 0;
     for (;idx<=n; idx+=idx&-idx) ret += tree[idx];
     return ret;
     }     
     };
BIT ans;
multiset<int> point;
typedef multiset<int>::iterator vi;
int main()
{
    int T, ca=0, ti = 0, a, bb, sum, le, ri;
    char op[10];
    vi p1, p2;
    scanf("%d", &T);
    while (T--)
    {
          scanf("%d%d%d", &n, &Q, &t);
        //  n+=2;
          ans.init();
          seg.init();
          point.clear();
          ti=0;
          printf("Case %d:\n", ++ca);
          for (int i=0; i<Q; i++)
          {
              scanf("%s", op);
              if (op[0]=='A')
              {
                  ti++;
                  scanf("%d%d", &que[ti][0], &que[ti][1]);
                  que[ti][0] += 2; que[ti][1] += 2;
              //    cout <<ti << " "<<t<<endl;
                  if (ti-t>=1) 
                  {
                      seg.insert_seg(que[ti-t][0], que[ti-t][1], -1);
                      point.erase(lower_bound(point.begin(), point.end(), que[ti-t][0]));
                      point.erase(lower_bound(point.begin(), point.end(), que[ti-t][1]));                                                         
                  }
                  if (point.size()>=2){
                  vi pp = point.end();
                  pp--;
                  le = max(*point.begin(), que[ti][0]); 
                  ri = min(*pp, que[ti][1]);
                  if (le > ri)
                  {
                     le = que[ti][0];
                     ri = que[ti][1];                         
                  }
                  cout <<le-2 <<" "<<ri-2 <<"----"<<*point.begin() <<" "<<*pp <<endl;
                  ans.updata(ri-2, 1);
                  ans.updata(le-1-2, -1);
                  }
                  point.insert(que[ti][0]);
                  point.insert(que[ti][1]);                  
                  if (ti-t>=1)
                  {
                     le = max(que[ti-t][0], le);
                     ri = min(ri, que[ti-t][1]);
                     cout <<le-2 <<" "<<ri-2<<"  recovery" <<endl;
                     ans.updata(ri-2, -1);
                     ans.updata(le-1-2, 1);                             
                         
                   le = n+2; ri = 2;
                   if (ti-t-1>=1){
                      for (int j=ti-t-1; j+t>=ti-t && j+t<ti; j--)
                      {
                        //  if (j < 1) break;
                          le = min(le, que[j][0]);
                          ri = max(ri, que[j][1]);    
                      }
                      le = max(le, que[ti-t][0]);
                      ri = min(ri, que[ti-t][1]);
                   //   cout <<le-2 <<" "<<ri-2<<" add" <<endl;
                      ans.updata(ri-2, 1);
                      ans.updata(le-1-2, -1);        
                      }                         
                  
                  }
              }
              else
              {
                  scanf("%d", &bb);
                  printf("%d\n", ans.query(bb));
              }
          }
    }
    system("pause");
    return 0;
    }

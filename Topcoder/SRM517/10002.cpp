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
          int n = init.size();
          for (int i=0; i<n; i++)
          {
              sum += init[i];              
          }
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

    


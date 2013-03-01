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
#define Maxn 100100
#define inf 999999999
#define pb push_back
#define mp make_pair
using namespace std;

string s;
int n;
bool check(int k)
{
     if(k == 0) return false;
     while (k > 0)
     {
           if (k % 10 != 4 && k%10 != 7) return false;
           k/=10;           
     }
     return true;
     }
struct edege
{
       int id;
       bool luck;
       edge() {}
       edge(int _a, bool _b)
       :id(_a),luck(_b){}
       }
vector<edge> g[Maxn];
int main()
{
    int a, b, c;
    bool tflag;
    cin >>n;
    for (int i=0; i<n-1; i++)
    {
        cin >>a >>b >>c;
        tflag = check(c);
        g[a].pb(edge(b,tflag));
        g[b].pb(edge(a,tflag));        
    }

    return 0;
    }

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

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Maxn 5000000
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;
typedef long long ll;
long long n, m, ans1, ans2;

inline void calc(ll x, ll y, ll z)
{
    ll s = (x+1)*(y+2)*(z+2);
    ans1 = min(ans1, s);
    ans2 = max(ans2, s);
}
inline void work(ll x, ll y, ll z)
{
    calc(x, y, z);
    calc(y, x, z);
    calc(z, x, y);
}
int main()
{
   // while (1){
    ll t1, t2;
    cin >>n;
    ans1 = 1LL<<60; ans2 = 0;
    for (ll i = 1; i*i <= n; i++)
    {
        if (n%i == 0){
           t1 = n / i;
           for (ll j=1; j*j<=t1; j++)
           {
              if (t1 % j == 0){
              t2 = t1 / j;
              work(i, j, t2);  
              }      
           }
        }
    }
    cout <<ans1-n <<" "<<ans2-n <<endl;
//}
    return 0;
}


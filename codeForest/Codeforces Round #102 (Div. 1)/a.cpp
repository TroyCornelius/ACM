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

long long n, m;

bool pri[Maxn+10];
vector<int> p, t;
vector<pii> a;
void init()
{
    memset(pri, false, sizeof(pri));
    p.clear();
    for (int i=2; i<=Maxn; i++)
        if (pri[i])
        {
            p.pb(i);
            for (int j=i+i; j<=Maxn; j+=i) pri[j] = false;        
        }
}
void dfs(int num, int idx)
{
    t.pb(num);
    if (idx >= a.size()) return;
    dfs(num, idx+1);
    int tmp = num;
    FOR(i, 0, a[idx].se)
    {
        tmp *= a[idx].fi;
        dfs(tmp, idx+1);    
    }
}
void calc()
{
    int ans1 = inf, ans2 = -1;
    dfs(1, 0);

}
int main()
{
   // while (1){
    cin >>n;
    /*init();
    a.clear();
    FOR(i, 2, p.size())
    {
        if (n <= 1) break;
        if (n%pri[i]==0)
        {
           tot = 0;
           while (n%pri[i]==0)
           {
               n/=pri[i];
               tot++;           
           }  
           a.pb(mp(pri[i], tot));           
        }    
    }
    if (n != 1) a.pb(mp(n, 1));
    calc();*/
   /* long long a, d, ans1;
    for (long long i=1; i*i<=n; i++)
    {
        if (n % (i*i) == 0)
        {
            a = i; d = n/i/i;        
        }    
    }
    if (a <= d) ans1 = (a+1)*(a+2)*(d+2)-n;
    else ans1 = (d+1)*(a+2)*(a+2) - n;
    cout <<ans1<<" "<<8*n+9 <<endl;
//}*/
    return 0;
}

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
#define all(a) (a).begin(),(a).end()
#define Maxn 10100
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
const long long MOD = 1000000007LL;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

int n, s;
pii chi[Maxn];

bool cmp(pii a, pii b)
{
    return a.se < b.se || (a.se == b.se && a.fi > b.fi);
}
bool check()
{
    long long cnt = s;
    REP(i, n)
    {
        if (cnt >= chi[i].se) cnt += chi[i].fi;
        else return false;    
    }
    return true;
}
int main()
{
    int a, b;
    long long cnt;
    while (~scanf("%d%d", &n, &s), n)
    {
        REP(i, n) scanf("%d%d", &chi[i].fi, &chi[i].se);
        sort(chi, chi+n, cmp);
        if (check()) printf("YES\n");
        else printf("NO\n");    
    }
    return 0;
}

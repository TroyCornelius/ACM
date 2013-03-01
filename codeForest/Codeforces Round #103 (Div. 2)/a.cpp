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
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

int n, m, num[128];
pii big, sm;
int main()
{
    //while (1){
    int ans = 0;
    big.fi = -1; sm.fi = inf;
    cin >>n;
    REP(i, n)
    {
        cin >>num[i];
        if (num[i] > big.fi) big = mp(num[i], i);
    }
    ans = big.se;
    for (int i=n-1; i>=0; i--)
        if (num[i] < sm.fi) sm = mp(num[i], i);
    if (sm.se < big.se) ans += n-1-sm.se-1;
    else ans += n-1 - sm.se;
    cout <<ans <<endl;
//}
    return 0;
}

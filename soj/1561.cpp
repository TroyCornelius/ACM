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
#define Maxn 2001000
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
const long long MOD = 1000000007LL;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

int n;
bool b[Maxn];
vector<int> p;
void init()
{
    p.clear();
    memset(b, true, sizeof(b));
    p.pb(1);
    for (int i=2; i<=2000000; i++)
        if (b[i])
        {
            p.pb(i);
            for (int j=i+i; j<=2000000; j+=i) b[j] = false;        
        }
}
int main()
{
    init();
    while (cin >>n) cout <<p[n] <<endl;

    return 0;
}

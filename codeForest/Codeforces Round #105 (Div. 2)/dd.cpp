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
#define Maxn 101000
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

int n, m;
double f[1010][1010];

double dfs(int w, int b)
{
    if (f[w][b] != -1.0) return f[w][b];
    if (!w && !b) return f[w][b] = 0.0;
    if (!b) return f[w][b] = 1.0;
    if (!w) return f[w][b] = 0.0;
    f[w][b] = 1.0 * w / (w + b);
    double tmp = 1.0 * b / (w + b) * (b-1)/(w+b-1);
    if (b >= 2) f[w][b] += tmp * w/(w+b-2) * dfs(w-1, b-2);
    if (b >= 3) f[w][b] += tmp * (b-2)/(w+b-2) * dfs(w, b-3);
    return f[w][b];
}
int main()
{
   // while (1){
    cin >>n >>m;
    REP(i,n+1)
      REP(j, m+1) f[i][j] = -1.0;
    printf("%.10f\n", dfs(n, m));
  //  }   
    return 0;
}

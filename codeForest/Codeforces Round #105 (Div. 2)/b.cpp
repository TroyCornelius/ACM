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


int vp, vd, t, f, c;
int main() 
{
    cin >> vp >> vd >> t >> f >> c;
    if(vp >= vd) 
    {
       cout << 0 << endl;
       return 0;
    }
    int ans = 0;
    double tmp = 0, sp = t * vp;
    
    while(1) 
    {
       tmp = sp / (vd - vp);
       sp += tmp * vp;
       if (sp >= c) break;
       else 
       {
            ans++;
            sp += (tmp + f) * vp;
       }
    }
        cout << ans << endl;
    
    return 0;
} 


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

const int mod =  1000000007;


int getsum(int x, int y)
{
    return (x + y) * (y - x + 1) / 2;
}
class PatrolRoute
{
    public:
    int countRoutes(int X, int Y, int minT, int maxT)
    {
        int ans = 0;
        
        REP(x1, X)
        {
            FOR(x3, x1+2, X)
            {
                int tmp = 2 * (x3 - x1);
                int le = max(0, minT - tmp), ri = max(0, maxT - tmp);
                if (maxT - tmp < 0) continue;
                le /=2; ri /= 2;
              //  if (ri >= Y) ri = Y-1;
                le = max(2, le);
                ri = min(ri, Y);
                if (ri >= le) {
                //int delta = ri - le + 1;
                int t = getsum(Y - ri, Y - le);
                t %= mod;
                t = (1LL * t * 6 * (x3 - x1 - 1)) % mod;
                
                ans += t;
                ans %= mod;
                
                }
                
              /*  le = max(0, minT - tmp), ri = max(0, maxT - tmp);
                if (maxT - tmp < 0) continue;  
                le /=2; ri /=2;
                
                le = max(1,le);
                ri = min(ri,Y);*/
                
                
            }
        }
        
        return ans;
    }
};
  



int main() 
{
    return 0;
}


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
#define ll long long
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
class TheDevice
{
        public:
            int minimumAdditional(vector <string> plates)
            {
                n = plates.size();
                m = plates[0].size();
                int ans = 0;
                REP(j, m) {
                    int c0 = 0, c1 = 0;
                    REP(i, n) { 
                        if (plates[i][j] == '1') c1++;
                        else c0++;
                    }
                    int need = (1 - (c0 > 1 ? 1 : c0)) + (2 - (c1 > 2 ? 2 : c1));           
                    ans = max(ans, need);
                }
                return ans;;
        }
};


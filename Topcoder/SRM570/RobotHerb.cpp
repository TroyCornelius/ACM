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

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

class RobotHerb
{
        public:
        long long getdist(int T, vector <int> a) {
            ll ans = 0;
            ll x = 0, y = 0;
            int p = 0, cnt = 0, tmp = T;
            while (tmp--) {
                REP(i, a.size()) {
                    x += a[i] * dx[p];
                    y += a[i] * dy[p];
                    p = (p + a[i]) % 4;
                }
                cnt++;
                if (p == 0) break;
            }
            ans = 1LL * (T / cnt) * (abs(x) + abs(y));
            T %= cnt;
            x = y = 0;
            if (T > 0) {
                while (T--) {
                    REP(i, a.size()) {
                        x += a[i] * dx[p];
                        y += a[i] * dy[p];
                        p = (p + a[i]) % 4;
                    }
                }
                ans += abs(x) + abs(y);
            }
            return ans;
        }

};

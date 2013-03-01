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
const int inf = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;


class HouseBuilding
{
        public:
    int getMinimum(vector<string> area) {
        int n = area.size(), m = area[0].size();
        int ans = inf;
        for (char mi = '0'; mi <='9'; mi++) {
            int sum = 0;
            REP(i, n) {
                REP(j, m) {
                    if (area[i][j] < mi) sum += mi - area[i][j];
                    else
                        if (area[i][j] - mi > 1) {
                            sum += area[i][j] - mi - 1;
                        }
                }
            }
            ans = min(ans, sum);
        }
        return ans;
    }        

};


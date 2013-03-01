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


class TheJediTest
{
        public:
        int minimumSupervisors(vector <int> stu, int K) {
            vi d = stu;
            int n = stu.size();
            REP(i, n - 1) {
                int mv = d[i] % K;
                if (mv > 0 && stu[i] >= mv) {
                    d[i+1] += mv;
                    d[i] -= mv;
                }
                else if (mv > 0 && stu[i] < mv) {
                    int tmp = K - mv;
                    tmp = min(tmp, stu[i+1]);
                    d[i+1] -= tmp;
                    d[i] += tmp;
                }
            }
            int ret = 0;
            REP(i, n) {
                ret += d[i] / K;
                if (d[i] % K != 0) ret++;
            }
            return ret;
        }

};

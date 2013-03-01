
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


class FoxAndMp3Easy
{
        public:
        string solve(int x) {
            string ret = "";
            while (x) {
                char ch = '0' + x % 10;
                x /= 10;
                ret = ch + ret;
            }
            return ret;
        }
        vector <string> playList(int n)
        {
            vector<string> ans;
            FOR(i, 1, n+1) {
                string tmp = solve(i) + ".mp3";
                ans.pb(tmp);
            }
            sort(all(ans));
            if (ans.size() >= 50) ans.resize(50);
            return ans;
        }
        


};


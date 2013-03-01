// BEGIN CUT HERE

// END CUT HERE
//#line 5 "CuttingBitString.cpp"
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <list>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vp;
typedef vector<vi> vvi;

const int N = 100010;
const int M = 55;
const int K = 200010;
const int LIT = 2500;
const int INF = 1 << 30;
const double EPS = 1e-13;

#define mp make_pair
#define pb push_back
#define fst first
#define snd second
const int inf = 1<<29;

class CuttingBitString
{
	public:
    string ltostr(long long x) {
        string ret = "";
        while (x) {
            char ch = '0' + (x % 2);
            ret = ch + ret;
            x /= 2;
        }
        return ret;
    }
	int getmin(string S)
 	{
        string st[100];
        long long f = 1;
        int n = S.size(), m = 0;
        while (f <= (1LL<<55)) {
            st[m++] = ltostr(f);
            f *= 5;
        }
        int dp[100];
        for (int i = 0; i <= n + 3; i++) dp[i] = inf;
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                if (st[j].size() > i) break;
                string tmp = S.substr(i-st[j].size(), st[j].size());
                if (tmp == st[j]) {
                    if (dp[i-st[j].size()] == -1) continue;
                    dp[i] = min(dp[i], dp[i-st[j].size()] + 1);
                }
            }
        }
        if (dp[n] >= inf) return -1;
        else return dp[n];
        
	}
};
int main()
{
    return 0;
}


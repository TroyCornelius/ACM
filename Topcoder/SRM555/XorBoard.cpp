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
const int mod = 555555555;
int c[1560*2][1560*2];
class XorBoard
{
    public:
        int count(int H, int W, int Rcount, int Ccount, int S)
        {
            c[0][0] = 1;
            for (int i = 1; i <= 1555*2; ++i) {
                c[i][0] = 1;
                for (int j = 1; j <= i; ++j) {
                    c[i][j] = c[i-1][j] + c[i-1][j-1];
                    if (c[i][j] >= mod) c[i][j] -= mod;
                }
            }
            long long ans = 0, sum;
            for (int i = 0; i <= min(H, Rcount); ++i) {
                if ((Rcount - i)%2==1) continue;
                for (int j = 0; j <= min(W, Ccount); ++j) {
                    if ((Ccount - j)%2 == 1) continue;
                    sum = i * W + j * H - i * j * 2;
                    if (sum == S) {
                        long long tmp = (1LL*c[H][i]*c[W][j])%mod;
                        int r1 = (Rcount - i) / 2, c1 = (Ccount - j) / 2;
                        tmp = (tmp * c[H+r1-1][H-1]) % mod;
                        tmp = (tmp * c[W+c1-1][W-1]) % mod;
                        ans = (ans + tmp) % mod;
                    }
                }
            }
            return ans;
	}
};

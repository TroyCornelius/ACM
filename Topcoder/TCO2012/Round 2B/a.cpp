// BEGIN CUT HERE

// END CUT HERE
#line 5 "BlurredDartboard.cpp"
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
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

bool vis[100];
class BlurredDartboard
{
    public:
        int minThrows(vector <int> points, int P)
        {
            memset(vis, true, sizeof(vis));
            int mx = 0, tot = 0, n = points.size(), s1 = 0, c;
            REP(i, n)
                if (points[i] == 0) tot++;
                else
                {
                    vis[points[i]] = false;
                    s1 += points[i];
                    mx = max(mx, points[i]);
                }
            vector<int> b;
            FOR(i, 1, n+1)
                if (vis[i]) b.pb(i); 
            int tmp = n * (n + 1) / 2 - s1;
            int ans = INF;
            if (P <= tmp) ans = tot;
            if (mx != 0) {
                c = P / mx + (P % mx == 0 ? 0 : 1);
                if (c < ans) ans = c;
            }
            //cout <<ans << " "<<mx <<" "<<tot <<" "<<s1 <<endl;


            if (tmp < tot * mx) tmp = tot * mx;
            if (tmp != 0) {
                c = P / tmp * tot;
                P %= tmp;
                int ccc = INF;
                if (p != 0) {
                if (mx != 0) ccc = P / mx + (P % mx == 0 ? 0 : 1);
                else ccc = tot;      
                int cnt = 0, st = 0;
                REP(i, b.size())   
                {
                    st += b[i];
                    cnt++;
                    if (st >= P) break;
                }   
                c += min(cnt, ccc);
                if (c < ans) ans = c;
                }
            }
            return ans;       

        }

};



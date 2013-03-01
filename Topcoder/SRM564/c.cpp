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
const int dx[] = {1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1};
class KnightCircuit {
    public:
        bool vis[1010][1010];
        ll W, H, A, B, n;
        ll dfs(int x, int y) {
            if (x < 0 || x >= W || y < 0 || y >= H || x >= n || y >= n)  return 0;
            if (vis[x][y]) return 0;
            vis[x][y] = 1;
            ll ret = W / n + (x + 1 <= W % n);
            ret *= H / n + (y + 1 <= H % n);
            REP(i, 4) ret += dfs(x+dx[i]*A, y+dy[i]*B) + dfs(x+dx[i]*B, y+dy[i]*A);
            return ret;
        }
        ll bfs(int x, int y) {
            queue<pii> que;
            que.push(mp(x, y));
            ll ret = 0, tmp;
            while (!que.empty()) {
                pii cur = que.front();
                que.pop();
                x = cur.fi, y = cur.se;
                if (x < 0 || x >= W || y < 0 || y >= H || x >= n || y >= n || vis[x][y])  continue;
                vis[x][y] = true;
                tmp = W / n + (x + 1 <= W % n);
                tmp *= H / n + (y + 1 <= H % n);
                ret += tmp;
                REP(i, 4) {
                    que.push(mp(x+dx[i]*A, y+dy[i]*B));
                    que.push(mp(x+dx[i]*B, y+dy[i]*A));
                }
            }
            return ret;
        }
        long long maxSize(int w, int h, int a, int b) {
            W = w, H = h, A = a, B = b;
            //n =  4 * max(a, b) * max(a, b);
            n = max(a, b);
            ll ans = 0, res;
            if (min(a, b) >= min(w, h)) return 1;
            memset(vis, 0, sizeof(vis));
            for (int i = 0; i < n && i < w; i++)
                for (int j = 0; j < n && j < h; j++)
                    if (!vis[i][j]) {
                        res = bfs(i, j);
                        ans = max(ans, res);
                    }
            return ans;
        }
};

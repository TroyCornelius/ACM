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
const int mm = 110*110;
const int mn = 110;
struct Circle
{
    int x, y;
    //double x,y,r;
}cir[110];
int n, size, res, lim, r;
int U[mm], D[mm], L[mm], R[mm], C[mm], X[mm];
int H[mn], S[mn], Q[mn];
bool v[mn];
void prepare(int r, int c)
{
    REP(i, c+1)
    {
        S[i] = 0;
        U[i] = D[i] = i;
        L[i+1] = i;
        R[i] = i+1;
    }
    R[c] = 0;
    size = c;
    while (r) H[r--] = -1;        
}
int f()
{
    //memset(v, false, sizeof(v));
    int i, j, c, ret = 0;
    for (c = R[0]; c; c=R[c]) v[c] = true;
    for (c = R[0]; c; c= R[c])
        if (v[c]) {
            for (++ret, v[c] = false, i=D[c]; i!=c; i=D[i])
                for (j=R[i];j!=i;j=R[j])
                    v[C[j]] = false;
        }
    return ret;
}
void remove(int c)
{
    for (int i = D[c]; i!=c; i=D[i])
        L[R[i]] = L[i], R[L[i]] = R[i];
}
void resume(int c)
{
    for (int i=U[c]; i!=c; i=U[i])
        L[R[i]] = R[L[i]] = i;
}
bool Dance(int k, int limit)
{
    if (!R[0]) return true;
 //   if (k + f() >= res) return false;
    int ut = k + f();
    if (ut > limit) 
    {
        lim = min(lim, ut);
        return false;
    }
    int i, j, c, tmp = mm;
    for (i=R[0]; i; i=R[i])
        if (S[i] < tmp)  tmp = S[c = i];
    for (i=D[c]; i!=c; i=D[i]) {
        Q[k] = i;
        remove(i);
        for (j=R[i]; j!=i; j=R[j]) remove(j);
        if (Dance(k+1, limit)) return true;
        for (j=L[i]; j!=i; j=L[j]) resume(j);
        resume(i);
    }
    return false;
}
void Link(int r, int c)
{
    ++S[C[++size] = c];
    X[size] = r;
    D[size] = D[c];
    U[D[c]] = size;
    U[size] = c;
    D[c] = size;
    if (H[r] < 0) H[r] = L[size] = R[size] = size;
    else
    {
        R[size] = R[H[r]];
        L[R[H[r]]] = size;
        L[size] = H[r];
        R[H[r]] = size;
    }
}
bool check(int x, int y)
{
    double tx = (cir[x].x - cir[y].x), ty = cir[x].y - cir[y].y;
    //double dis = tx*tx + ty*ty;
    //return cir[x].r * cir[x].r >= dis;
    return tx*tx + ty*ty <= r*r;
}
void solve() {
    int ans = n;
   /* for(int i = 1; i < n; i++) {
        if(Dance(0, i)) {
            ans = i;
            break;
        }
    }*/
    lim = 1;
    while (1)
    {
        ans = lim;
        lim = 110;
        if (Dance(0, ans)) break;
    }
    pf("%d\n", ans);
    REP(i, ans) pf("%d%c", X[Q[i]], i==ans-1?'\n':' ');
  //  cout << ans << endl;
}
int main() 
{
    //freopen("g.in", "r", stdin);
    //freopen("g2.out", "w", stdout);
    while (~sf("%d%d", &n, &r))
    {
        FOR(i, 1, n+1) sf("%d%d", &cir[i].x, &cir[i].y);
        prepare(n, n);
        res = n;
        FOR(i, 1, n+1)
            FOR(j, 1, n+1)
                if (check(i, j)) Link(i, j);
        solve();
      //  Dance(0);
      //  pf("%d\n", res);
    }
    return 0;
}

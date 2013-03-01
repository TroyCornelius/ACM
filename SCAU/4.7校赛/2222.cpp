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
}cir[110];
int n, size, res, rr;
int U[mm], D[mm], L[mm], R[mm], C[mm], X[mm];
int H[mn], S[mn], ans[mn], Q[mn], rec[mn];
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
    memset(v, false, sizeof(v));
    int i, j, c, ret = 0;
    for (c = R[0]; c; c=R[c]) v[c] = true;
    for (c = R[0]; c; c= R[c])
        if (v[c]) {
            for (++ret, v[c] = 0, i=D[c]; i!=c; i=D[i])
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
void Dance(int k)
{
    if (k + f() > res) return;
    if (!R[0]) {
        if (k <= res)
        {
            res = k;
            memcpy(rec, Q, sizeof(Q));
        }
        return  ;
    }
    int i, j, c, tmp = mm;
    for (i=R[0]; i; i=R[i])
        if (S[i] < tmp)  tmp = S[c = i];
    for (i=D[c]; i!=c; i=D[i]) {
        Q[k] = i;
        remove(i);
        for (j=R[i]; j!=i; j=R[j]) remove(j);
        Dance(k+1);
        for (j=L[i]; j!=i; j=L[j]) resume(j);
        resume(i);
    }
    return ;
}
void Link(int r, int c) {
    ++S[C[++size] = c];
    X[size] = r;  //要输出方案这里记录一下
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
bool check(int x, int y) {
    double tx = (cir[x].x - cir[y].x), ty = cir[x].y - cir[y].y;
    return tx*tx+ty*ty <=rr * rr;
}
int main() 
{
    while (~sf("%d%d", &n, &rr))
    {
        FOR(i, 1, n+1) sf("%d%d", &cir[i].x, &cir[i].y);
        prepare(n, n);
        res = n;
        FOR(i, 1, n+1)
            FOR(j, 1, n+1)
                if (check(i, j)) Link(i, j);
        Dance(0);
        pf("%d\n", res);
        REP(i, res) pf("%d%c", X[rec[i]], i==res-1?'\n':' ');
    }
    return 0;
}

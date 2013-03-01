/*
 * Author:  Teletubbies
 * Created Time:  2012年09月20日 星期四 13时32分39秒
 * File Name: f.cpp
 */
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
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
#define maxn 210
int A, B, C, n;
vector<int> vec[maxn];
#define eps 1e-10
/*
void yue(int& _a, int& _b) {
    if(_a == 0) return;
    int _v = abs(__gcd(_a, _b));
    _a /= _v;
    _b /= _v;
}
struct Fraction{
    int fi,se;
    Fraction() {}
    Fraction(int _a, int _b) {
        fi = _a, se = _b;
    }
    Fraction operator/(const Fraction _b){
        Fraction ret;
        ret = Fraction(fi*_b.se, se*_b.fi);
        yue(ret.fi, ret.se);
        return ret;
    }
    Fraction operator*(const Fraction _b) {
        Fraction ret;
        ret = Fraction(fi*_b.fi, se*_b.se);
        yue(ret.fi, ret.se);
        return ret;
    }
    Fraction operator+(const Fraction _b) {
        Fraction ret;
        ret = Fraction(fi*_b.se+_b.fi*se, se*_b.se);
        yue(ret.fi, ret.se);
        return ret;
    }
    Fraction operator-(const Fraction _b) {
        Fraction ret;
        ret = Fraction(fi*_b.se-_b.fi*se, se*_b.se);
        yue(ret.fi, ret.se);
        return ret;
    }
    bool notZero() {
        return abs(fi) != 0;
    }
}a[maxn][maxn], c[maxn], x[maxn];


bool notZero(double x) {
    if(fabs(x) < eps) return false;
    return true;
}
*/
inline long long ABS(long long x) {
    return x >= 0 ? x : -x;
}

struct Fraction
{
    long long molec, denom;
    Fraction(){}
    Fraction(long long _molec, long long _denom)
    :molec(_molec), denom(_denom){}
    bool notZero(){
        return ABS(molec) != 0;
    }
    Fraction reduction(Fraction &b)
    {
        long long v = __gcd(ABS(b.molec), ABS(b.denom));
        if (v == 0) v = 1;
        return Fraction(b.molec/v, b.denom/v);
    }
    Fraction operator+(const Fraction &b)
    {
        Fraction ret(molec * b.denom + b.molec * denom, denom * b.denom);
        return reduction(ret);         
    }
    Fraction operator-(const Fraction &b)
    {
        Fraction ret(molec * b.denom - b.molec * denom, denom * b.denom);
        return reduction(ret);
    }
    Fraction operator*(const Fraction &b)
    {
        Fraction ret(molec * b.molec, denom * b.denom);
        return reduction(ret);
    }
    Fraction operator/(const Fraction &b)
    {
        Fraction ret(molec * b.denom, denom * b.molec);
        return reduction(ret);
    }
    bool operator<(const Fraction &b)
    {
        return molec * b.denom < b.molec * denom;
    }
    bool operator==(const Fraction &b)
    {
        return molec * b.denom == b.molec * denom;
    }
}a[maxn][maxn], c[maxn], x[maxn];


void gauss() {
    int curRow = 1, curCol = 1;
    for(; curCol <= n; curCol++) {
        int i, j;
        for(i = curRow; i <= n; i++) {
            if(a[i][curCol].notZero()) break;
        }
        if(i > n) continue;
        if(i != curRow) {
            for(j = curCol; j <= n; j++)
                swap(a[curRow][j], a[i][j]);
            swap(c[i], c[curRow]);
        }
        for(i = curRow + 1; i <= n; i++) {
            if(a[i][curCol].notZero()) {
                Fraction tmp = a[curRow][curCol];
                Fraction tmp1 = a[i][curCol];
                for(j = curCol; j <= n; j++) {
                    a[i][j] = ((a[i][j] * tmp) / tmp1) - a[curRow][j];
                }
                c[i] = ((c[i] * tmp) / tmp1) - c[curRow];
            }
        }
        curRow++;
    }
    for(int i = n; i; i--) {
        Fraction tmp = c[i];
        for(int j = i + 1; j <= n; j++) 
            tmp = tmp - (a[i][j] * x[j]);
        x[i] = tmp / a[i][i];
    }
}

int main() {
    //cout <<__gcd(-10, -5) <<endl;
    while(~scanf("%d", &n)) {
        scanf("%d%d%d", &A, &B, &C);
        for(int i = 1; i <= n; i++) {
            vec[i].clear();
        }
        int u, v;
        for(int i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            vec[u].pb(v);
            vec[v].pb(u);
        }
        for(int i = 1; i <= n+1; i++) {
            c[i] = Fraction(0, 1);
            x[i] = Fraction(0, 1);
            for(int j = 1; j <= n+1; j++) {
                a[i][j] = Fraction(0, 1);
            }
        }
        for(int i = 1; i <= n; i++) {
            if(i == B) {
                a[i][i] = Fraction(1, 1);
                c[i] = Fraction(1, 1);
            } else if(i == C) {
                a[i][i] = Fraction(1, 1);
                c[i] = Fraction(0, 1);
            } else {
                a[i][i] = Fraction((int)vec[i].size(), 1);
                c[i] = Fraction(0, 1);
                for(int j = 0; j < vec[i].size(); j++) {
                    int ii = vec[i][j];
                    a[i][ii] = Fraction(-1, 1);
                }
            }
        }
        gauss();
        double ans = (1.0 * x[A].molec / (double)x[A].denom);
        if (fabs(ans) < eps) ans = 0.0;
        printf("%.6f\n", ans);
    }
    return 0;
}


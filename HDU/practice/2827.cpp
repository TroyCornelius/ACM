/*
 * Author:  Troy
 * Created Time:  2012/8/17 15:26:07
 * File Name: 2827.cpp
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
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
#define Maxn 110
#define ll long long
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
ll mod;
ll b[Maxn][Maxn], a[Maxn][Maxn];
ll get_ni(ll num, int m) //费马小定理求num相对于m的逆元
{
    ll ret = 1, tmp = num;
    int tt = m - 2;
    while (tt) {
        if (tt & 1) ret = ret * num % m;
        num = num * num % m;
        tt >>=1;
    }
    return ret;
}
ll solve(int n, int m) //n阶行列式，mod = m
{
    bool flag = 0;
	ll ret = 1;
	REP(i, n)
		REP(j, n)
		b[i][j] = a[i][j];
	REP(i, n)
	{
        ll mx = b[i][i];
        int pp = i;
        FOR(j, i+1, n)            
           if (b[j][i] > mx) mx = b[j][i], pp = j;
        if (pp != i) {
            FOR(k, i, n) 
                swap(b[i][k], b[pp][k]);
            flag ^= 1;
        }
        ret = (ret * b[i][i] % m + m) % m;
        ll tmp = get_ni(b[i][i], m);
        FOR(k, i+1, n) b[i][k] = b[i][k] * tmp % m;
        FOR(j, i+1, n)
            FOR(k, i+1, n)
            {
                b[j][k] -= b[j][i] * b[i][k] % m;
                b[j][k] = (b[j][k] % m + m) % m;
            }
    }
    if (flag) ret = (m - ret) % m;
    return ret;
}
bool pri[10010];
int pn[10010], cnt_p;
void get_prime() {
    cnt_p = 0;
    memset(pri, true, sizeof(pri));
    for (int i = 2; i <= 10000; i++)
        if (pri[i]) {
            if (i > 1000) pn[cnt_p++] = i;
            for (int j = i*i; j <= 10000; j += i) pri[j] = false;
        }
}
int subpri[110], len; //subpri保存模数
void calc(ll num)
{
    len = 0;
    REP(i, cnt_p)
        if (num % pn[i] == 0) subpri[len++] = pn[i];
}
int rem[110]; //保存余数
void exgcd(ll a, ll b,ll &x, ll &y)
{
    if (b==0) {
        x=1, y=0;
    }
    else {
        exgcd(b,a%b,x,y);
        int k=a/b;
        k=x-k*y;
        x=y, y=k;
    }
    return;
}
ll china_remainder(int n)
{
    ll ret, m = 1, mid, x, y;
    REP(i, n) m *= subpri[i];
    ret = 0;
    REP(i, n) {
        mid = m / subpri[i];
        exgcd(mid, subpri[i], x, y);
        ret = (ret + mid * x * rem[i]) % m;
    }
    if (ret < 0) ret += m;
    return ret;
}
int main() 
{
    int n;
    get_prime();
    while (~sf("%d%I64d", &n, &mod))
    {
        REP(i, n)
            REP(j, n) 
                sf("%I64d", &a[i][j]);
        if (mod == 1) pf("0\n");
        else {
            calc(mod);
            REP(i, len) rem[i] = solve(n, subpri[i]);
            pf("%I64d\n", china_remainder(len));
        }
    }
    return 0;
}

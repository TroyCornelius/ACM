/*
 * Author:  Troy
 * Created Time:  2012/3/30 19:03:35
 * File Name: c.cpp
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
#define Maxn 2000100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const int mod = 1000000;
int f[Maxn];
void init()
{
    f[0] = 1;
    FOR(i, 1, 2000001)
    {
        if (i&1) f[i] = f[i-1];
        else f[i] = f[i-1] + f[i/2];
        if (f[i] >= mod) f[i] -= mod;
    }
}
int main() 
{
    init();
    int T, n;
    sf("%d", &T);
    while (T--)
    {
        sf("%d", &n);
        pf("%d\n", f[n]);
    }
    return 0;
}


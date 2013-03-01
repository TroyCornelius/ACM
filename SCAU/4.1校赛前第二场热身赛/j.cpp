/*
 * Author:  Troy
 * Created Time:  2012/4/1 21:19:30
 * File Name: j.cpp
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
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>

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

int n, m;
int f[40][40];
int main() 
{
    int u, v, ca = 0;
    while (~sf("%d", &m))
    {
        memset(f, 0, sizeof(f));
        n = 0;
        REP(i, m)
        {
            sf("%d%d", &u, &v);
            f[u][v] = 1;
            n = max(n, max(u, v));
        }
        n++;
        REP(k, n)
            REP(i, n)
                REP(j, n)
                    f[i][j] += f[i][k] * f[k][j];
        REP(k, n)
            if (f[k][k])
            {
                REP(i, n)
                    REP(j, n)
                        if (f[i][k] && f[k][j]) f[i][j] = -1;
            }
        pf("matrix for city %d\n", ca++);
        REP(i, n){
            pf(" ");
            REP(j, n)
                pf("%d%c", f[i][j], j==n-1?'\n':' ');
            }

        
    }
    return 0;
}


/*
 * Author:  Troy
 * Created Time:  2012/4/1 19:03:35
 * File Name: a.cpp
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n;
long long f[65][65][65];

void init()
{
    memset(f, 0, sizeof(f));
    f[0][0][0] = 1;
    REP(i, 61)
        REP(j, 61)
            REP(k, 61)
            {
                if (!i && !j && !k) continue;
                if (i >= j && j >= k)
                {
                    if (i-1 >= 0 && i-1 >= j ) f[i][j][k] += f[i-1][j][k];
                    if (j-1 >= 0 && j-1 >= k ) f[i][j][k] += f[i][j-1][k];
                    if (k-1 >= 0) f[i][j][k] += f[i][j][k-1];
                }                
            }
}
int main() 
{
    init();
    while (sf("%d", &n))
    {
        cout <<f[n][n][n] <<endl;
    }
    return 0;
}


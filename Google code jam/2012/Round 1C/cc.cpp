/*
 * Author:  Troy
 * Created Time:  2012/5/6 17:03:24
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
typedef pair<long long,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
pii box[110], toy[110];
long long dp[110][110];

void combine(pii a[], int k)
{
    int p = 1;
    FOR(i, 1, k)
    {
        if (a[i+1].se != a[p].se) 
        {
            a[++p] = a[i+1];
        }
        else
        {
            a[p].fi += a[i+1].fi;
        }
    }
    k = p;
    return;
}

inline long long MIN(long long a, long long b)
{
    return a < b ? a : b;
}
int main() 
{
    ios::sync_with_stdio(false);
    int T, ca = 0;
    cin >>T;
    while (T--)
    {
        cin >>n >>m;
        FOR(i, 1, n+1)
            cin >>box[i].fi >>box[i].se;
        FOR(i, 1, m+1)
            cin >>toy[i].fi >>toy[i].se;
        
        memset(dp, 0, sizeof(dp));
        combine(box, n);
        combine(toy, m);
        
        box[0] = mp(0, -1);
        toy[0] = mp(0, -1);
        
        FOR(i, 1, n+1)
            FOR(j, 1, m+1)
            {
                
            }

        
        cout <<"Case #" <<++ca <<": " <<dp[n][m] <<endl;
    }
    return 0;
}


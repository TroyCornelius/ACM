/*
 * Author:  Troy
 * Created Time:  2012/3/17 0:19:43
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
pii p[210];
int n, ans;
int main() 
{
    ans = 0;
    cin >>n;
    REP(i, n)
        cin >>p[i].fi >>p[i].se;
    int cnt;
    REP(i, n)
    {
        cnt = 0;
        REP(j, n)
            if (i!=j)
            {
                if (p[j].fi == p[i].fi)
                {
                    if (p[j].se > p[i].se) cnt |= (1 << 0);
                    else cnt |= (1 << 1);
                }
                else
                if (p[j].se == p[i].se)
                {
                    if (p[j].fi > p[i].fi) cnt |= (1<<2);
                    else cnt |= (1<<3);
                }
            }
        if (cnt == 15) ans++;
    }
    cout <<ans <<endl;
    return 0;
}


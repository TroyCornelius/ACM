/*
 * Author:  Troy
 * Created Time:  2012/2/20 23:39:44
 * File Name: d.cpp
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
#define Maxn 1010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, tot;
int g[1010][1010], sx[Maxn][Maxn], sy[Maxn][Maxn];
pair<pii, pii> ans[2];
void print()
{
    cout <<"YES" <<endl;
    cout <<ans[0].fi.fi <<" "<<ans[0].fi.se <<" " <<ans[0].se.fi <<" "<<ans[0].se.se <<endl;
    cout <<ans[1].fi.fi <<" "<<ans[1].fi.se <<" " <<ans[1].se.fi <<" "<<ans[1].se.se <<endl;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin >>n >>m;
    char ch;
    FOR(i, 1, n+1)
        FOR(j, 1, m+1)
        {
            cin >>ch;
            g[i][j] = (ch == '#'?1:0);
            sx[i][j] = sx[i-1][j] + g[i][j];
            sy[i][j] = sy[i][j-1] + g[i][j];
        }
    tot = 0;
    FOR(x, 1, n-1)
        FOR(y, 1, m-1)
        {
            FORD(i, n, x+2)
            {
                if (sx[i][y] - sx[x-1][y] != (i-x+1)) break;
                FOR(j, y+2, m+1)
                {
                    if ((sy[i][j] - sy[i][y-1] != (j - y + 1)) || (sy[x][j] - sy[x][y-1] != (j-y+1))) break;
                    if (sx[i][j] - sx[x-1][j] == (i-x+1))
                    {
                        ans[tot++] = mp(mp(x, y), mp(i, j));
                    }
                    if (tot >= 2)
                    {
                        print();
                        return 0;
                    }
                }
            }
        }
    cout <<"NO" <<endl;
    return 0;
}


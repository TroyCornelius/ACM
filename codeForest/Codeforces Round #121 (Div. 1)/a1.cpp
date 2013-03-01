/*
 * Author:  Troy
 * Created Time:  2012/6/4 20:53:57
 * File Name: a1.cpp
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

int n, dp[50][50];
string s;

int main() 
{
    ios::sync_with_stdio(false);
    cin >>n;
    memset(dp, 0, sizeof(dp));
    REP(i, n)
    {
        cin >>s;
        int p1 = s[0] - 'a', p2 = s[s.size()-1] - 'a';
        REP(x, 26)
            if (dp[x][p1] > 0) dp[x][p2] = max(dp[x][p2], dp[x][p1] + (int)s.size());
        dp[p1][p2] = max(dp[p1][p2], (int)s.size());
        //REP(j, 26) cout <<dp[j][j] <<" ";
        //cout <<s <<" " <<p1 <<" "<<p2 <<endl;
    }
    int ans = 0;
    REP(i, 26) ans = max(ans, dp[i][i]);
    cout <<ans <<endl;
    return 0;
}


/*
 * Author:  Troy
 * Created Time:  2012/11/20 1:02:41
 * File Name: h.cpp
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
#define ll long long
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int q, n;
#define Maxn 5010
char s[Maxn];
int dp[Maxn][Maxn];
/*
void pk()   
{
    int id, mx=0;
    for (int i=1; i<n; i++)  
    {
        p[i] = mx>i ? min(p[2*id-i], mx-i):1;
        while (str[i+p[i]] == str[i-p[i]]) p[i]++;
        if (p[i]+i > mx)
        {
            mx = p[i]+i;
            id = i;                    
        } 
    }
}
void init()
{
    n = strlen(s);
    str[0]='$'; str[1] = '#'; 
    for (int i=0; i<n; i++)
    {
        str[i*2+2] = s[i];
        str[i*2+3] = '#';          
    }
    n = n*2+2;
    str[n] = 0;     
}
*/
void calc(int x, int y) {
    while (x >= 0 && y < n && s[x] == s[y])
        dp[x][y]++, x--, y++;
}
void init() {
    n = strlen(s);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n-1; i++)
        calc(i, i+1);
    for (int i = 0; i < n; i++)
        calc(i, i);
    
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) {
            dp[i][j] += dp[i][j-1];
        }
    for (int i = n-1; i >= 0; i--)
        for (int j = i+1; j < n; j++)
            dp[i][j] += dp[i+1][j];
}
int main() {
    while (~sf("%s", s)) {
        init();
        //for (int i = 1; i <= n; i++) cout <<p[i] - 1 <<" ";
        int l, r;
        sf("%d", &q);
        while (q--) {
            sf("%d%d", &l, &r);
            l--;
            r--;
            pf("%d\n", dp[l][r]);
        }
    }
    return 0;
}


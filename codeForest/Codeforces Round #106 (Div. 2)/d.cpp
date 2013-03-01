/*
 * Author:  Troy
 * Created Time:  2012/2/10 23:40:46
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
#define REP(i,b) FOR(i,0,b)
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const long long MOD = 1000000007;


string s;
long long dp[710][710][3][3], ans;
int n, next[710];

long long dfs(int x, int y, int c1, int c2)
{
    long long &ret = dp[x][y][c1][c2];
    if (ret != -1) return ret;
    ret = 0;
    if (x + 1 == y) 
    {
        ret = ((c1==0 && c2>0) || (c2==0 && c1>0))?1:0;
        return ret;
    }
    if (next[x] == y)
    {
        if ((c1==0 && c2==0) || (c1>0 && c2>0)) return ret;
        REP(i, 3)
            REP(j, 3)
            if ((c1==0 && j!=c2) || (c2==0 && i!=c1))
            {
                ret += dfs(x+1, y-1, i, j);
            }
    }
    else
    {
        REP(i, 3)
            REP(j, 3)
            if (!i || !j || i != j)
            {
                ret += dfs(x, next[x], c1, i) * dfs(next[x]+1, y, j, c2) %  MOD;
            }
    }
    ret %= MOD;
    return ret;    
}
int main() 
{
    cin >>s;
    memset(dp, -1, sizeof(dp));
    n = s.length();
    stack<int> st;
    FOR(i, 0, s.length())
    {
        if (s[i] == '(') st.push(i);
        else 
        {
            next[st.top()] = i;
            next[i] = st.top();
            st.pop();
        }
    }    
    ans = 0;
    REP(i, 3)
        REP(j, 3)
            ans += dfs(0, n-1, i, j);
    cout <<ans%MOD <<endl;
    
    return 0;
}


/*
 * Author:  Troy
 * Created Time:  2012/8/4 19:44:05
 * File Name: k.cpp
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
#define Maxn 1110
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, dp[Maxn][Maxn], ans;
int next[Maxn];
char s1[Maxn], s2[Maxn];
void get_next()
{
    memset(next, 0, sizeof(next));
    next[0] = -1;
    int k = -1, i = 0;
    while (i < m)
    {
        if (k == -1 || s2[i] == s2[k])
        {
            i++; k++;next[i] = k;
        }
        else k = next[k];
    }
}
int main() 
{
    while (~sf("%s%s", s1, s2))
    {
        n = strlen(s1);
        m = strlen(s2);
        get_next();
        ans = 0;
        //cout <<s2 <<endl;
        //REP(i, m+1) cout <<next[i] <<" ";
        //cout <<endl;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0;
        REP(i, n)
            REP(j, m+1)
            {
                if (dp[i][j] == -1) continue;
                if (s1[i] == '?')
                {
                    //s1[i] == s2[j]
                    int p = j + 1;
                    dp[i+1][p] = max(dp[i+1][p], dp[i][j] + (p == m ? 1 : 0));
                    //s1[i] != s2[j]
                    p = next[i+1];
                    dp[i+1][p] = max(dp[i+1][p], dp[i][j] + (p == m ? 1 : 0));
                }
                else
                {
                    int p = (s1[i] == s2[j] ? j+1 : next[i+1]);
                    dp[i+1][p] = max(dp[i+1][p], dp[i][j] + (p == m ? 1 : 0));
                }
                
            }
        
        ans = *max_element(dp[n], dp[n]+m+2);
        pf("%d\n", ans);
        
    }
    return 0;
}


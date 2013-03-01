/*
 * Author:  Troy
 * Created Time:  2012/3/30 19:27:04
 * File Name: 
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int s, n;
struct baggage
{
    int v, a, b;
    bool operator<(const baggage &t)const
    {
        return b > t.b;
    }
}d[110];
int dp[1100];
int main() 
{
    int T;
    sf("%d", &T);
    while (T--)
    {
        sf("%d%d", &s, &n);
        REP(i, n) sf("%d%d%d", &d[i].v, &d[i].a, &d[i].b);
        memset(dp, -1, sizeof(dp));
        sort(d, d+n);
        
        dp[s] = 0;
        REP(i, n)
        {
            FOR(j, d[i].a, s+1)
            if (dp[j] != -1)
            {
                int t = j - d[i].a + d[i].b;
                dp[t] = max(dp[t], dp[j] + d[i].v);
            }
        }      
        pf("%d\n", *max_element(dp, dp+s+1));
    }
    return 0;
}


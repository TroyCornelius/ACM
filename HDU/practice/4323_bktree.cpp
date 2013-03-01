/*
 * Author:  Troy
 * Created Time:  2012/8/1 23:51:23
 * File Name: 4323_bktree.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <cctype>
#include <functional>

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

struct Tnode
{
    char s[12];
    int next[12];
    void clr(){memset(next, -1, sizeof(next));}
}t[1510];
int n, m, root, tot, threshold;
char str[12];
int calc(char *s1, char *s2)
{
    int dp[12][12];
    memset(dp, 0, sizeof(dp));
    int len1 = strlen(s1), len2 = strlen(s2);
    REP(i, len1+1) dp[i][0] = i;
    REP(i, len2+1) dp[0][i] = i;
    FOR(i, 1, len1+1)
        FOR(j, 1, len2+1)
        dp[i][j] = min(dp[i-1][j-1] + (s1[i-1] == s2[j-1] ? 0 : 1), min(dp[i-1][j] + 1, dp[i][j-1] + 1));
    return dp[len1][len2];
}
void insert(int rt, char *st)
{
    int dis = calc(t[rt].s, st);
    if (t[rt].next[dis] == -1) {
        t[rt].next[dis] = ++tot;
        strcpy(t[tot].s, st);
        t[tot].clr();
    }
    else insert(t[rt].next[dis], st);
}
int cnt(int rt, char *st)
{
    int ret = 0;
    int dis = calc(t[rt].s, st);
    if (dis <= threshold) ret++;
    FOR(i, max(0, dis-threshold), min(10, dis+threshold)+1)
        if (t[rt].next[i] != -1) ret += cnt(t[rt].next[i], st);
    return ret;
}

int main() 
{
    int T, ca = 0;
    sf("%d", &T);
    while (T--)
    {
        sf("%d%d", &n, &m);
        root = tot = 0;
        t[root].clr();
        sf("%s", str);
        strcpy(t[root].s, str);
        REP(i, n-1) {
            sf("%s", str);
            insert(root, str);
        }
        pf("Case #%d:\n", ++ca);
        while (m--) {
            sf("%s%d", str, &threshold);
            pf("%d\n", cnt(root, str));            
        }
    }
    return 0;
}


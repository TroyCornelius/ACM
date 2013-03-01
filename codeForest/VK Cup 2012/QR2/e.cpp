/*
 * Author:  Troy
 * Created Time:  2012/3/10 11:08:55
 * File Name: e.cpp
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
#define Maxn 200010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<long long,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n;
struct Tnode
{
    int ci, si, id;
    bool operator<(const Tnode &b)const
    {
        return (ci < b.ci || (ci == b.ci && si > b.si));
    }
}cub[Maxn];

pii cnt[Maxn][2];
void check(int len, long long s, int loc)
{
    if (s > cnt[len][0].fi)
    {
        cnt[len][1] = cnt[len][0];
        cnt[len][0] = mp(s, loc);
    }
    else
    if (s > cnt[len][1].fi)
    {
        cnt[len][1] = mp(s, loc);
    }
}
void print_cnt(int x, int y)
{
    int ret = 0;
    FORD(i, x, 0)
        if (cub[i].ci == cub[x].ci) ret++;
    FORD(i, y, 0)
        if (cub[i].ci == cub[y].ci) ret++;
    printf("%d\n", ret);
}
void print_col(int x, int y)
{
    vi a, b, op;
    FORD(i, x, 0)
        if (cub[i].ci == cub[x].ci) a.pb(cub[i].id);
    FORD(i, y, 0)
        if (cub[i].ci == cub[y].ci) b.pb(cub[i].id);
    if (a.size() < b.size()) swap(a, b);
    int i = 0;
    for (; i<b.size(); i++) 
    {
        op.pb(a[i]);
        op.pb(b[i]);
    }
    if (i < a.size()) op.pb(a[i]);
    REP(i, op.size())
    {
        if (i) printf(" ");
        printf("%d", op[i]);
    }
    printf("\n");
}
int main() 
{
    scanf("%d", &n);
    REP(i, n)
    {
        scanf("%d%d", &cub[i].ci, &cub[i].si);
        cub[i].id = i+1;
    }
    sort(cub, cub+n);
    REP(i, n+1) cnt[i][0] = cnt[i][1] = mp(-1, -1);
    int i = 0, len = 0, j;
    long long sum = 0;
    while (i < n)
    {
        j = i;
        sum = 0; len = 0;
        while (j < n && cub[i].ci == cub[j].ci)
        {
            sum += cub[j].si;
            len++;
            check(len, sum, j);
            j++;
        }
        i = j;
    }
    
    long long ans = 0, c1, c2;
    FOR(i, 1, n+1)
    if (cnt[i][0].fi != -1)
    {
        if (cnt[i][1].fi != -1)
        {
            long long tmp = cnt[i][0].fi + cnt[i][1].fi;
            if (tmp > ans)
            {
                ans = tmp;
                c1 = cnt[i][0].se;
                c2 = cnt[i][1].se;
            }
        }
        if (i + 1 <= n && cnt[i+1][0].fi != -1 && cub[cnt[i+1][0].se].ci != cub[cnt[i][0].se].ci)
        {
            long long tmp = cnt[i][0].fi + cnt[i+1][0].fi;
            if (tmp > ans)
            {
                ans = tmp;
                c1 = cnt[i][0].se;
                c2 = cnt[i+1][0].se;
            }
        }
        else
        if (i + 1 <= n && cnt[i][1].fi != -1 && cnt[i+1][0].fi != -1 && cub[cnt[i+1][0].se].ci != cub[cnt[i][1].se].ci)
        {
            long long tmp = cnt[i][1].fi + cnt[i+1][0].fi;
            if (tmp > ans)
            {
                ans = tmp;
                c1 = cnt[i][1].se;
                c2 = cnt[i+1][0].se;
            }
        }
    
    }
    
    printf("%d\n", ans);
    print_cnt(c1, c2);
    print_col(c1, c2);
    
    return 0;
}


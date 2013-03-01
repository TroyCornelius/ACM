/*
 * Author:  Troy
 * Created Time:  2012/2/10 23:20:30
 * File Name: c.cpp
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
#define Maxn 100100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
int n;
pii d[Maxn];
vi ta, tb;
bool cmp(pii a, pii b)
{
    return a.fi > b.fi;
}
void print(vi ans)
{
    printf("%d\n", ans.size());
    REP(i, ans.size())
    {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}
int main() 
{
    scanf("%d", &n);
    FOR(i, 1, n+1)
    {
        scanf("%d", &d[i].fi);
        d[i].se = i;
    }
    int sa = 0, sb = 0;
    sort(d+1, d+n+1, cmp);
    int i = 1;
    while (i <= n)
    {
        if (sa < sb)
        {
            ta.pb(d[i].se);
            sa += d[i].fi;
            i++;
            if (i <= n)
            {
                tb.pb(d[i].se);
                sb += d[i].fi;
                i++;
            }
        }
        else
        {
            tb.pb(d[i].se); sb += d[i].fi; i++;
            if (i <= n)
            {
                ta.pb(d[i].se);
                sa += d[i].fi;
                i++;
            }
        }
    }
    
    print(ta);
    print(tb);
    
    return 0;
}


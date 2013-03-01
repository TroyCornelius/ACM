/*
 * Author:  Troy
 * Created Time:  2012/5/18 22:25:56
 * File Name: f.cpp
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
#define Maxn 10060
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, t, c, e;
struct Person
{
    int a, d, f, id;
    bool operator<(const Person &b) const
    {
        return (d < b.d) || (d == b.d && a > b.a);
    }
}p[60];

char ans[Maxn][50];
char calc(int x)
{
    if (x < 26) return (char)('a'+x);
    else return (char)('A' + x - 26);
}
bool work()
{
    sort(p, p+n);
    int ct;    
    FOR(i, 1, e+1)
    {
        ct = 0;
        REP(j, n)
            if (p[j].d <= i && p[j].f > 0) return false;
            else
            if (p[j].d > i && p[j].a <= i && p[j].f > 0)
            {
                ans[i][ct++] = calc(p[j].id);                
                p[j].f--;
                if (ct >= t * c) break;
            }          
        while (ct < t * c) ans[i][ct++] = '.';
    }    
    //REP(j, n)
        //if (p[j].f > 0) return false;
    return true;
}
int main() 
{
    int T, ca = 0;
    sf("%d", &T);
    while (T--)
    {
        sf("%d%d%d%d", &n, &t, &c, &e);
        REP(i, n)
        {
            sf("%d%d%d", &p[i].a, &p[i].d, &p[i].f);
            p[i].id = i;
        }
        bool flag = work();
        if (!flag) pf("Case %d: No\n", ++ca);
        else
        {
            pf("Case %d: Yes\n", ++ca);
            FOR(k, 1, e)
            {
                for (int i = 0; i < t*c; i += c)
                {
                    REP(j, c) pf("%c", ans[k][i+j]);
                    if (i + c == t * c) pf("\n");
                    else pf("|");                    
                }
            }
        }
    }
    return 0;
}


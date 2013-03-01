/*
 * Author:  Troy
 * Created Time:  2012/5/18 19:47:35
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
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
#define Maxn 100010000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int t[Maxn];
int n, q;

void add(int idx, int val)
{
    for (;idx<=n;idx+=idx&-idx) t[idx]+=val;
}
int sum(int idx)
{
    int ret=0;
    for (;idx;idx-=idx&-idx) ret += t[idx];
    return ret;
}
int main() 
{
    int T, ca = 0, a, b;
    sf("%d", &T);
    while (T--)
    {
        sf("%d%d", &n, &q);
        memset(t, 0, sizeof(t));
        REP(i, n)
        {
            sf("%d", &a);
            add(i+1, a);
        }
        int op, tmp;
        pf("Case %d:\n", ++ca);
        while (q--)
        {
            sf("%d", &op);
            if (op == 1)
            {
                sf("%d", &a);
                a++;
                tmp = sum(a) - sum(a-1);
                add(a, -tmp);
                pf("%d\n", tmp);                
            }
            else if (op == 2)
            {
                sf("%d%d", &a, &b);
                add(a+1, b);
            }
            else if (op == 3)
            {
                sf("%d%d", &a, &b);
                pf("%d\n", sum(b+1) - sum(a));
            }
        }
    }
    return 0;
}


/*
 * Author:  Troy
 * Created Time:  2012/6/11 0:23:41
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

int n;
struct Tnode
{
    double k, b;
    double x;
}d[Maxn];

bool cmp(Tnode a, Tnode c)
{
    return a.x < c.x;
}
int main() 
{
    while (~sf("%d", &n))
    {
        REP(i, n) 
        {
            sf("%lf%lf", &d[i].k, &d[i].b);
            if (d[i].k != 0) d[i].x = d[i].b / d[i].k;
        }
        sort(d, d+m, cmp);
        
    }
    return 0;
}


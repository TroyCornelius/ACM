/*
 * Author:  Troy
 * Created Time:  2012/4/6 13:00:25
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
int d[1010][7];
int get_sum(int tar)
{
    int ret = 0;
    tar--;
    REP(i, n) ret += d[i][tar];
    return ret;
}
int get_avg(int tar)
{
    int sum = get_sum(tar);
    double tmp = (double)sum / (double)n;
    tmp += 0.5;
    return (int)tmp;
}
int query_max(int tar)
{
    int ret = 0;
    tar--;
    REP(i, n) ret = max(ret, d[i][tar]);
    return ret;
}
int query_min(int tar)
{
    int ret = 101;
    tar--;
    REP(i, n) ret = min(ret, d[i][tar]);
    return ret;
}
int main() 
{
    int T, tar;
    char op[5];
    sf("%d", &T);
    while (T--)
    {
        sf("%d", &n);
        REP(i, n) 
            REP(j, 6) sf("%d", &d[i][j]);
        sf("%d", &m);
        while (m--)
        {
            sf("%s", op);
            sf("%d", &tar);
            if (op[0] == 's') pf("%d\n", get_sum(tar));
            else
            if (op[0] == 'a') pf("%d\n", get_avg(tar));
            else
            if (op[1] == 'a') pf("%d\n", query_max(tar));
            else pf("%d\n", query_min(tar));
        }
    }
    return 0;
}


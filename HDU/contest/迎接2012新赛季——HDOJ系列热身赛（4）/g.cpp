/*
 * Author:  Troy
 * Created Time:  2012/4/3 12:35:16
 * File Name: g.cpp
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

int sg[10000], k;
int f[1001][2];
int dfs(int n, int who)
{
    if (f[n][who] != -1) return f[n][who];
    if (n == 0) return f[n][who] = (who == 1?false:true);
    bool flag = false;
    int t = 1;
    while (t <= n)
    {
        flag |= dfs(n - t, 1 - who);
        t *= k;
    }
    return f[n][who] = (who == 1?flag:!flag);
}
int main() 
{
    memset(f, -1, sizeof(f));
    //sg[0] = 0;
    k = 2;
    FOR(i, 1, 101)
    {
        dfs(i, 1);
        cout <<i <<" : " <<f[i][1]<<endl;
    }
    return 0;
}


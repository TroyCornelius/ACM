/*
 * Author:  Troy
 * Created Time:  2012/4/15 15:02:30
 * File Name: b.cpp
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
#define Maxn 20050
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
int cost[Maxn];
long long sum[Maxn];
long long dp[Maxn], ans;
struct Tnode
{
    int le,ri,val;
    bool operator<(const Tnode &b)const
    {
        return ri < b.ri;
    }
}a[Maxn];
int main() 
{
    while (~sf("%d%d", &n, &m))
    {
        sum[0] = 0;
        a[0].le = a[0].ri = a[0].val = 0;
        FOR(i, 1, n+1) 
        {
            sf("%d", &cost[i]);
            sum[i] = sum[i-1] + cost[i];
        }
        FOR(i, 1, n+1)
        {
            sf("%d%d%d", &a[i].le, &a[i].ri, &a[i].val);
        }
        sort(a+1, a+n+1);
        ans = 0;
        
        
        
    }
    
    
    return 0;
}


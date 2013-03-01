/*
 * Author:  Troy
 * Created Time:  2012/6/15 20:33:39
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
#define Maxn 200100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, N;
int t[Maxn], hash[Maxn];

void add(int idx, int val)
{
    for (;idx<=N;idx+=idx&-idx) t[idx] += val;    
}
int query(int idx)
{
    int ret = 0;
    for (;idx;idx-=idx&-idx) ret += t[idx];
    return ret;
}
int main() 
{
    int T;
    sf("%d", &T);
    while (T--)
    {
        sf("%d%d", &n, &m);
        memset(t, 0, sizeof(t));
        N = n + m + 10;
        FOR(i, 1, n+1)
        {
            hash[i] = i+m;
            add(hash[i], 1);
        }
        int num, ans, p = m;
        REP(i, m)
        {
            sf("%d", &num);
            ans = query(hash[num]-1);
            pf("%d%c", ans, i == m-1 ? '\n' : ' ');
            add(hash[num], -1);
            hash[num] = p--;
            add(hash[num], 1);
        }
    }
    
    return 0;
}


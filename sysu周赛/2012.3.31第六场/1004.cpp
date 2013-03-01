/*
 * Author:  Troy
 * Created Time:  2012/3/31 19:18:28
 * File Name: 1004.cpp
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
#define Maxn 100100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

const long long mod = 12345678910LL;
stack<int>st;
int n, a[Maxn], next[Maxn];
long long ans;
long long dfs(int le, int ri)
{
    long long ret = 0;
    if (le + 1 == ri) return 1;
    else
    {
        int p = le;
        while (p < ri)
        {
            if (p + 1 == next[p]) ret += dfs(p, next[p]);
            else ret += 2LL * dfs(p+1, next[p]-1);
            p = next[p] + 1;
            ret %= mod;
        }
    }
    return ret % mod;
}
int main() 
{
    while (~sf("%d", &n))
    {
        REP(i, n) sf("%d", &a[i]);
        while (!st.empty()) st.pop();
        REP(i, n)
            if (a[i] == 0) st.push(i);
            else
            {
                next[i] = st.top(); next[st.top()] = i;
                st.pop();
            }
        ans = dfs(0, n-1);
        cout <<ans <<endl;
        
    }
    return 0;
}


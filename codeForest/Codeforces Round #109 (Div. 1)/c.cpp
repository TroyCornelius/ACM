/*
 * Author:  Troy
 * Created Time:  2012/2/28 21:43:39
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
#define Maxn 1000010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
typedef unsigned long long ull;

int n, m;
ull c[Maxn], hash[Maxn];
long long ans;
pii edge[Maxn];
int main() 
{
    ios::sync_with_stdio(false);
    cin >>n >>m;
    c[0] = 1;
    FOR(i, 1, n+1) c[i] = c[i-1] * 31;
    memset(hash, 0, sizeof(hash));
    int x, y;
    REP(i, m)
    {
        cin >>x >>y;
        x--; y--;
        hash[x] += c[y]; hash[y] += c[x];
        edge[i] = mp(x, y);
    }
    
    ans = 0;
    REP(i, m)
    {
        int u = edge[i].fi, v = edge[i].se;
        if (hash[u] + c[u] == hash[v] + c[v]) ans++;
    }    
    sort(hash, hash+n);
    long long now = 0;
    REP(i, n)
    {
        if (!i || hash[i] == hash[i-1]) now++;
        else
        {
            ans += now * (now - 1) / 2;
            now = 1;
        }
    }
    ans += now * (now - 1) / 2;
    cout <<ans <<endl;
    
    return 0;
}


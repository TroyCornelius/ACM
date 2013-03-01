/*
 * Author:  Troy
 * Created Time:  2012/4/8 15:21:39
 * File Name: a.cpp
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
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int st;
int a[Maxn], n, s, w;
int t[Maxn];
long long ans;
vi b;
int main() 
{
    int T;
    sf("%d", &T);
    while (T--)
    {
        sf("%d%d%d", &n, &s, &w);
        int g = s;
        REP(i, n)
        {
            a[i] = g;
            if (a[i] == 0) a[i] = g = w;
            if (g%2 == 0) g /= 2;
            else g = (g/2) ^ w;
        }
        //REP(i, n) cout <<a[i] <<" ";
        //cout <<endl;
        st = 0;
        //REP(i, n) st ^= a[i];
        b.clear();
        b.pb(0);
        REP(i, n)
        {
            st ^= a[i];
            b.pb(st);
        }
        sort(all(b));
        vit en = unique(all(b));
        memset(t, 0, sizeof(t));
        ans = 0;
        int sum = 0, p;
        st = 0;
        REP(i, n)
        {
            st ^= a[i];
            ans += i+1;
            if (st == 0) ans--;
            p = lower_bound(b.begin(), en, st) - b.begin();
            ans -= t[p];
            t[p]++;
        }
        //pf("%d\n", ans);
        cout <<ans <<endl;
    }
    
    return 0;
}


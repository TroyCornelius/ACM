/*
 * Author:  Troy
 * Created Time:  2012/4/6 13:17:07
 * File Name: i.cpp
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
#define Maxn 100050
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int ans, m, n;
int d[Maxn], q[Maxn];
inline bool check(int p, int num)
{
    return d[q[p]] > d[num];
}
int calc(int num)
{
    int lo = 0, hi = m-1, mid=0;
    while (lo+1 < hi)
    {
        //cout <<q[mid] << " "<<num <<" "<<lo <<" "<<hi <<endl;
        mid = (lo + hi)/2;
        if (check(mid, num)) hi = mid;
        else lo = mid;
    }
    if (check(lo, num)) return q[lo];
    else if (check(mid, num)) return q[mid];
    else return q[hi];
}
int main() 
{
    freopen("i.in", "r", stdin);
    int st = clock();
    int T, ca = 0;
    sf("%d", &T);
    while (T--)
    {
        sf("%d", &n);
        REP(i, n) sf("%d", &d[i]);
        m = 0;
        q[m++] = n-1;
        FORD(i, n-1, 0)
            if (d[i] > d[q[m-1]]) q[m++] = i;
        ans = 1;
        //cout <<m <<endl;
        REP(i, n)
        {
            if (m-1 >= 0 && q[m-1] == i) {m--;continue;}
            if (m == 0) break;
            int tmp = calc(i);
            if (tmp - i + 1 > ans) ans = tmp - i + 1;
            //cout <<tmp <<" " <<i <<endl;
        }
        pf("Case %d: %d\n", ++ca, ans);
        
    }
    cout <<clock() - st <<endl;
    return 0;
}


/*
 * Author:  Troy
 * Created Time:  2012/4/8 16:46:30
 * File Name: 
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


long long s, t, a, b, ans;
inline long long ABS(long long x)
{
    return x >= 0 ? x : -x;
}
int main() 
{
    ios::sync_with_stdio(false);
    int T;
    cin >>T;
    while (T--)
    {
        cin >>s >>t >>a >>b;
        ans += ABS(s - t) / (a + b);
        long long len = ABS(s - t) % (a + b);
        if (len == 0) cout <<ans <<endl;
        else
        {
            if (s > t) s = t + len;
            else s = t - len;
            //cout <<s <<" "<<ans <<" " <<t <<endl;
            long long c = a + b;
            int tmp, mi = 10000;
            int p1 = s < t?0:-25, p2 = s < t?26:1;
            FOR(i, -25, 26)
                FOR(j, -25, 26)
                    FOR(k, p1, p2)
                    if (s + 1LL*i*a + 1LL*j*b + 1LL*c * k == t)
                    {
                        tmp = abs(i) + abs(j) + abs(k);
                        mi = min(mi, tmp);
                    }
            if (mi != 10000) ans += mi;
            else ans = -1;
        }
        cout <<ans <<endl;
        
        
    }
    
    return 0;
}


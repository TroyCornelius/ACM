/*
 * Author:  Troy
 * Created Time:  2012/4/14 10:29:52
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, s, p, a[110];
int ans;

int main() 
{
   //freopen("B-large.in", "r", stdin);
    //freopen("B-large.out", "w", stdout);
    int T, ca = 0;
    cin >>T;
    while (T--)
    {
        cin >>n >>s >>p;
        REP(i, n) cin >>a[i];
        ans = 0;
        int tot = 0;
        REP(i, n)
        {
            if (a[i] % 3 == 0)
            {
                int tmp = a[i] / 3;
                if (tmp >= p) ans++;
                else if (a[i] != 0 && tmp + 1 >= p) tot++;
            }
            else
                if (a[i] % 3 == 1)
                {
                    int tmp = (a[i] - 1) / 3;
                    if (tmp + 1 >= p) ans++;
                }
                else if (a[i] % 3 == 2)
                {
                    int tmp = (a[i] + 1) / 3;
                    if (tmp >= p) ans++;
                    else if (tmp + 1 >= p) tot++;
                }
        }
        ans += min(tot, s);
        cout <<"Case #" <<++ca <<": " <<ans <<endl;
    }
    return 0;
}


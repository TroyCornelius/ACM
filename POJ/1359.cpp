/*
 * Author:  Troy
 * Created Time:  2012/3/10 20:11:42
 * File Name: 1359.cpp
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, tot, ans;
struct Tnode
{
    int id, num;
    int ca, cb;
    bool ra, rb;
}d[110];
int main() 
{
    int T;
    char ch1, ch2;
    cin >>T;
    while (T--)
    {
        tot = 0;
        cin >>n;
        REP(i, n)
        {
            cin >>d[i].num >>d[i].ca >>ch1 >>d[i].cb >>ch2;
            d[i].ra = (ch1 == 'Y' ? true : false);
            d[i].rb = (ch2 == 'Y' ? true : false);
        }
        ans = -1;
        bool flag;
        REP(i, n)
        {
            flag = true;
            int now = d[i].num;                
            REP(j, n)
            {
                if (j == i) continue;
                if ((!d[j].ra && d[j].ca != now) || (d[j].ca==now && d[j].ra)) {flag = false; break;}
                if ((!d[j].rb && d[j].cb != now) || (d[j].cb==now && d[j].rb)) {flag = false; break;}
            }
            if (!flag) continue;
       /*     if (ans == -1) ans = d[i].num;
            else
            {
                printf("impossible\n");
                return 0;
            }*/
            tot++;
            ans = d[i].num;
        }
        if (tot != 1) printf("impossible\n");
        else printf("%d\n", ans);
    }
    return 0;
}


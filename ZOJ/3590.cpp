/*
 * Author:  Troy
 * Created Time:  2012/3/13 23:58:23
 * File Name: 3590.cpp
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
#define Maxn 20010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
int n;
long long ans, cnt;
int x[Maxn], sum[5];
int main() 
{
    while (~scanf("%d", &n))
    {
        REP(i, n) scanf("%d", &x[i]);
        cnt = ans = 0;
        memset(sum, 0, sizeof(sum));
        REP(i, n)
        {
            ans += x[i] / 3;
            cnt += x[i] / 3;
            sum[x[i]%3]++;
        }
        
        while (cnt >= 1 && sum[2] > 0)
        {
            ans++;
            sum[2]--;
        }
        while (cnt >= 2 && sum[1] > 0)
        {
            ans++;
            cnt--;
            sum[1]--;
        }
        while (cnt >= 3)
        {
            cnt -= 2;
            ans++;
        }
     //   printf("%d\n", ans);
        cout <<ans <<endl;
    }
    return 0;
}


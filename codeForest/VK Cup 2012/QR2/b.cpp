/*
 * Author:  Troy
 * Created Time:  2012/3/9 23:13:04
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
#define Maxn 100100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
vector<pii> cap;
multiset<pii> ma;
int cnt[1010], ans1, ans2;
int main() 
{
    ans1 = ans2 = 0;
    int x, y;
    memset(cnt, 0, sizeof(cnt));
    scanf("%d%d", &n, &m);
    REP(i, n)
    {
        scanf("%d%d", &x, &y);
        ma.insert(mp(x,y));
    }
    REP(i, m)
    {
        scanf("%d%d", &x, &y);
        pii t = mp(x, y);
        multiset<pii>::iterator it = ma.find(t);
        if (it != ma.end())
        {
            ans1++; ans2++;
            ma.erase(it);
        }
        else cnt[y]++;
    }
    for (multiset<pii>::iterator it = ma.begin(); it != ma.end(); it++)
    {
        pii now = *it;
        if (cnt[now.se] > 0)
        {
            ans1++;
            cnt[now.se]--;
        }
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}


/*
 * Author:  Troy
 * Created Time:  2012/6/1 20:07:07
 * File Name: f.cpp
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

int n, s, w, q;
int a[Maxn];

void init()
{
    int g = s;
    REP(i, n)
    {
        a[i] = (g / 7) % 10;
        if (g % 2 == 0) g /= 2;
        else g = (g/2)^w;
    }
}
int main() 
{
    while (~sf("%d%d%d%d", &n, &s, &w, &q))
    {
        if (!n && !s && !w && !q) break;
        init();
    }
    return 0;
}


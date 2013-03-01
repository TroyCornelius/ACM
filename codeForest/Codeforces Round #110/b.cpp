/*
 * Author:  Troy
 * Created Time:  2012/3/1 20:20:51
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
int n;
double r[110], ans;
int main() 
{
    cin >>n;
    REP(i, n) cin >>r[i];
    r[n] = 0.0;
    sort(r, r+n+1);
    ans = 0.0;
    for (int i = n; i >= 0; i-=2)
    {
        ans += pi * (r[i]*r[i] - r[i-1]*r[i-1]);
    }
    printf("%.8f\n", ans);
    return 0;
}


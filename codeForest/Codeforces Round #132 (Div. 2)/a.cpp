/*
 * Author:  Troy
 * Created Time:  2012/8/6 23:29:25
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, a[100], b[100], m;
int main() 
{
    cin >>n;
    REP(i, n) cin >>a[i];
    cin >>m;
    REP(i, m) cin >>b[i];
    sort(a, a+n);
    sort(b, b+m);
    int ans = 0, tmp = 0;
    REP(i, m)
        REP(j, n)
        if (b[i] % a[j] == 0) tmp = max(tmp, b[i] / a[j]);
    REP(i, m)
        REP(j, n)
        if (b[i] % a[j] == 0 && b[i] / a[j] == tmp) ans++;
    cout <<ans <<endl;
    
    return 0;
}


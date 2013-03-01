/*
 * Author:  Troy
 * Created Time:  2012/9/1 1:55:36
 * File Name: c.cpp
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

int n, a[Maxn], b[Maxn];
int pos[Maxn];
int delta ;

multiset<int> s;

int get_ans(int x) {
    int ret = n + 10;
    multiset<int>::interator it = s.lower_bound(x);
    
}


int main() 
{
    int x;
    sf("%d", &n);
    FOR(i, 1, n+1) sf("%d", &a[i]);
    FOR(i, 1, n+1) sf("%d", &b[i]);
    FOR(i, 1, n+1) pos[a[i]] = i;
    delta = 0;
    FOR(i, 1, n+1) {
        s.insert(i - pos[b[i]]);
    }
    FOR(i, 1, n+1) {
        pf("%d\n", get_ans());
    }
    return 0;
}


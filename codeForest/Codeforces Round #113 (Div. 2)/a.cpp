/*
 * Author:  Troy
 * Created Time:  2012/3/24 0:12:43
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

struct Tnode
{
    int x,y;
}a[550];
bool cmp(const Tnode a, const Tnode b)
{
    return a.x > b.x || (a.x == b.x && a.y < b.y);
}
int n, k, ans;

int main() 
{
    cin >>n >>k;
    REP(i, n) cin >>a[i].x >>a[i].y;
    sort(a, a+n, cmp);
    Tnode tmp = a[k-1];
    ans = 0;
    REP(i, n)
        if (a[i].x == tmp.x && a[i].y == tmp.y) ans++;
    cout <<ans <<endl;
    return 0;
}


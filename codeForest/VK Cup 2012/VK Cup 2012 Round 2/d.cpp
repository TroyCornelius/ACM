/*
 * Author:  Troy
 * Created Time:  2012/3/26 0:10:37
 * File Name: d.cpp
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
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int k, n, h;
struct Tnode
{
    int vi, mi, id;
    bool operator < (const Tnode &b) const
    {
        return mi < b.mi;
    }
}lem[Maxn];
int main() 
{
    scanf("%d%d%d", &n, &k, &h);
    REP(i, n) scanf("%d", &lem[i].mi);
    REP(i, n) scanf("%d", &lem[i].vi), lem[i].id = i+1;
    sort(lem, lem+n);
    FOR(i, 1, k+1)
    {
        
    }
    return 0;
}


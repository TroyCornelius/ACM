/*
 * Author:  Troy
 * Created Time:  2012/3/26 23:15:59
 * File Name: 1b.cpp
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

int n;
double k, h;
struct Tnode
{
    double vi;
    int id, mi;    
    bool operator<(const Tnode &b)const
    {
        return mi < b.mi || (mi == b.mi && vi < b.vi);
    }
}lem[Maxn];
vi ans, tmp;

bool check(double t)
{
    tmp.clear();
    int i = 0;
    double p = 1;
    while (p <= k)
    {
        while (i < n && p*h > lem[i].vi*t) i++;
        if (i < n)
        {
            tmp.pb(lem[i].id);
            i++;
            p++;
        }
        else break;
    }
    return p > k;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin >>n >>k >>h;
    REP(i, n) cin >>lem[i].mi;
    REP(i, n) cin >>lem[i].vi, lem[i].id = i+1;
    sort(lem, lem+n);
    
    double lo = 0.0, hi = 1000000001.0, mid;
    REP(i, 100)
    {
        mid = (lo + hi) / 2.0;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    check(hi);
    REP(i, tmp.size())
        cout <<tmp[i] <<(i==tmp.size()-1 ? '\n' :' ');
    
    return 0;
}


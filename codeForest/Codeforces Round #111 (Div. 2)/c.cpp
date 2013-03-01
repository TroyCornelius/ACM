/*
 * Author:  Troy
 * Created Time:  2012/3/6 23:00:28
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<long long> vi;
typedef vector<int>::iterator vit;

long long n;
long long k;
vi d;
vector<pii> b;
int main() 
{
    d.clear();
    int num;
    ios::sync_with_stdio(false);    
    cin >>n >>k;
    REP(i, n)
    {
        cin >>num;
        d.pb(num);
    }
    sort(all(d));
    
    cout <<d[(k-1)/n] <<" ";
    long long tmp = k - n *( (k-1) / n);
    b.clear();
    int cnt = 0, num = d[0];
    
   // cout <<d[((k % n)-1+n)%n] <<endl;
    return 0;
}


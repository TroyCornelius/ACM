/*
 * Author:  Troy
 * Created Time:  2012/3/6 23:26:06
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
string a;
int n;
vector<int> d1, d2;

bool solve() 
{
    sort(all(d1));
    sort(all(d2));
    if(d1[n-1] == d2[n-1]) return false;
    if(d1[n-1] > d2[n-1]) 
    {
        for(int i = 0; i < n; i++)
            if(d1[i] <= d2[i]) return false;
        return true;
    }
    else
    {
        for(int i = 0; i < n; i++)
            if(d1[i] >= d2[i]) return false;
        return true;
    }
}

int main()
{
    cin >> n >> a;
    d1.clear(), d2.clear();
    
    REP(i, n) d1.pb(a[i] - '0'); 
    for(int i = n; i < 2 * n; i++) d2.pb(a[i] - '0'); 
    
    if(solve()) cout << "YES" << endl;
    else cout << "NO" << endl;       
    
    return 0;
}


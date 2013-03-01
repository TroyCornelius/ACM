/*
 * Author:  Troy
 * Created Time:  2012/3/16 23:38:58
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
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int k;
string s;
long long ans;
vi pos;
int main() 
{
    ios::sync_with_stdio(false);
    cin >>k;
    cin >>s;
    REP(i, s.length())
        if (s[i] == '1') pos.pb(i);
    ans = 0;
    int lo = 0, hi = k-1;
    long long t1, t2;
    int n = pos.size();
    if (k == 0)
    {
        pos.pb(s.length());
        while (lo < pos.size())
        {
            if (lo == 0) t1 = pos[lo] - 0;
            else t1 = pos[lo] - pos[lo-1] - 1;
            ans += t1 * (t1+1) / 2;
            //cout <<t1 <<" "<<ans <<" "<<pos[lo]endl;
            lo++;
        }
        
    }
    else{
    while (hi < n)
    {
        t1 = t2 = 0;
        if (lo == 0) t1 = pos[lo] + 1;
        else t1 = pos[lo] - pos[lo-1];
        
        if (hi + 1 < n) t2 = pos[hi+1] - pos[hi];
        else t2 = s.length() - pos[hi];
        ans += t1 * t2;
        lo++; hi++;
    }
    }
    cout <<ans <<endl;
    
    return 0;
}


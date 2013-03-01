/*
 * Author:  Troy
 * Created Time:  2012/2/15 16:58:24
 * File Name: e.cpp
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

string s, rs;

int m, ans;
vi zfunction(string w)
{
    int len = w.length();
    vi ret(len);
    for (int i=1, l=0, r=0; i<len; ++i)
    {
        if (i <= r) ret[i] = min(r-i+1, ret[i-l]);
        while (i+ret[i] < len && w[ret[i]] == w[i+ret[i]] ) ++ret[i];
        if (i+ret[i]-1 > r) l = i, r = i+ret[i]-1;        
    }
    return ret;        
}
bool check(string st)
{
    if (st.length() <= 1) return false;
    vi z = zfunction(st + '#' + s);
    REP(i, z.size()) cout <<z[i] <<" ";
    cout <<endl;
    z.erase(z.begin(), z.begin() + st.size() + 1);
    string rst = st;
    reverse(all(rst));
    vi zb = zfunction(rst + '#' + rs);
    
    REP(i, zb.size()) cout <<zb[i] <<" ";
    cout <<endl;
    zb.erase(zb.begin(), zb.begin() + rst.size() + 1);
    
    FOR(i, 1, zb.size())
        if (zb[i-1] > zb[i]) zb[i] = zb[i-1];
    int len = st.length(), n = z.size();
    REP(i, n)
    {
        if (i + len > n) break;
        if (z[i] > 0)
        {
            int o = zb[n - (i + len)];
            if (o > 0 && z[i] + o >= len) return true;
        }
    }
    return false;
}
int main() 
{
    string t;
    cin >>s;
    rs = s;
    reverse(all(rs));
    cin >>m;
    ans = 0;
    while (m--)
    {
        cin >>t;
        if (check(t)) ans++;
    }        
    cout <<ans <<endl;

    return 0;
}


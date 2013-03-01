/*
 * Author:  Troy
 * Created Time:  2012/3/9 23:37:46
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

vi loc[30];
int k, n;
string s;
vector<pair<int,char> >ans;
bool cmp(pair<int,char> a, pair<int,char> b)
{
    return a.fi < b.fi;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin >>k;
    cin >>s;
    int len = s.length();
    REP(i, len)
    {
        int p = s[i] - 'a', q = i+1;
        while (q <= k*len)
        {
            loc[p].pb(q);
            q += len;
        }
    }
    REP(i, 26) sort(all(loc[i]));
    char ch;
    int x;
    cin >>n;
    REP(i, n)
    {
        cin >>x >>ch;
        loc[ch-'a'].erase(loc[ch-'a'].begin()+x-1);
    }
    REP(i, 26)
    {
        REP(j, loc[i].size()) ans.pb(mp(loc[i][j], 'a'+i));
    }   
    sort(all(ans), cmp);
    REP(i, ans.size()) cout <<ans[i].se;
    cout <<endl;
    return 0;
}


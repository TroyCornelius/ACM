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
#define Maxn 200010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

vi loc[30];
int k, n, m;
int t[28][Maxn];
string s;
vector<pair<int,char> >ans;

void add(int p, int idx, int val, int lim)
{
    for (; idx<=lim; idx += idx&-idx) t[p][idx] += val;
}
int query(int p, int kth, int lim)
{
    int cnt = 0, ret = 0;
    FORD(i, 20, 0)
    {
        ret += (1<<i);
        if (ret > lim || cnt + t[p][ret] >= kth) ret -= (1<<i);
        else cnt += t[p][ret];
    }
    return ret+1;
}

bool cmp(pair<int,char> a, pair<int,char> b)
{
    return a.fi < b.fi;
}

int main() 
{
    ios::sync_with_stdio(false);
    memset(t, 0, sizeof(t));
    cin >>k;
    cin >>s;
    int len = s.length();
    m = k * len;
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
    //REP(j, loc[0].size()) cout <<loc[0][j] <<" ";
    //cout <<endl;
    REP(i, 26)
    {
        //cout <<loc[i].size() <<endl;
        REP(j, loc[i].size()+5) add(i, j+1, 1, loc[i].size());
    }
    char ch;
    int x, y;
    cin >>n;
    REP(i, n)
    {
        cin >>x >>ch;
        y = query(ch-'a', x, loc[ch-'a'].size());
      //  cout <<x <<" "<<ch <<" "<<y <<" "<<loc[ch-'a'].size() <<endl;
        add(ch-'a', y, -1, loc[ch-'a'].size());
      //  REP(j, loc[ch-'a'].size()) cout <<sum(ch-'a', j+1) <<" ";
     //   cout <<endl;
        loc[ch-'a'][y-1] = -1;
    }
    REP(i, 26)
    {
        REP(j, loc[i].size()) 
            if (loc[i][j] != -1) ans.pb(mp(loc[i][j], 'a'+i));
    }   
    sort(all(ans), cmp);
    REP(i, ans.size()) cout <<ans[i].se;
    cout <<endl;
    return 0;
}


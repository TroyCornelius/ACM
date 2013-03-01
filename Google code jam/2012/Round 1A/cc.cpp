/*
 * Author:  Troy
 * Created Time:  2012/4/28 10:39:13
 * File Name: 
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
typedef pair<double,double> pdd;
int n;

vector<pdd> L, R;

bool cmp(const pdd &a, const pdd &b)
{
    return a.fi > b.fi;
}
bool check()
{
    REP(i, (int)L.size()-1)
        if (L[i].se < L[i+1].se) return false;
    REP(i, (int)R.size()-1)
        if (R[i].se < R[i+1].se) return false;
    return true;
}

pair<int,double> getcol(vector<pdd> &a)
{
    int ret = -1;
    double ti = 1e100;
    REP(i, (int)a.size()-1)
    {
        if (a[i+1].se > a[i].se)
        {
            double tmp = (a[i].fi - a[i+1].fi - 5) / (a[i+1].se - a[i].se);
            if (tmp < ti) 
            {
                ret = i+1;
                ti = tmp;
            }
        }
    }
    return mp(ret, ti);
}
int main() 
{
    ios::sync_with_stdio(false);
    int T, ca = 0;
    cin >>T;
    char ch;
    double s, p;
    while (T--)
    {
        L.clear();
        R.clear();
        cin >>n;
        REP(i, n)
        {
            cin >>ch >>s >>p;
            if (ch == L) L.pb(mp(p, s));
            else R.pb(mp(p, s));
        }
        sort(all(L), cmp);
        sort(all(R), cmp);
        cout <<"Case #" <<++ca<<": ";
        while (1)
        {
            if (check())
            {
                cout <<"Possible" <<endl;
                break;                
            }
            
            pair<int,double> p1 = getcol(L);
            pair<int,double> p2 = getcol(R);
            double tmi = 1e100;
            if (p1.fi != -1 && p2.fi != -1)
            {
                tmin = min(p1.se, p2.se);
                if (p1.se < p2.se)
                {
                    double len = L[p1.fi].fi + L[p1.fi].se * tmin;
                    REP()                    
                }
            }
            
            
        }
    }
    return 0;
}


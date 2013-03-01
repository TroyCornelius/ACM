/*
 * Author:  Troy
 * Created Time:  2012/3/12 0:13:00
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
#define Maxn 1010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, k;
vector<pii> sto, pen;
vector<pii> ans[Maxn];
double money;
bool cmp(const pii &a, const pii &b)
{
    return a.fi < b.fi;
}
int main() 
{
    int a, b;
    ios::sync_with_stdio(false);
    cin >>n >>k;
    REP(i, n)
    {
        cin >>a >>b;
        if (b == 1) sto.pb(mp(a, i+1));
        else pen.pb(mp(a, i+1));
    }
    sort(all(sto), cmp);
    sort(all(pen), cmp);
    money = 0.0;
    int i = sto.size()-1, j = k-1;
    while (i >= 0)
    {
        if (j < 0)
        {
            while (i >= 0)
            {
               money += (double)sto[i].fi;
               ans[0].pb(sto[i]);
               i--;
            }
            money += (double)ans[0][0].fi-1.0*ans[0][0].fi / 2.0 - (double)sto[0].fi + 1.0*sto[0].fi/2.0;
        
        }
        else
        {
            ans[j].pb(sto[i]);
            money += 1.0 * sto[i].fi / 2.0;
            i--; j--;
        }
    }
    int p;
   if (sto.size() < k)
   {
       for (p = 0; p < pen.size() && j >= 0; p++, j--)
       {
           ans[j].pb(pen[p]);
           money += (double)pen[p].fi;
       }
       while (p < pen.size()) 
       {
           ans[0].pb(pen[p]);
           money += (double)pen[p].fi;
           p++;
       }
   }
   else
   {
       if (sto.size() > 0 && pen.size() > 0 && pen[0].fi < sto[0].fi)
       {
           money += (1.0*pen[0].fi/2.0 - 1.0*sto[0].fi/2.0 + (double)(sto[0].fi));
           FOR(p, 1, pen.size()) 
           {
               money += (double)pen[p].fi;
               ans[0].pb(pen[p]);
           }
           ans[0].pb(pen[0]);
       }
       else
       {
           FOR(p, 0, pen.size())
           {
               money += (double)pen[p].fi;
               ans[0].pb(pen[p]);
           }
         //  cout <<money <<endl;
       }
   }
   cout <<fixed <<setprecision(1) <<money <<endl;
   REP(p1, k)
   {
       cout <<ans[p1].size();
       REP(p2, ans[p1].size()) cout <<" "<<ans[p1][p2].se;
       cout <<endl;
   }
    
    return 0;
}


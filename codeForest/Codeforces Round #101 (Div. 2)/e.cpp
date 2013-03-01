#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Maxn 10100
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

int n, m, fas[Maxn], fam[Maxn];
char ch;
vector<pii> gs[Maxn], gm[Maxn];
vector<int> ans;

int finds(int x)
{
    if (fas[x] == x) return x;
    else return fas[x] = finds(fas[x]);
}
int findm(int x)
{
    if (fam[x] == x) return x;
    else return fam[x] = findm(fam[x]);
}
int main()
{
  // while (1){
    ans.clear();
    REP(i, n+1) gs[i].clear(), gm[i].clear();
    int u, v, cnts=0, cntm=0;
    cin >>n >>m;
    REP(i, m)
    {
        cin >>u >>v >>ch;
        if (ch == 'S')
        {
            cnts++;
            gs[u].pb(mp(v, i+1)); gs[v].pb(mp(u, i+1));
        }
        else
        {
            cntm++;
            gm[u].pb(mp(v, i+1)); gm[v].pb(mp(u, i+1));        
        }    
    }
    REP(i, n+1) fas[i] = fam[i] = i;
    
    FOR(i,1,n+1)
      FOR(j, 0, int(gs[i].size()))
      {
          int x = finds(i), y = finds(gs[i][j].fi);
          fas[x] = y;      
      }
    if (n%2==0 || cnts<(n-1)/2 || cntm<(n-1)/2) {cout <<"-1" <<endl; return 0;}
    
    int tot = 0;
    FOR(i, 1, n+1)
        FOR(j, 0, int(gm[i].size()))
        {
            v = gm[i][j].fi;
            int x = finds(i), y = finds(v);
            if (x == y) continue;
            tot++;
            ans.pb(gm[i][j].se);
            fas[x] = y;
            fam[findm(i)] = findm(v);           
        }
    if (tot > (n-1)/2) {cout <<"-1" <<endl; return 0;}
   
    FOR(i, 1, n+1)
        FOR(j, 0, int(gm[i].size()))
        {
            if (tot == (n-1)/2) break;
            v = gm[i][j].fi;
            int x = findm(i), y = findm(v);
            if (x == y) continue;
            tot++;
            ans.pb(gm[i][j].se);
            fam[x] = y;        
        }
    
    if (tot < (n-1)/2) {cout <<"-1" <<endl; return 0;}
    
    FOR(i, 1, n+1)
        FOR(j, 0, int(gs[i].size()))
        {
            v = gs[i][j].fi;
            int x = findm(i), y = findm(v);
            if (x == y) continue;
            tot++;
            ans.pb(gs[i][j].se);
            fam[x] = y;        
        }
    
    cout <<tot <<endl;
    REP(i, tot) cout <<ans[i] <<" ";
    cout <<endl; 

    return 0;
}

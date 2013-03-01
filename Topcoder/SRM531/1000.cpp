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

#define all(a) (a).begin(),(a).end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Maxn 256
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

int fa[Maxn];
vector<pair<pii, int> > e1, e2;
    bool cmp1(pair<pii, int> a, pair<pii, int> b)
    {
        return a.se > b.se;
    }
        bool cmp2(pair<pii, int> a, pair<pii, int> b)
    {
        return a.se < b.se;
    }
        int find(int x)
    {
        if (fa[x] == x) return x;
        else return fa[x] = find(fa[x]);
    }
    int get_cost(char c)
    {
        if (c >= 'A' && c <= 'Z') return c - 'A';
        else return c - 'a' + 26; 
    }
class KingdomReorganization
{
    public:
    int getCost(vector <string> kingdom, vector <string> build, vector <string> destroy)
    {
        int n = kingdom.size();
        int ans = 0;
        REP(i, n) fa[i] = i;
        
        REP(i, n)
            REP(j, i+1)
            if (kingdom[i][j]=='1')
            {
                e1.pb(mp(mp(i, j),get_cost(destroy[i][j])));
                ans += get_cost(destroy[i][j]);
            }
            else e2.pb(mp(mp(i,j), get_cost(build[i][j]))); 
        sort(all(e1), cmp1);
        sort(all(e2), cmp2);
        REP(i, e1.size())
        {
            int u = e1[i].fi.fi, v = e1[i].fi.se, cost = e1[i].se;
            u = find(u);
            v = find(v);
            if (u != v)
            {
                fa[u] = v;
                ans -= cost;           
            }        
        }
        REP(i, e2.size())
        {
            int u = e2[i].fi.fi, v = e2[i].fi.se, cost = e2[i].se;
            u = find(u);
            v = find(v);
            if (u != v)
            {
                fa[u] = v;
                ans += cost;           
            }         
        }
    return ans;
    }
};

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
#define all(a) (a).begin(),(a).end()
#define Maxn 10100
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

int n, m;
vector<pair<pii,int> > d;
vector<int> ans;
priority_queue<pii> h;
int main()
{
    int r, c;
    //while (1){
    d.clear();
    ans.clear();
    scanf("%d%d", &n, &m);
    REP(i, m)
    {
        scanf("%d%d", &r, &c);
        d.pb(mp(mp(n-r+1, c), i)); 
    }
    sort(all(d));
    for (int j=0, pos=1; pos<=n; pos++)
    {
        while (j<m && d[j].fi.fi <= pos) 
        {
            h.push(mp(-d[j].fi.se, d[j].se));
            j++;
        }
        while (!h.empty() && (-h.top().fi) < pos) h.pop();
        if (!h.empty())
        {
            ans.pb(h.top().se);
            h.pop();                    
        }    
    }
    printf("%d\n", ans.size());
    REP(i, ans.size())
    {
        if (i) printf(" ");
        printf("%d", ans[i]+1);    
    }
    puts("");
//}
    return 0;
}

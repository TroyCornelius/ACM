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
#define Maxn 100100
using namespace std;
int n, d[Maxn], ans;
typedef pair<int, int> pii;
vector<pii> snow;
struct Tnode
{
    int ball[5];
    Tnode(){}
    Tnode(int a, int b, int c)
    {
        ball[0] = a; ball[1] = b; ball[2] = c;    
    }
};
vector<Tnode> ou;
struct TT
{
       pii data;
       TT() {}
       TT(pii _a)
       :data(_a){}
       bool operator<(const TT b) const
       {
            return (data.se <b.data.se);            
       }
       };
priority_queue<TT> h;
bool cmp(pii a, pii b)
{
    return a.se > b.se;
}
int main()
{
   // while (1){
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &d[i]);
    sort(d, d+n);
    
    snow.clear();
    int kind = d[0], cnt = 1;
    for (int i=1; i<n; i++)
    {
        if (d[i] == d[i-1]) cnt++;
        else
        {
            snow.pb(mp(kind, cnt));
            kind = d[i];
            cnt = 1;        
        }    
    }
    snow.pb(mp(kind, cnt));
    sort(snow.begin(), snow.end(), cmp);
    
    int m = snow.size();
    if (m == 0) printf("0\n");
    else
    {
        ans = 0;
        ou.clear();
       // int p1=0, p2=1, p3=2;
      /*  while (p3<m && p2 <m && p1<m)
        {
            if (snow[p1].se == 0) p1 = max(p1, max(p2, p3)) + 1;
            if (snow[p2].se == 0) p2 = max(p1, max(p2, p3)) + 1;
            if (snow[p3].se == 0) p3 = max(p1, max(p2, p3)) + 1;
            if (p1<m && p2<m && p3 <m)
            {
                ans++;
                ou.pb(Tnode(snow[p1].fi, snow[p2].fi, snow[p3].fi));
                snow[p1].se--; snow[p2].se--; snow[p3].se--;           
            }            
        }*/
        while (!h.empty()) h.pop();
        for (int i=0; i<m; i++) h.push(TT(snow[i]));
        while (h.size() >= 3)
        {
              TT p1 = h.top(); h.pop();
              TT p2 = h.top(); h.pop();
              TT p3 = h.top(); h.pop();
              
              ans++;
              ou.pb(Tnode(p1.data.fi, p2.data.fi, p3.data.fi));
              p1.data.se--; p2.data.se--; p3.data.se--;
              if (p1.data.se > 0) h.push(p1);
              if (p2.data.se > 0) h.push(p2);
              if (p3.data.se > 0) h.push(p3);              
              
        }
        printf("%d\n", ans);
        for (int i=0; i<ans; i++)
        {
            sort(ou[i].ball, ou[i].ball+3);
            printf("%d %d %d\n", ou[i].ball[2], ou[i].ball[1], ou[i].ball[0]);        
        }
    }
//}
    
    return 0;
}

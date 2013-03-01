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
bool cmp(pii a, pii b)
{
    return a.se > b.se;
}
bool cmp2(pii a, pii b)
{
    return a.fi < b.fi;
}
int main()
{
  //  while (1){
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
    ans = 0;
    int lo = 0, hi = n/3, mid, s;
    while (lo <= hi)
    {
          mid = (lo + hi) / 2;
          s = 0;
          for (int i=0; i<m && snow[i].se > mid; i++) s += (snow[i].se - mid);
          
          if ((n-s)/3>=mid) ans=mid, lo = mid+1;
          else hi = mid-1;          
    }
    printf("%d\n", ans);
    sort(snow.begin(), snow.end(), cmp2);
    int p=m-1;
    while (ans--)
    {
        while (snow[p].se == 0) p--;
        for (int j=p, t=0; j>=0; j--)
        if (snow[j].se > 0)
        {
            t++;
            snow[j].se--;
            printf("%d", snow[j].fi);
            if (t != 3) printf(" ");
            else break;
        } 
        printf("\n");
        
    
    }
//}
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <set>
#include <queue>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define Maxn 30100
#define Maxm 100100
using namespace std;

typedef pair<int,int> pii;

int T, n, m, opp[Maxn];
long long t[Maxn], ans[Maxm];
pii num[Maxn];
vector<int> d;
struct Tquery
{
       int id;
       pii q;
       bool operator<(const Tquery &b)const
       {
          return (q.se < b.q.se || (q.se==b.q.se && q.fi < b.q.fi));     
       }
       }tmp;
vector<Tquery> que;
void insert(int idx, long long val)
{
     for (;idx<=n;idx+=idx&-idx) t[idx]+=val;     
     }
long long gsum(int idx)
{
     long long ret = 0;
     for (;idx;idx-=idx&-idx) ret+=t[idx];
     return ret;
     }
int main()
{
    int a, b;
    scanf("%d", &T);
    for (;T;T--)
    {
        memset(t, 0, sizeof(t));
        scanf("%d", &n);
        d.clear(); que.clear();
        for (int i=1; i<=n; i++) 
        {
            scanf("%I64d", &num[i].fi);
            d.pb(num[i].fi);
        }
        d.erase(unique(d.begin(), d.end()), d.end());
        sort(d.begin(), d.end());
        for (int i=1; i<=n; i++) num[i].se = lower_bound(d.begin(), d.end(), num[i].fi) - d.begin() + 1;      
        scanf("%d", &m);
        for (int i=0; i<m; i++)
        {
            scanf("%d%d", &a, &b);
            tmp.id = i; tmp.q = mp(a, b);
            que.pb(tmp);
        }
        sort(que.begin(), que.end());
        memset(opp, -1, sizeof(opp));
        int last = 0;
        for (int i=0; i<m; i++)
        {
            for (int j=max(1,last); j<=que[i].q.se; j++)
            {
                if (opp[num[j].se]!=-1) insert(opp[num[j].se], -num[j].fi);
                insert(j, num[j].fi);
                opp[num[j].se] = j;                
            }
            last = que[i].q.se+1;
            ans[que[i].id] = gsum(que[i].q.se) - gsum(que[i].q.fi-1);     
        }
        for (int i=0; i<m; i++) printf("%I64d\n", ans[i]);
    }
    return 0;
    }

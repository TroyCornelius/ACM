#include <cstring>
#include <iostream>
#include <cstdio>

#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
#define Maxn 200100
using namespace std;

int n, t[Maxn], ans[Maxn];
int pos[Maxn], val[Maxn];
void dec(int idx)
{
    for(; idx<=n; idx += idx&(-idx)) t[idx]--;
}
int get_k(int k)
{
    int cnt = 0, ret = 0;
    for (int i=18; i>=0; i--)
    {
        ret += (1<<i);
        if (ret >= n || cnt + t[ret] >= k) ret -= (1<<i);
        else cnt += t[ret];
    }
    return ret + 1;    
}
inline int getint()
{
    char c = getchar();
    int t = 0;
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9')
   {
        t = t * 10 + c - '0';
        c = getchar();
    }
    return t;
}

int main() 
{
    while (~scanf("%d", &n))
    {
    ////    FOR(i, 1, n+1) 
        for (int i=1; i<=n; i++) t[i] = i&-i;
       // REP(i, n)
        for (int i=0; i<n; i++) scanf("%d%d", &pos[i], &val[i]);
      //  REP(i, n) pos[i] = getint(), val[i] = getint();
        for (int i=n-1; i>=0; i--)
        {
            int loc = get_k(pos[i]+1);
            ans[loc] = val[i];
            dec(loc);
        }
      //  FOR(i, 1, n+1)
        for (int i=1; i<=n; i++) 
        {
          //  if (i > 1) printf(" ");
            printf("%d ", ans[i]);    
        }
        printf("\n");
    }
    
    return 0;
}


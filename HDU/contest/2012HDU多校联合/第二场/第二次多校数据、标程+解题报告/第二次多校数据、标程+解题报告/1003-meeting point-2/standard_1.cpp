#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 100010
int T,n;
struct Node
{
    __int64 val;
    int id;
    bool operator<(const Node &nd)const
    {
        return val < nd.val;
    }
}ndx[maxn],ndy[maxn];
__int64 sumx[maxn],sumy[maxn];
int main()
{
    int x,y,i;
    __int64 sx,sy,ans;
 //   freopen("data.in","r",stdin);
 //   freopen("data.out","w",stdout);
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            scanf("%d",&n);
            for(i = 0; i < n; i++)
            {
                scanf("%d%d",&x,&y);
                ndx[i].val = (__int64)(x + y);
                ndx[i].id = i;
                ndy[i].val = (__int64)(y - x);
                ndy[i].id = i;
            }
            sort(ndx,ndx+n);
            sort(ndy,ndy+n);
            sx = sy = 0LL;
            for(i = 1; i < n; i++)
            {
                sx += (__int64)(ndx[i].val - ndx[0].val);
                sy += (__int64)(ndy[i].val - ndy[0].val);
            }
            sumx[ndx[0].id] = sx;
            sumy[ndy[0].id] = sy;
            for(i = 1; i < n; i++)
            {
                sx += -(__int64)(n - i * 2)*(ndx[i].val - ndx[i-1].val);
                sy += -(__int64)(n - i * 2)*(ndy[i].val - ndy[i-1].val);
                sumx[ndx[i].id] = sx;
                sumy[ndy[i].id] = sy;
            }
            ans = (sumx[0] + sumy[0])/2;
            for(i = 1; i < n; i++)
            {
                ans = min(ans,(sumx[i]+sumy[i])/2);
            }
            printf("%I64d\n",ans);
        }
    }
    return 0;
}

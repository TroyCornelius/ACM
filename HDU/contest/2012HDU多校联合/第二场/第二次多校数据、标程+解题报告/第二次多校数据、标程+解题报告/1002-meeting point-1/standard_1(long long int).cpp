#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 100010
struct Node
{
    int val,id;
    bool operator<(const Node &nd)const
    {
        return val < nd.val;
    }
}ndx[maxn],ndy[maxn];
long long int sumx[maxn],sumy[maxn];
int main()
{
    int t,n,i;
    long long int tmpx,tmpy,ans;
    freopen("data.in","r",stdin);
    freopen("data1.out","w",stdout);
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            scanf("%d",&n);
            for(i = 0; i < n; i++)
            {
                scanf("%d%d",&ndx[i].val,&ndy[i].val);
                ndx[i].id = ndy[i].id = i;
            }
            sort(ndx,ndx+n);
            sort(ndy,ndy+n);
            tmpx = tmpy = 0LL;
            for(i = 1; i < n; i++)
            {
                tmpx += (long long int)(ndx[i].val - ndx[0].val);
                tmpy += (long long int)(ndy[i].val - ndy[0].val);
            }
            sumx[ndx[0].id] = tmpx;
            sumy[ndy[0].id] = tmpy;
            for(i = 1; i < n; i++)
            {
                tmpx += -(long long int)(n - 2 * i)*(ndx[i].val - ndx[i-1].val);
                tmpy += -(long long int)(n - 2 * i)*(ndy[i].val - ndy[i-1].val);
                sumx[ndx[i].id] = tmpx;
                sumy[ndy[i].id] = tmpy;
            }
            ans = sumx[0] + sumy[0];
            for(i = 1; i < n; i++)
            {
                ans = min(ans,sumx[i] + sumy[i]);
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}

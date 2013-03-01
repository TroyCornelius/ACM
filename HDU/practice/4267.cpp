#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,q;
long long arr[15][15][50100];

void update2(int x,int y,int z,long long t)
{
    while(z>0)
    {
        arr[x][y][z]+=t;
        z-=(z&-z);
    }
}
long long sum(int x,int y,int z)
{
    long long ret=0;
    while(z<=n)
    {
        ret+=arr[x][y][z];
        z+=(z&-z);
    }
    return ret;
}

long long query(int b)
{
    long long ret=0;
    for(int i=1;i<=10;i++)
    {
        ret+=sum(i,b%i,(b-1)/i+1);
    }
    return ret;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=10;i++)
        {
            for(int j=0;j<i;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    arr[i][j][k]=0;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            int j=1;
            update2(j,i%j,(i-1)/j+1,tmp);
            update2(j,i%j,(i-1)/j,-tmp);
        }

        scanf("%d",&q);

        while(q>0)
        {
            q--;
            int d;
            scanf("%d",&d);
            if(d==1)
            {
                int a,b,k,c;
                scanf("%d%d%d%d",&a,&b,&k,&c);
                update2(k,a%k,(a-1)/k,-c);
                update2(k,a%k,(b-1)/k+((b-1)%k>=(a-1)%k),c);
            }
            else if(d==2)
            {
                int b;
                scanf("%d",&b);
                printf("%lld\n",query(b));
            }
        }
    }
    return 0;
}


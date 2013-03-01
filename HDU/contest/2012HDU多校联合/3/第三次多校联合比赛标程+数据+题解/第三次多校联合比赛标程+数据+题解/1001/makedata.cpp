#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
long long pri[300000],pn=0;
bool bo[1000010];
int main()
{
    freopen("c:\\din.in","w",stdout);
    memset(bo,true,sizeof(bo));
    for(long long i=2;i<=1000000;i++)
    {
        if(bo[i]==false)
            continue;
        pri[pn++]=i;
        for(long long j=i+i;j<=1000000;j+=i)
            bo[j]=false;
    }
    printf("2000\n");
    for(int i=0;i<1000;i++)
    {
        int a=rand()%90;
        int b=rand()%90;
        int c=rand()%90;
        printf("%I64d %I64d\n",pri[a]*pri[a]*pri[b]*pri[c],pri[a]*pri[b]*pri[b]*pri[c]);
    }
    //for(;;);
    for(int id=0;id<1000;id++)
    {
        long long d1=(rand()%1000)*100000000LL+(rand()%10000)*10000LL+(rand()%10000LL);
        long long da=d1;
        long long d2=1;
        for(int i=0;i<pn && pri[i]*pri[i]<=d1 ;i++)
        {
            if(d1%pri[i]==0)
            {
                if(rand()%100 < 80)
                {
                    d2*=pri[i];
                }
                while(d1%pri[i]==0)
                    d1/=pri[i];
            }
        }
        if(rand()%100 < 80)
        {
            d2*=d1;
        }
        if(d2==1)
            d2=(rand()%10000)*10000LL+(rand()%10000LL);
        printf("%I64d %I64d\n",da,d2);
    }
    return 0;
}

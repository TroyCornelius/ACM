#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
__int64 pri[300000],pn=0;
bool bo[1000010];
int main()
{
    freopen("1001.in","r",stdin);
    freopen("10010.out","w",stdout);
    memset(bo,true,sizeof(bo));
    for(__int64 i=2;i<=1000000;i++)
    {
        if(bo[i]==false)
            continue;
        pri[pn++]=i;
        for(__int64 j=i+i;j<=1000000;j+=i)
            bo[j]=false;
    }
    __int64 z;
    int cas = 1;
    scanf("%I64d",&z);
    while(z--)
    {
        __int64 d1,d2;
        scanf("%I64d%I64d",&d1,&d2);
        while(d1>=1000000000000LL || d1<2 || d2>=1000000000000LL || d2<2 );
        bool ba=true;
        for(int i=0;i<pn && pri[i]*pri[i]<=d1 ;i++)
        {
            if(d1%pri[i]==0)
            {
                if(d2%pri[i]!=0)
                {
                    ba=false;
                    break;
                }
                while(d1%pri[i]==0)
                    d1/=pri[i];
            }
        }
        printf("Case #%d: ",cas++);
        if(d2%d1!=0)
            ba=false;
        if(ba)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

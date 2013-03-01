#include<cstdio>
#include<cstring>
#define size 1000010
bool isp[size];
int prime[size],lp;

void make_prime()
{
    int i,j;
    memset(isp,0,sizeof(isp));
    isp[0]=isp[1]=1;
    lp=0;
    for(i=2;i<size;i++)
    {
        if(isp[i]==0)
            prime[lp++]=i;
        for(j=0;j<lp&&prime[j]*i<size;j++)
        {
            isp[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int main()
{
    make_prime();
   /// freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);
    int ti;
    scanf("%d",&ti);
    for(int ca=1;ca<=ti;ca++)
    {
        long long a,b;
        scanf("%I64d%I64d",&a,&b);
        int flag=1;
        for(int i=0;(long long)prime[i]*prime[i]<=a;i++)
        {
            if(a%prime[i]==0)
            {
                while(a%prime[i]==0)a/=prime[i];
                if(b%prime[i]!=0)
                {
                    flag=0;
                    break;
                }
            }
        }
        if(b%a)
        {
            flag=0;
        }
        printf("Case #%d: %s\n",ca,flag?"YES":"NO");
    }
}

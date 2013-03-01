#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
char d[10010];
int x[10010];
int n;
int dx[10010],dn;
int search(int num)
{
    int l=0,r=dn-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(dx[mid]<num)l=mid+1;
        else if(dx[mid]>num)r=mid-1;
        else return mid;
    }
}
int arr[10010];
void update(int x,int i)
{
    if(x==0)return;
    while(x<=dn)
    {
        arr[x]+=i;
        x+=(x&-x);
    }
}
int sum(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=arr[x];
        x-=(x&-x);
    }
    return ret;
}
int findk(int k)
{
    int cnt=0,sum=0;
    for(int i=20; i>=0; i--)
    {
        sum+=(1<<i);
        if(sum>dn||cnt+arr[sum]>=k)
            sum-=(1<<i);
        else
            cnt+=arr[sum];
    }
    return sum;
}
int main()
{
    //#ifndef ONLINE_JUDGE
    freopen("b.in","r",stdin);
    freopen("b.out", "w", stdout);
    //#endif
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        char str[10];
        for(int i=0; i<n; i++)
        {
            scanf("%s%d",str,&x[i]);
            dx[i]=x[i];
            d[i]=str[0];
        }

        sort(dx,dx+n);
        dn=unique(dx,dx+n)-dx;

        for(int i=1; i<=dn; i++)
            arr[i]=0;
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            if(d[i]=='r')
            {
                int t=search(x[i])+1;
                if(sum(t)-sum(t-1)>0)
                {
                    update(t,-1);
                    cnt--;
                    if(cnt==0)
                    {
                        printf("Empty!\n");
                    }
                    else if(cnt%2==1)
                    {
                        int v=dx[findk(cnt/2+1)];
                        printf("%d\n",v);
                    }
                    else
                    {
                        int v1=dx[findk(cnt/2)];
                        int v2=dx[findk(cnt/2+1)];
                        double out=0.5*v1+0.5*v2;
                        bool f1=v1%2,f2=v2%2;
                        if(f1!=f2)
                            printf("%.1f\n",out);
                        else
                            printf("%.0f\n",out);
                    }
                }
                else
                {
                    printf("Wrong!\n");
                }
            }
            else
            {
                int t=search(x[i])+1;
                update(t,1);
                cnt++;
                if(cnt%2==1)
                {
                    int v=dx[findk(cnt/2+1)];
                    printf("%d\n",v);
                }
                else
                {
                    int v1=dx[findk(cnt/2)];
                    int v2=dx[findk(cnt/2+1)];
                    double out=0.5*v1+0.5*v2;

                    bool f1=v1%2,f2=v2%2;
                    if(f1!=f2)
                        printf("%.1f\n",out);
                    else
                        printf("%.0f\n",out);
                }
            }
        }
    }
    return 0;
}

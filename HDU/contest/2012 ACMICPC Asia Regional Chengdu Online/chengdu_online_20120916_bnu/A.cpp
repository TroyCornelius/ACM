#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
using namespace std;
const int MAX=100005;
#define LL __int64
struct node
{
    int l,r,cnt;
    LL s[6];
}t[MAX*4];
int a[MAX],op[MAX],val[MAX],n,tot;
map<int,int>mp;
char s[100];
void build(int ll,int rr,int n)
{
    t[n].l=ll; t[n].r=rr;
    t[n].cnt=0;
    for(int i=1;i<=5;i++)
        t[n].s[i]=0;
    if(ll==rr)
        return;
    int mid=(ll+rr)>>1;
    build(ll,mid,n<<1);
    build(mid+1,rr,n<<1|1);
}
int get(int x,int y)
{
    return (x-y%5+4)%5+1;
}
void update(int ll,int rr,int n,int val)
{
    if(t[n].l==ll&&t[n].r==rr)
    {
        t[n].cnt+=val;
        t[n].s[1]+=(LL)val*a[ll];
        return;
    }
    int mid=(t[n].l+t[n].r)>>1;
    if(mid>=rr)
        update(ll,rr,n<<1,val);
    else
        update(ll,rr,n<<1|1,val);
    t[n].cnt=t[n<<1].cnt+t[n<<1|1].cnt;
    for(int i=1;i<=5;i++)
        t[n].s[i]=t[n<<1].s[i]+t[n<<1|1].s[get(i,t[n<<1].cnt)];
}
int main()
{
    int i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
        mp.clear();
        tot=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            if(s[0]=='s')
                op[i]=0;
            else
            {
                scanf("%d",&j);
                if(mp[j]==0)
                {
                    mp[j]=++tot;
                    a[tot]=j;
                }
                if(s[0]=='a')
                {
                    op[i]=j;
                    val[i]=1;
                }
                else
                {
                    op[i]=j;
                    val[i]=-1;
                }
            }
        }
        sort(a+1,a+tot+1);
        mp.clear();
        for(i=1;i<=tot;i++)
            mp[a[i]]=i;
        if(tot==0)
            t[1].s[3]=0;
        else
        build(1,tot,1);
        for(i=0;i<n;i++)
        {
            if(op[i])
                update(mp[op[i]],mp[op[i]],1,val[i]);
            else
                printf("%I64d\n",t[1].s[3]);
        }
    }
    return 0;
}
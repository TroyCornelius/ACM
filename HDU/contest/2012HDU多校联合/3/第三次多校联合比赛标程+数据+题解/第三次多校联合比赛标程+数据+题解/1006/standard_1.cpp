#include<cstdio>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100010;
struct eee{int st,end;}ee[N];
int foruse[N];
int nt[N];
int size;
int getvalue(int i)
{
    int l=0,r=size;
    while(l+1<r)
    {
        int mid=(r+l)/2;
        if(foruse[mid]<=i)
        {
            l=mid;
        }
        else r=mid;
    }
    return r;
}

int lowbit(int num)
{
    return num&(num^(num-1));
}

void add(int num,int pos)
{
    while(pos<N)
    {
        nt[pos]+=num;
        pos+=lowbit(pos);
    }
}

int get(int pos)
{
    int ret=0;
    while(pos>0)
    {
        ret+=nt[pos];
        pos-=lowbit(pos);
    }
    return ret;
}

int main()
{
    freopen("data.in","r",stdin);
    freopen("data3.out","w",stdout);
    int ti;
    scanf("%d",&ti);
    for(int ca=1;ca<=ti;ca++)
    {
        int n,m;
        int cnt=0;
        int *it;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            int t1,t2;
            scanf("%d%d",&t1,&t2);
            ee[i].st=t1;
            ee[i].end=t2+1;
            foruse[2*i+1]=t1;
            foruse[2*i+2]=t2+1;
        }
        sort(foruse+1,foruse+2*n+1);
        it=unique(foruse+1,foruse+2*n+1);
        size=it-foruse;
        foruse[0]=0;foruse[size]=1e9+1;
        memset(nt,0,sizeof(nt));
        for(int i=0;i<n;i++)
        {
            add(1,getvalue(ee[i].st));
            add(-1,getvalue(ee[i].end));
        }
        printf("Case #%d:\n",ca);
        for(int i=0;i<m;i++)
        {
            int t;
            scanf("%d",&t);
            printf("%d\n",get(getvalue(t)));
        }
    }
    return 0;
}

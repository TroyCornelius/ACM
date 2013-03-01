#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
vector<int>prm;
vector<__int64>res1;
vector<__int64>res2;
int vis[11000],sz;
void init()
{
    memset(vis,0,sizeof(vis));
    for(int i=2;i<=100;++i)if(!vis[i])
        for(int j=i*i;j<=10000;j+=i)
            vis[j]=1;
    for(int i=2;i<=4000;++i)if(!vis[i])
        prm.push_back(i);
    sz=prm.size();
}
map<int,int>cnt;
void phi(int x,int k)
{
    for(int i=0;i<sz;++i)
    {
        if(prm[i]*prm[i]>x) break;
        if(x%prm[i])    continue;
        int num=0;
        while(x%prm[i]==0)
            x/=prm[i],num++;
        cnt[prm[i]]+=num*k;
    }
    if(x==1)    return;
    cnt[x]+=k;
}
int main()
{
    int n,m,x;
    init();
    scanf("%d %d",&n,&m);
    while(n--)
    {
        scanf("%d",&x);
        phi(x,1);
    }
    while(m--)
    {
        scanf("%d",&x);
        phi(x,-1);
    }
    for(map<int,int>::iterator it=cnt.begin();it!=cnt.end();++it)
    {
        if((it->second)>0)
        {
            int pp=(it->first),cc=(it->second);
            while(cc>0)
            {
                __int64 tmp=1;
                while(cc>0&&tmp*pp<=10000000)
                    tmp*=pp,cc--;
                res1.push_back(tmp);
            }
        }
        if((it->second)<0)
        {
            int pp=(it->first),cc=-(it->second);
            while(cc>0)
            {
                __int64 tmp=1;
                while(cc>0&&tmp*pp<=10000000)
                    tmp*=pp,cc--;
                res2.push_back(tmp);
            }
        }
    }
    if(res1.size())
        printf("%d ",res1.size());
    else
        printf("1 ");
    if(res2.size())
        printf("%d\n",res2.size());
    else
        printf("1\n");
    int rs1=res1.size(),rs2=res2.size();
    for(int i=0;i<rs1;++i)  printf("%I64d ",res1[i]);
    if(rs1)
        printf("\n");
    else
        printf("1\n");
    for(int i=0;i<rs2;++i)  printf("%I64d ",res2[i]);
    if(rs2)
        printf("\n");
    else
        printf("1\n");
    return 0;
}


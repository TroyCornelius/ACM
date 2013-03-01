#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct edge
{
    int v,prev,limit,flow;
};

const int MAX=1005;
edge e[(MAX*(MAX-1)/2+MAX*2)*2];
int last[MAX],head[MAX],h[MAX],toth[MAX];
int b[MAX][MAX],c[MAX],d[MAX];
int n,s,t,tot,ans;
char ch[20000];

void ae(int x,int y,int c1,int c2)
{
    e[++tot].v=y;
    e[tot].prev=head[x];
    e[tot].limit=c1;
    e[tot].flow=0;
    head[x]=tot;
    e[++tot].v=x;
    e[tot].prev=head[y];
    e[tot].limit=c2;
    e[tot].flow=0;
    head[y]=tot;
}

void getline(int data[])
{
    gets(ch); int i=1;
    for (int k=0;ch[k];k++)
    {
        data[i]=0;
        for (;ch[k] && ch[k]!=' ';k++) data[i]=data[i]*10+ch[k]-'0';
        i++;
    };
}

void init()
{
    memset(head,0,sizeof(head));
    memset(toth,0,sizeof(toth));
    memset(h,0,sizeof(h));
    memset(d,0,sizeof(d));    
    scanf("%d\n",&n);
    ans=0; tot=1; s=0; t=n+1; toth[0]=t+1;
	/*
    for (int i=1;i<=n;i++) getline(b[i]);
    getline(c);
	*/
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&b[i][j]);
	for (int i=1;i<=n;++i)
		scanf("%d",&c[i]);
    for (int i=1;i<=n;i++) c[i]-=b[i][i];
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            b[i][j]+=b[j][i];
            ans+=b[i][j]; d[i]+=b[i][j]; d[j]+=b[i][j];
            ae(i,j,b[i][j],b[i][j]);
        }
    for (int i=1;i<=n;i++)
    {
        ae(s,i,d[i],0);
        if (c[i]>0) ae(i,t,c[i]*2,0);
		else ans+=-c[i];
    }
}

int aug(int u,int flow)
{
    if (u==t) return flow;
    int l=flow,minh=t;
    for (int i=last[u];;)
    {
        if (e[i].limit>e[i].flow)
        {
            if (h[e[i].v]+1==h[u])
            {
                int k=aug(e[i].v,min(e[i].limit-e[i].flow,l));
                e[i].flow+=k;
                e[i^1].flow-=k;
                l-=k;
                if (l==0) {last[u]=i; break;}
                if (h[s]>t) return flow-l;
            }
            minh=min(minh,h[e[i].v]);
        }
        i=e[i].prev;
        if (!i) i=head[u];
        if (i==last[u]) break;
    }
    if (flow==l)
    {
        toth[h[u]]--;
        if (!toth[h[u]]) h[s]=t+1;
        h[u]=minh+1;
        toth[h[u]]++;
    }
    return flow-l;
}

int maxflow()
{
    memcpy(last,head,sizeof(head));
    int res = 0;
    while (h[s]<=t) res+=aug(s,0x3ffffff);
	return res;
}

int main()
{
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		init();
		printf("%d\n", ans-maxflow()/2);
	}
}

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 310;
const int E = 200010;
const int oo = 1000000000;

int node,src,dest,ne;
int head[N],work[N],Q[N],dist[N];
int pnt[E],flow[E],cap[E],nxt[E];
struct edge
{
	int u,v,cost;
	edge(int U=0,int V=0,int C=0):u(U),v(V),cost(C) {}
}bri[13];

inline void init(int _node)
{
	node=_node;
	src=0;
	dest=node-1;
	memset(head,255,sizeof(head));
	ne=0;
}
inline void add(int u,int v,int c)
{
	pnt[ne]=v,cap[ne]=c,flow[ne]=0,nxt[ne]=head[u],head[u]=ne++;
	pnt[ne]=u,cap[ne]=0,flow[ne]=0,nxt[ne]=head[v],head[v]=ne++;
}
inline void chg(int u,int v,int c)
{
	for(int i=head[u];~i;i=nxt[i])	if(v==pnt[i])
	{
		cap[i]=c;
		return;
	}
}
bool dinic_bfs(void)
{
	int i,u,v,l,r=0;
	memset(dist,255,sizeof(dist));
	dist[Q[r++]=src]=0;
	for(l=0;l<r;l++)	for(i=head[u=Q[l]];~i;i=nxt[i])
		if(flow[i]<cap[i] && dist[v=pnt[i]]<0)
		{
			dist[Q[r++]=v]=dist[u]+1;
			if(v==dest)	return 1;
		}
	return 0;
}
int dinic_dfs(int u,int exp)
{
	if(u==dest)	return exp;
	for(int &i=work[u],v,tmp;~i;i=nxt[i])
		if(flow[i]<cap[i] && dist[v=pnt[i]]==dist[u]+1 && (tmp=dinic_dfs(v,min(exp,cap[i]-flow[i])))>0)
		{
			flow[i]+=tmp;
			flow[i^1]-=tmp;
			return tmp;
		}
	return 0;
}
int dinic_flow(void)
{
	int res=0,delta;
	while(dinic_bfs())
	{
		copy(head,head+node,work);
		while(delta=dinic_dfs(src,oo))	res+=delta;
	}
	return res;
}
int main(void)
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n,m;
	while(scanf("%d%d",&n,&m)==2)
	{
		init(n+20+2);
		int cnt=n,cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++)
		{
			int p;
			scanf("%d",&p);
			if(p)	add(src,i,p);
			cnt1+=p;
		}
		for(int i=0;i<m;i++)
		{
			int u,v,w,p;
			scanf("%d%d%d%d",&u,&v,&w,&p);
			if(p<0)
			{
				add(u,++cnt,oo);
				add(cnt,v,oo);
				add(cnt,dest,w);
			}
			else	if(p==0)	add(u,v,oo);
			else
			{
				bri[cnt2++]=edge(u,v,w);
				add(u,v,1);
			}
		}
		if(cnt==n || !cnt1)
		{
			puts("Poor Heaven Empire");
			continue;
		}
		int maxF=0,minC=oo,lim=(1<<cnt2);
		for(int i=0;i<lim;i++)
		{
			memset(flow,0,sizeof(flow));
			int F=0,C=0;
			for(int j=0;j<cnt2;j++)
			{
				if(i&(1<<j))
				{
					C+=bri[j].cost;
					chg(bri[j].u,bri[j].v,oo);
				}
				else	chg(bri[j].u,bri[j].v,1);
			}
			F=dinic_flow();
			if(F>maxF || (F==maxF && C<minC))
			{
				maxF=F;
				minC=C;
			}
		}
		if(maxF)	printf("%d %d\n",maxF,minC);
		else	puts("Poor Heaven Empire");
	}
	return 0;
}

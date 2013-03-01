#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 50050;
struct Node{int w,v,next;}nodes[MAXN*2];
int G[MAXN];
int Q[MAXN][2],front,tail;
int dist[MAXN],seq[MAXN];
bool vi[MAXN];
int N,L,alloc,M;
int best_size,center,len;
long long ret;
void add(int u,int v,int w)
{
	nodes[alloc].v=v,nodes[alloc].w=w;
	nodes[alloc].next=G[u];G[u]=alloc++;
}
long long count(int *first,int *last)
{
    long long ret = 0;
    sort(first,last--);
    while(first < last)
    {
        if(*first+*last<L)first++;
        else if(*first+*last>L)last--;
        else
        {
            if(*first==*last)
            {
                ret += 1LL * (last-first)*(last-first+1)/2;
                break;
            }
            int *b=first,*e=last;
            while(*b==*first)b++;
            while(*e==*last)e--;
            ret+=(b-first)*(last-e);
            first=b;
            last=e;
        }
    }
    return ret;
}
int centerOfGravity(int u,int p)
{
	int max_sub = 0,size = 1;
	for(int son=G[u];son!=-1;son=nodes[son].next)
	{
		int v=nodes[son].v;
		if(v==p||!vi[v])continue;
		int t = centerOfGravity(v,u);
		size += t;
		if(t>max_sub)max_sub = t;
	}
	if(Q[front][1]-Q[front][0]-size>max_sub)
		max_sub = Q[front][1]-Q[front][0]-size;
	if(max_sub<best_size)
	{
		center = u;
		best_size = max_sub;
	}
	return size;
}
void find(int u,int p,int now_dist)
{
	seq[len] = u;
	dist[len++] = now_dist;
	int last = len;
	for(int son=G[u];son!=-1;son=nodes[son].next)
	{
		int v = nodes[son].v,w=nodes[son].w;
		if(!vi[v] || v==p) continue;
		find(v,u,now_dist+w);
		if(p==-1)
        {
			Q[tail][0]=last,Q[tail][1]=len;
			tail++;
			ret-=count(dist+last,dist+len);
			last = len;
		}
	}
}
int main()
{
    scanf("%d%d", &N, &L);
	memset(G+1,-1,sizeof(int)*N);
	alloc = 0;
	for(int i=1;i<N;i++)
	{
		int w,v,u;
		scanf("%d%d",&u,&v);
		add(u,v,1);
		add(v,u,1);
	}
	ret = 0;
	front=0;tail=1;
	for(int i=1;i<=N;i++)seq[i]=i;
	for(Q[front][0]=1,Q[front][1]=N+1;front!=tail;front++)
	{
		for(int i=Q[front][0];i<Q[front][1];i++)vi[seq[i]]=1;
		best_size=N+1;
		centerOfGravity(seq[Q[front][0]],-1);
		len = Q[front][0];
		find(center,-1,0);
		ret += count(dist+Q[front][0],dist+Q[front][1]);
		for(int i=Q[front][0];i<Q[front][1];i++)vi[seq[i]]=0;
	}
    cout <<ret <<endl;
	return 0;
}


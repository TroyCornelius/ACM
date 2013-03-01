#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 50010
#define maxm 2500010
#define eps 1e-6
int size;
int head[maxn];
int flag[maxn];
double dist[maxn];
struct Edge
{
    int v,next;
    double p;
    Edge(){}
    Edge(int a,double _p,int c):v(a),p(_p),next(c){}
}edge[maxm];
inline void initg()
{
    size = 0;
    memset(head,-1,sizeof(head));
    memset(flag,0,sizeof(flag));

    memset(dist,0,sizeof(dist));
}
inline void add_edge(int u,int v,double d)
{
    edge[size] = Edge(v,d,head[u]);
    head[u] = size++;
}
struct HNode
{
    int id;
    double val;
    HNode(){}
    HNode(int _id,double _val):id(_id),val(_val){}
}queue[maxn*5];
bool cmp(const HNode &nd1,const HNode &nd2)
{
    return nd1.val < nd2.val;
}
double solve(int s,int t,double M)
{
    int i;
    int p = 0;
    HNode hn = HNode(s,M);
    HNode hm;
    queue[p++] = hn;
    dist[s] = M;
    push_heap(queue,queue+p,cmp);
    while(1)
    {
        if(p == 0)
            return -1.0;
        do
        {
            pop_heap(queue,queue+p,cmp);
            hn = queue[p-1];
            p--;
        }while(flag[hn.id] == 1 && p != 0);
        flag[hn.id] = 1;
        dist[hn.id] = hn.val;
        if(hn.id == t)
            return hn.val;
        for(i = head[hn.id]; i!=-1; i = edge[i].next)
        {
            if(flag[edge[i].v] == 0 && dist[edge[i].v] < edge[i].p * hn.val){
                hm = HNode(edge[i].v,edge[i].p * hn.val);
                dist[hm.id] = hm.val;
                queue[p++] = hm;
                push_heap(queue,queue+p,cmp);
            }
        }
    }
}
int main()
{
    int N,s,t;
    double M;
    int i,j,k,a;
    double b,res;
 //   freopen("data.in","r",stdin);

 //   freopen("data.out","w",stdout);
    while(scanf("%d",&N)!=EOF)
    {
        initg();
        for(i = 0; i < N; i++)
        {
            scanf("%d",&k);
            for(j = 0; j < k; j++)
            {
                scanf("%d%lf",&a,&b);
                if(i!=a)
                {
                    if(b!=100.0)
                    add_edge(i+1,a,1.0 - b/100.0);
                }
            }
        }
        scanf("%d%d%lf",&s,&t,&M);
        res = solve(s,t,M);
        if(res < eps)
            printf("IMPOSSIBLE!\n");
        else
            printf("%.2lf\n",M - res);
    }
    return 0;
}

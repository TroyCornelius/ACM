//Lib
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
//Macro
#define	rep(i,a,b)	for(int i=a,tt=b;i<=tt;++i)
#define	drep(i,a,b)	for(int i=a,tt=b;i>=tt;--i)
#define	erep(i,e,x)	for(int i=x;i;i=e[i].next)
#define	irep(i,x)	for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define	read()	(strtol(ipos,&ipos,10))
#define	sqr(x)	((x)*(x))
#define	pb	push_back
#define	PS	system("pause");
typedef	long long	ll;
typedef	pair<int,int>	pii;
const int oo=~0U>>1;
const double inf=1e100;
const double eps=1e-6;
string name="BRS", in=".in", out=".out";
//Var
int n,K,cnt,tot,ans;
int lisan[100008],l[100008];
int limit=1000000008;
struct P
{
	int x,y,idx;	
	bool operator <(const P &o)const{return x<o.x||x==o.x&&y<o.y;}
}d[100008];
struct BIT
{
	static const int limit=100000;
	int s[100008],p[100008];
	void set(){rep(i,1,limit)s[i]=oo;}
	inline int lowbit(int x){return x&-x;}
	void insert(int x,int v,int pos)
	{
		for(int i=x;i>0;i-=lowbit(i))
			if(s[i]>v)s[i]=v,p[i]=pos;
	}
	int query(int x)
	{
		int ret=oo,pos=n+1;
		for(int i=x;i<=n;i+=lowbit(i))
			if(s[i]<ret)ret=s[i],pos=p[i];
		return pos;
	}
}Q;
struct E
{
	int a,b,c;
	bool operator <(const E &o)const{return c<o.c;}
}e[1000000];
struct UNION
{
	int f[100008];
	static const int limit=100000;
	void set(){rep(i,1,n)f[i]=i;}
	int find(int x){return x==f[x]?f[x]:f[x]=find(f[x]);}
	void Union(int x,int y){f[x]=y;}
}U;
void Init()
{
	scanf("%d%d",&n,&K);
	rep(i,1,n)
		scanf("%d%d",&d[i].x,&d[i].y);	
}
void Discrate()
{
	rep(i,1,n)l[i]=d[i].y-d[i].x;
	sort(l+1,l+1+n);
	rep(i,1,n)lisan[i]=lower_bound(l+1,l+1+n,d[i].y-d[i].x)-l;
}
void add(int a,int b,int c){e[++tot].a = a;e[tot].b = b;e[tot].c = c;}
int Dis(int i,int j){return abs(d[i].x - d[j].x) + abs(d[i].y - d[j].y);}
void Solve()
{
	sort(d + 1,d + 1 + n);
	Discrate();Q.set();
	int pos;
    //cout <<Q.limit <<endl;
	drep(i,n,1)
	{
		pos = Q.query(lisan[i]);
		if(pos != n + 1)
			add(d[i].idx,d[pos].idx,Dis(i,pos));
		Q.insert(lisan[i],d[i].y + d[i].x,i);
	}
}
void Kruskal()
{
	sort(e+1,e+1+tot);
	int x,y;int cnt=n-K;
	U.set();
    //cout <<cnt <<endl;
	for(int i=1;i<=tot&&cnt;i++)
	{
		x=U.find(e[i].a);y=U.find(e[i].b);
		if(x!=y)
		{
			U.Union(x,y);
			cnt--;ans=e[i].c;
		}
	}
}
void Work()
{
	rep(i,1,n)d[i].idx=i;
	rep(i,1,4)
	{
		if(i == 3)
			rep(j,1,n)d[j].x = limit - d[j].x;
		if(i == 2 || i == 4)
			rep(j,1,n)swap(d[j].x,d[j].y);
		Solve();
	}	
	Kruskal();
	cout<<ans<<endl;
}
int main()
{
	//freopen((name+in).c_str(),"r",stdin);
	//freopen((name+out).c_str(),"w",stdout);
	Init();
	Work();
//	PS;
	return 0;
}


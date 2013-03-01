#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;


const int ziyad=9999999;
const int maxn=200000;


struct node
{
	int v;
	int dis;
};

bool operator < (node a,node b)
{
	if (a.dis!=b.dis)
		return (a.dis<b.dis);
	return (a.v<b.v);
}

int n,dis[maxn],cost[maxn][4],a[maxn],aval,akhar;
set<node> tr;


void input()
{
	cin >> aval >> akhar;
	cin >> n;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	for (int i=1;i<=n;i++)
		for (int j=0;j<4;j++)
			cin >> cost[i][j];
}

void change(int u,int v,int j,int k)
{
	if (dis[u]>dis[v]+cost[j][k])
	{
		node pp;
		pp.v=u;
		pp.dis=dis[u];	
		if (tr.find(pp)==tr.end())
		{
			cerr<<"Wrong" << endl;
			exit(0);
		}
		tr.erase(tr.find(pp));
		pp.dis=dis[v]+cost[j][k];
		tr.insert(pp);
		dis[u]=dis[v]+cost[j][k];
	}
}

int dijkstra()
{
	node p;
	for (int i=0;i<=100000;i++)
	{
		dis[i]=ziyad;
		p.dis=ziyad;
		p.v=i;
		if (i!=aval)
			tr.insert(p);
	}
	dis[aval]=0;
	p.dis=0;
	p.v=aval;
	tr.insert(p);
	for (int i=0;i<=100000;i++)
	{
		if (tr.empty())
			return -1;
		p=*tr.begin();
		if (p.dis==ziyad) return -1;
		tr.erase(tr.begin());
		int v=p.v;
		for (int j=1;j<=n;j++)
		{
			int u=v+a[j];
			if (u<=100000) 
				change(u,v,j,0);
			u=v-a[j];
			if (u>=0)
				change(u,v,j,1);	
			u=v*a[j];
			if (u<=100000)
				change(u,v,j,2);
			u=v/a[j];
			if (u>=0)
				change(u,v,j,3);
			
		}
	}
	return dis[akhar];
}

int main()
{
	int tests;
	cin >> tests;
	for (int ii=1;ii<=tests;ii++)
	{
		tr.clear();
		for (int i=0;i<=100000;i++)
			dis[i]=0;
		input();
		int adad=dijkstra();
		if (adad<ziyad)
			cout << adad << endl;
		else cout <<"IMPOSSIBLE" << endl;

	}
	return 0;
}

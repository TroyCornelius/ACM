#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=10000;


int n,m,vazn[maxn],yal[maxn][2],best,sum;
int is_there_num[maxn][10];
int ertefa[maxn];
int tartib[maxn];
int tartib_length;
int test_number;
int bfs_visit[maxn],bfs_visit_yal[maxn];
int max_yek=0,checked[maxn];
int q[maxn];
int mark[maxn];
int delta;
vector<int> e[maxn];

bool is_there(int x)
{
	
	int u=yal[x][0];
	int v=yal[x][1];
	if (mark[u] || mark[v])
	{
		return true;
	}
	return false;
	
}

bool sefr(int x)
{
	int u=yal[x][0];
	int v=yal[x][1];
	for (int i=0;i<e[u].size();i++)
	{
		int w=e[u][i];
		if (vazn[w]==2 || w>x)
			return true;
	}
	for (int i=0;i<e[v].size();i++)
	{
		int w=e[v][i];
		if (vazn[w]==2 || w>x)
			return true;

	}
	return false;
}

bool yek(int x)
{
	if (is_there(x)) return false;
	return true;
}

bool doo(int x)
{
	if (is_there(x)) return false;
	return true;
}

bool good()
{
	for (int i=1;i<=m;i++)
		if (vazn[i]==0)
		{
			int u=yal[i][0];
			int v=yal[i][1];
			if (mark[u]<2 && mark[v]<2)
				return false;
		}
	return true;
}


void mark_yalha(int x,int num)
{
	int u=yal[x][0];
	int v=yal[x][1];
	mark[u]=num;
	mark[v]=num;
}

void unmark_yalha(int x,int num)
{
	int u=yal[x][0];
	int v=yal[x][1];
	mark[u]=0;
	mark[v]=0;
}

int ayande()
{
	int temp_mark[maxn];
	vector<int> tt;
	tt.clear();
	int maximal=0;
	bool edame=true;
	while (edame)
	{
		edame=false;
		for (int i=1;i<=m;i++)
			if (vazn[i]==0 && mark[yal[i][0]]<2 && mark[yal[i][1]]<2)
			{
				temp_mark[yal[i][0]]=mark[yal[i][0]];
				temp_mark[yal[i][1]]=mark[yal[i][1]];
				edame=true;
				maximal++;
				mark_yalha(i,2);
				vazn[i]=2;
				tt.push_back(i);
			}

	}
	for (int i=0;i<tt.size();i++)
	{
		vazn[tt[i]]=0;
		mark[yal[tt[i]][0]]=temp_mark[yal[tt[i]][0]];

		mark[yal[tt[i]][1]]=temp_mark[yal[tt[i]][1]];
	}
	return maximal;
}


int sample_sol[10000];
void capture_sol()
{
	for (int i=1;i<=m;i++)
		sample_sol[i]=vazn[i];
}

void bt(int kodum)
{
	int x=tartib[kodum];
	x=kodum;
	vazn[x]=0;
	if (kodum==m+1)
	{
		if (sum<=best && good())
		{
			if (sum<best)
				max_yek=99999;
			best=sum;
			int tedad_yek=0;
			for (int i=1;i<=m;i++)
				if (vazn[i]==1)
				{
					tedad_yek++;
				}
			if (max_yek>tedad_yek)
			{
				capture_sol();
				max_yek=tedad_yek;
			}
		}
		return ;
	}
	int now_ertefa=min(ertefa[yal[x][0]],ertefa[yal[x][1]]);
		vazn[x]=2;
	if (doo(x))
	{
	mark_yalha(x,2);
		sum+=2;
		if (sum<=best)
			bt(kodum+1);
		sum-=2;
	unmark_yalha(x,2);
	}
	vazn[x]=1;
	if (yek(x))
	{
		mark_yalha(x,1);
		sum++;
		if (sum<=best)
			bt(kodum+1);
		sum--;
		unmark_yalha(x,1);
	}
	vazn[x]=0;
	if (sefr(x))
	{
		vazn[x]=0;
		bt(kodum+1);
	}
}

void bfs()
{
	int p=1;
	int r=1;
	q[1]=1;
	ertefa[1]=0;
	while (p<=r)
	{
		int v=q[p];
		for (int i=0;i<e[v].size();i++)
		{
			int number=e[v][i];
			int u;
			if (yal[number][0]==v)
				u=yal[number][1];			
			else
				u=yal[number][0];
			if (bfs_visit_yal[number]!=test_number)
			{
				bfs_visit_yal[number]=test_number;
				tartib[++tartib_length]=number;
			}	
			if (bfs_visit[u]!=test_number)
			{
				bfs_visit[u]=test_number;
				q[++r]=u;
				ertefa[u]=ertefa[v]+1;
			}
		}	
		p++;
	}
}

int main()
{
	int  Number_of_Graphs=0;
	int Exatcly=0;
	test_number=0;
	int khoobha,khoobha2,khoobha3;
		khoobha=khoobha2=khoobha3=0;
		int all_yek=0;
	int ttt;
	cin >> ttt; 
	for (int iii=0;iii<ttt;iii++)
	{
		tartib_length=0;
		test_number++;	
		scanf("%d%d",&n,&m);
		Number_of_Graphs++;
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&yal[i][0],&yal[i][1]);
			e[yal[i][0]].push_back(i);
			e[yal[i][1]].push_back(i);
		}
		delta=0;
		for (int i=1;i<=n;i++)
			if (delta<e[i].size())
				delta=e[i].size();
		bfs();
		for (int i=1;i<=m;i++)
			vazn[i]=0;
		sum=0;
		best=9999999;
		max_yek=9999;
		bt(1);
		if (best==(delta*n)/(delta+1))
		{
			khoobha++;

		}
		if ((delta*n)/(delta+1)!=(delta*n+delta)/(delta+1) && best==(delta*n+delta)/(delta+1))
		{
			khoobha2++;
		}
		if (best>(delta*n+delta)/(delta+1))
		{
			khoobha3++;
		}
		if (all_yek<max_yek)
			all_yek=max_yek;
		cout << best << endl;
		for (int i=0;i<=n;i++)
			e[i].clear();
		for (int i=0;i<=m;i++)
			vazn[i]=0;
	}
	return 0;
}

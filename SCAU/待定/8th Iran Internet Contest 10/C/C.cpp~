#include <iostream>
using namespace std;

const int maxn=250;

int ii,m,n,visit[maxn][maxn],tedad;
int har[8][2]={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
char jadval[maxn][maxn];

void dfs(int row,int col)
{
	visit[row][col]=ii;
	for (int i=0;i<8;i++)
	{
		int next_row=row+har[i][0];
		int next_col=col+har[i][1];
		if (next_row<1 || next_row>m) continue;
		if (next_col<1 || next_col>n) continue;
		if (visit[next_row][next_col]!=ii && jadval[next_row][next_col]=='@')
		dfs(next_row,next_col);
	}
}

int main()
{
	int tests;
	cin >> tests;
	for (ii=1;ii<=tests;ii++)
	{
		tedad=0;
		cin >> m >> n;
		for (int i=1;i<=m;i++)
			for (int j=1;j<=n;j++)
				cin>> jadval[i][j];
		for (int i=1;i<=m;i++)
			for (int j=1;j<=n;j++)
				if (visit[i][j]!=ii && jadval[i][j]=='@')
				{
					dfs(i,j);
					tedad++;
				}
		cout << tedad << endl;
	}
	return 0;
}

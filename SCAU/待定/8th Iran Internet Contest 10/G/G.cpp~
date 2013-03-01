#include <iostream>
#include <map>
using namespace std;

const int maxn=250;


int m,n,a,b,c,visit[maxn][maxn][10],test_number,adad[5],tedad;
map<string,int> tr;
char jadval[maxn][maxn];

bool good(int row1,int col1,string cube)
{
	int satr=adad[cube[0]-'a'];
	int sotun=adad[cube[1]-'a'];
	int cube_number=tr[cube];
	if (visit[row1][col1][cube_number]==test_number)
		return false;
	for (int i=row1;i<row1+satr;i++)
		for (int j=col1;j<col1+sotun;j++)
		{
			if (i<1 || j<1 || i>m || j>n)
				return false;
			if (jadval[i][j]=='R')
				return false;
		}
	return true;
}

void dfs(int row1,int col1,string cube)
{
	int cube_number=tr[cube];
	visit[row1][col1][cube_number]=test_number;
	int satr=adad[cube[0]-'a'];
	int sotun=adad[cube[1]-'a'];
	int ertefa=adad[cube[2]-'a'];
	string next_cube="DDD";
	for (int i=row1;i<row1+satr;i++)
		for (int j=col1;j<col1+sotun;j++)
		{
			if (jadval[i][j]=='R')
			{
				cout <<"WRONG" << endl;
				exit(0);
			}
			if (jadval[i][j]=='B' && jadval[i][j]!='*')
			{
				tedad++;
				jadval[i][j]='*';
			}
		}
	next_cube[0]=cube[2];
	next_cube[1]=cube[1];
	next_cube[2]=cube[0];
	if (good(row1+satr,col1,next_cube))
	{
		dfs(row1+satr,col1,next_cube);
	}	
	next_cube[0]=cube[2];
	next_cube[1]=cube[1];
	next_cube[2]=cube[0];
	if (good(row1-ertefa,col1,next_cube))
		dfs(row1-ertefa,col1,next_cube);


	next_cube[0]=cube[0];
	next_cube[1]=cube[2];
	next_cube[2]=cube[1];	
	if (good(row1,col1+sotun,next_cube))
		dfs(row1,col1+sotun,next_cube);

	

	next_cube[0]=cube[0];
	next_cube[1]=cube[2];
	next_cube[2]=cube[1];
	if (good(row1,col1-ertefa,next_cube))
		dfs(row1,col1-ertefa,next_cube);
}

int main()
{
	int tests;
	cin >> tests;
	tr["abc"]=1;
	tr["acb"]=2;
	tr["bac"]=3;
	tr["bca"]=4;
	tr["cab"]=5;
	tr["cba"]=6;
	for (int ii=1;ii<=tests;ii++)
	{
		test_number=ii;
		cin >> a >> b >> c;
		cin >> m >> n;
		tedad=0;
		adad[0]=a;
		adad[1]=b;
		adad[2]=c;
		for (int i=1;i<=m;i++)
			for (int j=1;j<=n;j++)
				cin >> jadval[i][j];
		dfs(1,1,"abc");
		cout << tedad << endl;
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <string>
//#include <fstream>
using namespace std;

int findpos(int m, int l, int t, int r)
{
	int f=m-l;
	if(r >= f && r <= m)
	{
		if(r-t%(l+1) < f)		//有跨过循环范围
			r=m-(t%(l+1)-(r-f))+1;
		else
			r=r-t%(l+1);		//没有跨过循环范围
	}
	return r;
}

int main()
{
	int N,R;
	int M1,L1,T1;	//所处排名M1，排名向前L1名，有T1次滚动
	int M2,L2,T2;
	string name[10001];

	//ifstream fin("promote.in");
	//ofstream fout("data0.out");

	int cnt;
	cin>>cnt;
	//fin>>cnt;
	while(cnt--)
	{
		//fin>>N>>R;
		//fin>>M1>>L1>>T1;
		//fin>>M2>>L2>>T2;
		cin>>N>>R;
		cin>>M1>>L1>>T1;
		cin>>M2>>L2>>T2;

		for(int i=1;i<=N;i++)
			cin>>name[i];

		//for(int i=1;i<=N;i++)
		//	fin>>name[i];

		R=findpos(M2, L2, T2, R);
		R=findpos(M1, L1, T1, R);

		cout<<name[R]<<endl;
		//fout<<name[R]<<endl;
	}

	return 0;
}

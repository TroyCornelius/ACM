#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
using namespace std;

void massmove(int b, int m, string name[])
{
	string tmp=name[m];
	for(int i=m;i>b;i--)
		name[i]=name[i-1];
	name[b]=tmp;
}

int main()
{
	int N,R;
	int M1,L1,T1;	//所处排名M1，排名向前L1名，有T1次滚动
	int M2,L2,T2;
	string name[10001];

	ifstream fin("promote_s2.in");
	ofstream fout("promote_s2.out");

	int cnt=0;
	while(fin>>N)
	{
		++cnt;

		fin>>R;
		fin>>M1>>L1>>T1;
		fin>>M2>>L2>>T2;

		for(int i=1;i<=N;i++)
			fin>>name[i];

		for(int i=0;i<T1;i++)
			massmove(M1-L1, M1, name);
		for(int i=0;i<T2;i++)
			massmove(M2-L2, M2, name);

		cout<<name[R]<<endl;
		fout<<name[R]<<endl;
	}

	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

int getPrime(int N,int p[])
{
	int i,j,N2=N/2;
	memset(p,1,N2*sizeof(int));
	for (i=3;i*i<N;i+=2)
		if (p[i>>1])
			for(j=(i*i)>>1;j<N2;j+=i) p[j]=0;
	j=1; p[0]=2; REP(i,1,N2) if (p[i]) p[j++]=i*2+1;
	return j;
}


void getEulerPhiUsePrimes(int N,ll phi[],int ps,int p[])
{
	int i,j,k;
	REP(i,1,N) phi[i]=i;
	rep(i,ps)
	{
		j=k=p[i];
		while(j<N){phi[j]=phi[j]/k*(k-1);j+=k;}
	}
}

#define Y 200000
ll phi[Y]; int ps,p[Y];
ll in[500]; ll size;


ll sol(int d,ll m,int *up)
{
	int i,j,chk;
	ll res,num,next,num_is_big=0;

	if (m==1)
	{
		if(in[d]>1) *up=1;
		else *up=0;
		return 0;
	}

	if (in[d]>=m) {*up=1; return 0;}

	num=1;
	REP(i,2,in[d]+1)
	{
		num=num*i;
		if (num>=m) num_is_big=1, num%=m;
	}

	next=sol(d+1,phi[m],&chk);
	if (chk==1) next+=phi[m];

	res=1; *up=0;
	rep(i,next)
	{
		res=res*num;
		if (res>=m) *up=1, res%=m;
		if (num_is_big) *up=1;
	}
	
	return res;
}

int Calculate_value(vector<int> a, int m)
{
	int i;
	size=a.size();
	rep(i,size) in[i]=a[i];
	ps=getPrime(Y,p); getEulerPhiUsePrimes(Y,phi,ps,p);

	if (m==1) return 0;
	return sol(0,m,&i);
}

int main()
{
	int tests;
	cin >> tests;
	int n,m;
	vector<int> a;
	for (int test_number=1;test_number<=tests;test_number++)
	{
		for (int i=0;i<Y;i++)
			phi[i]=p[i]=0;
		for (int i=0;i<500;i++)
			in[i]=0;
		cin>> n >> m;
		a.clear();
		for (int i=1;i<=n;i++)
		{
			int numm;
			cin >> numm;
			a.push_back(numm);
		}
		cout << Calculate_value(a,m) << endl;
	}
	return 0;
}

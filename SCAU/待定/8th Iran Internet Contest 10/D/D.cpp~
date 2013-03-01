#include <iostream>
using namespace std;

const int maxn=20000;
int m,n,t,tedad[maxn],bad[maxn],prime[maxn],sum[maxn];
void make_prime()
{

	for (int i=2;i<=10000;i++)
	{
		if (!bad[i])
		{
			prime[++m]=i;
			for (int j=2*i;j<=10000;j+=i)
				bad[j]=true;
		}
	}
}

int main()
{
	make_prime();
	for (int i=1;i<=m;i++)
	{
		sum[i]=sum[i-1]+prime[i];
		if (sum[i]<=10000)
			tedad[sum[i]]++;
	}
	for (int i=1;i<=m;i++)
		for (int j=i+1;j<=m;j++)
			if (sum[j]-sum[i]<=10000)
				tedad[sum[j]-sum[i]]++;
	cin >> t;
	for (int test_number=1;test_number<=t;test_number++)
	{
		cin >> n;
		cout << tedad[n] << endl;
	}
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;


const int maxn=20000;

int n;
long long A[maxn],S[maxn];

int sol()
{
	sort(A,A+n);
	reverse(A,A+n);
	for (int i=0;i<n;i++) S[i]=A[i];
	long long r=0;
	for (int i=0;i<n;i++)
		if (S[i]==0) 
			r+=A[i];
		else
		{
			long long p=(S[i]^(S[i]-1))&S[i];
			for (int j=i+1;j<n;j++)
				if (S[j]&p)
					S[j]^=S[i];
		}
	return r;
		
}

int main()
{
	int t;
	cin >> t;
	for (int test_number=1;test_number<=t;test_number++)
	{
		cin >> n;
		for (int i=0;i<maxn;i++)
			A[i]=S[i]=0;
		for (int i=0;i<n;i++)
			cin >> A[i];
		cout << sol() << endl;
	}
	return 0;
}

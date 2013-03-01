#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

typedef long long llong;
typedef vector<llong> tVLL;

int n;
int p[128];
int hp[128];
int tmp[128];
int mp[128];


llong gcd(const llong a, const llong b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

llong permorder()
{
	llong res = 1;		
	
	for (int i=0; i<n; i++)
	{
		int c = i;
		llong cnt = 1;
		while (p[c] != i)
		{
			c = p[c];
			++cnt;
		}

		llong d = gcd(res, cnt);
		res /= d;
		res *= cnt;
	}
	return res;
}


void calcperm(llong ex)
{
	for (int i=0; i<n; i++)
	{
		mp[i] = i;
		hp[i] = p[i];
	}

	while (ex)
	{
		if (ex & 1LL)
		{
			for (int i=0; i<n; i++)
				mp[i] = hp[mp[i]];
		}
		for (int i=0; i<n; i++) tmp[i] = hp[i];
		for (int i=0; i<n; i++) hp[i] = tmp[tmp[i]];

		ex >>= 1;
	}
}

int main()
{
//	ifstream in("decode.in");
	llong m;
	while (cin >> n >> m)
	{	
		if (!n && !m) break;
		assert(n>=1 && n<=80);
		assert(m>=1 && m<=1000000000);
		for (int i=0; i<n; i++)
		{
			cin >> p[i];
			--p[i];
		}
		cin.ignore();
		string enc;
		getline(cin, enc);

		llong ord = permorder();
		m %= ord;
        cout <<ord <<endl;
		llong ex = ord - m;
		
		calcperm(ex);
		string dec = enc;
		for (int i=0; i<n; i++)
		{
			dec[i] = enc[mp[i]];
		}
		cout << dec << endl;
	}
    system("pause");
    
	return 0;
}

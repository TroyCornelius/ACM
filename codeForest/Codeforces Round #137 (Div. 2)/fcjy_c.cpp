#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>

#define PI pair<int, int>
#define MP make_pair

const double pi = acos(-1.);
const double eps = 1e-10;
const int INF = (1<<30);
const int mod = 1000000007;
const int maxn = 1;

using namespace std;

bool isp[5000];
int p[5000], e;
int sum1[5000], sum2[5000];
map<int, int> d1, d2;

int cnt1[10000001];
int cnt2[10000001];

void add( int v, int* a, int& res )
{
	int i, j, k;

	for( i = 0; i < e && p[i] <= v; ++i )
	{
		while( v%p[i] == 0 )
		{
			v /= p[i];
			a[i]++;
		}
	}

	res = v;
}

void gao( int& v, int* a )
{
	int i, j, k;

	for( i = 0; i < e && p[i] <= v; ++i )
	{
		while( v%p[i] == 0 && a[i] > 0 )
		{
			v /= p[i];
			a[i]--;
		}
	}
}

int n1[100010], n2[100010];
int res1[100010], res2[100010];

int main()
{
	//freopen("dd.in","r",stdin);
	//freopen("dd.out","w",stdout);

	int i, j, k;
	long long t;
	int n, m;

	memset(isp, 0, sizeof(isp));
	e = 0;
	for( i = 2; i < 3200; ++i )	if( !isp[i] )
	{
		p[e++] = i;
		for( j = i+i; j < 3200; j = j+i )
			isp[j] = 1;
	}

	while( scanf("%d %d", &n, &m) != EOF )
	{
		for( i = 0; i < n; ++i )
		{
			scanf("%d", &n1[i]);
			add(n1[i], sum1, res1[i]);
		}
		for( i = 0; i < m; ++i )
		{
			scanf("%d", &n2[i]);
			add(n2[i], sum2, res2[i]);
		}

		for( i = 0; i < e; ++i )
		{
			if( sum1[i] >= sum2[i] )
				sum1[i] = sum2[i];
			else
				sum2[i] = sum1[i];
		}

		for( i = 0; i < n; ++i )
			gao(n1[i], sum1);
		for( i = 0; i < m; ++i )
			gao(n2[i], sum2);

		for( i = 0; i < n; ++i )	if( res1[i] != 1 )
			cnt1[res1[i]]++;
		for( i = 0; i < m; ++i )	if( res2[i] != 1 )
			cnt2[res2[i]]++;

		for( i = 0; i < n; ++i )	if( res1[i] != 1 )
		{
			if( cnt2[res1[i]] > 0 )
			{
				cnt2[res1[i]]--;
				n1[i] /= res1[i];
			}
		}

		for( i = 0; i < m; ++i )	if( res2[i] != 1 )
		{
			if( cnt1[res2[i]] > 0 )
			{
				cnt1[res2[i]]--;
				n2[i] /= res2[i];
			}
		}

		printf("%d %d\n", n, m);
		for( i = 0; i < n; ++i )
		{
			if( i )	printf(" ");
			printf("%d", n1[i]);
		}
		puts("");
		for( i = 0; i < m; ++i )
		{
			if( i )	printf(" ");
			printf("%d", n2[i]);
		}
		puts("");
	}

	return 0;
}


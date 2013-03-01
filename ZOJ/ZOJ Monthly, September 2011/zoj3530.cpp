#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <cassert>
#define pi acos(-1.0)
#define MAX 1000000000
using namespace std;
int a[1001];
int G[1001];
int i,j;
int main()
{
	long long t,n,F,W,g;
	long long f,rate,ans,def;
	while(cin>>n>>F>>W>>g)
	{
		assert(1 <= n && n <= 1000);
		assert(1 <= F && F <= 10000);
		assert(1 <= W && W <= 10000);
		assert(1 <= g && g <= 1000000);
		for(i=1;i<=n;i++) {
			assert(scanf("%d%d",&a[i],&G[i]) == 2);
			assert(1 <= a[i] && a[i] <= 1000000);
			assert(1 <= G[i] && G[i] <= 1000000);
		}
		G[0]=g;
		def=0;
		for(i=1;i<=n;i++)
		{
			if(def<a[i])
			{
				for(j=i-1;j>=0;j--)
				{
					if(a[i]-def<=G[j])
					{
						G[j]-=(a[i]-def);
						def=a[i];
						break;
					}
					else
					{
						def+=G[j];
						G[j]=0;
					}
				}
				if(def<a[i])
					break;
			}
		}
		if(i<=n)
		{
			printf("It's useless to collect wood.\n");
			continue;
		}
		ans=0;
		f=0;
		rate=W;
		g=0;
		for(i=0;i<=n;i++)
		{
			g+=G[i];
			t=g/F;
			g=g%F;
			ans+=f*rate;
			if(t+f>rate)
			{
				t=t+f-rate;
				f=rate;
				f+=t/2;
				rate+=t/2;
				if(t%2)
					f++;
			}
			else
				f+=t;
		}
		cout<<ans<<endl;
	}
	return 0;
}


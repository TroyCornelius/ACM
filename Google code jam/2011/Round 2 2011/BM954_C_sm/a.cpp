#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;
#define M 1100

bool notp[M];//素数判定
int pr[670],pn,ans;//pr存放素数,pn当前素数个数。
void getprime()
{
	pn=0;
	memset(notp,0,sizeof(notp));
	for(int i=2;i<M;i++) 
	{
		if(!notp[i])
			pr[pn++]=i;
		for(int j=0;j<pn && pr[j]*i<M;j++) 
		{
			notp[pr[j]*i]=1;
			if(i%pr[j]==0)break;
		}
	}
}

int n;

int bs(int x)
{
	int low=0,mid,high=pn-1;
	while(low<high)
	{
		mid=(low+high)>>1;
		if(x==pr[mid])
			return mid;
		if(x>pr[mid])
			low=mid+1;
		else
			high=mid-1;
	}
	return high;
}

int main()
{
	int i,j,k,t,tc=1;
	int amin,amax;
	freopen("gcj/2011.6.4/C-small-attempt0.in","r",stdin);
	freopen("in.txt","w",stdout);
	scanf("%d",&t);
	getprime();
	while(t--)
	{
		printf("Case #%d: ", tc++);
		scanf("%d",&n);
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		amin=bs(n);
		amax=1;
		for(i=0;i<amin;i++)
		{
			k=n;
			while(k>=pr[i])
			{
				k/=pr[i];
				amax++;
			}
		}
		//if(pr[amin]==n) amax++;
		
		printf("%d\n",amax-amin);
	}
	return 0;
}

/*
2
6 7 2
1111111
1122271
1211521
1329131
1242121
1122211
3 3 7
123
234
345
*/


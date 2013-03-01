#include<stdio.h>
#include<string.h>

int a[10100000],b[10100000];
int isp[101000];
int sushu[11000],num;
int zuishao[10100000];

void cal(int *c,int n)
{
	int i,j;
	for(i=1;sushu[i]*sushu[i]<=n;i++)if(n%sushu[i]==0)
	{
		while(n%sushu[i]==0)
			c[sushu[i]]++,n/=sushu[i];
	}
	if(n>1)
		c[n]++;
}
int f(int *c,int n)
{
	int i,j=n;
	for(i=1;sushu[i]*sushu[i]<=n;i++)if(n%sushu[i]==0)
	{
		while(n%sushu[i]==0)
		{
			if(c[sushu[i]])
				c[sushu[i]]--,j/=sushu[i];
			n/=sushu[i];
		}
	}
	if(n>1)
	{
		if(c[n])
			c[n]--,j/=n;
	}
	return j;
}
int aa[110000],bb[110000];
int main()
{
	int n,m,i,j,nn,mm;
	for(i=2;i<=11000;i++)if(!isp[i])
	{
		sushu[++num]=i;
		for(j=i+i;j<=11000;j+=i)
			isp[j]=1;
	}

	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&j),cal(a,j),aa[i]=j;
	for(i=1;i<=m;i++)
		scanf("%d",&j),cal(b,j),bb[i]=j;
	for(i=1,nn=mm=0;i<=10000000;i++)
		zuishao[i]=a[i]<b[i]?a[i]:b[i],a[i]=zuishao[i];
	for(i=1;i<=n;i++)
		aa[i]=f(zuishao,aa[i]);
	for(i=1;i<=m;i++)
		bb[i]=f(a,bb[i]);
	printf("%d %d\n",n,m);
	for(i=1;i<n;i++)
		printf("%d ",aa[i]);
	printf("%d\n",aa[n]);
	for(i=1;i<m;i++)
		printf("%d ",bb[i]);
	printf("%d\n",bb[i]);
}


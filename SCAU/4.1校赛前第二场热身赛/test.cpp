#include<stdio.h>
main(void)
{
	int n, y[102], m[102], d[102], i, j, k, s, q;
	scanf("%d", &q);
	for(n=0; n<q; n++)
	{
		scanf("%d %d %d", &y[n], &m[n], &d[n]);
	}
	for(n=0; n<q; n++)
	{
		for(j=m[n]; j<=m[n]; j++)
		{
			if(y[n]<2001&&y[n]%4==0&&y[n]%100==0)
			{
				if(j==2)  k=29-d[n];
				else if(j==4||j==6||j==9||j==11)  k=30-d[n];
				else k=31-d[n];
			}
			else if(y[n]<2001&&y[n]%4==0&&y[n]%100!=0)
			{
				if(j==2)  k=29-d[n];
				else if(j==4||j==6||j==9||j==11)  k=30-d[n];
				else k=31-d[n];
			}
			else if(y[n]<2001)
			{
				if(j==2)  k=28-d[n];
				else if(j==4||j==6||j==9||j==11)  k=30-d[n];
				else k=31-d[n];
			}
			else if(y[n]==2001)
			{
				if(j==2)  k=28-d[n];
				else if(j==4||j==6||j==9)  k=30-d[n];
				else if(j==11) k=4-d[n];
				else k=31-d[n];
			}
		}
		s = k;
		for(i=y[n]; i<2002; i++)
		{
			for(j=m[n]+1; j<12; j++)
			{
				if(y[n]%4==0&&y[n]%100==0)
			{
				if(j==2)  s+=29;
				else if(j==4||j==6||j==9)  s+=30;
				else if(j==11) s+=4;
				else s+=31;
			}
			else if(y[n]%4==0&&y[n]%100!=0)
			{
				if(j==2)  s+=29;
				else if(j==4||j==6||j==9)  s+=30;
				else if(j==11) s+=4;
				else s+=31;
			}
			else
			{
				if(j==2)  s+=29;
				else if(j==4||j==6||j==9)  s+=30;
				else if(j==11) s+=4;
				else s+=31;
			}
			}
		}
		if(s%2!=0)  printf("YES\n");
		else  printf("NO\n");
	}
	return 0;
}


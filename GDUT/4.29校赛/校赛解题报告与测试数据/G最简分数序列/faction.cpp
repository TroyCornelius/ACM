#include <iostream>
#include <cstdio>
using namespace std;

typedef long long lld;

const lld mtx[2][2][2]={{1,1,0,1},{1,0,1,1}};

bool mtxeql(lld m1[2][2], const lld m2[2][2])
{
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			if(m1[i][j] != m2[i][j])
				return false;
	return true;
}

void mtxcpy(lld m1[2][2], const lld m2[2][2])
{
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			m1[i][j]=m2[i][j];
}

void mtxmul(lld m1[2][2], const lld m2[2][2])
{
	lld m3[2][2]={0};
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				m3[i][j]+=m1[i][k]*m2[k][j];
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			m1[i][j]=m3[i][j];
}

void extendedgcd(lld m, lld n, lld &x, lld &y)
{
	//x*m+y*n=gcd(m,n), n>=m
	//printf("m:%d n:%d\n", m, n);
	x=0;
	y=1;
	if(m == 0) return;
	lld xx,yy;
	extendedgcd(n%m, m, xx, yy);
	x=yy-(n/m)*xx;
	y=xx;
	//printf("x:%d y:%d\n", x, y);
}

void matrixize(lld nc, lld de, lld m[2][2])
{
	lld x,y;
	extendedgcd(nc, de, x, y);
	if(x < 0)
	{	//x小于0，偏大型
		m[0][1]=-x;
		m[1][1]=y;
		m[0][0]=de-(-x);
		m[1][0]=nc-y;
	}
	else
	{	//x大于0，偏小型
		m[0][0]=x;
		m[1][0]=-y;
		m[0][1]=de-x;
		m[1][1]=nc-(-y);
	}
}

void trace_fordward(lld &nc, lld &de, lld n)
{
	lld m[2][2];
	lld m1[2][2];
	lld m2[2][2];

	matrixize(nc, de, m);
	mtxcpy(m1, m);
	mtxmul(m1, mtx[1]);	//向右分支前进一步
	if(m1[0][0]+m1[0][1] > n)
	{	//连向右分支走一步都不对了
		//取右方紧邻的较大的分数
		de=m[0][1];
		nc=m[1][1];
	}
	else
	{
		//接下来就向左分支遍历，一路到底
		mtxcpy(m, m1);
		mtxcpy(m2, mtx[0]);
		//做矩阵乘法，直到连只乘一次都会超出范围
		do
		{
			mtxmul(m1, m2);
			if(m1[0][0]+m1[0][1] > n)
			{
				if(mtxeql(m2, mtx[0]))
					break;	//连只是乘了一次都会超出范围，停止循环
				mtxcpy(m1, m);		//还原
				mtxcpy(m2, mtx[0]);
			}
			else
			{
				mtxcpy(m, m1);
				mtxmul(m2, m2);
			}
		}while(true);
		de=m[0][0]+m[0][1];
		nc=m[1][0]+m[1][1];
	}
}

int main()
{
	freopen("faction.in", "r", stdin);
	freopen("faction.out", "w", stdout);

	int T,N,len;
	lld nc,de;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);
		scanf("%I64d", &nc);
		scanf("%I64d", &de);
		scanf("%d", &len);

		for(int i=0;i<len;i++)
		{
			if(nc==1 && de==1)
				break;
			trace_fordward(nc, de, N);
			printf("%I64d %I64d\n", nc, de);
		}
		printf("End\n\n");
	}

	return 0;
}

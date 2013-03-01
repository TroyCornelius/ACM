#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define seq(a) ((a)*(a))

int main()
{
	int T;
	int xo,yo;
	int x1,y1;
	int x2,y2;
	double d;

	freopen("rectangle.in", "r", stdin);
	freopen("rectangle.out", "w", stdout);
	scanf("%d", &T);

	while(T--)
	{

		scanf("%d%d", &xo, &yo);
		scanf("%d%d", &x1, &y1);
		scanf("%d%d", &x2, &y2);
		scanf("%lf", &d);

		double aq=seq(x1-xo)+seq(y1-yo);
		double bq=seq(x2-xo)+seq(y2-yo);
		double cq=seq(x1-x2)+seq(y1-y2);
		double a=sqrt(aq);
		double b=sqrt(bq);

		double nc=4*a*b*d*d;
		double de=4*aq*bq-seq(aq+bq-cq);
		double area=nc/sqrt(de);

		printf("%.2lf\n", area);
	}
	return 0;
}

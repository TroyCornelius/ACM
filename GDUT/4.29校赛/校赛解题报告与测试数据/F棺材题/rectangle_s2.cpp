#include <iostream>
#include <cmath>
using namespace std;

typedef double db;
#define sq(a) ((a)*(a))
const db pre = 1e-12;

struct point
{
	int x,y;
	db xx,yy;
	point() {}
	point(int x1, int y1)
	{ x=x1; y=y1; xx=x1; yy=y1; }
	//point(db x2, db y2): xx(x2), yy(y2) {}
};

struct line
{
	db a,b,c;
	point p,q;
	//line(): a(0), b(0), c(0) {}
	//line(db aa, db bb, db cc): a(aa), b(bb), c(cc) {}
};

/***************************
把直线变为一般式
ax + by + c = 0.
***************************/
void lcnvrs(point p, point q, line &l)
{
	l.a = p.y - q.y;
	l.b = q.x - p.x;
	l.c = p.x * q.y - q.x * p.y;
}

/********************************************
计算相交坐标。两直线均用一般式表示，交点为p。
********************************************/
int intersect( line l1, line l2 , point &p )
{
	db db1;

	db1 = l1.a * l2.b - l1.b * l2.a;	//db1 = 0 表示两直线平行。
	if( db1 < pre || db1 > pre )
	{
		p.xx = ( l1.b * l2.c - l1.c * l2.b ) / db1;
		p.yy = ( l1.c * l2.a - l1.a * l2.c ) / db1;
		return 1;
	}
	return 0;
}

line move(line l, double d)
{
	line ltmp=l;
	ltmp.c += d*sqrt(sq(l.a)+sq(l.b));
	return ltmp;
}

point symmetry(point p, point o)
{
	point q;
	q.xx=2*o.xx-p.xx;
	q.yy=2*o.yy-p.yy;
	return q;
}

db distance(point* p, point* q)
{
	return sqrt(sq(p->xx-q->xx)+sq(p->yy-q->yy));
}

int main()
{
	int T;
	int xo,yo;
	int x1,y1;
	int x2,y2;
	double d;

	freopen("rectangle.in", "r", stdin);
	freopen("rectangle_s2.out", "w", stdout);
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &xo, &yo);
		scanf("%d%d", &x1, &y1);
		scanf("%d%d", &x2, &y2);
		scanf("%lf", &d);

		point O(xo, yo);
		point A(x1, y1);
		point B(x2, y2);
		line lOA;
		lcnvrs(A, O, lOA);
		line lOB;
		lcnvrs(B, O, lOB);
		line lOC;
		lOC=move(lOA, d);
		point ps1;
		intersect(lOB, lOC, ps1);
		line lOD;
		lOD=move(lOB, d);
		point ps2;
		intersect(lOA, lOD, ps2);
		point ps3;
		ps3=symmetry(ps2, O);
		db w = distance(&ps1, &ps2);
		db h = distance(&ps1, &ps3);
		printf("%.2lf\n", w*h);
	}

	return 0;
}

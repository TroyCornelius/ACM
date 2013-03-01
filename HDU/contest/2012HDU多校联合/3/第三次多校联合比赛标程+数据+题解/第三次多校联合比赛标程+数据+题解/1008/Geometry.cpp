#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair
#define A first
#define B second
#define eps 1e-11
#define len 1
#define rot 0.70710678118654752440084436210485
#define MAXN 210
#define zero(x) (((x)>0?(x):-(x))<eps)

struct point{
    double x, y;
} p[210], p1[210];

void rotate(point &p) {
    point p1;
    p1.x = p.x * rot - p.y * rot;
    p1.y = p.x * rot + p.y * rot;
    p = p1;
}

double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int same_side(point p1,point p2,point l1,point l2){
	return xmult(l1,p1,l2)*xmult(l1,p2,l2)>eps;
}

point intersection(point u1,point u2,point v1,point v2){
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
			/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}

//将多边形沿l1,l2确定的直线切割在side侧切割,保证l1,l2,side不共线
void polygon_cut(int& n,point* p,point l1,point l2,point side){
	point pp[200];
	int m=0,i;
	for (i=0;i<n;i++){
		if (same_side(p[i],side,l1,l2))
			pp[m++]=p[i];
		if (!same_side(p[i],p[(i+1)%n],l1,l2)&&!(zero(xmult(p[i],l1,l2))&&zero(xmult(p[(i+1)%n],l1,l2))))
			pp[m++]=intersection(p[i],p[(i+1)%n],l1,l2);
	}
	for (n=i=0;i<m;i++)
		if (!i||!zero(pp[i].x-pp[i-1].x)||!zero(pp[i].y-pp[i-1].y))
			p[n++]=pp[i];
	if (zero(p[n-1].x-p[0].x)&&zero(p[n-1].y-p[0].y))
		n--;
	if (n<3)
		n=0;
}

double area(int n, point* p) {
    if (n == 0) return 0;
    int s = 0;
    for (int i = 1; i < n; i ++ ) {
        if (p[i].y < p[s].y)
            s = i;
    }
    double ans = 0;

    for (int i = s, j = 0; j != n; i = (i + 1) % n, j ++ ) {
        int j = (i + n - 1) % n;
        if (zero(p[i].y - p[j].y)) continue;
        double a = - (p[i].x - p[j].x) / (p[i].y - p[j].y) * rot * 2;
        double b = - (p[j].x - p[j].y * (p[i].x - p[j].x) / (p[i].y - p[j].y)) * rot * 2
                   + 2 * (p[i].x - p[j].x) / (p[i].y - p[j].y);
        double c = (p[j].x - p[j].y * (p[i].x - p[j].x) / (p[i].y - p[j].y)) * 2;
        ans = ans + a / 3 * (p[i].y * p[i].y * p[i].y - p[j].y * p[j].y * p[j].y);
        ans = ans + b / 2 * (p[i].y * p[i].y - p[j].y * p[j].y);
        ans = ans + c * (p[i].y - p[j].y);
    }
    return fabs(ans);
}

int t, n;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas ++ ) {
        scanf("%d", &n);
        for (int j = 0; j < n; j ++ ) {
            scanf("%lf%lf", &p[j].x, &p[j].y);
            rotate(p[j]);
        }
        printf("Case #%d:\n", cas);
        double ans = 0;
        for (int i = 0; i < n; i ++ ) {
            p1[0].x = 0, p1[0].y = 0;
            p1[1].x = len * rot, p1[1].y = len * rot;
            p1[2].x = 0, p1[2].y = len * rot * 2;
            p1[3].x = -len * rot, p1[3].y = len * rot;
            int m = 4;
            for (int j = 0; j < n; j ++ )
                if (j != i) {
                    point l1, l2;
                    l1.x = (p[i].x + p[j].x) / 2;
                    l1.y = (p[i].y + p[j].y) / 2;
                    l2.x = l1.x - (p[i].y - p[j].y);
                    l2.y = l1.y + (p[i].x - p[j].x);
                    polygon_cut(m, p1, l1, l2, p[i]);
                }
            printf("%.6lf\n", area(m, p1));
        }
    }
    return 0;
}

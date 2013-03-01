#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define pi acos(-1.0)
using namespace std;
struct point{double x,y;}p[300+5];
int n;
double dis(const point &a,const point &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double k(const point &a, const point &b)
{
    double ki = atan(fabs((b.y-a.y)/(b.x-a.x)));
    if(b.y - a.y > 0)
       {if(b.x  - a.x < 0) ki = pi - ki;}
    else
       if(b.x < a.x) ki += pi;
       else ki = 2*pi - ki;
    return ki;
}
struct angle
{
	double ang;
	bool is;
}even[1000+10];
bool cmp(const angle &a, const angle &b){return a.ang < b.ang;}
int CircleMaxPoint(double r)
{
	int ans = 1, i, j, top;
	double dist,thi,delta;  
	for(i = 0; i < n; i++)
	{
		top = 0;
		for(j = 0; j < n; j++)
		{
			if(i == j) continue;
			dist = dis(p[i],p[j]);
			if(dist > 2 * r) continue;
			thi = k(p[i],p[j]);
			delta = acos(dist / 2.0 / r);
			even[top].ang = thi - delta; even[top++].is = true;
			even[top].ang = thi + delta; even[top++].is = false;
		}
		if(top < ans) continue;
		sort(even,even+top,cmp);
		int coun = 1;
		for(j = 0; j < top; j++)
		{
			if(even[j].is)
				coun++;
			else
				coun--;
			if(coun > ans)
				ans = coun;
		}
	}
	return ans;
}
int main()
{
	int t;
	while(scanf("%d", &n) != EOF)
	{
		if(!n) break;
		for(int i = 0; i < n; i++)
			scanf("%lf %lf", &p[i].x, &p[i].y);
		printf("%d\n", CircleMaxPoint(1.0));
	}
}


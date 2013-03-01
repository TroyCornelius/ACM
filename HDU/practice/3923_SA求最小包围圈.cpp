#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <time.h>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define BUG puts("here!!!")

using namespace std;

const int MAX = 1010;
const double inf = 1e30;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int N = 10;
const int L = 40;
bool dy(double x,double y)    {    return x > y + eps;}    // x > y 
bool xy(double x,double y)    {    return x < y - eps;}    // x < y 
bool dyd(double x,double y)    {     return x > y - eps;}    // x >= y 
bool xyd(double x,double y)    {    return x < y + eps;}     // x <= y 
bool dd(double x,double y)     {    return fabs( x - y ) < eps;}  // x == y
struct point { double x,y;
    point (double x,double y):x(x),y(y){}
    point ():x(0),y(0){}
};
double disp2p(point a,point b) //  a b 两点之间的距离 
{
    return sqrt(( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ));
}
point p[MAX];
point rp[MAX];
double len[MAX];
double min_dis(point a,point *p,int n)
{
    double min = 0;
    for(int i=0; i<n; i++)
    {
        double len = disp2p(a,p[i]);
        if( dy(len,min) )
            min = len;
    }
    return min;
}
bool check(point a,double x,double y)
{
    return dyd(a.x,0.0) && dyd(a.y,0) && xyd(a.x,x) && xyd(a.y,y);
}
point Rand(double x,double y)
{
	point c;
	c.x = ( rand()%1000 + 1 ) / 1000.0 * x;
	c.y = ( rand()%1000 + 1 ) / 1000.0 * y;
	return c;
}
int main()
{
    int n,m,ncases;
	double x,y;
	srand(time(NULL));
	while( ~scanf("%lf%lf%d",&x,&y,&n) )
	{
        for(int i=0; i<n; i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        for(int i=0; i<N; i++)
        {
			rp[i] = Rand(x,y);
			len[i] = min_dis(rp[i],p,n);
		}
        point st;
        double step = max(x,y)/sqrt((double)n);
        while( step > 0.001 )
        {
            for(int k=0; k<N; k++)
            {
				st = rp[k];
                for(int i=0; i<L; i++)
                {
					double ang = (rand()%1000+1)/1000.0*10*pi;
					double xx = st.x + step*cos(ang);
					double yy = st.y + step*sin(ang);	
                    point t = point(xx,yy);
                    if( !check(t,x,y) ) continue;
                    double dis = min_dis(t,p,n);
                    if( xy(dis,len[k]) )
                    {
                        rp[k] = t;
                        len[k] = dis;
                    }
                }
			}
            step *= 0.8;
        }
        int ind = 0;
        for(int i=1; i<N; i++)
        	if( len[i] < len[ind] )
        		ind = i;
		printf("(%.1lf,%.1lf).\n",rp[ind].x,rp[ind].y);
		printf("%.1lf\n",len[ind]);
    }

return 0;
}


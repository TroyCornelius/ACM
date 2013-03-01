#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
#define maxn 100
#define eps 1e-6
int dblcmp(double k)
{
    if(k > eps)
        return 1;
    else if(k < -eps)
        return -1;
    else
        return 0;
}
struct Plane
{
    double a,b,c;
    Plane(){}
    Plane(double _a,double _b,double _c):a(_a),b(_b),c(_c){}
};
struct Point_3D
{
    double x,y,z;
    Point_3D(){}
    Point_3D(double _x,double _y,double _z):x(_x),y(_y),z(_z){}
    double X(Point_3D p)
    {
        return p.x * x + p.y * y + p.z * z;
    }

    Point_3D O(Point_3D p)
    {
        return Point_3D(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);
    }
    void get()
    {
        scanf("%lf%lf%lf",&x,&y,&z);
    }
    void print()
    {
        printf("%.2lf %.2lf %.2lf\n",x,y,z);
    }
}point_3D[maxn];
struct Line_3D
{
    double dx,dy,dz;
    Point_3D pst;
    Line_3D(){}
    Line_3D(double _dx,double _dy,double _dz):dx(_dx),dy(_dy),dz(_dz){}
    Point_3D Line_Plane_intersection_3D(Plane pla)
    {
        double k = -(pst.x * pla.a + pst.y * pla.b + pst.z * pla.c) / (pla.a * dx + pla.b * dy + pla.c * dz);
        return Point_3D(pst.x + dx * k, pst.y + dy * k, pst.z + dz * k);
    }
};
struct Point
{
    double x,y;
    Point() {}
    Point(double _x,double _y):x(_x),y(_y) {}
    void get()
    {
        scanf("%lf%lf",&x,&y);
    }
    void print()
    {
        printf("(%.6lf,%.6lf) ",x,y);
    }
} p[maxn];
struct Line
{
    Point a,b;
    double ang;
    Line() {}
    Line(Point _a,Point _b):a(_a),b(_b) {}
} l[maxn],tl[maxn];
double cross(Point a,Point b,Point c)
{
    return (b.x-a.x)*(c.y-b.y)-(b.y-a.y)*(c.x-b.x);
}
inline bool cmp(Line l1,Line l2)
{
    if(fabs(l1.ang - l2.ang) < eps)
        return cross(l1.a,l2.a,l2.b) > eps;
    return l1.ang < l2.ang;
}
Point Intersection(Line l1,Line l2)
{
    Point s1,t1,s2,t2,pp;
    s1 = l1.a,t1 = l1.b;
    s2 = l2.a,t2 = l2.b;
    double d1,d2;
    d1 = cross(s1,s2,t1);
    d2 = cross(s1,t1,t2);
    pp.x = (s2.x * d2 + t2.x * d1)/(d2 + d1);
    pp.y = (s2.y * d2 + t2.y * d1)/(d1 + d2);
    return pp;
}
inline bool out(Point pt,Line tl)
{
    return cross(pt, tl.a, tl.b)< eps;//?
}
void HalfPlaneIntersection(int n,int &bot,int &top)
{
    int i,j;
    bot = 1,top = 2;
    sort(l,l+n,cmp);
    for(i=1,j=0; i < n; i++)
        if( fabs(l[j].ang - l[i].ang)>=eps )
            l[++j] = l[i];
    n = j + 1;

    tl[1] = l[0],tl[2] = l[1];
    for(i=2; i<n; i++)
    {
        while(bot < top && out(Intersection(tl[top],tl[top-1]),l[i]))
            --top;
        while(bot < top && out(Intersection(tl[bot],tl[bot+1]),l[i]))
            ++bot;
        tl[++top] = l[i];
    }
    while(bot < top && out( Intersection(tl[top], tl[top-1]),tl[bot]))
        --top;
    while(bot < top && out( Intersection(tl[bot], tl[bot+1]),tl[top]))
        bot++;
    return;
}
double polyArea(Point poly[],int numv)
{
    int i;
    //printf("----------------\n");
    double area = 0;
    //for(i=0; i < numv; i++)
    //    poly[i].print();
    //printf("\n");
    for(i=1; i<numv-1; i++)
        area += cross(poly[0],poly[i],poly[i+1]);
    //printf("----------------\n");
    return fabs(area/2.0);
}
double Core_Area(int k1,int k2)
{
    Point core[maxn];
    if(k2 - k1 < 2)
        return 0.0;
    int ct = 0,i;
    double area;
    /*
    for(i = k1; i <= k2; i++)
    {
        tl[i].a.print();
        printf("---");
        tl[i].b.print();
        printf("\n");
    }
    */
    for(i=k1;i<k2;i++)
        core[ct++] = Intersection(tl[i],tl[i+1]);
    core[ct++] = Intersection(tl[k2],tl[k1]);
    area = polyArea(core,ct);
    return area;
}
Point ph[3][maxn];
Point ans[3][maxn];
int tt[3];
double dis(Point a,Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y-b.y);
}
Point pk;
bool cmp2(Point a,Point b)
{
	if(dblcmp(cross(pk,a,b))==0)
		return dis(pk,a)-eps > dis(pk,b);
	return cross(pk,a,b) - eps > cross(pk,b,a);
}
Point p_hull[maxn];
void convex_hull(int numv,int id,Point p[])
{
	int i,k = 0;
	for(i=1;i<numv;i++)
	{
		if(p[i].y<p[k].y-eps || (fabs(p[i].y-p[k].y)<eps && p[i].x<p[k].x-eps))
			k = i;
	}
	if(k!=0)
	{
		Point tmp;
		tmp = p[0];
		p[0] = p[k];
		p[k] = tmp;
    }
    pk = p[0];
	sort(p+1,p+numv,cmp2);
	ans[id][0] = p[0];
	ans[id][1] = p[1];
	tt[id] = 1;
	for(int i=2;i<numv;i++)
	{
		if(dblcmp(cross(p[0],p[i-1],p[i]))==0)
			continue;
		while(cross(ans[id][tt[id]-1],ans[id][tt[id]],p[i])<0-eps)
			tt[id]--;
		ans[id][tt[id]+1] = p[i];
		tt[id]++;
    }
	return;
}

int main()
{
    Point_3D pp[3],p_3d;
    Line_3D l_3d;
    Plane pl_3d;
    Point tp;
    int cc,n,bot,top;
    int i,j;
    double area1,area2;
 //   freopen("data.in","r",stdin);
  //  freopen("data.out","w",stdout);
    while(scanf("%d",&n)!=EOF)
    {
        cc = 0;
        for(i = 0 ; i < n; i++)
        {
            point_3D[i].get();
        }

        for(i = 0 ; i < 3; i++)
        {
            tp.get();
            pp[i] = Point_3D(tp.x,tp.y,100.0);
            for(j = 0; j < n; j++)
            {
                l_3d = Line_3D(pp[i].x - point_3D[j].x, pp[i].y - point_3D[j].y, pp[i].z - point_3D[j].z);
                l_3d.pst = pp[i];
                pl_3d = Plane(0,0,1);
                p_3d = l_3d.Line_Plane_intersection_3D(pl_3d);
                ph[i][j] = Point(p_3d.x,p_3d.y);
            }
            convex_hull(n,i,ph[i]);
        }
        /*
        for(i = 0; i < 3; i++)
        {
            for(j = 0; j <= tt[i]; j++)
            {
                ans[i][j].print();
            }
            printf("\n");
        }
        */
        for(i = 0; i < 3; i++)
        {
            for(j = 0; j <= tt[i]; j++)
            {
                l[cc] = Line(ans[i][j],ans[i][(j+1)%(tt[i]+1)]);
                //l[cc].a.print();
                //printf("----");
                //l[cc].b.print();
                //printf("\n");
                //printf("-----------------\n");
                l[cc].ang = atan2(l[cc].a.y-l[cc].b.y,l[cc].a.x-l[cc].b.x);
                cc++;
            }
        }
        HalfPlaneIntersection(cc,bot,top);
        area1 = Core_Area(bot,top);
        printf("%.2lf\n",area1);
    }
    return 0;
}

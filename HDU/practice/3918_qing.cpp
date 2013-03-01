#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

#define FOR(i,s,t) for(int i=s;i<t;i++)
#define FRO(i,t,s) for(int i=t;i>s;--i)
#define CLR(a,c) memset(a,c,sizeof(a))
using namespace std;
const int maxn=101;
const double  eps=1e-8;
int m,n;
struct Point{
    double x,y;
    Point(){}
    Point(double a,double b){
        x=a,y=b;
    }
}p_left[maxn],p_right[maxn],pt[maxn+maxn];

int sig(double x){
    return x<-eps?-1:x>eps;
}

Point gravity(Point *org,int pn)
{
        //三角形重心是中线交点为：((X1+X2+X3)/3,(Y1+Y2+Y3)/3)
        Point center=Point(0,0);
        double area=0;
        org[pn]=org[0];
        FOR(i,0,pn){
                double tmp=org[i].x*org[i+1].y-org[i].y*org[i+1].x;
                area+=tmp/2;
                center.x+=tmp*(org[i].x+org[i+1].x);
                center.y+=tmp*(org[i].y+org[i+1].y);
        }
        center.x/=6*area;
        center.y/=6*area;
        return center;
}
Point interect(const Point &x,const Point &y,const double &a,const double &b,const double &c)
{
    double u=fabs(a*x.x+b*x.y+c);
    double v=fabs(a*y.x+b*y.y+c);
    return Point((x.x*v+y.x*u)/(u+v),(x.y*v+y.y*u)/(u+v));
}

double binary(double h,int le,int ri)
{
            double l=max(p_left[le].y,p_right[ri].y),r=h;
            while(sig(r-l)>0){
                        double mid=(l+r)/2;
                        int j=0;
                        FOR(i,0,le+1) pt[j++]=p_left[i];
                        pt[j++]=interect(p_left[le],p_left[le+1],0,1,-mid);
                        pt[j++]=interect(p_right[ri+1],p_right[ri],0,1,-mid);
                        FRO(i,ri,-1) pt[j++]=p_right[i];
                        double x=gravity(pt,j).x;
                        if(sig(x-p_left[0].x)>=0&&sig(p_right[0].x-x)>=0)
                              l=mid;
                        else  r=mid;
            }
            return l;
}
void solve()
{
    int le=1,ri=1;
    double y;
    while(le<m&&ri<n){
                int j=0;
                 y=min(p_left[le].y,p_right[ri].y);
                FOR(i,0,le) pt[j++]=p_left[i];
                if(sig(p_left[le].y-y)>0){
                        pt[j++]=interect(p_left[le-1],p_left[le],0,1,-y);
                }
                else{
                    pt[j++]=p_left[le];
                    le++;
                }
                if(sig(p_right[ri].y-y)>0){
                    pt[j++]=interect(p_right[ri],p_right[ri-1],0,1,-y);
                }
                else{
                    ri++;
                }
                FRO(i,ri-1,-1)  pt[j++]=p_right[i];
                double x=gravity(pt,j).x;
                if(sig(x-p_left[0].x)<0||sig(x-p_right[0].x)>0)  break;
    }
    if(sig(p_left[le-1].y-y)<0)  le--;
    else  le-=2;
    if(sig(p_right[ri-1].y-y)<0) ri--;
    else ri-=2;
    printf("%.3f\n",binary(y,le,ri));
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>m>>n;
        FOR(i,0,m){
            scanf("%lf%lf",&p_left[i].x,&p_left[i].y);
        }
        FOR(i,0,n){
            scanf("%lf%lf",&p_right[i].x,&p_right[i].y);
        }
        solve();
    }
    return 0;
}

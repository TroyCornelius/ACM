#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define EPS 1e-8
const int MAXN = 110;
struct Point{
	double x,y;
	Point(){}
	Point(double _x,double _y):x(_x),y(_y){}
	void input(){
		scanf("%lf%lf",&x,&y);
	}
};
struct Plane{
	double a,b,c;
	Plane(){}
	Plane(double _a,double _b,double _c):a(_a),b(_b),c(_c){}
};
struct TPoint{
	double x,y,z;
	TPoint(){}
	TPoint(double _x,double _y,double _z):x(_x),y(_y),z(_z){}
	double dotcross(TPoint p){
		return p.x*x + p.y*y + p.z*z;
	}
	TPoint difcross(TPoint p){
		return TPoint(p.z*y-p.y*z,p.x*z-p.z*x,p.y*x-p.x*y);
	}
	
	void input(){
		scanf("%lf%lf%lf",&x,&y,&z);
	}
	
};
struct TLine{
	double dx,dy,dz;
	TPoint st;
	TLine(){}
	TLine(double _dx,double _dy,double _dz,TPoint _st):dx(_dx),dy(_dy),dz(_dz),st(_st){}
};

inline TPoint LineInterPlane(TLine tli,Plane pla){
	double k = -(tli.st.x*pla.a + tli.st.y*pla.b + tli.st.z*pla.c) / (pla.a*tli.dx + pla.b*tli.dy + pla.c*tli.dz);
    return TPoint(tli.st.x + tli.dx*k, tli.st.y + tli.dy*k, tli.st.z + tli.dz*k);
}
Point p0;

inline double pdis(Point a,Point b){  
    return sqrt((a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y));  
}  
inline double det(Point p0,Point p1,Point p2){  
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y - p0.y);  
}  
inline int cmp(Point a,Point b){  
    double k = det(p0,a,b);  
    if(k > 0)return 1;  
    else if(k == 0 && pdis(p0,a) - pdis(p0,b) > 0)return 1;  
    return 0;  
}

Point ploy[3][MAXN],tploy[MAXN];
int graham[MAXN],top,num[3];
inline void Graham(int n,Point p[],int tag){  
    int i,u = 0;  
    for(i = 1; i < n; i++){  
        if(p[i].y < p[u].y || (p[i].y == p[u].y && p[i].x < p[u].x))u = i;  
    }  
    Point t;  
    t.x = p[u].x;t.y = p[u].y;  
    p[u] = p[0];  
    p[0] = t;
    p0 = p[0]; 
    sort(p+1,p+n,cmp);  
    graham[0] = 0;  
    graham[1] = 1;  
    graham[2] = 2;  
    top = 2;  
    for(i = 3; i < n; i++){  
        while(det(p[i],p[graham[top]],p[graham[top-1]]) > 0){  
            top--;  
            if(top == 0)break;  
        }  
        graham[++top] = i;  
    }
	num[tag] = 0;
	for(i = 0; i <= top; ++i)
		ploy[tag][num[tag]++] = p[graham[i]];

}  
/*半平面相交（点标号从1开始）*/
Point p[MAXN],q[MAXN];
int nt;
int cCnt,curCnt;
inline void getline(Point x,Point y,double &a,double &b,double &c){
    a = y.y - x.y;
    b = x.x - y.x;
    c = y.x * x.y - x.x * y.y;
}
inline Point intersect(Point x,Point y,double a,double b,double c){
    double u = fabs(a * x.x + b * x.y + c);
    double v = fabs(a * y.x + b * y.y + c);
    return Point( (x.x * v + y.x * u) / (u + v) , (x.y * v + y.y * u) / (u + v) );
}
inline void cut(double a,double b ,double c){
    curCnt = 0;
    for(int i = 1; i <= cCnt; ++i){
        if(a*p[i].x + b*p[i].y + c >= EPS)q[++curCnt] = p[i];
        else {
            if(a*p[i-1].x + b*p[i-1].y + c > EPS){
                q[++curCnt] = intersect(p[i],p[i-1],a,b,c);
            }
            if(a*p[i+1].x + b*p[i+1].y + c > EPS){
                q[++curCnt] = intersect(p[i],p[i+1],a,b,c);
            }
        }
    }
    for(int i = 1; i <= curCnt; ++i)p[i] = q[i];
    p[curCnt+1] = q[1];p[0] = p[curCnt];
    cCnt = curCnt;
}

TPoint psrc[3],pxz,tpoints[MAXN];
TLine tmpline;
Plane tmppla;
double x,y,z;
int n;

int main(){
//	freopen("data.in","r",stdin);
//    freopen("data_test.out","w",stdout);
	while (scanf("%d",&n) != EOF){
		for(int i = 0; i < n; ++i){
			tpoints[i].input();
		}
		memset(num,0,sizeof(num));
		for(int i = 0; i < 3; ++i){
			scanf("%lf%lf",&x,&y);
			psrc[i] = TPoint(x,y,100.0);
			for(int j = 0; j < n; ++j){
				tmpline = TLine(psrc[i].x - tpoints[j].x, psrc[i].y - tpoints[j].y, psrc[i].z - tpoints[j].z,psrc[i]);
				tmppla = Plane(0.0,0.0,1.0);
				pxz = LineInterPlane(tmpline,tmppla);
				tploy[j] = Point(pxz.x,pxz.y);
			}
			Graham(n,tploy,i);
		}
		
		//求交
		for(int i = 1; i <= num[0]; ++i){
                  p[i] = ploy[0][num[0]-i];
       }
		p[num[0]+1] = p[1];
		p[0] = p[num[0]];
		cCnt = num[0];
		
		ploy[1][num[1]] = ploy[1][0];
		ploy[2][num[2]] = ploy[2][0];
		double a,b,c;
		for(int i = num[1]; i >= 1; --i){
			getline(ploy[1][i],ploy[1][i-1],a,b,c);
			cut(a,b,c);
		}
		for(int i = num[2]; i >= 1; --i){
			getline(ploy[2][i],ploy[2][i-1],a,b,c);
			cut(a,b,c);
		}
		
		double area = 0;
		for(int i = 1; i <= curCnt; ++i){
			area += p[i].x * p[i + 1].y - p[i + 1].x * p[i].y;
        }
		area = fabs(area / 2.0);
		printf("%.2lf\n",area);
        
	}
	return 0;
}



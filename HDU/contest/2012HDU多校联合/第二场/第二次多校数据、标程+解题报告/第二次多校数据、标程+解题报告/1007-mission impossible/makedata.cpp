#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define eps 1e-6
#define maxn 300
#define MAXV 500
struct Point_3D
{
    double x,y,z;
    Point_3D(){}
    Point_3D(double _x,double _y,double _z):x(_x),y(_y),z(_z){}
    void print()
    {
        printf("%.2lf %.2lf %.2lf\n",x,y,z);
    }
    void get()
    {
        scanf("%lf%lf%lf",&x,&y,&z);
    }
}point_3D[maxn];

struct Point_2D
{
    double x,y;
    Point_2D(){}
    Point_2D(double _x,double _y):x(_x),y(_y){}
    void print()
    {
        printf("%.2lf %.2lf\n",x,y);
    }
    void get()
    {
        scanf("%lf%lf",&x,&y);
    }
}point_2D[maxn];
Point_3D pro_point_3D()
{
    double x,y,z;
    x = (rand()%100)*(rand()%100)/100.0;
    y = (rand()%100)*(rand()%100)/100.0;
    z = (rand()%100)*(rand()%100)/100.0;
    Point_3D p = Point_3D(x,y,z);
    return p;
}
Point_2D pro_point_2D()
{
    double x,y;
    x = (rand()%100)*(rand()%100)/100.0;
    y = (rand()%100)*(rand()%100)/100.0;
    Point_2D p = Point_2D(x,y);
    return p;
}

struct pt{
	double x, y, z;
	pt(){}
	pt(double _x, double _y, double _z): x(_x), y(_y), z(_z){}
	pt operator - (const pt p1){return pt(x - p1.x, y - p1.y, z - p1.z);}
	pt operator * (pt p){return pt(y*p.z-z*p.y, z*p.x-x*p.z, x*p.y-y*p.x);}
	double operator ^ (pt p){return x*p.x+y*p.y+z*p.z;}
};

struct _3DCH{
	struct fac{
		int a, b, c;
		bool ok;
	};

	int n;
	pt P[MAXV];

	int cnt;
	fac F[MAXV*8];

	int to[MAXV][MAXV];

	double vlen(pt a){return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);}
	double area(pt a, pt b, pt c){return vlen((b-a)*(c-a));}
	double volume(pt a, pt b, pt c, pt d){return (b-a)*(c-a)^(d-a);}


	double ptof(pt &p, fac &f){
		pt m = P[f.b]-P[f.a], n = P[f.c]-P[f.a], t = p-P[f.a];
		return (m * n) ^ t;
	}

	void deal(int p, int a, int b){
		int f = to[a][b];
		fac add;
		if (F[f].ok){
			if (ptof(P[p], F[f]) > eps)
				dfs(p, f);
			else{
				add.a = b, add.b = a, add.c = p, add.ok = 1;
				to[p][b] = to[a][p] = to[b][a] = cnt;
				F[cnt++] = add;
			}
		}
	}

	void dfs(int p, int cur){
		F[cur].ok = 0;
		deal(p, F[cur].b, F[cur].a);
		deal(p, F[cur].c, F[cur].b);
		deal(p, F[cur].a, F[cur].c);
	}

	bool same(int s, int t){
		pt &a = P[F[s].a], &b = P[F[s].b], &c = P[F[s].c];
		return fabs(volume(a, b, c, P[F[t].a])) < eps && fabs(volume(a, b, c, P[F[t].b])) < eps && fabs(volume(a, b, c, P[F[t].c])) < eps;
	}

	void construct(){
		cnt = 0;
		if (n < 4)
			return;
		bool sb = 1;
		for (int i = 1; i < n; i++){
			if (vlen(P[0] - P[i]) > eps){
				swap(P[1], P[i]);
				sb = 0;
				break;
			}
		}
		if (sb)return;

		sb = 1;
		for (int i = 2; i < n; i++){
			if (vlen((P[0] - P[1]) * (P[1] - P[i])) > eps){
				swap(P[2], P[i]);
				sb = 0;
				break;
			}
		}
		if (sb)return;

		sb = 1;
		for (int i = 3; i < n; i++){
			if (fabs((P[0] - P[1]) * (P[1] - P[2]) ^ (P[0] - P[i])) > eps){
				swap(P[3], P[i]);
				sb = 0;
				break;
			}
		}
		if (sb)return;


		fac add;
		for (int i = 0; i < 4; i++){
			add.a = (i+1)%4, add.b = (i+2)%4, add.c = (i+3)%4, add.ok = 1;
			if (ptof(P[i], add) > 0)
				swap(add.b, add.c);
			to[add.a][add.b] = to[add.b][add.c] = to[add.c][add.a] = cnt;
			F[cnt++] = add;
		}

		for (int i = 4; i < n; i++){
			for (int j = 0; j < cnt; j++){
				if (F[j].ok && ptof(P[i], F[j]) > eps){
					dfs(i, j);
					break;
				}
			}
		}
		int tmp = cnt;
		cnt = 0;
		for (int i = 0; i < tmp; i++){
			if (F[i].ok){
				F[cnt++] = F[i];
			}
		}
	}

	double area(){
		double ret = 0.0;
		for (int i = 0; i < cnt; i++){
			ret += area(P[F[i].a], P[F[i].b], P[F[i].c]);
		}
		return ret / 2.0;
	}

	double volume(){
		pt O(0, 0, 0);
		double ret = 0.0;
		for (int i = 0; i < cnt; i++){
			ret += volume(O, P[F[i].a], P[F[i].b], P[F[i].c]);
		}
		return fabs(ret / 6.0);
	}

	int facetCnt_tri(){
		return cnt;
	}

	int facetCnt(){
		int ans = 0;
		for (int i = 0; i < cnt; i++){
			bool nb = 1;
			for (int j = 0; j < i; j++){
				if (same(i, j)){
					nb = 0;
					break;
				}
			}
			ans += nb;
		}
		return ans;
	}
};

_3DCH hull;

int flag[MAXV];
int main()
{
    int T = 10;
    int n,i;
    Point_2D p;
    Point_3D p3;
    srand(0);
    freopen("data.in","w",stdout);
    while(T--)
    {

        n = 0;
        for(i = 0; i < 300; i++)
        {
            point_3D[i] = pro_point_3D();
        }
        for(i = 0; i < 10; i++)
        {
            p = pro_point_2D();
            point_3D[i+300] = Point_3D(p.x,p.y,0.0);
        }
        hull.n = 310;
        for(i = 0; i < hull.n; i++)
        {
            hull.P[i].x = point_3D[i].x;
            hull.P[i].y = point_3D[i].y;
            hull.P[i].z = point_3D[i].z;
        }
        hull.construct();
        memset(flag,0,sizeof(flag));
        for(i = 0; i < hull.cnt; i++)
        {
            flag[hull.F[i].a] = 1;
            flag[hull.F[i].b] = 1;
            flag[hull.F[i].c] = 1;
        }
        for(i = 0; i < hull.n; i++)
        {
            if(flag[i] != 0)
            {
                n++;
            }
        }
        printf("%d\n",n);

        for(i = 0; i < hull.n; i++)
        {
            if(flag[i] != 0)
                printf("%.2lf %.2lf %.2lf\n",hull.P[i].x,hull.P[i].y,hull.P[i].z);
        }
        for(i = 0; i < 3 ; i++)
        {
            p = pro_point_2D();
            //p3.z = 100.0;
            p.print();
        }

    }
    return 0;
}

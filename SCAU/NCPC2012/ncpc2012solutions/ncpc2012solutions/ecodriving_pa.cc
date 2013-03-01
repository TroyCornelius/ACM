//Sample solution for the Eco-driving problem in NCPC 2012 by Per Austrin
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>

using namespace std;
const double pi = 2.0*acos(0.0);
typedef vector<int> vi;
typedef pair<double, int> pii;

struct point {
	double x, y;
	point(double x=0, double y=0): x(x), y(y) {}
	double angle() { 
		return atan2(y, x);
	}
	double angle(point p) {
		double r = angle() - p.angle();
		if (r < -pi) r += 2*pi;
		if (r > pi) r -= 2*pi;
		return r;
	}
	double dot(const point &p) { return x*p.x + y*p.y; }
	double dist() { return sqrt(dot(*this)); }
	point operator-(const point &p) { return point(x-p.x, y-p.y); }
};

int J, R, M;
point P[3000];
double ddist[300][300];
vi adj[3000];

bool poss(double phi) {
	if (J == 1) return true;
	set<pii> Q;
	double dist[300][300];
	for (int i = 0; i <= J; ++i)
		for (int j = 0; j <= J; ++j) dist[i][j] = M+1;
	for (vi::iterator it = adj[1].begin(); it != adj[1].end(); ++it) {
		Q.insert(make_pair(dist[1][*it] = (P[*it]-P[1]).dist(), 300 + *it));
	}
	//	printf("try %lf\n", phi);
	while (!Q.empty()) {
		int u = Q.begin()->second / 300, v = Q.begin()->second % 300;
		//		printf("at %d %d (%lf)\n", u, v, dist[u][v]);
		if (Q.begin()->first > M) return false;
		if (v == J) return true;
		Q.erase(Q.begin());
		for (vi::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
			if (fabs((P[*it]-P[v]).angle(P[v]-P[u])) < phi) {
				double nd = dist[u][v] + (P[*it]-P[v]).dist();
				//				printf(" -> %d (%lf, %lf)\n", *it, nd, (P[*it]-P[v]).angle(P[v]-P[u]));
				if (nd < dist[v][*it]) {
					Q.erase(make_pair(dist[v][*it], 300*v + *it));
					Q.insert(make_pair(dist[v][*it] = nd, 300*v + *it));
				}
			}
		}
	}
	return false;
}

int main(void) {
	scanf("%d%d%d", &J, &R, &M);
	
	for (int i = 1; i <= J; ++i) scanf("%lf%lf", &P[i].x, &P[i].y);

	for (int i = 0; i < R; ++i) {
		int A, B;
		scanf("%d%d", &A, &B);
		adj[A].push_back(B);
	}
	
	double lo = 0, hi = 2*pi;
	for (int i = 0; i < 30; ++i) {
		double m = (lo+hi)/2;
		(poss(m) ? hi : lo) = m;
	}
	if (lo > pi) printf("Impossible\n");	  
	else printf("%.10lf\n", hi*180/pi);
	return 0;
}

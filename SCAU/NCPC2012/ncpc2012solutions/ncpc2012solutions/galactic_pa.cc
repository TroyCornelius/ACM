//Sample solution for the Galactic Warlords problem in NCPC 2012 by Per Austrin
#include <cstdio>
#include <algorithm>
using namespace std;

struct point {
	int x, y;
	point(int x=0, int y=0): x(x), y(y) {}
	point operator-(point p) { return point(x-p.x, y-p.y); }
	int cross(point p) { return x*p.y-y*p.x; }
};

int main(void) {
	int W, P;
	point L[200][2];
	scanf("%d%d", &W, &P);
	int x = 0;
	bool parallel = true;
	for (int i = 0; i < P; ++i) {
		scanf("%d%d%d%d", &L[i][0].x, &L[i][0].y, &L[i][1].x, &L[i][1].y);
		bool seen = false;
		for (int j = 0; j < i; ++j)
			if (!(L[i][0]-L[j][0]).cross(L[j][1]-L[j][0]) &&
				!(L[i][1]-L[j][0]).cross(L[j][1]-L[j][0]))
				seen = true;
		x += !seen;
		if ((L[i][1]-L[i][0]).cross(L[0][1]-L[0][0])) parallel = false;
	}
	printf("%d\n", max((W-2*x+1)/2, int(parallel && (x+1<W))));
	return 0;
}

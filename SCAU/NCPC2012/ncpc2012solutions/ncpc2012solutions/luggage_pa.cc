//Sample solution for the Luggage problem in NCPC 2012 by Per Austrin
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<double, double> pdd;

void prune(vector<pdd> &X, vector<pdd> Y) {
	vector<pdd> Z;
	vector<pdd>::iterator xt = X.begin(), yt = Y.begin();
	while (xt != X.end() && yt != Y.end()) {
		pdd z = pdd(max(xt->first, yt->first),
					min(xt->second, yt->second));
		if (z.second >= z.first) Z.push_back(z);
		if (xt->second < yt->second) ++xt;
		else ++yt;
	}
	X = Z;
}

int main(void) {
	int N, L;
	double x[2000];
	vector<pdd> ivals;
	scanf("%d%d", &N, &L);
	for (int i = 0; i < N; ++i) scanf("%lf", x+i);
	sort(x, x+N);
	ivals.push_back(pdd(0.1, 10.0));
	for (int i = 0; i < N; ++i) for (int j = 0; j < i; ++j) {
		vector<pdd> refine;
		for (int k = 0; ; ++k) {
			double lo = (k*L+1) / (x[i]-x[j]), hi = ((k+1)*L-1) / (x[i]-x[j]);
			if (lo > 10) break;
			//			printf("add (%lf %lf)\n", lo, hi);
			refine.push_back(pdd(lo, hi));
		}
		//		printf("prune\n");
		prune(ivals, refine);
	}
	if (ivals.empty()) printf("no fika\n");
	else printf("%.10lf\n", 1.0/ivals.front().first);
	return 0;
}

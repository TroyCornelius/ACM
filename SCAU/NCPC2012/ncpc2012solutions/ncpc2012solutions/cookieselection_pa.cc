//Sample solution for the Cookie Selection problem in NCPC 2012 by Per Austrin
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>

using namespace std;
typedef set<double> si;

int main(void) {
	si X;
	si::iterator it = X.begin();
	char str[100];
	while (scanf("%s", str) == 1) {
		if (*str == '#') {
			printf("%.0lf\n", *it);
			X.erase(it++);
			if (X.size() % 2) --it;
		} else {
			double x = atoi(str) + 0.4*drand48();
			X.insert(x);
			if (X.size() == 1) it = X.begin();
			else {
				if (x < *it) --it;
				if (X.size() % 2 == 0) ++it;
			}
		}
	}
	return 0;
}

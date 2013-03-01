//Sample solution for the Doorman problem in NCPC 2012 by Per Austrin
#include <cstdio>

int abs(int x) { return x < 0 ? -x : x; }

int main() {
	int K;
	char X[1000], *Y;
	scanf("%d", &K);
	scanf("%s", X);
	int d = 0;
	for (Y = X; *Y; ++Y) {
		int z = *Y == 'W' ? 1 : -1;
		if (abs(d+z) > K) {
			if (Y[1] && Y[1] != Y[0]) {
				d -= z;
				++Y;
			} else 
				break;
		}
		d += z;
	}
	printf("%d\n", Y-X);
	return 0;
}

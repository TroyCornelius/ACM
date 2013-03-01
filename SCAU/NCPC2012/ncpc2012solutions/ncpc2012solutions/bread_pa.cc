//Sample solution for the Bread Sorting problem in NCPC 2012 by Per Austrin
#include <cstdio>
#include <algorithm>

using namespace std;

int inv(int n, int *A) {
	if (n < 2) return 0;
	int m = n/2;
	int r = inv(m, A) + inv(n-m, A+m);
	int x = 0, y = m;
	while (x < m && y < n) {
		if (A[y] < A[x]) { r += m-x, ++y; }
		else ++x;
	}
	sort(A, A+n);
	return r;
}

int main(void) {
	int A[200000], B[200000], C[200000];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", A+i);
	for (int i = 0; i < n; ++i) {
		scanf("%d", B+i);
		C[B[i]] = i;
	}
	for (int i = 0; i < n; ++i) A[i] = C[A[i]];
	printf("%sossible\n", inv(n, A) % 2 ? "Imp" : "P");
	return 0;
}

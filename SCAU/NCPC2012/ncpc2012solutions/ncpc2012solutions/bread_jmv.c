#include <stdio.h>

void fenwickSetup(int *f, int k) {
	int i;
	for (i = 0; i < 1 << k; i++)
		f[i] = 0;
}

void fenwickAdd(int *f, int k, int p, int v) {
	int i;
	for (i = 0; i < k; i++) 
		if (!(((p - 1) >> i) & 1)) 
			f[p - 1 + (~(p - 1) & ((1 << i) - 1))] += v;
}

char fenwickGet(int *f, int k, int p) {
	int i, r = 0;
	for (i = 0; i < k; i++) 
		if ((p >> i) & 1) 
			r += f[(p & ~((1 << i) - 1)) - 1];
	return r;
}

void fenwickPrint(int *f, int k) {
	int i;
	fprintf(stderr, "Fenwick tree with %d elements (and 0-position): ", (1 << k) - 1);
	for (i = 0; i < 1 << k; i++) {
		fprintf(stderr, "%d ", f[i]);
	}
	fprintf(stderr, "\n\n");
}

int main() {
	int n, i, q;
	int P[1 << 17], Q[1 << 17], F[1 << 17];
	fenwickSetup(F, 17);
//	fenwickPrint(F, 4);
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", P + i);
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &q);
		Q[q] = i;
	}
	
	for (i = n, q = 0; i--; ) {
		q ^= fenwickGet(F, 17, Q[P[i]]);
//		fprintf(stderr, "Cumulative sum up to position %d in the tree is: %d\n", Q[P[i]], fenwickGet(F, 17, Q[P[i]]));
		fenwickAdd(F, 17, Q[P[i]], 1);
//		fprintf(stderr, "Added 1 to position %d in the tree.\n", Q[P[i]]);
//		fenwickPrint(F, 4);
	}
	
	printf("%sossible\n", q & 1 ? "Imp" : "P");
	
	return 0;
}

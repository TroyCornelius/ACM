//Sample solution for the Aaah! problem in NCPC 2012 by Per Austrin

#include <cstdio>
#include <cstring>

int main(void) {
	char A[5000], B[5000];
	scanf("%s%s", A, B);
	printf("%s\n", strlen(A) < strlen(B) ? "no" : "go");
	return 0;
}

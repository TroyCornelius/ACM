#include <stdio.h>

int main() {
	int D, d, i;
	char buffer[101];
	
	scanf("%d", &D);
	scanf("%s", buffer);
	
	for (i = d = 0, D += 1; buffer[i] && d <= D && d >= -D; i++) {
		d += buffer[i] == 'M' ? 1 : -1;
	}
	
	printf("%d\n", i - 2 * (d > D || d < -D) - ((d == D || d == -D) & !buffer[i]) );
	
	return 0;
}

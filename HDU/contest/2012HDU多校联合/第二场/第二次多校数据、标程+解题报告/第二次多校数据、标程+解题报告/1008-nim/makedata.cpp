#include <cstdio>
#include <cstdlib>

const int MAXN = 10;
const int MAXM = 1000000;
int T = 100;
int a[MAXN];

int rand32() {
    return ((int)rand() << 15) + rand();
}

int main() {
    freopen("data.in","w",stdout);
    int ca, n, m;
    for (ca = 0 ; ca < T ; ++ca) {
        if (ca < T - 10) {n = 5; m = 100;}
        else {n = MAXN; m = MAXM;}
        for (int i = 0 ; i < n ; i++)
            a[i] = rand32() % m + 1;
        printf("%d\n", n);
        for (int i = 0 ; i < n ; i++) {
            if (i) printf(" ");
            printf("%d", a[i]);
        }
        printf("\n");
    }
    return 0;
}

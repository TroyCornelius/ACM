#include <cstdio>
#include <cstdlib>

const int T = 100;
const int MAXV = 1000;

int main() {
    freopen("data.in","w",stdout);
    srand(11);
    int ca, n;
    for (ca = 0 ; ca < T ; ++ca) {
        if (ca < T - 2) n = 100;
        else n = 100000;
        printf("%d\n", n);
        for (int i = 0 ; i < n ; i++) {
            int tmp = rand() % MAXV;
            if (rand() & 1) tmp = -tmp;
            if (i) printf(" ");
            printf("%d", tmp);
        }
        printf("\n");
    }
    return 0;
}

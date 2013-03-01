#include <cstdio>
#include <cstdlib>

const int T = 50;

int main() {
    freopen("data.in","w",stdout);
    srand(2);
    int ca, n;
    for (ca = 0 ; ca < T ; ++ca) {
        if (ca < T - 2) n = 10;
        else n = 20;
        printf("%d\n",n);
        for (int i = 0 ; i < n ; i++) {
            printf("%d %d\n", rand() % 100+1, rand() % 100+1);
        }
    }
    return 0;
}

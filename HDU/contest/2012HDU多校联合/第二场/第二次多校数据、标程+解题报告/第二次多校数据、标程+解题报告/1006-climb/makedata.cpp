#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

const int T = 100;
int a[100010];

int main() {
    //freopen("data.in","w",stdout);
    srand(888);
    int ca, n, k, i, maxn;
    for (ca = 0 ; ca < T ; ++ca) {
        if (ca < T / 2) {n = 10; maxn = 20;}
        else if (ca < T - 10) {n = 100; maxn = 200;}
        else {n = 1000; maxn = 100000;}
        if (ca % 2 == 0) k = 2;
        else k = rand() % n + 1;
        for (i = 1 ; i <= maxn ; i++)
            a[i-1] = i;
        random_shuffle(a, a+maxn);
        sort(a, a+n);
        printf("%d %d\n", n, k);
        for (i = 0 ; i < n ; i++) {
            if (i) printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}

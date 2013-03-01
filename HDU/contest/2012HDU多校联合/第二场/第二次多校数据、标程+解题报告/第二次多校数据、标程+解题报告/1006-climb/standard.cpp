#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
using namespace std;

const int MAXN = 1024;
int a[MAXN];

int main() {
  //  freopen("data.in","r",stdin);
  //  freopen("data.out","w",stdout);
    int n, k, i;
    while (scanf("%d%d",&n,&k) != EOF) {
        assert(n >= 1 && n <= 1000);
        assert(k >= 1 && k <= n);
        for (i = 0 ; i < n ; i++) {
            scanf("%d",&a[i]);
            assert(a[i] > 0 && a[i] < 100000);
            if (i) assert(a[i] > a[i-1]);
        }
        if (k == 1) {printf("Alice\n"); continue;}
        int ans = 0;
        if (k == 2) {
            ans = 0;
            if (n % 2 == 0) {
                for (i = 0 ; i < n ; i += 2)
                    ans ^= (a[i+1] - a[i] - 1);
            } else {
                ans ^= (a[0] - 1);
                for (i = 1 ; i < n ; i += 2)
                    ans ^= (a[i+1] - a[i] - 1);
            }
        } else {
            ans = 0;
            if (n % 2 == 0) {
                for (i = 0 ; i < n ; i += 2)
                    ans ^= (a[i+1] - a[i] - 1);
            } else {
                ans ^= a[0];
                for (i = 1 ; i < n ; i += 2)
                    ans ^= (a[i+1] - a[i] - 1);
            }
        }
        if (ans) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}

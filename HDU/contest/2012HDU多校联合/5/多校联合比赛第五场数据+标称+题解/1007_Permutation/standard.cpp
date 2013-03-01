#include <cstdio>
#include <cstring>

using namespace std;
typedef __int64 ll;
ll f[200][1024];
int p[200], g;

ll calc(int i, int n) {
    if (i == g) return 1;
    if (f[i][n] != -1) return f[i][n];
    f[i][n] = calc(i + 1, n);
    int cnt = p[i];
    while (cnt <= n) {
        f[i][n] += calc(i + 1, n - cnt);
        cnt *= p[i];
    }
    return f[i][n];
}

int main() {
   // freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);
    int n;
    while (scanf("%d", &n) == 1) {
        int i, j;
        bool u[1024];
        memset(u, 0, sizeof (u));
        for (i = 2; i <= n; i++)
            if (!u[i])
                for (j = i + i; j <= n; j += i)
                    u[j] = true;
        g = 0;
        for (i = 2; i <= n; i++)
            if (!u[i])
                p[g++] = i;
        memset(f, 0XFF, sizeof (f));
        printf("%I64d\n", calc(0, n));
    }
    return 0;
}
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int lowbit(int x) {
    return x & (-x);
}

int get_result(int n) {
    int res = 0;
    while (n) {
        n -= lowbit(n);
        res++;
    }
    return res;
}

int main() {
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", 1 << get_result(n));
    }
    return 0;
}

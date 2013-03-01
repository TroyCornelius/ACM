#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define Maxn 5000
#define inf 999999999
#define pb push_back
using namespace std;

int n, f[20];
int main()
{
    scanf("%d", &n);
    int del = n - 10;
    if (del <= 0) printf("0\n");
    else
    {
        for (int i=1; i<=10; i++) f[i] = 4;
        f[10] += 11;
        f[11] = 4;
        if (del > 11) printf("0\n");
        else printf("%d\n", f[del]);
    }
    return 0;
}

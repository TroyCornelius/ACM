#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <list>
#include <set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <ctime>
#include <numeric>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <iomanip>
#include <cassert>
#define pb push_back
#define mp make_pair
#define inf 999999999
#define Maxn 1010

using namespace std;
typedef pair<int, int> pii;

int T, n, m;
int d[Maxn];
int ans[3000100];
int main()
{
    int p1;
    int num, tmp;
    scanf("%d", &T);
    for (int t=1; t<=T; t++)
    {
        scanf("%d", &n);
        memset(ans, 0, sizeof(ans));
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
            {
                scanf("%d", &num);
                if (num) d[i] = j;
            }
        p1 = 0;
        for (int i=0; i<n-1; i++)
        {
            for (int j=n-1; j>i; j--)
            {
           //     cout << d[j] << d[j-1] << endl;
                if (d[j] < d[j-1])
                {
                    swap(d[j], d[j-1]);
                    ans[p1++] = j-1;
                }
            }
        }
            printf("Case %d: %d\n", t, p1);
            for (int i=0; i<p1-1; i++) printf("%d ", ans[i]);
            if (p1 != 0) printf("%d", ans[p1 - 1]);
            printf("\n");
    }
    system("pause");
    return 0;
}

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
#define Maxn 100010
#define inf 999999999
#define pb push_back
using namespace std;

int n, d[Maxn];
int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &d[i]);
    sort(d, d+n);
    bool flag = false;
    for (int i=0; i<n-1; i++)
    if (d[i] != d[i+1] && d[i]*2>d[i+1]){flag=true;break;}
    if (!flag) printf("NO\n");
    else printf("YES\n");

    return 0;
    }

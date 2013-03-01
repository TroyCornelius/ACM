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
#define Maxn 1010
#define inf 999999999
#define pb push_back
using namespace std;

int n, m, h;
int num[Maxn];
int main()
{
    int s = 0;
    scanf("%d%d%d", &n, &m, &h);
    for (int i=1; i<=m; i++)
    {
        scanf("%d", &num[i]);
        s+=num[i];        
    }
    if (s < n) printf("-1.000000\n");
    else 
    if (num[h] != 1 &&  s == n) printf("1.0000000\n");
    else
    if (num[h] == 1) printf("0.0000000\n");
    else
    {
        
        
        
    }
    
    return 0;
    }

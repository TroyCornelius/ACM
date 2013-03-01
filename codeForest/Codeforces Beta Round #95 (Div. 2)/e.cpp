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
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Maxn 10100
using namespace std;

int n, m;
typedef pair<int, int> pii;
pii d[Maxn];
int main()
{
    int a, b;
    scanf("%d%d", &n, &m);
    for (int i =0; i<m; i++)
    {
        scanf("%d%d", &a, &b);
        d[i] = mp(a,b);        
    }
    

    return 0;
    }

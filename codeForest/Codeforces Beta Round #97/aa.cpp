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
const int inf = 1<<30;

int n, ans[128];
int main()
{
    int p;
    cin >>n;
    for (int i=0; i<n; i++)
    {
        cin >>p;
        ans[p] = i+1;        
    }
    for (int i=1; i<=n; i++)
    {
        if (i > 1) cout <<" ";
        cout <<ans[i];        
    }
    cout <<endl;
    
    return 0;
    }

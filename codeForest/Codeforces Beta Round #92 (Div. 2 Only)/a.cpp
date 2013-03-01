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

using namespace std;

int n, a, b;
int main()
{
    cin >>n >>a >>b;
    int ans = 0;
    for (int i=1; i<=n; i++)
    if (i-1>=a && n-i<=b) ans++;
    cout <<ans <<endl;
    
    
    
    
    return 0;
    }

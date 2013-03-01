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
using namespace std;

int n, d[128];
int main()
{
    int sum = 0;
    cin >>n;
    for (int i=0; i<n; i++)
    {
        cin >>d[i];
        sum += d[i];        
    }
    int ans = 0;
    for (int i=0; i<n; i++)
    {
        if ((sum - d[i]) % 2 == 0) ans++;
    }
    cout <<ans <<endl;
    
    return 0;
    }

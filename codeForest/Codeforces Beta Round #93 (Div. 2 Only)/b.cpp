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

int n, d[110];
int cnt[110], ans;
int main()
{
    memset(cnt, 0, sizeof(cnt));
    cin >>n;
    for (int i=0; i<n; i++)
    {
        cin >>d[i];
        cnt[d[i]]++;        
    }
    ans = 0;
    int sum = 0;
    for (int i=1; i<=100; i++)
    {
        if (cnt[i] >= 4) 
        {
           ans += cnt[i] / 4;
           cnt[i] %= 4;                   
        }
             cnt[i] /= 2;
             sum += cnt[i];        
    }
    printf("%d\n", ans + sum/2);
    
    
    return 0;
    }

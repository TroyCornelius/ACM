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

int n;
long long cnt[50];
long long ans;
int main()
{
    int num;
    memset(cnt, 0, sizeof(cnt));
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &num);
        cnt[num+10]++;        
    }
    ans = 0;
    for (int i=0; i<=10; i++)
    if (cnt[i] != 0)
    {
        if (i == 10) ans += (cnt[i] * (cnt[i]-1)) / 2;
        else
        {
            ans += cnt[i] * cnt[10 + 10 - i];
        }        
    }
    cout <<ans <<endl;

    return 0;
    }

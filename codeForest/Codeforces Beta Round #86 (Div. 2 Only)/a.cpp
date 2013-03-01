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
#define Maxn 100100
#define inf 999999999
#define pb push_back
#define mp make_pair
using namespace std;

long long k, l;
int main()
{
    cin >>k;
    cin >>l;
    long long s = k;
    int ans = 0;
    bool flag = false;
    while (s < l)
    {
          if (s == l) {flag = true;break;}
          s *= k;   
          ans++;
    }
    if (s==l) flag = true;
    if (flag) cout <<"YES"<<endl<<ans<<endl;
    else cout <<"NO"<<endl;
    return 0;
    }

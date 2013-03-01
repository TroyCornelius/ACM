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

int n, m, t;
long long s[70][70];
void init()
{
     memset(s, 0, sizeof(s));
     for (int i = 0; i<=35; i++)
     s[i][0] = s[i][i] = 1;
     
     for (int i=2; i<=32; i++)
       for (int j=1; j<=i; j++)
         s[i][j] = s[i-1][j] + s[i-1][j-1];     
     }
int main()
{
    init();
  //  while (1){
    cin >>n >>m >>t;
    long long ans = 0;
    for (int a=4; a<=min(t-1, n); a++)
    {
        if (t-a > m || t-a < 1) continue;
        ans += s[n][a] * s[m][t-a];
    }
    cout <<ans <<endl;
//}
    return 0;
    }

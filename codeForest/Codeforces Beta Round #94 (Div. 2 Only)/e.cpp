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
const int mod = 1000000007;
int n, m, k;
int c[1024][1024];

void init()
{
     memset(c, 0, sizeof(c));
     for (int i=0; i<=1000; i++) c[i][0] = 1;
     for (int i=1; i<=1000; i++)
       for (int j=1 ; j<=i; j++)
       {
           c[i][j] = c[i-1][j] + c[i-1][j-1];
           if (c[i][j] >= mod) c[i][j] -= mod;           
       } 
     }
int main()
{
    cin >>n >>m >>k;
    init();
    if (2*k > n-1 || 2*k>m-1) cout <<0 <<endl;
    else cout << 1LL*c[n-1][2*k]*c[m-1][2*k]%mod <<endl;

    return 0;
    }

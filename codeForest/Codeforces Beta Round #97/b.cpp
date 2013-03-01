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
int a, c, ma, mc;
int aa[100], bb[100], cc[100];
void calc()
{
     int len = max(ma, mc);
     for (int i=0; i<len; i++)
       bb[i] = (cc[i]+3-aa[i])%3;
     int ans = 0, tmp=1;
     for (int i=0; i<len; i++)
     {
         ans += bb[i] * tmp;
         tmp *= 3;
         
     }
     cout <<ans <<endl;
     }
int main()
{
    cin >>a >>c;
    memset(aa, 0, sizeof(aa));
    memset(bb, 0, sizeof(bb));
    memset(cc, 0, sizeof(cc));
    ma=0, mc=0;
    while (a > 0)
    {
          aa[ma++] = a % 3;
          a /= 3;
    }
    while (c > 0)
    {
          cc[mc++] = c % 3;
          c /= 3;
    }     
    calc();

    
    return 0;
    }

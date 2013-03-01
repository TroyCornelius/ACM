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
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

bool ispri(long long num)
{
     for (long long i=2; i*i <= num; i++)
     if (num % 2 == 0) return false;
     return true;
     }
class MinskyMysteryDiv2
{
public:
      long long computeAnswer(long long N)
      {
           if (N == 1) return -1;
          // if (ispri(N)) return N+1;
           for (long long a = 2; a*a <= N; a++)
           if (N%a == 0)
           {
               return N/a + a;                   
           }
           return N+1;
      }
      }t;

int main()
{
    long long d;
    while (cin >>d)
    {
          cout <<t.computeAnswer(d) <<endl;
    }
    return 0;
    }


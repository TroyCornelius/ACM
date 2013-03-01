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
const double pi = 3.14159265358979323;
const double eps = 1e-8;
int n, d[10];
int sum;
bool check(double x)
{
     return (x < eps);     
     }
int main()
{
    int tmp;
  //  while (1){
    double r, R;
    cin >>n >>R >>r;
    if (R < r) cout <<"NO" <<endl;
    else
    if (2*r > R)
    {
            if (n == 1) cout <<"YES" <<endl;
            else cout <<"NO" <<endl;
            
    }
    else
    {
        double a = R - r;
        double c = (2*a*a - 4*r*r)/2.0/a/a;
        double o = acos(c);
        if (check(o * n - 2*pi)) cout <<"YES" <<endl;
        else cout <<"NO" <<endl;

    }
    
    //if (tmp >= n) cout <<"YES" <<endl;
   // else cout <<"NO" <<endl;
    
//}
    return 0;
}

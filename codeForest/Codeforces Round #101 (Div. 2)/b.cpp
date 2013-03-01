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
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

double a, x, y;
int main()
{
    int ans = -1;
    cin >>a >>y >>x;
    if (x <= 0) ans = -1;
    else
    {
        if (x > 0 && x < a && (y > (-a/2.0)) && (y<(a/2.0))) ans = 1;
        else
        {
            x -= a;
            int tmp = 2;
            double c= 2.0*a;
            while (x > c) x-=c, tmp+=3;
            if (x > 0 && x < a)
            {
                if (y>(-a/2.0) && y<(a/2.0)) ans = tmp;            
            }
            else
                if (x > a && x < c)
                {
                    if (y > -a && y < 0) ans = tmp + 1;
                    else
                        if (y > 0 && y < a) ans = tmp + 2;                
                }
        }       
    }
    cout <<ans <<endl;
    

    return 0;
}

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
#include <cmath>
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

int n, m, ans;
int main()
{
    cin >>n >>m;
    if (n > m) swap(n, m);
    if (n == 1) ans = m;
    else
        if (n == 2)
        {
            if (m%4 == 0) ans = m;
            else
                if (m%4 == 1) ans = m+1;
                else ans = (m/2 - 1)*2 + 4;        
        }
        else ans = (n*m+1)/2;
    cout <<ans <<endl;
        
    
    return 0;
}

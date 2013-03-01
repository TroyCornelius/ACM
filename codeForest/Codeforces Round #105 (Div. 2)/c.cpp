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
#define all(a) (a).begin(),(a).end()
#define Maxn 101000
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

int n, a, b;
int ans[1000];
int main()
{
    while (1){
    cin >>n >>a >>b;
    int i = 2, sum = 1;
    ans[1] = 1;
    while (a) ans[i] = ans[i-1]+1, sum+=ans[i], a--, i++;
    
    for (; b; b--, i++)
    {
        ans[i] = sum+1;
        sum += ans[i];
        if (ans[i] > 50000)
        {
            cout <<-1 <<endl;
            return 0;
        }
    }
    
    while (i <= n) ans[i++] = 1;
    for (int i=1; i<=n; i++)
    {
        if (i>1) cout <<" ";
        cout <<ans[i];
    } 
    cout <<endl;    
    }   
    return 0;
}

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

typedef pair<int,int> pii;
bool p[Maxn];
void init()
{
    memset(p, true, sizeof(p));
    for (int i=2; i<=2014; i++)
    if (p[i])
    {
        for (int j=i+i; j<=2014; j+=i) p[j] = false;    
    }   

}
class MagicStonesStore
{
    
    public:
    string ableToDivide(int n)
    {
        init();
        n = 2*n;
        for (int i=2; i<=n; i++)
        {
            if (n - i <= 1) break;
            if (p[i] && p[n-i]) return "YES";        
        }
        return "NO";
        
    
    
    }


};

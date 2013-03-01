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
#define Maxn 10100
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

int a, b, cnt, s[100];
int c[1000000];
bool check(int x) 
{
    int tot = 0;
    while(x) 
    {
        if(x % 10 == 4 || x % 10 == 7) c[tot++] = x % 10;
        x /= 10;
    }
    if(cnt != tot) return false;
    for(int i = 0; i < tot; i++) 
    {
        if(s[i] != c[i]) return false;
    }
    return true;
}

int main() 
{
    //while(1)
     {
        cin >>a >>b;
        int tmp = b;
        cnt = 0;
        while(tmp) 
        {
            s[cnt++] = tmp % 10;
            tmp /= 10;
        }
        int ans = a + 1;
        while(1) 
        {
            if(check(ans)) break;
            ans++;
        } 
        cout << ans << endl;
    }
    return 0;
}

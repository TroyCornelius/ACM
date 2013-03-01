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

int n, m;
string s;

bool check()
{
    REP(i, n)
        if (s[i] != '4' && s[i] != '7') return false;
    int s1 = 0, s2 = 0;
    REP(i, n/2)
    {
        s1 += s[i]-'0';
        s2 += s[i+n/2]-'0';
    }
    return s1 == s2;
}
int main()
{
   // while (1)
   // {
        cin >>n;
        cin >>s;
        if (check()) cout <<"YES" <<endl;
        else cout <<"NO" <<endl;
  //  }
   
    return 0;
}

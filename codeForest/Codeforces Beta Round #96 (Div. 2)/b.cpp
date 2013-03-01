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
#define MOD 1000003
using namespace std;

map<char, int> num;
string s;
int main()
{
    cin >>s;
    num['>'] = 8; num['<']=9; num['+'] = 10; num['-'] = 11;
    num['.'] = 12; num[','] = 13; num['['] = 14; num[']'] = 15;
    
    int ans = 0, t = (1<<4);
    for (int i=0; i<s.length(); i++)
    {
        int tmp = num[s[i]];
      //  if (tmp < 10) ans = ans * 10 + tmp;
      //  else ans = ans * 100 + tmp;
      ans = ans * t + tmp;
        ans %= MOD;        
    }
    cout <<ans <<endl;


    return 0;
    }

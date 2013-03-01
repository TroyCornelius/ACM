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

string s;
int calc_r(char c)
{
            vector<int> ret;
            ret.clear();
            int num = c;
            while (num)
            {
                  ret.pb(num%2);
                  num/=2;                  
            }
            while (ret.size() < 8) ret.pb(0);
            int sum = 0, p = 1;
            for (int i=ret.size()-1; i>=0; i--)
            {
                if (ret[i] == 1) sum += p;
                p *= 2;                
            }
            return sum;
            }
int main()
{
    while (1){
    cin >>s;
    int ans = 0;
    for (int i=0; i<s.length(); i++)
    {
        int tmp = calc_r(s[i]);
        ans = ans - tmp;
        if (ans < 0) ans += 256;
        else if (ans >= 256) ans -= 256;
        cout <<ans <<endl;
    }}

    return 0;
    }

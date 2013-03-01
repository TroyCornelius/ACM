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
    int res = 0, p;
    string s;    
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        cout << (res - calc_r(s[i]) + 256) % 256 << endl;
        res = calc_r(s[i]);
    }
    return 0;
    }

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
int main()
{
    cin >>s;
    int ans = 0, tmp = 0;
    char now='#';
    for (int i=0; i<s.length(); i++)
    {
        if (s[i] != now || tmp >= 5)
        {
            now = s[i];
            tmp = 1;
            ans++;        
        }
        else tmp++;      
    
    }
    cout <<ans <<endl;
    return 0;
}

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
#define Maxn 5000
#define inf 999999999
#define pb push_back
#define mp make_pair
using namespace std;

string s;
bool check(int k)
{
     if(k == 0) return false;
     while (k > 0)
     {
           if (k % 10 != 4 && k%10 != 7) return false;
           k/=10;           
     }
     return true;
     }
int main()
{
    cin >>s;
    int ans = 0;
    for (int i=0; i<s.length(); i++)
    if (s[i] == '4' || s[i] == '7') ans++;
    
    if (check(ans)) cout <<"YES"<<endl;
    else
    cout <<"NO" <<endl;
    return 0;
    }

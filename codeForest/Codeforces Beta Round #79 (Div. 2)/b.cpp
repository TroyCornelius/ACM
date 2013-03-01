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
using namespace std;

string num;
int s, ans;
int change(int x)
{
    int ret = 0;
    while (x > 0) 
    {
       ret+=x%10;
       x/=10;          
    }
    return ret;
    }
int main()
{
    s = 0; ans = 0;
    cin >>num;
    if (num.length()==1) printf("0\n");
    else
    {
    for (int i=0; i<num.length(); i++) s+=(num[i]-'0');
    while (s>=10)
    {
       s = change(s);
       ans++;
    }
    printf("%d\n", ans+1);
    }
    return 0;
    }

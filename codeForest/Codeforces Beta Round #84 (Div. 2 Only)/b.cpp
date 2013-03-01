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
#define Maxn 100100
#define inf 999999999
#define pb push_back
#define mp make_pair
using namespace std;

string s;
char ans[Maxn];
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
int n;
int main()
{
    cin >>n;
    char ch = 'a';
    for (int i=1; i<=n; i++) ans[i] = '#';
    for (int i=1; i<=n; i++)
    if (ans[i] == '#')
    {
        int j = i;
        while (j <= n)
        {
            ans [j] = ch;
            j+=4;             
        }
        ch++;
    }
    else break;
    for (int i=1; i<=n; i++) cout <<ans[i];
    cout <<endl;
    return 0;
    }

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
#define inf 1<<30
using namespace std;

int ch[10], n, k;
int num[10][10];
int check()
{
    int big = 0, sma = inf;
    int s;
    for (int i=0; i<n; i++)
    {
        s = 0;
        for (int j=0; j<k; j++) s = s*10 + num[i][ch[j]];
        big = max(big, s);
        sma = min(sma, s);        
    }
    return big - sma;
    }
int main()
{
    cin >>n >>k;
    string s;
    for (int i=0; i<n; i++)
    {
        cin >>s;
        for (int j=0; j<s.length(); j++) num[i][j] = int(s[j]-'0');
    }
    int ans = inf;
    for (int i=0; i<k; i++) ch[i] = i;
    do
    {
        int tmp = check();
        ans = min(ans, tmp);        
    }while (next_permutation(ch, ch+k));
    
    cout <<ans <<endl;
    return 0;
    }

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
using namespace std;

int n, m, a, b, ans;
int main()
{
    while(cin >>n >>m >>a >>b){//;
    ans = 0;
    if (m == 1) ans = 1;
    else
    if (a%m==1 && b%m==0) ans = 1;
    else
    if (((b/m + (b%m==0?0:1))-(a/m+(a%m==0?0:1))) == 0) ans = 1;
    else
    if (a==1 && b==n) ans = 1;
    else
    if (a%m==1 && b==n) ans = 1;
    else
    if (a%m==1 && b%m!=0) ans = 2;
    else
    if (a%m!=1 && b%m==0) ans = 2;
    else
    if (((b/m+(b%m==0?0:1))-(a/m+(a%m==0?0:1))) == 1) ans = 2;    
    else  ans = 3;
    cout <<ans <<endl;

    }system("pause");

    return 0;
    }

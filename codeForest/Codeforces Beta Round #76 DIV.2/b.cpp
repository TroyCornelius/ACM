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

int deg[10], m;
int main()
{
    cin >>m;
    memset(deg, 0, sizeof(deg));
    int a, b;
    for (int i=0; i<m; i++)
    {
        cin >>a >>b;
        deg[a]++;
        deg[b]++;        
    }
    bool flag = false;
    for (int i=1; i<=5; i++)
    {
        if (deg[i] == 3 || deg[i] == 1) 
        {
           flag = true;
           break;                   
        }        
    }
    if (flag) cout <<"WIN" <<endl;
    else cout <<"FAIL" <<endl;

    
    return 0;
    }

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

int ans[Maxn];

int n;
int main()
{
    cin >>n;
    for (int i=0; i<=250000; i++)
    {
        int tmp = n - i*4;
        if (tmp < 0) break;
        if (tmp%7 == 0)
        {
           for (int j=0; j<i; j++) cout <<"4";
           for (int j=0; j<tmp/7; j++) cout<<"7";
           cout <<endl;
           return 0;                  
        }
    }
    cout <<-1<<endl;
    return 0;
    }

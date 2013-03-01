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
string s[28]={"","#","#","#","4","#","#", "7","44","4444","#","47","444","#","77","447","4444","#","477","4447","44444","777","4477","44447","444444","4777","44477","444447"};
int n;
int main()
{
    cin >>n;
    int t1=n/28, tmp = n-t1*28;
    if (s[tmp] == "#") cout <<-1<<endl;
    else
    {
       cout <<s[tmp];
       for (int i=0; i<t1; i++) cout <<"7777";
       cout <<endl;   
    }
    system("pause");
    return 0;
    }

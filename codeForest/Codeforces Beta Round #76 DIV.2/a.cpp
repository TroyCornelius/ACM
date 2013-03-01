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

string s, ans;
string d[15];
string ch[10]={"0","1", "2", "3","4","5","6","7","8","9"};
int main()
{
    
    cin >>s;
    for (int i=0; i<10; i++) cin >>d[i];
    ans.clear();
    for (int i=0; i<s.length(); i+=10)
    {
        string t = s.substr(i, 10);
        for (int j=0; j<10; j++)
        if (t == d[j]) {ans+=ch[j];break;}        
    }
    cout <<ans <<endl;

    
    return 0;
    }

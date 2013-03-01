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
    if (s.find("H", 0) != string::npos || s.find("Q", 0)!=string::npos || s.find("9", 0) != string::npos) cout <<"YES" <<endl;
    else cout <<"NO" <<endl;
    return 0;
    }

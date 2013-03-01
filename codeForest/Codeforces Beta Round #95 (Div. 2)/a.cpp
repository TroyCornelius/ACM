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
using namespace std;

string s;
bool check(string st)
{
     for (int i=st.length()-1; i>0; i--)
     if (st[i]<'A' || st[i] > 'Z') return false;
     return true;
     }
int main()
{
    cin >>s;
    if (check(s))
    {
       if (s[0] >= 'a' && s[0] <= 'z')
       {
          s[0] = toupper(s[0]);                
       }
       else s[0] = tolower(s[0]);
       for (int i=1; i<s.length(); i++) s[i] = tolower(s[i]);                
                 
    }
    cout <<s <<endl;
    
    
    return 0;
    }

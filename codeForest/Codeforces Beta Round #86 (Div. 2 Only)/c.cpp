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
int get_sex(string st)
{
    int len = st.length();
    if (len-4>=0 && st.substr(len-4) == "lios") return 1;
    else if (len-3>=0 && st.substr(len-3)=="etr") return 3;
    else if (len-6>=0 && st.substr(len-6)=="initis") return 5;    
    if (len-5>=0 && st.substr(len-5) == "liala") return 2;
    else if (len-4>=0 && st.substr(len-4)=="etra") return 4;
    else if (len-6>=0 && st.substr(len-6)=="inites") return 6;   
    return -1;
    }
int get_spe(int num)
{
    if (num>=1 && num <= 2) return 1; //adj
    else if (num >=3 && num <= 4) return 2; //n.
    else if (num>=5 && num <= 6) return 3; //v.
    }
int main()
{
    string s1;
    getline(cin, s);
    int loc = s.find(" ", 0), sp=0; 
    if (loc != string::npos)
    {
        int gen = -2;
        int cnt_adj = 0, cnt_n = 0, cnt_v = 0;
        int big = 0, tmp;
        while (sp < s.length())
        {              
           s1 = s.substr(sp, loc-sp);
           sp = loc+1;
           loc = s.find(" ", sp);
           if (loc == string::npos) loc = s.length();
           int tsex = get_sex(s1);
           tmp = get_spe(tsex);
           if (tmp > big) big = tmp;           
           if (gen==-2) gen = (tsex&1);                      
           if (tmp == 1) cnt_adj++;
           else if (tmp==2) cnt_n++;
           else if (tmp==3) cnt_v++;           
           if (tsex==-1 || gen != (tsex&1) || tmp < big || cnt_n > 1)
           {
              cout <<"NO" <<endl;
              return 0;                      
           }
        }
        if (cnt_n == 0) cout <<"NO" <<endl;
        else
        cout <<"YES" <<endl;                 
    }
    else
    {
        int t = get_sex(s);
        if (t != -1) cout <<"YES" <<endl;
        else cout <<"NO" <<endl;        
    }
    return 0;
    }

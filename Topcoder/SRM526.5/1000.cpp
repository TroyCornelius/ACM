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
#define pb push_back
using namespace std;
    int cmp(string s1, string s2)
    {
        int i;
        for (i=0; i<min(s1.length(), s2.length()); i++)
        {
            if (s1[i] == s2[i]) continue;
            else if (s1[i] < s2[i]) return 0;
            else return 1;        
        }
        return 2;
    }
class MagicNaming
{
    public:
 
    int maxReindeers(string s)
    {
        vector<string> d;
        d.clear();
        int len = s.length(), idx = 0;
        string t;
        while (idx < len)
        {
              
            t = s[idx++];
         //   cout <<t <<" "<<idx <<endl;
            if (d.size() == 0) d.pb(t);
            else
            {
                int ret;
                while ((ret = cmp(d.back(), t)) > 0)
                {
                    if (idx >= len) break;
                    if (ret == 1)
                    {
                        t = d.back() + t;
                        d.erase(d.end()-1);
                        if (d.size() == 0) {break;}
                    }
                    else if (ret == 2 && idx < len) t += s[idx++];   
                  //  cout <<t <<" "<<idx<<" "<<ret <<endl;   
                  //  system("pause");         
                }
                while (d.size() >= 1 && (ret = cmp(d.back(), t)) == 1) 
                {
                        t = d.back() + t;
                        d.erase(d.end()-1);
                        if (d.size() == 0) {break;}                     
                      
                }
                d.pb(t);
            }    
           // cout <<t <<" "<<idx<<endl;        
        
        }
        return d.size();
    
    }
}test;

int main()
{
    string s;
    while (cin >>s)
    {
       cout <<     test.maxReindeers(s) <<endl;
    }
    
    return 0;
    }

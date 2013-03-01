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
const int inf = 1<<30;

typedef pair<int,int> pii;
pii p[10];
int pat[8];
inline int calc(pii a, pii b)
{
       return (a.fi - b.fi)*(a.fi - b.fi) + (a.se - b.se) * (a.se - b.se);
       }
bool check(pii a, pii b, pii c)
{
     return(((b.fi - a.fi)*(c.fi - b.fi) + (b.se - a.se) * (c.se - b.se)) == 0);
     }
bool check_ret(pii a, pii b, pii c, pii d)
{
     bool fa = check(a, b, c);
     bool fb = check(a, d, c);
     bool fc = check(b, c, d);
     return (fa && fb && fc);     
     
     }
bool check_sqr(pii a, pii b, pii c, pii d)
{
     vector<int> len;
     len.clear();
     len.pb(calc(a, b));
     len.pb(calc(a, c));
     len.pb(calc(a, d));
     len.pb(calc(b, c));
     len.pb(calc(d, b));
     len.pb(calc(c, d));
    //   for (int i=0; i<len.size(); i++) cout <<len[i] <<" ";
   //  cout <<endl;
     len.erase(unique(len.begin(), len.end())-1, len.end());
   //  for (int i=0; i<len.size(); i++) cout <<len[i] <<" ";
   //  cout <<endl;
   //  cout <<len.size() <<endl;
     sort(len.begin(), len.end());
     
     if (len.size() != 2 || len[0] * 2 != len[1]) return false;
     else return true;    
     
     }
int main()
{
   // while (1){
    int a, b;
    for (int i=1; i<=8; i++)
    {
        pat[i-1] = i;
        cin >>a >>b;
        p[i] = mp(a, b);        
    }
 // cout <<  check_sqr(p[5], p[6], p[7], p[8]) <<endl;
    do
    {
      //   for (int i=0; i<4; i++) cout <<pat[i]<<" ";
       //                          cout <<endl;
        if (check_sqr(p[pat[0]], p[pat[1]], p[pat[2]], p[pat[3]]))
        {
        //  for (int i=0; i<4; i++) cout <<pat[i]<<" ";
               //                  cout <<endl;
           
            if (check_ret(p[pat[4]], p[pat[5]], p[pat[6]], p[pat[7]]))
            {
                cout <<"YES" <<endl;
                cout <<pat[0]<<" "<<pat[1]<<" "<<pat[2] <<" "<<pat[3] <<endl;
                cout <<pat[4]<<" "<<pat[5]<<" "<<pat[6] <<" "<<pat[7] <<endl; 
                
               // system("pause");
                return 0;                    
            }                                 
        }
        
    }while (next_permutation(pat, pat+8));//*/
    cout <<"NO" <<endl;

    return 0;
    }

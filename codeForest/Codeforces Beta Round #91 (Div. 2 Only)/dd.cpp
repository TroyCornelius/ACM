#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <map>
#include <vector>
#define pb push_back
using namespace std;

string st, s1;
int n, k, tot;
int main()
{
    int loc, loop = -1, cir;
    cin >>n >>k;
    cin >>st;
    int len = st.length();
    while (k)
    {
          loc = st.find("47", 0);
          if (loc == string::npos)
          {
             cout <<st <<endl;  // system("pause");
             return 0;                  
          }
          else
          {
              if (loc%2==0)
              {
                 if (loc+2 < len && st[loc+2]=='7')
                 {
                    if (k%2==1)
                    {
                       st.replace(loc, 2, "44");
                       cout <<st <<endl;  // system("pause");
                       return 0;                               
                    }
                    else 
                    {
                       cout <<st <<endl;  // system("pause");
                       return 0;                         
                    }                           
                 }
                 else
                 {
                     st.replace(loc, 2, "44");                      
                 }                          
              }
              else
              {
                  if (loc >= 1 && st[loc-1]=='4')
                  {
                    if (k%2==1)
                    {
                       st.replace(loc, 2, "77");
                       cout <<st <<endl;   //system("pause");
                       return 0;                               
                    }
                    else 
                    {
                       cout <<st <<endl;   //system("pause");
                       return 0;                         
                    }                       
                  }
                  else st.replace(loc, 2, "77");                  
              }
          }
          k--;          
    }
    cout <<st <<endl;    
   //system("pause");
    
    
    return 0;
}

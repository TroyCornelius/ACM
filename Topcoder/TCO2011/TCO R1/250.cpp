#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int n;
vector<int> p;
class MinimumLiars
{
      
      public :
      bool check(int k)
      {
           int tot = 0;
           for (int i=0; i<p.size(); i++)
           if (k < p[i]) tot++;
           if (tot == k) return true;
           else return false;
           
      }
      int getMinimum(vector <int> claim)
      {
          p = claim;
          n = claim.size();
          for (int i=0; i<=n; i++)
          {
             if (check(i))
             {
                 return i;            
             }               
          }
          return -1;          
      }
      
      };
      
int main()
{
    
    return 0;
    }

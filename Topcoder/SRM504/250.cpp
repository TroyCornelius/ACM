#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

class ComparerInator
{
      public:
      int makeProgram(vector <int> A, vector <int> B, vector <int> wanted)
      {
          int ans = -1, tmp;
          bool flag = true;
          for (int i=0; i<A.size(); i++)
          if (A[i] != wanted[i]) 
          {
             flag = false;
             break;        
          }          
          if (flag) ans = 1;
          
          flag = true;
          for (int i=0; i<B.size(); i++)
          if (B[i] != wanted[i]) 
          {
             flag = false;
             break;        
          }          
          if (flag) ans = 1;  
          
          flag = true;
          for (int i=0; i<A.size(); i++)          
          {
             tmp = A[i] < B[i] ? A[i] : B[i];
             if (tmp != wanted[i]) 
             {
                 flag = false;
                 break;       
             }   
          }
          if (flag && ans == -1) ans = 7;
 
          flag = true;
          for (int i=0; i<A.size(); i++)          
          {
             tmp = A[i] < B[i] ? B[i] : A[i];
             if (tmp != wanted[i]) 
             {
                 flag = false;
                 break;       
             }   
          }
          if (flag && ans == -1) ans = 7;  
          return ans;
      }
      };

int main()
{
    
    
    return 0;
    }

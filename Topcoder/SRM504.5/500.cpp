#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

class TheNumbersWithLuckyLastDigit
{
      
      public: 
      int find(int p)
      {
          int n = p;
          if (n % 10 == 3) 
          {
             if (n >= 23) return 5;
             else return -1;
                
          }
          else
          if (n%10 == 4 || n%10 == 7) return 1;
          else
          if (n%10==0)
          {
             if (n >= 20) return 5;
             else return -1;                      
          }
          else
          if (n%10==1)
          {
            if (n >= 11) return 2;
            else return -1;                      
          }
          else
          if (n%10==2)
          {
             if (n>=12) return 3;
             else return -1;                      
          }
          else
          if (n%10==5)
          {
            if (n >= 15) return 3;
            else return -1;                      
          }
          else
          if (n%10==6)
          {
             if (n >=26) return 5;
             else return -1;                      
          }
          else
          if (n%10==8) 
          {
             if (n>=8) return 2;
             else return -1;            
          }
          else
          if (n%10==9)
          {
             if (n>=19) return 4;
             else return -1;           
          }
          return -1;
      }
      
      };
int main()
{
    
    return 0;
    }

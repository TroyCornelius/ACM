#include <iostream>
using namespace std;

bool check(int d)
{
     while (d != 0)
       {
          if (d%10==5) return true;
          d/=10;  
       } 
     return false;
     }
int main()
{
    
    for (int i=1; i<=9999; i++)
      if (i%7 == 0 && check(i)) cout<<i<<endl;
      
    return 0;
    }

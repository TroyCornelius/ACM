#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

bool check(int k)
{
     int cnt = 0;
     while (k > 0)
     {
        if (k%10 != 4 && k%10 != 7) cnt++;
        k/=10;
     }
     return cnt <= 1;
     }
class TheAlmostLuckyNumbersDivTwo
{
      public :
      int find(int a, int b)
      {
          int ans = 0;
          for (int i=a; i<=b; i++)
          {
              if (check(i)) ans++;                            
          }
          return ans;
          
      }
      }t;


int main()
{
    int a, b;
    cin >>a >>b;
    cout <<t.find(a, b)<<endl;
    system("pause");
    
    
    
    return 0;
    }

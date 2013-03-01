#include <iostream>
#include <ctime>
using namespace std;


int n, x1, x2, t1, t2, t0;
int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    cin >>t1 >>t2 >>x1 >>x2 >>t0;
    int aa, bb, ans;
    double s = 999999999;
    for (int a = x1; a>=0; a--)
      for (int b = x2; b>=0; b--)
      {
          if (!a && !b) break;
          double c = 1.0*(a*t1 + b*t2)/(a+b);
        //  if (a == 1000 && b == 0) cout <<c <<" "<<t0 <<" "<<s <<endl;
          if (c >= double(t0))
          {
                if (c - double(t0) < s)
                {
                      s = c-double(t0);
                      aa = a;
                      bb = b;                      
                }                
          }     
      }
      cout <<aa << " "<<bb <<endl;
    
    return 0;
    }

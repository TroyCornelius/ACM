#include <iostream>
using namespace std;

double a, b;
int main()
{
    while (cin >>a >>b)
      {
          if (a==0 && b==0) break;
          printf("%.2lf", 3.14 * a*a*9.8*b*b/4.0 / 3.0);
          
      }
    system("pause");
    
    return 0;
    }

#include <iostream>
using namespace std;

int ans[60010];

int main()
{
    freopen("output.txt", "w", stdout);
    for (int i=0; i<=60000; i++) ans[i] = 4;
    int s, tmp;
    for (int a=0; a<=245; a++)
      for (int b=0; b<=245; b++)
        for (int c=0; c<=245; c++)
          for (int d=0; d<=245; d++)
          {
              s = a*a + b*b + c*c + d*d;
              if (s > 60000) break;
              tmp = 4;
              if (a == 0) tmp--;
              if (b == 0) tmp--;
              if (c == 0) tmp--;
              if (d == 0) tmp--;
              ans[s] <?= tmp;                            
          }
    for (int i=0; i<=60000; i++) printf("%d,", ans[i]);
    
    return 0;
    }

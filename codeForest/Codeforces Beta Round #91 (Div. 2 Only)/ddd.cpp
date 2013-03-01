#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int n, k, i;
char s[110000];
int main()
{
    scanf("%d%d", &n, &k); 
    scanf("%s", s);
    n = strlen(s);
    i = 0;
    while (k > 0 && i < n)
    {
          if (i < n - 1 && (i & 1) == 0 && s[i] == '4' && s[i + 2] == '7' && (s[i + 1] == '4' || s[i + 1] == '7'))
          {
                if (k & 1)
                {
                      if (s[i + 1] == '4') s[i + 1] = '7';
                      else s[i + 1] = '4';
                }
                break;
          }
          if (s[i] == '4' && s[i + 1] == '7')
          {
                   if (i & 1)
                   {
                         s[i] = '7';
                         if (i > 0) i -= 2;
                   }
                   else s[i + 1] = '4';
                   k--;
          }
          i++;
    }
    printf("%s\n", s); 
    system("pause");
    return 0;
}

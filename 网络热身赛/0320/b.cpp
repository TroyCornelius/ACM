#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


char s[1000005];
int m, len,p1,p2,t1,t2,ans;
int b[500];
int main()
{
    while (scanf("%d", &m))
    {
        if (m == 0) break;
        getchar();
        gets(s);
        len = strlen(s);
        p1=0; p2=0; ans = 0;
        t1=0; t2=0;
        memset(b, 0, sizeof(b));
        while (p1 <= p2 && p2 < len)
        {
           while (t1 <= m && p2 < len)
           {
              if (b[s[p2]] == 0) 
              {
                 b[s[p2]]=1;
                 t1++;
                 if (t1 > m) break;
              }
              else b[s[p2]]++;
              p2++; t2++;
                               
           }
           ans >?= t2;
           if (p2 >= len) break;
           while (true)
           {
              b[s[p1]]--;
              if (b[s[p1]] == 0) break;
              p1++; t2--;                 
           }  
           p1++; t1--; p2++;
        }
        printf("%d\n", ans);
        
          
    }
    
    system("pause");
    return 0;
    }

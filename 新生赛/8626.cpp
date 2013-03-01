#include <iostream>
#include <string>
using namespace std;

int T;
string s; 
double d[30], d1[30];
void work()
{
     double ans = 0;
     int i = 0, j, tmp;
     memset(d, 0, sizeof(d));
     while (i < s.size())
       {
         if (isalpha(s[i])) {d[int(s[i]-'A')] += d1[int(s[i]-'A')];i++;continue;}
         if (isdigit(s[i]))
           {
              tmp = 0;
              for (j=i; j<s.size(); j++)
                {
                   if (isalpha(s[j])) break;
                   tmp = tmp*10 + int(s[j] - '0');                       
                }
              d[int(s[i-1]-'A')] *= tmp;
              i = j;
              for (int t=0; t<=26; t++) ans+= d[t];  
              memset(d, 0, sizeof(d));
           }  
            
       }
     for (int t=0; t<=26; t++) ans += d[t]; 
     printf("%.3lf\n", ans);     
     
     }
int main()
{
    cin >>T;
    d1[int('C'-'A')] = 12.01;
    d1[int('H'-'A')] = 1.008;
    d1[int('O'-'A')] = 16.00;
    d1[int('N'-'A')] = 14.01;
    while (T > 0)
      {
          T--;
          cin >>s;
          work();
          
      }
    return 0;
    }

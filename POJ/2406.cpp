#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#define Maxn 1000010
using namespace std;

string s;
//char s[Maxn];
int next[Maxn];
void work()
{
     int n = s.length(), tmp;
    // int n = strlen(s), tmp;
     memset(next, 0, sizeof(next));
     for (int i=1; i<n; i++)
     {
         tmp = next[i-1];
         while (tmp && s[tmp]!=s[i]) tmp = next[tmp-1];
         if (s[tmp] == s[i]) next[i] = tmp+1;         
     }
  /*   if (n%(n-next[n-1]) == 0) printf("%d\n", n / (n  - next[n-1]));
     else printf("1\n");    */
     if (n%(n-next[n-1]) == 0) cout << n / (n  - next[n-1]) <<endl;
     else cout <<1 <<endl; 
     }
int main()
{    
    ios::sync_with_stdio(false);
  /*  while (scanf("%s", s) != EOF)
    {
       if (strcmp(s, ".")==0) break;
       work();          
    }*/
    while (cin >>s)
    {
       if (s == ".") break;
       work();
    }
    system("pause");
    
    
    return 0;
    }

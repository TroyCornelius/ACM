#include <iostream>
#include <stack>
#include <cstring>
#define Maxn 200010
using namespace std;


int n;
int couple[Maxn];
stack<int> t;
int main()
{
    while (cin >>n)
    {
       if (n == 0) break;
       memset(couple, -1, sizeof(couple));
       for (int i=0; i<n; i++)
       {
          int a, b;
          scanf("%d%d", &a, &b);
          couple[a] = b;
          couple[b] = a;     
       }
       while (!t.empty()) t.pop();
       for (int i=1; i<=2*n; i++)
       {
           if (t.empty()) t.push(i);
           else
           {
             if (t.top() ==  couple[i]) t.pop();
             else t.push(i);
           }           
       }
       if (t.empty()) printf("Yes\n");
       else printf("No\n");  
    }    

    return 0;
    }

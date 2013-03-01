#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int n;
char ans[4][110];
int main()
{
    cin >>n;
    if (n == 1) cout <<"a"<<endl<<"a"<<endl<<"b"<<endl<<"b"<<endl;
    else
    {
    ans[0][0]='a'; ans[0][1]='a';
    ans[1][0]='c'; ans[1][1]='c';
    ans[2][0]='b'; ans[2][1]='a';
    ans[3][0]='b'; ans[3][1]='a';
    for (int i=2; i<n; i++)
    {
       if (ans[0][i-1] == ans[1][i-1])
         {
            ans[0][i] = ans[0][i-1];
            for (char c='a'; c<='z'; c++)
            if (ans[0][i-1] != c && ans[1][i-2] != c &&  ans[2][i-1] != c)
              {
                 ans[1][i-1] = ans[1][i] = c;
                 break;                            
              }
            for (char c='a'; c<='z'; c++)
            if (ans[1][i] != c && ans[2][i-1] != c && ans[3][i-1] != c)
              {
                 ans[2][i] = ans[3][i] = c;
                 break;
              }
         }
       else
       if (ans[2][i-1] == ans[3][i-1])
         {
            ans[2][i] = ans[2][i-1];
            for (char c='a'; c<='z'; c++)
            if (ans[2][i-1] != c && ans[3][i-2] != c)
              {
                 ans[3][i-1] = c; ans[3][i] = c;
                 break;                            
              }
            for (char c='a'; c<='z'; c++)
            if (ans[0][i-1] != c && ans[1][i-1] != c && ans[2][i]!=c)
              {
                 ans[0][i] = ans[1][i] = c;
                 break;                            
              }                       
         }
        
    }
    for (int i=0; i<4; i++)
    {
       for (int j=0; j<n; j++) cout<<ans[i][j];
       cout<<endl;       
    }
    }
 
    return 0;
    }

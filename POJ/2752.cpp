#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define pb push_back
#define Maxn 400100
using namespace std;


char s[Maxn];
int next[Maxn];
vector<int> ans;
void calc()
{
     memset(next, 0, sizeof(next));
     int len = strlen(s), tmp;
     for (int i=1; i<len; i++)
     {
         tmp = next[i-1];
         while (tmp && s[tmp]!=s[i]) tmp = next[tmp-1];
         if (s[tmp] == s[i]) next[i] = tmp+1;         
     }
     ans.clear();
     int j=len-1;
     while (next[j])
     {
        ans.pb(next[j]);
        j = next[j]-1;           
     }
     for (int i=ans.size()-1; i>=0; i--) printf("%d ", ans[i]);
     printf("%d\n", len);   
     }

int main()
{
    while (scanf("%s", s) != EOF)
    {
       calc();          
    }
    return 0;
    }

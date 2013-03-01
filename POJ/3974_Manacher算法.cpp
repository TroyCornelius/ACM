/*
   O(n)求最长回文子串 
   p[i]-1为新串以str[i]为中心的最大回文长度，以#为中心则回文串长度为偶数，否则为奇数 
*/ 

#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#define Maxn 1000100
using namespace std;

char str[Maxn*2], s[Maxn];
int p[Maxn*2], n;

void pk()   
{
     int id, mx=0;
     for (int i=1; i<n; i++)   //下标从1开始 
     {
         p[i] = mx>i ? min(p[2*id-i], mx-i):1;
         while (str[i+p[i]] == str[i-p[i]]) p[i]++;
         if (p[i]+i > mx)
         {
            mx = p[i]+i;
            id = i;                    
         } 
     }
     }
void init()
{
     str[0]='$'; str[1] = '#';  //str[0]放越界 
     for (int i=0; i<n; i++)
     {
         str[i*2+2] = s[i];
         str[i*2+3] = '#';          //相邻之间加特殊符号 
     }
     n = n*2+2;
     str[n] = 0;     
     }
int main()
{
    int t = 0;
    while (scanf("%s", s) != EOF)
    {
        if (s[0] == 'E') break;
        n = strlen(s);
        init();
        pk();
        int ans = 0;
        for (int i=0; i<n; i++) ans = max(ans, p[i]);
        printf("Case %d: %d\n", ++t, ans-1);
    }
    return 0;
    }

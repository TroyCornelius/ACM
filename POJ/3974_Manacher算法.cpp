/*
   O(n)��������Ӵ� 
   p[i]-1Ϊ�´���str[i]Ϊ���ĵ������ĳ��ȣ���#Ϊ��������Ĵ�����Ϊż��������Ϊ���� 
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
     for (int i=1; i<n; i++)   //�±��1��ʼ 
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
     str[0]='$'; str[1] = '#';  //str[0]��Խ�� 
     for (int i=0; i<n; i++)
     {
         str[i*2+2] = s[i];
         str[i*2+3] = '#';          //����֮���������� 
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

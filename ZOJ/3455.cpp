#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
#define pb push_back
#define Maxn 500100
using namespace std;

char str[Maxn], p[Maxn];
vector<int> ans; 
int cnt[300];
int main()
{
    int n, m;
    while (scanf("%s%s", str, p) != EOF)
    {
          ans.clear();
          n = strlen(str);
          m = strlen(p);          
          memset(cnt, 0, sizeof(cnt));
          for (int i=0; i<m; i++) cnt[p[i]]++;
          
          
          
          
    }
    
    
    return 0;
    }

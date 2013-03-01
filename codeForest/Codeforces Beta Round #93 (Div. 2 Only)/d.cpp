#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Maxn 1000010
using namespace std;

char T[1000010];
int next[Maxn], n;

void getnext()               
{
       next[0] = -1;
       int k = -1, i = 0;
       while (i < n)
         {
             if (k == -1 || T[i] == T[k])
               {
                 i++;k++;next[i] = k;    
               }
             else k = next[k];            
         }    
       }
int main()
{
    scanf("%s", T);
    n = strlen(T);
    getnext();
    for (int i=0; i<=n; i++) cout <<next[i] <<" ";
    
    system("pause");
    
    
    return 0;
    }

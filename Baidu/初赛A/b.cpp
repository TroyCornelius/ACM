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


using namespace std;

int n, m,ex,ey;
struct Tnode
{
       int x,y;
       }d[10010];
int sum[110][110];
void init()
{
     memset(sum, 0, sizeof (sum));
       scanf("%d", &n);
       for (int i=0; i<n; i++) 
       {
           scanf("%d%d", &d[i].x, &d[i].y);
           d[i].x++;  d[i].y++;
           sum[d[i].x][d[i].y] = 1;
       }    
       
       for (int i=1; i<=ex; i++)
         for (int j=1; j<=ey; j++)
           sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];      
     
     }
void work()
{
     for (int x1=1; x1<=ex-15; x1++)
       for (int yy=1; yy<=ey-15; yy++)
       {
           for (int x2=x1+1; x2<=ex; x2++)
             for (int y2=yy+1; yy<=ey; yy++)
             {
                 
             }
           
       }
     
     
     }
int main()
{
    while (scanf("%d%d", &ex, &ey))
    {
       if (ex == 0 && ey == 0) break;
       ex++; ey++;       
       init();    
       work();      
    }
    
    
    
    
    return 0;
    }

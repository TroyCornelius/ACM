#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <cctype>
#include <algorithm>
#include <functional>
#define lowbit(x) ((x)&(-(x)))
using namespace std;

int sum[50][50];
int n, m;

bool check(int x1, int y1, int x2, int y2)
{
     x1++; y1++; x2++; y2++;
     int t = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];
     if (t % 2 == 0) return true;
     else return false;    
     
     }
class ComplementMachine2D
{
      
      public :
      int largestSubmatrix(vector <string> matrix)
      {
          n = matrix.size();
          m = matrix[0].length();
          memset(sum ,0, sizeof(sum));
          
          for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
              if (matrix[i][j]=='0') sum[i+1][j+1] = 0;
              else sum[i+1][j+1] = 1;
          
          for (int i=1; i<n; i++)
            for (int j=1; j<m; j++)
              sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
          int ans = 1;
          for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
              for (int x=i; x<n; x++)
                for (int y=j; y<m; y++)
                  {
                     if (check(i,j,x,y)) ans = max(ans,(x-i+1) * (y-j+1));                         
                  }
          return ans;        
      }
      
      };


int main()
{
    
    return 0;   
}

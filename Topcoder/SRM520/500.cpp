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

const int g[3] = {2, 4, 8};
inline int get_t(int p, int i, int j, int k)
{
       if (p==0) return i;
       else if (p==1) return j;
       else return k;
       }

class SRMCodingPhase
{
      public:
      int countScore(vector <int> points, vector <int> sk, int luck)
      {
          int ans = 0, tmp, ti;
          for (int i=0; i<=luck; i++)
            for (int j=0; j<=luck; j++)
              for (int k=0; k<=luck; k++)
              {
                  if (i + j + k <= luck)
                  {
                        if (sk[0]-i>0 && sk[1]-j>0 && sk[2]-k>0){
                        for (int t=1; t<8; t++)
                        {
                            tmp = ti = 0;
                            for (int p=0; p<3; p++)
                            if ((1<<p)&t)
                            {
                               tmp += points[p] - g[p]*(sk[p] - get_t(p, i, j, k));
                               ti += sk[p] - get_t(p, i, j, k);                                         
                            }
                           // cout <<i<<" "<<j<<" "<<k<<" "<<t<<tmp <<" "<<ti <<endl;
                            if (ti <= 75) ans = max(ans, tmp);
                        }
                        }
                  }
                  
              }      
          return ans;
      }
     
      };
int main()
{
    int num;
    vector<int>a, b;
    for (int i=0; i<3; i++) {cin >>num;a.push_back(num);}
    for (int i=0; i<3; i++) {cin >>num;b.push_back(num);}
    cin >>num;
    cout <<test.countScore(a, b, num) <<endl;
    
    system("pause");
    return 0;
    }

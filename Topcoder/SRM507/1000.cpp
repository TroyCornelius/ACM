#include <iostream>
#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#define Maxn 100000
#define oo 999999999
using namespace std;


int f[Maxn*2+10];
class CubeRoll
{
      public:
      int getMinimumSteps(int initPos, int goalPos, vector <int> holePos)
      {
          f[Maxn] = 0;
          int t = 0;
          for (int i=Maxn+1; i<=2*Maxn; i++) f[i] = ++t; 
          t = 0;
          int c;
          for (int j=Maxn-1; j>=0; j--) f[j] = ++t; 
          for (int i=2; i<=320; i++)
          {
             c = i * i;
             for (int j=Maxn-c; j>=0; j--) f[j] = min(f[j], f[j+c] + 1);
             for (int j=Maxn+c; j<=Maxn+Maxn; j++) f[j] = min(f[j], f[j-c]+1);
          }
          if (initPos > goalPos) swap(initPos, goalPos);
          int x;
          int y;
          for (x=0; x<holePos.size()-1; x++)
          {
             if (initPos > holePos[x] && holePos[x+1]>initPos) break;              
          }
          for (y=0; y<holePos.size()-1; y++)
          {
             if (goalPos > holePos[y] && holePos[y+1]>initPos) break;              
          }          
          if (holePos.size()==1 && initPos < holePos[0] && goalPos > holePos[0]) return -1;
          if (x != y) return -1;
          else return f[goalPos-initPos+Maxn];
      }
      }d;
int main()
{
    int n, m, c;
    vector<int> p;
    p.clear();
    p.push_back(3);
   cout << d.getMinimumSteps(5, 1, p) <<endl;
    system("pause");
}

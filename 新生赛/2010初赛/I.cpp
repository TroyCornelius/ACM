#include <iostream>
using namespace std;
typedef pair<int, int> point;
int T, map[6][6], ans;

int calc(int m)
{
    int sum = 0;
    for (int i=0; i<16; i++)
      if ((1<<i) & m) sum++;
    return sum;       
    }
point tran(int k)
{
      point ret;
      ret.second = k % 4;
      ret.first = k / 4;      
      }
bool check(int cho)
{
     int d[6][6];
     memcpy(d, map, sizeof(map));
     for (int j=0; j<16; j++)
       if ((1<<j) & cho)
         {
            point loc = tran(j);
            for (int x=0; x<4; x++) d[x][loc.second] = 1 - d[x][loc.second];
            for (int y=0; y<4; y++) d[loc.first][y] = 1 - d[loc.first][y];
            d[loc.first][loc.second] = 1 - d[loc.first][loc.second];                  
         }
     for (int i=0; i<4; i++)
       for (int j=0; j<4; j++)
         if (d[i][j] != 1) return false;
     return true;
     }
int main()
{
    cout <<(1<<16)-1 <<endl;
    cin >>T;
    int count;
    char c;
    for (; T>0; T--)
      {
         for (int i=0; i<4; i++)
           for (int j=0; j<4; j++)
             {
                cin >>c;
                map[i][j] = int(c - '0');
             }
         ans = 999999999;
         for (int i=0; i<(1<<16)-1; i++)
           {
              count = calc(i); 
              if (count > ans) continue;
              if (check(i)) ans <?= count;
           }
         cout <<ans <<endl;
      }
      
      system("pause");
    return 0;
    }

#include <iostream>
using namespace std;

int d[5][5];
bool check(int x, int y)
{
     for (int i=0; i<3; i++) if (d[i][y] < d[x][y]) return false;
     for (int j=0; j<4; j++) if (d[x][j] > d[x][y]) return false;
     return true; 
     }
int main()
{
    for (int i=0; i<3; i++)
      for (int j=0; j<4; j++)
        cin >>d[i][j];
    bool flag = false;
    for (int i=0; i<3; i++)
      for (int j=0; j<4; j++)
        {
           if (check(i,j)) {cout<<d[i][j]<<endl; flag = true;}       
        }
    if (!flag) cout<<"NO"<<endl;
   
    return 0;
    }

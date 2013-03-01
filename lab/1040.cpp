#include <iostream>
using namespace std;

int d[25];
bool check(int loc)
{
     for (int i=0; i<loc; i++) 
       if (d[i] == d[loc]) return false;
     return true;
     }
int main()
{
    int ans = 0;
    for (int i=0; i<20; i++)
      {
         cin >>d[i];
         if (check(i)) ans++;       
      }
    cout <<ans <<endl;  
    return 0;
    }

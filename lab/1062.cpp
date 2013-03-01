#include <iostream>
using namespace std;

int a[5][5];
int main()
{
    for (int i=0; i<3; i++)
      for (int j=0; j<4; j++)
        cin >>a[i][j];
    for (int j=0; j<4; j++){
      for (int i=0; i<3; i++)
        cout <<a[i][j] <<" ";
      cout<<endl;
      }
    
    return 0;
    }

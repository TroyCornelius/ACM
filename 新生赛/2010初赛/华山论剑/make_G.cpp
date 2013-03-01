#include <iostream>
using namespace std;

int n, m;
int main()
{
    freopen("g.in", "w", stdout);
    srand(time(NULL));
    n = rand()%5+1;
    m = rand()%5+1;
    cout <<n <<" "<<m <<endl;
    for (int i=0; i<n; i++)
      {
         for (int j=0; j<m; j++)
           cout<<rand()% 3 <<" ";
         cout <<endl;
             
      }

    return 0;
    }

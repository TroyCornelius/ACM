#include <iostream>
#include <ctime>
using namespace std;


int n, x1, x2, t1, t2, t0;
int main()
{
    freopen("c.in", "w", stdout);
    srand(time(NULL));
    t1 = rand()%10000;
    t2 = rand()%10000;
    t2 = t1 + t2;
    t0 = t1 + (rand()%(t2 - t1));
    
    x1 = rand()%10000 + 1;
    x2 = rand()%10000 + 1;
    printf("%d %d %d %d %d\n", t1, t2, x1, x2, t0);
    
    return 0;
    }

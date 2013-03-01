#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;
const int maxn = 20;
int T, n, k, Q;
int main()
{
    freopen("d.in", "w", stdout);
    int tmp, a, b, c, t;
    srand(time(NULL));
    T = 3;
    cout <<T <<endl;
    while (T--)
    {
        n = (rand()%maxn) + 1;
        k = rand()%9 + 2;
        Q = (rand()%maxn) + 1;
        printf("%d %d %d\n", n, k, Q);
        tmp = 0;
        for (int i=1; i<k; i++)
        {
            tmp += (rand()% (maxn)) + 1;
            printf("%d%c", tmp, i==k-1?'\n':' ');
        }
        for (int i=0; i<Q; i++)
        {
            tmp = rand() % 2;
            if (tmp == 0)
            {
               c = rand() % maxn + 1;
               a = rand() % n + 1;
               b = rand()%(n - a + 1);
               b+=a;
               printf("W %d %d %d\n", a, b, c);                    
            }
            else
            {
                a = rand() % n + 1;
                b = rand() %(n - a + 1);     
                b += a;  
                printf("Q %d %d\n", a, b);        
            }            
        }
        printf("\n");          
    }
    
    return 0;
    }

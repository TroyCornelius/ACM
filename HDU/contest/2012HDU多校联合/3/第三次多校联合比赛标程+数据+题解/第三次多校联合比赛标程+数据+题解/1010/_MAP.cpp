#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <sstream>
using namespace std;

int n;
char ann[110][10100];
char rst[110][10100];
char c;

double getAP(char *a , char *b)
{
    map<string , int> mp;

    istringstream ann(a);
    istringstream rst(b);

    string s;
    double AP = 0.0;
    int ccount = 0 , id = 0 , total = 0;

    ann >> s;
    while(ann >> s)
        mp[s] = 1 , total ++;

    rst >> s;
    while(rst >> s)
    {
        ccount ++;
        if(mp[s] == 1)
        {
            id ++;
            AP += 1.0 * id / ccount;
        }
    }

    return AP / total;
}
int main()
{
    while(scanf("%d" , &n) != EOF)
    {
        gets(ann[0]);
        for(int i = 1 ; i <= n ; i ++)
            gets(ann[i]);
        for(int i = 1 ; i <= n ; i ++)
            gets(rst[i]);

        double mAP = 0.0;
        for(int i = 1 ; i <= n ; i ++)
            mAP += getAP( ann[i] , rst[i] );

        printf("%.6f\n" , mAP / n);
    }
    return 0;
}

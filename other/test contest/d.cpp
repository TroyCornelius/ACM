#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct Tnode
{
    double x,y,r;
    int id;
    bool operator<(const Tnode &b)const
    {
        return r > b.r;
    }
}p[5];
inline double calc(int i, int j)
{
    double tx = p[i].x - p[j].x, ty = p[i].y - p[j].y;
    return sqrt(tx*tx + ty*ty);
}
bool ans[5];
int main()
{
    int T;
    cin >>T;
    while (T--)
    {
        for (int i=0; i<3; i++) cin >>p[i].x >>p[i].y;
        for (int i=0; i<3; i++) cin >>p[i].r, p[i].id = i;
        sort(p, p+3);
        
        double len1 = calc(0, 1), len2 = calc(0, 2);
        if (len1 <= p[0].r+p[1].r && len2 <= p[2].r+p[0].r) printf("%c\n",('A'+p[0].id));
        else cout <<"No Solution!" <<endl;
        
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int T, n;
vector<int> d;

int main()
{
    scanf("%d", &T);
    for (;T>0;T--)
    {
        scanf("%d", &n);
        d.clear();
        int t;
        for (int i=0; i<n; i++)
        {
            scanf("%d", &t);
            d.push_back(t);            
        }
        sort(d.begin(), d.end());
        for (int i=0; i<d.size(); i++) printf("%d\n", d[i]);        
    }
    
    
    return 0;
    }

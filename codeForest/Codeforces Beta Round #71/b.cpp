#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int n, m, k, T;
long long blk[2010];
long long encode(long long a, long long b)
{
     long long ret;
    return ret =  m * (a - 1) + b;
    }
int get_loc(long long num)
{
    int lo = 0, hi = k-1, mid;
    while (lo + 1 < hi)
    {
       mid = (lo + hi) / 2;
       if (blk[mid] < num) lo = mid;
       else hi = mid;          
    }
    if (blk[lo] >= num) return lo;
    else 
    if (blk[mid]>= num) return mid;
    else
    return hi;    
    }
int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &T);
    long long a, b;
    for (int i=0; i<k; i++)
    {
        cin >>a >>b;
        blk[i] = encode(a,b);
    }
    sort(blk, blk+k, less<int>());
    for (;T>0;T--)
    {
        cin >>a >>b;
        long long id = encode(a, b);
        int loc = get_loc(id);
        if (blk[loc] == id) cout <<"Waste" <<endl;
        else
        {
           long long tot = id - loc;
           if (tot % 3 == 0) cout <<"Grapes" <<endl;
           else
           if (tot % 3 == 1) cout <<"Carrots" <<endl;
           else cout <<"Kiwis" <<endl;            
        }
    }
    return 0;
    }

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Maxn 10100
using namespace std;

int n, d[10];
int sum;
int main()
{
  //  while (1){
    sum = 0;
    cin >>n;
    for (int i=1; i<=7; i++) 
    {
        cin >>d[i];
        sum += d[i];
    }
    n %= sum;
    if (n == 0) 
    {
          for (int i=7; i>=1; i--)
          if (d[i] != 0)
          {
             cout <<i <<endl;
             break;                   
          }          
    }
    else{
    int ans = 1;
    n -= d[1];
    while (n > 0)
    {
        ans++;
        n -= d[ans];    
    }
    cout <<ans <<endl;
}
//}
    return 0;
}

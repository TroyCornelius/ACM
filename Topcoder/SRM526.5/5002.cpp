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
using namespace std;

class MagicCandy
{
    public:
    int whichOne(int n)
    {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        else
        {
            long long sum = 2, now = 2, ans=3, tmp=2;
            while (sum < n)
            {
                sum += now;
                if (sum >= n) break;
                ans += tmp;
                
                sum += now;
                if (sum >= n) break;
                ans +=tmp;
                tmp++;
                now++;                
            }
            return ans;
        
        
        }
    
    }
        

};


#include <iostream>


using namespace std;


int main()
{
    dp[0] = 1.0;
    for (int i=0; i<=T; i++)
    {
        for (int j=0; j<n; j++)
        {   
            int  v = min(T+1, i+length[j]);
            if (v == T+1) ret[j] += dp[i]/n;
            else dp[v] += dp[i]/n;            
        }
        
    }
    
    return 0;
    }

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#define Maxn 100100
using namespace std;

int n, Q;
string s1, s2;
int t[Maxn];
set<int> loc;
void add(int idx, int val)
{
    for (; idx<=n; idx+=idx&-idx) t[idx] += val;
}
int gsum(int idx)
{
    int ret = 0;
    for (;idx; idx-=idx&-idx) ret += t[idx];
    return ret;
}
void print(int c, int idx)
{
    int sum = s1[idx]-'0' + s2[idx]-'0' + c;
    cout <<sum%2 ;
}
int main()
{
    string op;
    int a;
    char b;
    while (cin >>n >>Q)
    {
        loc.clear();
        memset(t, 0, sizeof(t));
        cin >>s1;
        cin >>s2;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        loc.insert(n+1);
        for (int i=0; i<n; i++)
        {
            if (s1[i] == '1') add(i+1, 1);
            if (s2[i] == '1') add(i+1, 1);
            if (s1[i] == '1' && s2[i] == '1') loc.insert(i+1);        
        }
        s1 += "0"; s2 += "0";
        while (Q--)
        {
            cin >>op;
            if (op == "set_a")
            {
                cin >>a >>b;
                if (s1[a] == b) continue;
                if (b == '1') 
                {
                    add(a+1, 1);
                    if (s2[a] == '1') loc.insert(a+1);
                    s1[a] = b;
                }
                else 
                {
                    add(a+1, -1);
                    if (s2[a] == '1')
                    {
                        loc.erase(loc.lower_bound(a+1));
                    }
                    s1[a] = b;
                }
                
            }
            else
            if (op == "set_b")
            {
                cin >>a >>b;
                if (s2[a] == b) continue;
                if (b == '1') 
                {
                    add(a+1, 1);
                    if (s1[a] == '1') loc.insert(a+1);
                    s2[a] = b;
                }
                else 
                {
                    add(a+1, -1);    
                    if (s1[a] == '1') loc.erase(loc.lower_bound(a+1));
                    s2[a] = b;
                }            
            }
            else
            {
                cin >>a;
                set<int>::iterator p = loc.lower_bound(a+1);
                if (p != loc.begin())
                {
                    p--;
                    int len = *p;
                    int tmp = gsum(a) - gsum(len);
                    if (tmp == a - len) print(1, a);
                    else print(0, a);               
                   // cout <<len <<" "<<tmp<<" "<<a-len<<endl;      
                }               
                else print(0, a);              
            }
          //  cout <<s1 <<" "<<s2 <<endl;
        }
        cout <<endl;
    }
    return 0;
}

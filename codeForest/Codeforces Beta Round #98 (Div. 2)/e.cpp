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
struct Tnode
{
    bool flag;
    int len, sum;
    Tnode(){}
    Tnode(bool _a, int _b, int _c)
    :flag(_a), len(_b), sum(_c){}
};
string s;
inline bool isvol(char ch)
{
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}
Tnode check(int k)
{
    int sc = 0, sv = 0;
    int cnt = 0, j = k;
    bool f = false;
    for (int i=0; i<k; i++)
        if (isvol(s[i])) sv++;
        else sc++;
        
    if (sv <= 2 * sc) f = true, cnt++;
    while (j < s.length())
    {
        if (isvol(s[j-k])) sv--;
        else sc--;
        if (isvol(s[j])) sv++;
        else sc++;
        if (sv <= 2*sc) f=true, cnt++;
        j++;    
    } 
    return Tnode(f, k, cnt);
}
int main()
{
    while (1){
    Tnode ans(1, -1, 0);
    cin >>s;
    for (int i=0; i<s.length(); i++) s[i] = tolower(s[i]);
    cout <<s <<endl;
    int lo = 0, hi = s.length()+1, mid=1;
    while (lo + 1 < hi)
    {
        mid = (lo + hi) >>1;
        Tnode tmp = check(mid);
        cout <<mid <<" "<<tmp.flag <<" "<<tmp.sum <<" "<<lo <<" "<<hi <<endl;
        if (tmp.flag) lo = mid, ans = tmp;
        else hi = mid;    
    }
    Tnode tmp = check(mid);
    if (tmp.flag) ans = tmp;
    if (ans.len==-1) cout <<"No solution"<<endl;
    else cout <<ans.len <<" "<<ans.sum <<endl;
}
    return 0;
}

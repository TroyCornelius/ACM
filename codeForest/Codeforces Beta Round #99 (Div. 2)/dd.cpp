#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>

using namespace std;

string s, ans1, ans2;
int cnt[15], tot;

void calc(int x1, int x2)
{
    string s1, s2;
    int t1[15], t2[15];
    memcpy(t1, cnt, sizeof(cnt));
    memcpy(t2, cnt, sizeof(cnt));
    t1[x1]--; t2[x2]--;
    if (t1[x1] < 0 || t2[x2] < 0) return;
    
    s1 = string(1, '0'+x1); 
    s2 = string(1, '0'+x2);
    
    int tmp = 1;
    for (int i=0; i<=9; i++)
    {
        int now = min(t1[i], t2[9-i]);
        t1[i] -= now; t2[9-i] -= now;
        s1 += string(now, '0'+i);
        s2 += string(now, '0'+(9-i));
        tmp += now;
    }
    int now = min(t1[0], t2[0]);
    tmp += now;
    s1 = string(now, '0') + s1;
    s2 = string(now, '0') + s2;
    t1[0] -= now; t2[0] -= now;
    for (int i=0; i<10; i++)
    {
        s1 += string(t1[i], '0'+i);
        s2 += string(t2[i], '0'+i);
    }
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    
    if (tmp > tot)
    {
        tot = tmp;
        ans1 = s1;
        ans2 = s2;    
    }
    return;
}
int main()
{
  //  while (1){
    cin >>s;
    memset(cnt, 0, sizeof(cnt));
    int len = s.length();
    for (int i=0; i<len; i++) cnt[s[i]-'0']++;
    
    tot = cnt[0];
    for (int i=0; i<10; i++) ans1 += string(cnt[i], '0'+i);
    reverse(ans1.begin(), ans1.end());
    ans2 = ans1;
    
    for (int i=1; i<10; i++)
    {
        calc(i, 10-i);    
    }
    cout <<ans1 <<endl;
    cout <<ans2 <<endl;
//}

    return 0;
}

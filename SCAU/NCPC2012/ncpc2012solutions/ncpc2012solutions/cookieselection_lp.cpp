//Sample solution for the Cookie Selection problem in NCPC 2012 by Lukáš Poláček (lukasP)
#include <vector>
#include <cstdio>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

typedef vector<int> vi;
int main()
{
    string s;
    priority_queue<int> a;
    priority_queue<int, vi, greater<int> > b;
    while (getline(cin, s))
    {
        if (s.empty())
            break;
        if (s[0] == '#')
        {
            printf("%d\n", a.top());
            a.pop();
            if (!b.empty() && a.size() <= b.size())
            {
                a.push(b.top());
                b.pop();
            }
        }
        else
        {
            int n;
            sscanf(s.c_str(), "%d", &n);
            if (!a.empty() && n > a.top())
            {
                b.push(n);
                if (a.size() <= b.size())
                {
                    a.push(b.top());
                    b.pop();
                }
            }
            else
            {
                a.push(n);
                if (a.size() > b.size() + 2)
                {
                    b.push(a.top());
                    a.pop();
                }
            }
        }
    }
}

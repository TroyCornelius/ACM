#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
#define N 8
using namespace std;

typedef vector<int> vi;

int sg[N];
int lit[] = {0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 55};
vi t;

void cal(int x, int y, vi v) //x: the number, y: pieces
{
    if(y < 0) return ;
    if(x < lit[y]) return ;
    
    if(!x)
    {
        if(y) {cout<<"error"<<endl; while(1);}
        int r = 0;
        for(int i = 0; i < v.size(); i++) r ^= sg[v[i]];
        REP(i, v.size()) cout <<v[i]<<" ";
        cout <<endl;
        t.pb(r);
        return ;
    }
    
    int b = v.size() ? v[v.size()-1] : 0;
    for(int i = b+1; i <= x; i++)
    {
        int p = x - i;
        if(p < 0) break;
        v.pb(i);
        cal(p, y-1, v);
        v.pop_back();
    }
}

void prep()
{
    memset(sg, 0, sizeof(sg));
    for(int i = 3; i < N; i++)
    {
        cout<<endl<<"checking: "<<i<<endl;
        vi v;
        t.clear();
        for(int j = 2; j <= 10; j++)
        {
            cal(i, j, v);
        }
        sort(t.begin(), t.end());
        t.erase(unique(t.begin(), t.end()), t.end());
        int x = 0;
        sg[i] = -1;
        for(int j = 0; j < t.size(); j++, x++)
        {
            if(t[j] == x) continue;
            sg[i] = x;
            break;
        }
        if(sg[i] == -1) sg[i] = x;
    }
    
   /* memset(sg, -1, sizeof(sg));
    sg[1] = sg[2] = sg[4] = sg[8] = 0;
    for(int i = 1, j = 1; i < N; i++)
    {
        if(sg[i] == 0) continue;
        sg[i] = j++;  
        //cout <<sg[i] <<endl;  
    }*/
}

int main()
{
    prep();
    system("pause");   
    return 0;
    }

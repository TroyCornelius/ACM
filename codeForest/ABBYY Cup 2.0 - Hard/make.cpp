/*
 * Author:  Troy
 * Created Time:  2012/4/29 0:32:15
 * File Name: 
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

vi a;
bool vis[20000];
int main() 
{
    freopen("c.in", "w", stdout);
    srand(time(NULL));
    cout << 100 <<" "<<rand()%10+1 <<" " <<20 <<endl;
    memset(vis, false, sizeof(vis));
    int id;
    REP(i, 20)
    {
        int tmp = rand()%2;
        //cout <<tmp <<endl;
        if (tmp == 0)
        {
            cout <<"+ ";
            while (1){
                id = rand()%1000 + 1;
                //cout <<id <<endl;
                if (!vis[id])
                {
                    vis[id] = true;
                    a.pb(id);
                    break;
                }            
            }
            cout <<id <<" " <<(rand()%100) <<endl;
        }  
        else
        {
            if (a.size() == 0)
            {
                i--;
                continue;
            }
            int loc = rand()%(a.size());
            cout <<"- " <<a[loc] <<endl;
            a.erase(a.begin() + loc);
        }
        //cout <<"---" <<i <<endl;
    }
    return 0;
}


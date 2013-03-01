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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

vector<string> vec;
int n;
string a, b;
int main() 
{
    cin >>n;
    vec.clear();
    vec.pb("/");
    for(int i = 0; i < n; i++) 
    {
        cin >> a;
        if(a == "cd") 
        {
            cin >> b;
            int idx1 = 0, idx2 = 0;;
            if(b[0] == '/') idx1 = 1;
            while(true)
            {
                if((idx2 = b.find("/", idx1)) != string::npos)
                {
                    string tmp = b.substr(idx1, idx2 - idx1);
                    if(tmp == "..") vec.pop_back();
                    else vec.pb(tmp + "/");
                } 
                else
                {
                    string tmp = b.substr(idx1);
                    if(tmp == "..") vec.pop_back();
                    else vec.pb(tmp + "/");
                    break;
                }
                idx1 = idx2 + 1;
            }
        } 
        else 
        {
            int size = vec.size();
            for(int i = 0; i < size; i++) cout << vec[i];
            cout << endl;
        }
    }
    
    return 0;
}

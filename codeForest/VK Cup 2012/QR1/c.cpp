#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "vector"
#include "queue"
#include "cmath"
#include "string"
#include "cctype"
#include "map"
#include "iomanip"
using namespace std;
#define pb push_back
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long
vector<string> vec;
int n;
string a, b;
int main() {
    while(cin >> n) {
        vec.clear();
        vec.push_back("/");
        for(int i = 0; i < n; i++) {
            cin >> a;
            if(a == "cd") {
                cin >> b;
                int idx1 = 0, idx2 = 0;;
                if(b[0] == '/') idx1 = 1;
                while(1) {
                    if((idx2 = b.find("/", idx1)) != string::npos) {
                        string tmp = b.substr(idx1, idx2 - idx1);
                        if(tmp == "..") vec.pop_back();
                        else vec.push_back(tmp + "/");
                    } else {
                        string tmp = b.substr(idx1);
                        if(tmp == "..") vec.pop_back();
                        else vec.push_back(tmp + "/");
                        break;
                    }
                    idx1 = idx2 + 1;
                }
            } else {
                int size = vec.size();
                for(int i = 0; i < size; i++) cout << vec[i];
                cout << endl;
            }
        }
    }
    return 0;
}

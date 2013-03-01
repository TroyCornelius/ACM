#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int n;
int T = 0;
vi t,u;
vector<vi> p;

bool possible(int kid, int teacher) {
    if (t[kid] == teacher || u[kid] != -1 && u[kid] != teacher) {
	return false;
    }
    if (u[kid] == teacher) {
	return true;
    }
    u[kid] = teacher;
    for (int i = 0; i < n; ++i) {
	if (i == kid) continue;
	if ((p[kid][i] >= T || p[i][kid] >= T) && teacher != t[i]) {
	    for (int j = 0; j < 3; ++j)
		if (j != teacher && j != t[i] && !possible(i,j)) {
		    u[kid] = -1;
		    return false;
		}
	}
    }
    return true;
}

int main() {
    cin >> n;
    t = vi(n); //current teacher
    u = vi(n,-1); //new teacher
    p = vector<vi>(n,vi(n,0)); //preferences
    for (int i = 0; i < n; ++i) {
	cin >> t[i];
	for (int j = 0; j < n; ++j) {
	    if (i==j) continue;
	    int kid;
	    cin >> kid;
	    p[i][kid-1] = j - (j>i);
	}
    }
    for (T = 0; ; ++T) {
	bool ok = true;
	u = vi(n,-1);
	for (int i = 0; i < n; ++i) {
	    vi up = u;
	    if (u[i] == -1) {
		for (int j = 0; j < 3; ++j) {
		    if (!possible(i,j))
			u = up;
		    else
			break;
		}
	    }
	    if (u[i] == -1) {
		ok = false;
		break;
	    }
	}
	if (ok) {
	    cout << T << endl;;
	    break;
	}
    }
}

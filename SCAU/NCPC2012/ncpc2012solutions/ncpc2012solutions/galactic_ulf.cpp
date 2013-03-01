#include <iostream>
#include <vector>
using namespace std;

int main() {
    int W, P;
    cin >> W >> P;
    vector<int> x1(P), y1(P), x2(P), y2(P);
    bool parallel = true;
    int same = 0;
    for (int i = 0; i < P; ++i) {
	cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	parallel = parallel && (x2[i]-x1[i])*(y2[0]-y1[0])-(y2[i]-y1[i])*(x2[0]-x1[0]) == 0 || !i;
	for (int j = 0; j < i; ++j) {
	    if ((x2[i]-x1[i])*(y2[j]-y1[j])-(y2[i]-y1[i])*(x2[j]-x1[j]) == 0 && (x2[i]-x1[i])*(y2[i]-y1[j])-(y2[i]-y1[i])*(x2[i]-x1[j]) == 0) {
		++same;
		break;
	    }
	}
    }
    P -= same;
    if (parallel) {
	if (W <= P+1)
	    cout << 0 << endl;
	else
	    cout << max(1, (W+1)/2-P) << endl;
    } else
	cout << max(0, (W+1)/2-P) << endl;
}


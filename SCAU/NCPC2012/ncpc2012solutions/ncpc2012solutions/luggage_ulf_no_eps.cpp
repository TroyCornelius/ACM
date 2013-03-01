#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<double, double> pdd;

int main() {
    int N, L;
    cin >> N >> L;
    vector<double> x(N,0);
    for (int i = 0; i < N; ++i) {
	cin >> x[i];
    }

    //vector of speed intervals that will cause a collision
    vector<pdd> I;
    I.push_back(pdd(10,100));

    //for each pair of bags add all collision speeds to I
    for (int i = 0; i < N; ++i) {
	for (int j = i+1; j < N; ++j) {
	    double Dx = max(x[i]-x[j],x[j]-x[i]); //distance on conveyor
	    I.push_back(pdd(Dx,100));   //collision if faster than Dx
	    for (int n = 1; Dx/(n*L-1) > 0.1; ++n) { //number of turns n
		//minimum and maximum speed for collision after n turns
		I.push_back(pdd(Dx/(n*L+1),Dx/(n*L-1)));
	    }
	}
    }

    //find the maximum non-collision speed
    sort(I.begin(),I.end());
    double end = 0.1, best = 0;
    for (int i = 0; i < I.size() && I[i].first <= 10; ++i) {
	if (I[i].first >= end)
	    best = I[i].first;
	end = max(end,I[i].second);
    }

    //output result
    if (best == 0)
	cout << "no fika" << endl;
    else {
	cout.precision(10);
	cout << best << endl;
    }
}

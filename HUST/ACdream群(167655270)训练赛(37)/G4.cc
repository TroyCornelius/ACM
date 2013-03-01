// @EXPECTED_RESULTS@: CORRECT
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>
#include <float.h>

using namespace std;

#define MAX_P 105
#define INF (0.5*DBL_MAX)
#define sq(x) ((x)*(x))
#define dist(a,b) (sqrt(sq(x[a]-x[b])+sq(y[a]-y[b])))

double order[MAX_P][MAX_P];
bool fired[MAX_P];
map<string,int> names;
string persons[MAX_P];
double x[MAX_P], y[MAX_P];
int indegree[MAX_P];

int main(int argc, char **argv) {
	int numCases;
	cin >> numCases;

	while (numCases --> 0) {
		int numPersons, numObserv, numFired = 0;
		cin >> numPersons >> numObserv;

		names.clear();
		for (int i = 0; i < numPersons; i++) {
			fired[i] = false;
			for (int j = 0; j < numPersons; j++) {
				order[i][j] = -INF;
			}
			cin >> persons[i] >> x[i] >> y[i];
			names[persons[i]] = i;
			indegree[i] = 0;
		}

		for (int i = 0; i < numObserv; i++) {
			string a, b, c, d, e, f;
			cin >> a >> b >> c >> d >> e >> f;
			int first = names[c];
			int second = names[f];
			int observer = names[a];

			double distance = dist(first,observer) - dist(second,observer);
			order[second][first] = max(order[second][first], distance);
			fired[first] = fired[second] = true;
		}

		bool impossible = false;
		for (int k = 0; !impossible && k < numPersons; k++) {
			if (fired[k]) numFired++;
			for (int i = 0; i < numPersons; i++) {
				for (int j = 0; j < numPersons; j++) {
					order[i][j] = max(order[i][j], order[i][k] + order[k][j]);
				}
				if (order[i][i] > 0) {
					impossible = true;
					break;
				}
			}
		}
		if (impossible) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}

		queue<int> q;
		for (int i = 0; i < numPersons; i++) {
			for (int j = 0; j < numPersons; j++) {
				if (order[i][j] > 0.0) {
					indegree[i]++;
				}
			}
			if (indegree[i] == 0 && fired[i]) {
				q.push(i);
			}
		}

		bool unknown = false;
		vector<int> output;
		while (!q.empty()) {
			if (q.size() > 1) {
				unknown = true;
				break;
			}
			int next = q.front();
			q.pop();
			output.push_back(next);
			for (int i = 0; i < numPersons; i++) {
				if (order[i][next] > 0.0) {
					indegree[i]--;
					if (indegree[i] == 0 && fired[i]) {
						q.push(i);
					}
				}
			}
		}

		if (unknown) {
			cout << "UNKNOWN" << endl;
		} else {
			for (int i = 0; i < numFired; i++) {
				cout << (i==0 ? "" : " ") << persons[output[i]];
			}
			cout << endl;
		}
	}

	return 0;
}

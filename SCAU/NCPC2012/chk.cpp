// Sample solution for the Eco-driving problem in NCPC 2012 by Fredrik Svensson.
#include <cmath>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
using namespace std;

const double ERROR_DISTANCE = 1.0e100;
const int MAX_JUNCTIONS = 200;

struct Junction
{
	int x;
	int y;
	vector<int> dests;
};

int junctionCount, roadCount;
Junction junctions[MAX_JUNCTIONS];

struct Path
{
	int curJunc;
	int prevJunc;
	double distToCur;

	bool operator<(const Path& rhs) const
	{
		return distToCur > rhs.distToCur; // Priority queue takes largest first; do opposite
	}
};

double FindDistance(double maxDistance, double maxAngleDeg = -2)
{
	double minCosAngle;
	if (maxAngleDeg < -1)
		minCosAngle = -2; // Everything will work
	else
		minCosAngle = cos(maxAngleDeg * 3.1415926535897932384626433832795 / 180.0);

	bool visited[MAX_JUNCTIONS][MAX_JUNCTIONS]; // curJunc, prevJunc
	for (int i = 0; i < junctionCount; ++i)
		for (int j = 0; j < junctionCount; ++j)
			visited[i][j] = false;

	priority_queue<Path> pathQueue;
	// Initialize with all roads out from the start junction
	{
		Path p;
		p.prevJunc = 0;
		const Junction& prevJunc = junctions[0];
		for (size_t j = 0; j < prevJunc.dests.size(); ++j)
		{
			p.curJunc = prevJunc.dests[j];
			const Junction& curJunc = junctions[p.curJunc];
			double dx1 = curJunc.x - prevJunc.x;
			double dy1 = curJunc.y - prevJunc.y;
			p.distToCur = sqrt(dx1*dx1+dy1*dy1);
			pathQueue.push(p);
		}
	}
	while (!pathQueue.empty())
	{
		Path p = pathQueue.top();
		pathQueue.pop();

		if (p.curJunc == junctionCount - 1)
			return p.distToCur;

		const Junction& curJunc = junctions[p.curJunc];
		const Junction& prevJunc = junctions[p.prevJunc];
		if (visited[p.curJunc][p.prevJunc])
			continue;
		visited[p.curJunc][p.prevJunc] = true;

		double dx1 = curJunc.x - prevJunc.x;
		double dy1 = curJunc.y - prevJunc.y;
		double len1 = sqrt(dx1*dx1+dy1*dy1); // Yes, I know that sqrt() is not needed
		for (size_t j = 0; j < curJunc.dests.size(); ++j)
		{
			int nextJuncIdx = curJunc.dests[j];
			if (visited[nextJuncIdx][p.curJunc])
				continue;
			const Junction& nextJunc = junctions[nextJuncIdx];
			double dx2 = nextJunc.x - curJunc.x;
			double dy2 = nextJunc.y - curJunc.y;
			double len2 = sqrt(dx2*dx2+dy2*dy2); // Yes, I know that sqrt() is not needed yet
			double scalarScaled = dx1*dx2 + dy1*dy2;
			if (scalarScaled >= len1 * len2 * minCosAngle)
			{
				// Possible to travel prev->cur->next
				Path np;
				np.curJunc = nextJuncIdx;
				np.prevJunc = p.curJunc;
				np.distToCur = p.distToCur + len2; // sqrt() is then needed here
				pathQueue.push(np);
			}
		}
	}
	return 2*ERROR_DISTANCE;
}

double DoIt(double maxDistance)
{
	if (FindDistance(maxDistance) > maxDistance)
		return -1;
	double minAngle = 0;
	double maxAngle = 180;
	while (maxAngle - minAngle > 1.0e-8)
	{
		double angle = (minAngle + maxAngle) / 2;
		double distance = FindDistance(maxDistance, angle);
		if (distance > maxDistance)
			minAngle = angle;
		else
			maxAngle = angle;
	}
	double ret = (minAngle + maxAngle) / 2;
	return ret;
}

int main()
{
    freopen("ecodriving.in", "r", stdin);
    //freopen("e.out", "w", stdout);
	double maxDistance;
	while (cin >> junctionCount >> roadCount >> maxDistance) {
	for (int i = 0; i < junctionCount; ++i)
	{
		Junction j;
		cin >> j.x >> j.y;
		junctions[i] = j;
	}
	for (int i = 0; i < roadCount; ++i)
	{
		int source, dest;
		cin >> source >> dest;
		--source;
		--dest;
		junctions[source].dests.push_back(dest);
	}

	double ret = DoIt(maxDistance);

	if (ret < -0.5)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		cout << fixed << setprecision(3) << ret << endl;
	}
}
	return 0;
}


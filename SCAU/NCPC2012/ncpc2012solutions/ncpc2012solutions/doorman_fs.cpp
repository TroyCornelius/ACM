// Sample solution for the Doorman problem in NCPC 2012 by Fredrik Svensson.
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int x;
	string q;
	cin >> x;
	cin >> q;
	int diff = 0;
	for (size_t i = 0; i < q.size(); ++i)
	{
		if (q[i] == 'M')
			++diff;
		else
			--diff;
		if (abs(diff) > x+1)
		{
			cout << i-1 << endl;
			return 0;
		}
	}
	if (abs(diff) == x+1)
		cout << q.size()-1 << endl;
	else
		cout << q.size() << endl;
	return 0;
}

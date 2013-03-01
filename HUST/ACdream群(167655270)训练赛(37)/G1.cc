/*
 *   [NWERC'11] Smoking Gun
 *   by: Jan Kuipers
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

const double infty = 1e100;

int main () {

	int runs;
  cin>>runs;
	
  while (runs--) {

		int N,M;
		cin>>N>>M;
		
		map<string,int> id;
		vector<string> s(N);
		vector<double> x(N),y(N);
		
		for (int i=0; i<N; i++) {
			cin>>s[i]>>x[i]>>y[i];
			id[s[i]]=i;
		}

		vector<vector<double> > t(N, vector<double>(N, infty));
		vector<bool> u(N, false);
		
		for (int i=0; i<M; i++) {
			string a,b,c,d;
			cin>>a>>d>>b>>d>>d>>c;
			
			int i=id[a],j=id[b],k=id[c];
			double tij = sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
			double tik = sqrt((x[k]-x[i])*(x[k]-x[i])+(y[k]-y[i])*(y[k]-y[i]));
			
			t[j][k] = min(t[j][k], tik - tij);
			u[j] = u[k] = true;
		}

		for (int k=0; k<N; k++)
			for (int i=0; i<N; i++)
				for (int j=0; j<N; j++)
					t[i][j] = min(t[i][j], t[i][k]+t[k][j]);

		bool ok = true;

		for (int i=0; i<N; i++)
			if (u[i] && t[i][i]<0)
				ok = false;

		if (!ok) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}

		int nused = 0;		
		for (int i=0; i<N; i++)
			if (u[i]) nused++;
		
		vector<int> order(nused, -1);

		for (int i=0; i<nused; i++) {
			for (int j=0; j<N; j++) 
				if (u[j]) {
					
					ok = true;
					for (int k=0; k<N; k++) 
						if (u[k] && t[k][j]<0)
							ok = false;
						
					if (ok) {
						if (order[i]!=-1) {
							order[i] = -1;
							break;
						}
						order[i] = j;
					}
				}

			ok = order[i]!=-1;
			if (!ok) break;

			u[order[i]] = false;
		}

		if (!ok) {
			cout << "UNKNOWN" << endl;
			continue;
		}
		
		for (int i=0; i<order.size(); i++) {
			if (i>0) cout << " ";
			cout << s[order[i]];
		}

		cout << endl;
  }
	
  return 0;   
}

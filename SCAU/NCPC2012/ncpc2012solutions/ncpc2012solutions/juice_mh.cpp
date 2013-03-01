/*
 * Juice problem: Judge solution
 * Author: Matias Holte <kjetimh@ulrik.uio.no>
 * Licence: Creative Commons Attribution 3.0 Unported Licence
 *
 * Using dynamic programming to solve problem
 */

#include<iostream>
#include<vector>

#define INF 1000000

using namespace std;

vector<vector<int> > children;
vector<vector<int> > demand;
vector<vector<int> > capacity;

/* input: node = current house
 * return an array res:
 * res[i] = power required to light up i houses among children of node
 */

vector<int> maxjuice(int node){
  vector<int> res(1,0);
  for (int i=0;i<children[node].size();i++){
    vector<int> child = maxjuice(children[node][i]);
    child.push_back(INF);
    for (int j=child.size()-1;j>=0;j--){
      if (child[j+1]>child[j]+demand[node][i])
	child[j+1]=child[j]+demand[node][i];
    }
    for (int j=1;j<child.size();j++){
      if (child[j]>capacity[node][i]){
	child.resize(j);
	break;
      }
    } 
    vector<int> rcopy(child.size()+res.size()-1,INF);
    for (int j=0;j<res.size();j++){
      for (int k=0;k<child.size();k++){
	if (rcopy[j+k]>res[j]+child[k])
	  rcopy[j+k]=res[j]+child[k];
      }
    }
    res = rcopy;
  }
  return res;
}


int main(){
  int N,p,r,c;
  cin>>N;
  children.resize(N+1);
  demand.resize(N+1);
  capacity.resize(N+1);
  for (int i=0;i<N;i++){
    cin>>p>>r>>c;
    children[p].push_back(i+1);
    demand[p].push_back(r);
    capacity[p].push_back(c);
  }
  vector<int> res = maxjuice(0);
  cout<<res.size()-1<<endl;
}

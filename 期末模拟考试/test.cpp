//#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
int  main()
{
 typedef vector<int> vint;
 vint v1,v2;
 cout<<"please enter the v1(must be int)"<<endl;
 int i;
 while (cin>>i)
  v1.push_back(i);
 cout<<"please enter the v2(must be int)"<<endl;
 while (cin>>i)
  v2.push_back(i);
 if (v1.size()==v2.size())
 {
  cout<<"no pre";
  return 0;
 }
 vint::size_type n=0;
 bool result=true;
 n=(v1.size()>v2.size())? v1.size() : v2.size();
 for (vint::size_type i=0;i<n;++i)
 {
  if (v1[i]=v2[i])
   continue;
  else
  {
   result=false;
   break;
  }
 }
 cout<<result;
 return 0;
}

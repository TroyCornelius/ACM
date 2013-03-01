#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

string s;
int num;

int main()
{
	int tests;
	cin >> tests;
	for (int ii=1;ii<=tests;ii++)
	{
		cin >> s;
		while (s.length()>1)
		{
			int num=0;
			for (int i=0;i<s.length();i++)
				num+=(s[i]-'0');
			string ss="";
			while (num>0)
			{
				ss+=(char) ((num%10)+'0');
				num/=10;
			}
			s="";
			for (int i=ss.length()-1;i>=0;i--)
				s+=ss[i];
		}
		cout << s[0] << endl;
	}
	return 0;
}

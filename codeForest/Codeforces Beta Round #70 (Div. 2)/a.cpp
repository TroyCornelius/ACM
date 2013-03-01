#include <iostream>
#include <string>
using namespace std;

string s;
int tot[3];

int calc()
{
    int ret = 0;
    for (int i=0; i<s.length(); i++)
    if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') ret++;
    return ret;   
    }
int main()
{
    memset(tot, 0, sizeof(tot));
    for (int i=0; i<3; i++)
    {
        getline(cin, s);
        tot[i] = calc();
    }
    if (tot[0] == 5 && tot[1] == 7 && tot[2] == 5) cout<<"YES" <<endl;
    else cout <<"NO" <<endl;
    

    
    return 0;
    }

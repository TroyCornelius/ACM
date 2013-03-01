#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <cstring>
using namespace std;

string st;
char s[26];
bool f[30][30];
int main()
{
    int len;
    while (getline(cin, st))
    {
        for (int i=0; i<st.length(); i++) 
        if (st[i]==' ') st.erase(i,1);
        strcpy(s, st.c_str());
        len = st.length();
        s[len]='\0';

        getline(cin, st);
        memset(f, false, sizeof(f));
        for (int i=0; i<st.length(); i+=4)
          f[st[i]-'a'][st[i+2]-'a'] = true;  
                
        sort(s, s+len);
        bool flag = true, tt = false;
        
        for (bool flag =true; flag; flag = next_permutation(s, s+len))
        {
           for (int i=0; i<len-1 && flag; i++)
             for (int j=i+1; j<len && flag; j++)
               flag &= !f[s[j]-'a'][s[i]-'a'];
           if (flag) 
           {
              printf("%s\n", s);  
              tt = true;                   
           }           
        }
        if (tt) cout <<endl;    
    }

    return 0;
    }

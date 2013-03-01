#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n;
string s1, s2;
size_t string_distance(string source, string target) 
{
        const size_t n = source.length();
        const size_t m = target.length();
        if (n == 0) {
                return m;
        }
        if (m == 0) {
                return n;
        }
        std::vector< std::vector<size_t> > matrix(n + 1);
        for (size_t i = 0; i <= n; i++) {
                matrix[i].resize(m + 1);
        }
        for (size_t i = 0; i <= n; i++) {
                matrix[i][0]=i;
        }

        for (size_t j = 0; j <= m; j++) {
                matrix[0][j]=j;
        }
        for (size_t i = 1; i <= n; i++) {
                const char s_i = source[i - 1];
                for (size_t j = 1; j <= m; j++) {
                        const char t_j = target[j - 1];
                        int cost = (s_i == t_j)? 0 : 1;
                        const size_t above = matrix[i - 1][j];
                        const size_t left = matrix[i][j - 1];
                        const size_t diag = matrix[i - 1][j - 1];
                        size_t cell = std::min( above + 1, std::min(left + 1, diag + cost));
                        matrix[i][j]=cell;
                }
        }
        return matrix[n][m];
}

int main() 
{
    cin >>n;
    for (int i=0; i<n; i++)
    {
        cin >>s1;
        cin >>s2;
        printf("%d\n", string_distance(s1, s2));  
        }      
        return 0;
}

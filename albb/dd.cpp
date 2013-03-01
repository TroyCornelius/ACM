#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
int main() 
{
	bool bFirst = true;
	char szOrder[24];

	//循环读取并处理每一个组原字符串和约束
	for (string str; getline(cin, str); bFirst = false) 
    {
		strcpy(szOrder, str.c_str());

		//去掉原字符串中间的空格

		int nLen = remove(szOrder, &szOrder[str.size()], " ") - szOrder;

		szOrder[nLen] = '\0';

		//获取约束串

		getline(cin, str);

		//去掉约束串中间的空格

		str.erase(remove(str.begin(), str.end(), " "), str.end());

		//生成约束关系表，如果存在约束i > j，则aCompMat[i][j]为true

		bool aCompMat[26][26] = {0};

		for (string::iterator i = str.begin(); i != str.end(); i += 2) {

			aCompMat[*i - 'a'][*(i + 1) - 'a'] = true;

		}

		//将原字符串从大到小排序，准备生成全排列

		sort(&szOrder[0], &szOrder[nLen]);

		//如果不是第一次，要按要求在第一行输出一个回车

		if (!bFirst) {

			cout << endl;

		}

		//bFlag为false表示发现该顺序不满足约束。每次生成下一组全排列

		for (bool bFlag = true; bFlag; bFlag = next_permutation(

			&szOrder[0], &szOrder[nLen])) {

			//循环判断当前生成的顺序中是否每一对字符都满足约束

			for (int i = 0; i < nLen - 1 && bFlag; ++i) {

				for (int j = i + 1; j < nLen && bFlag; ++j) 
                {
					//出现逆序，即aCompMat[j][i] = true，即不满足
					bFlag &= !aCompMat[szOrder[j] - 'a'][szOrder[i] - 'a'];
				}
			}
		if (bFlag) {
				cout << szOrder << endl;
			}
		}
	}
	return 0;

}

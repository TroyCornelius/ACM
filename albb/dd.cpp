#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
int main() 
{
	bool bFirst = true;
	char szOrder[24];

	//ѭ����ȡ������ÿһ����ԭ�ַ�����Լ��
	for (string str; getline(cin, str); bFirst = false) 
    {
		strcpy(szOrder, str.c_str());

		//ȥ��ԭ�ַ����м�Ŀո�

		int nLen = remove(szOrder, &szOrder[str.size()], " ") - szOrder;

		szOrder[nLen] = '\0';

		//��ȡԼ����

		getline(cin, str);

		//ȥ��Լ�����м�Ŀո�

		str.erase(remove(str.begin(), str.end(), " "), str.end());

		//����Լ����ϵ���������Լ��i > j����aCompMat[i][j]Ϊtrue

		bool aCompMat[26][26] = {0};

		for (string::iterator i = str.begin(); i != str.end(); i += 2) {

			aCompMat[*i - 'a'][*(i + 1) - 'a'] = true;

		}

		//��ԭ�ַ����Ӵ�С����׼������ȫ����

		sort(&szOrder[0], &szOrder[nLen]);

		//������ǵ�һ�Σ�Ҫ��Ҫ���ڵ�һ�����һ���س�

		if (!bFirst) {

			cout << endl;

		}

		//bFlagΪfalse��ʾ���ָ�˳������Լ����ÿ��������һ��ȫ����

		for (bool bFlag = true; bFlag; bFlag = next_permutation(

			&szOrder[0], &szOrder[nLen])) {

			//ѭ���жϵ�ǰ���ɵ�˳�����Ƿ�ÿһ���ַ�������Լ��

			for (int i = 0; i < nLen - 1 && bFlag; ++i) {

				for (int j = i + 1; j < nLen && bFlag; ++j) 
                {
					//�������򣬼�aCompMat[j][i] = true����������
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

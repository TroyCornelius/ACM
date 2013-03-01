// Sample solution for the Infiltration problem in NCPC 2012 by Fredrik Svensson.
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

const char* savvyWordsInPlainText2[] = {
	"be"
};
const char* savvyWordsInPlainText3[] = {
	"our","rum"
};
const char* savvyWordsInPlainText4[] = {
	"will","dead","hook","ship"
};
const char* savvyWordsInPlainText5[] = {
	"blood","sable"
};
const char* savvyWordsInPlainText6[] = {
	"avenge","parrot"
};
const char* savvyWordsInPlainText7[] = {
	"captain"
};


vector<string> savvys;
bool decodedSavvys[201];
char m[256];
bool plainLetterUsed[256];
char mRes[256];
int letterCount;

bool decode(size_t idx);

bool decode(size_t idx, const char* plain)
{
	const string& savvy = savvys[idx];
	int lettersToReset = 0;
	bool success = true;
	for (size_t i = 0; i < savvy.size(); ++i)
	{
		if (!m[savvy[i]])
		{
			if (plainLetterUsed[plain[i]])
			{
				success = false;
				break;
			}
			--letterCount;
			m[savvy[i]] = plain[i];
			plainLetterUsed[plain[i]] = true;
			lettersToReset |= (1<<i);
		}
		else if (m[savvy[i]] != plain[i])
		{
			success = false;
			break;
		}
	}
	if (success)
	{
		if (!decode(idx+1))
			success = false;
	}
	for (size_t i = 0; i < savvy.size(); ++i)
	{
		if (lettersToReset & (1<<i))
		{
			m[savvy[i]] = '\0';
			plainLetterUsed[plain[i]] = false;
			++letterCount;
		}
	}	
	return success;
}

bool isOneOf(const std::string& savvy, const char** plainText, int plainCount)
{
	for (int i = 0; i < plainCount; ++i)
	{
		bool eq = true;
		for (size_t j = 0; j < savvy.size(); ++j)
		{
			if (m[savvy[j]] != plainText[i][j])
			{
				eq = false;
				break;
			}
		}
		if (eq)
			return true;
	}
	return false;
}

bool decode(size_t idx, const char** plainText, int plainCount)
{
	int count = 0;
	decodedSavvys[idx] = true;
	for (int i = 0; i < plainCount; ++i)
	{
		if (decode(idx, plainText[i]))
		{
			++count;
			if (count > 1)
				return false;
		}
	}
	decodedSavvys[idx] = false;
	if (decode(idx+1))
		++count;
	if (count == 1)
		return true;
	return false;
}

bool decode(size_t idx)
{
	if (idx >= savvys.size())
	{
		if (letterCount == 0)
		{
			for (size_t i = 0; i < savvys.size(); ++i)
			{
				if (!decodedSavvys[i])
				{
					// Check if decoded as a savvy
					switch (savvys[i].size())
					{
					case 2:
						if (isOneOf(savvys[i], savvyWordsInPlainText2, 1))
							return false;
						break;
					case 3:
						if (isOneOf(savvys[i], savvyWordsInPlainText3, 2))
							return false;
						break;
					case 4:
						if (isOneOf(savvys[i], savvyWordsInPlainText4, 4))
							return false;
						break;
					case 5:
						if (isOneOf(savvys[i], savvyWordsInPlainText5, 2))
							return false;
						break;
					case 6:
						if (isOneOf(savvys[i], savvyWordsInPlainText6, 2))
							return false;
						break;
					case 7:
						if (isOneOf(savvys[i], savvyWordsInPlainText7, 1))
							return false;
						break;
					}
				}
			}
			memcpy(mRes, m, sizeof(mRes));
			/*
			char asdf[200];
			int c = 0;
			for (size_t i = 0; i < savvys.size(); ++i)
			{
				for (size_t j = 0; j < savvys[i].size(); ++j)
					asdf[c++] = m[savvys[i][j]];
				asdf[c++] = ' ';
			}
			asdf[c] = '\0';
			*/
			return true;
		}
		return false;
	}
	const string& s = savvys[idx];
	switch (s.size())
	{
	default:
		return decode(idx+1);
	case 2:
		return decode(idx, savvyWordsInPlainText2, 1);
	case 3:
		return decode(idx, savvyWordsInPlainText3, 2);
	case 4:
		return decode(idx, savvyWordsInPlainText4, 4);
	case 5:
		return decode(idx, savvyWordsInPlainText5, 2);
	case 6:
		return decode(idx, savvyWordsInPlainText6, 2);
	case 7:
		return decode(idx, savvyWordsInPlainText7, 1);
	}
}

int main()
{
	{
		string str;
		while (cin >> str)
			savvys.push_back(str);
	}
	letterCount = 0;
	{
		bool foundLetters[256];
		for (int i = 0; i < 256; ++i)
			foundLetters[i] = false;
		for (size_t i = 0; i < savvys.size(); ++i)
		{
			for (size_t j = 0; j < savvys[i].size(); ++j)
			{
				if (!foundLetters[savvys[i][j]])
				{
					foundLetters[savvys[i][j]] = true;
					++letterCount;
				}
			}
		}
	}
	for (int i = 0; i < 256; ++i)
	{
		m[i] = '\0';
		plainLetterUsed[i] = false;
	}
	for (int i = 0; i < 201; ++i)
		decodedSavvys[i] = false;
	if (decode(0))
	{
		for (size_t i = 0; i < savvys.size(); ++i)
		{
			if (i != 0)
				cout << ' ';
			for (size_t j = 0; j < savvys[i].size(); ++j)
				cout << mRes[savvys[i][j]];
		}
		cout << endl;
	}
	else
	{
		cout << "Impossible" << endl;
	}
	return 0;
}

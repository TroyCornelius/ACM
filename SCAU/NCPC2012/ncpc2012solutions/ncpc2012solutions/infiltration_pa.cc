//Sample solution for the Infiltration problem in NCPC 2012 by Per Austrin
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;

const char *known[12] = {"be","our","rum","will","dead","hook","ship","blood","sable","avenge","parrot", "captain"};

vs enc;
vi words[30];
int prio[30];
char mapping[30], invmapping[30];
bool hasans;
char ansmap[30];

bool pless(int i, int j) {
	if (words[j].empty() && words[i].empty()) return i < j;
	if (words[j].empty()) return true;
	if (words[i].empty()) return false;
	return words[i].size() < words[j].size();
}

bool assign(int e, int k) {
	int L = strlen(known[k]);
	if (L != enc[e].length()) return false;
	for (int i = 0; i < L; ++i) {
		if (mapping[enc[e][i]-'a']) {
			if (mapping[enc[e][i]-'a'] != known[k][i]) return false;
		} else {
			if (invmapping[known[k][i]-'a']) return false;
		}
		mapping[enc[e][i]-'a'] = known[k][i];
		invmapping[known[k][i]-'a'] = enc[e][i];
	}
	return true;
}

int search(int x) {
	int ch = prio[x];
	if (words[ch].empty()) {
		//		printf("found a sol!\n");
		if (hasans) {
			if (memcmp(mapping, ansmap, sizeof(ansmap))) {
				return 2;
			}
		} else {
			memcpy(ansmap, mapping, sizeof(ansmap));
			hasans = true;
		}
		return 1;
	} 
	if (mapping[ch]) return search(x+1);
	//	printf("try assign '%c' (%d words)\n", ch+'a', words[ch].size());
	int r = 0;
	char pmapping[30], pinv[30];
	memcpy(pmapping, mapping, sizeof(mapping));
	memcpy(pinv, invmapping, sizeof(mapping));
	for (vi::iterator it = words[ch].begin(); it != words[ch].end(); ++it) {
		for (int j = 0; j < 12; ++j) {
			if (assign(*it, j)) {
				//				printf("went with \"%s\" at word %d for %c\n", known[j], *it, ch+'a');
				r = max(r, search(x+1));
				//				printf("undo \"%s\" for %c\n", known[j], ch+'a');
			}
			memcpy(mapping, pmapping, sizeof(mapping));
			memcpy(invmapping, pinv, sizeof(mapping));
			if (r > 1) return r;
		}
	}
	return r;
}

int main(void) {
	string word;
	while (cin >> word) {
		for (string::iterator it = word.begin(); it != word.end(); ++it)
			words[*it-'a'].push_back(enc.size());
		enc.push_back(word);
	}
	for (int i = 0; i < 30; ++i)
		words[i].resize(unique(words[i].begin(), words[i].end())-words[i].begin());
	memset(mapping, 0, sizeof(mapping));
	memset(invmapping, 0, sizeof(invmapping));
	memset(ansmap, 0, sizeof(ansmap));
	for (int i = 0; i < 30; ++i)
		prio[i] = i;
	sort(prio, prio+30, pless);
	hasans = false;
	if (search(0) == 1) {
		for (vs::iterator it = enc.begin(); it != enc.end(); ++it) {
			if (it != enc.begin()) printf(" ");
			for (string::iterator jt = it->begin(); jt != it->end(); ++jt)
				printf("%c", ansmap[*jt-'a']);
		}
		printf("\n");
	} else {
		printf("Impossible\n");
	}
}

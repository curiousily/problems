/*
 ID: v.valko1
 PROG: prefix
 LANG: C++
 */

#include <fcntl.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctype.h>
#include <algorithm>
#include <set>
#include <queue>
#include <climits>

using namespace std;

#define MODULO 9901

#define FOR(upperLimit) \
  for(unsigned i = 0; i < upperLimit; i++)

#define FOREACH(var, upperLimit) \
  for(unsigned var = 0; var < upperLimit; var++)

#define READINT ({int num;scanf("%d",&num);num;});
#define READLONG ({long num;scanf("%ld",&num);num;});
#define READSTRING ({string strLine; cin >> strLine; strLine;});
#define READLINE ({string strLine; getline(cin, strLine); strLine;});

#define MAX_SEQUENCE_LENGTH 200002

unsigned MaxPrefixLength = 0;
string Sequence;
vector<string> Primitives;
int prefixLengths[MAX_SEQUENCE_LENGTH] = { 0 };

void SplitAndFill(string& input, vector<string>& parts) {
	stringstream ss(input);
	string temp;
	while (ss >> temp) {
		parts.push_back(temp);
	}
}

bool IsShorterThan(int sequenceIndex, string & primitive) {
	return sequenceIndex + primitive.size() <= Sequence.size();
}

bool BeginsWith(int sequenceIndex, string& primitive) {
	return strncmp(Sequence.c_str() + sequenceIndex, primitive.c_str(),
			primitive.size()) == 0;
}

int main() {

	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);

	string line;
	getline(cin, line);
	while (line != ".") {
		SplitAndFill(line, Primitives);
		getline(cin, line);
	}
	while (getline(cin, line)) {
		Sequence += line;
	}

//	FOREACH(i, Primitives.size()) {
//		printf("%s ", Primitives[i].c_str());
//	}

	for (int sequenceIndex = Sequence.size() - 1; sequenceIndex >= 0;
			--sequenceIndex) {
		FOREACH(primitiveIndex, Primitives.size()) {
			string primitive = Primitives[primitiveIndex];
			if (IsShorterThan(sequenceIndex, primitive)) {
				if (BeginsWith(sequenceIndex, primitive)) {
					int newLength = prefixLengths[sequenceIndex
							+ primitive.size()] + primitive.size();
					if (prefixLengths[sequenceIndex] < newLength) {
						prefixLengths[sequenceIndex] = newLength;
					}
				}
			}
		}

	}

	printf("%d\n", prefixLengths[0]);

	return 0;
}

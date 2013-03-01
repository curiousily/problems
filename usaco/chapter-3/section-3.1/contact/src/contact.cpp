/*
 ID: v.valko1
 PROG: contact
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

#define FOR(upperLimit) \
  for(unsigned i = 0; i < upperLimit; i++)

#define FOREACH(var, upperLimit) \
  for(unsigned var = 0; var < upperLimit; var++)

#define READINT ({int num;scanf("%d",&num);num;});
#define READLONG ({long num;scanf("%ld",&num);num;});
#define READSTRING ({string strLine; cin >> strLine; strLine;});
#define READLINE ({string strLine; getline(cin, strLine); strLine;});

unsigned MinLength, MaxLength, N;

string Sequence;

map<string, int> Frequences;

struct Pattern {
	string pattern;
	int frequency;
};

bool operator <(const Pattern& a, const Pattern& b) {
	if (a.frequency == b.frequency) {
		if (a.pattern.length() == b.pattern.length()) {
			return a.pattern < b.pattern;
		}
		return a.pattern.length() < b.pattern.length();
	}
	return a.frequency > b.frequency;
}

void AddPattern(const string & pattern) {
	if (Frequences.find(pattern) == Frequences.end()) {
		Frequences[pattern] = 1;
	} else {
		Frequences[pattern]++;
	}
}

int main() {

	freopen("contact.in", "r", stdin);
	freopen("contact.out", "w", stdout);

	MinLength = READINT;
	MaxLength = READINT;
	N = READINT;

	string line;

	getline(cin, line);

	while (getline(cin, line)) {
		Sequence += line;
	}
	for (unsigned start = 0; start < Sequence.length(); start++) {
		for (unsigned end = start; end < Sequence.length(); end++) {
			unsigned patternLength = end - start + 1;
			if (patternLength < MinLength) {
				continue;
			}
			if (patternLength > MaxLength) {
				break;
			}
			string pattern = Sequence.substr(start, patternLength);
			AddPattern(pattern);
		}
	}

	std::map<string, int>::iterator it;

	vector<Pattern> patterns;

	for (it = Frequences.begin(); it != Frequences.end(); it++) {
		patterns.push_back(Pattern { it->first, it->second });
//		printf("%s - %d\n", it->first.c_str(), it->second);
	}

	sort(patterns.begin(), patterns.end());

	unsigned printedFrequencies = 0;

	for (unsigned patternsUsed = 0; patternsUsed < patterns.size();) {
		if (printedFrequencies >= N) {
			break;
		}
		Pattern pattern = patterns[patternsUsed];
		int frequency = pattern.frequency;
		printf("%d\n", pattern.frequency);
		printf("%s", pattern.pattern.c_str());
		int patternCount = 1;
		while (true) {
			unsigned nextPattern = patternCount + patternsUsed;
			if (nextPattern < patterns.size()
					&& patterns[nextPattern].frequency == frequency) {
				if (patternCount % 6 == 0) {
					printf("\n");
				} else {
					printf(" ");
				}
				patternCount++;
				printf("%s", patterns[nextPattern].pattern.c_str());
			} else {
				printf("\n");
				patternsUsed += patternCount;
				break;
			}
		}
		printedFrequencies++;
//		printf("%d\n%s\n", pattern.count, pattern.pattern.c_str());
	}

//	printf("%s\n", Sequence.c_str());

	return 0;
}

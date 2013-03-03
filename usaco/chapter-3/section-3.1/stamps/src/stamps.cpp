/*
 ID: v.valko1
 PROG: stamps
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

#define MAX_VALUE 2000001

int MaxStamps, StampValueCount;

vector<int> StampValues;

int Memo[MAX_VALUE];

int main() {

	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);

	MaxStamps = READINT;
	StampValueCount = READINT;

	FOR(StampValueCount) {
		unsigned stampValue = READINT;
		StampValues.push_back(stampValue);
	}

	sort(StampValues.begin(), StampValues.end());

	Memo[0] = 0;
	int i = 1;
	for (;; i++) {
		Memo[i] = MAX_VALUE;

		for (int stamp = 0; stamp < StampValues.size(); stamp++) {
			if (i - StampValues[stamp] < 0) {
				break;
			}
			Memo[i] = min(Memo[i], Memo[i - StampValues[stamp]] + 1);
		}

		if (Memo[i] > MaxStamps) {
			break;
		}
	}

	printf("%d\n", i - 1);
	return 0;
}

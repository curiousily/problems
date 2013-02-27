/*
 ID: v.valko1
 PROG: inflate
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

#define MAX_PROBLEMS 10001

int Time, Classes;

int BestTimes[MAX_PROBLEMS];

int main() {

	freopen("inflate.in", "r", stdin);
	freopen("inflate.out", "w", stdout);

	Time = READINT;
	Classes = READINT;

	FOREACH(i, Time) {
		BestTimes[i] = 0;
	}

	FOREACH(classIndex, Classes) {
		int classPoints = READINT;
		int classTime = READINT;
		for (int time = classTime; time <= Time; time++) {
			if (BestTimes[time - classTime] + classPoints > BestTimes[time]) {
				BestTimes[time] = BestTimes[time - classTime] + classPoints;
			}
		}
	}

	printf("%d\n", BestTimes[Time]);

	return 0;
}

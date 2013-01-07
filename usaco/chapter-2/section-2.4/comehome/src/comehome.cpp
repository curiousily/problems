/*
 ID: v.valko1
 PROG: comehome
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

#define BARN_INDEX 25

unsigned P;

int Distances[100][100];

int toNum(char c) {
	if (isupper(c))
		return c - 'A';
	else
		return c - 'a' + 26;
}

void InitializeDistances() {
	FOREACH(i, 100) {
		FOREACH(j, 100) {
			Distances[i][j] = 100000;
		}
	}
	FOREACH(i, 26) {
		Distances[i][i] = 0;
	}
}

int main() {

	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);

	P = READINT;
	char pasture1, pasture2;
	int distance;
	string line;
	getline(cin, line);
	InitializeDistances();
	FOR(P) {
		scanf("%c %c %d\n", &pasture1, &pasture2, &distance);
		if (Distances[toNum(pasture1)][toNum(pasture2)] > distance) {
			Distances[toNum(pasture1)][toNum(pasture2)] = distance;
			Distances[toNum(pasture2)][toNum(pasture1)] = distance;
		}
	}
	FOREACH(k, 100) {
		FOREACH(i, 100) {
			FOREACH(j, 100) {
				Distances[i][j] = min(Distances[i][j],
						Distances[i][k] + Distances[k][j]);
			}
		}
	}
	int minDistance = 100000;
	int minIndex = 0;
	FOREACH(index, BARN_INDEX) {
		if (minDistance > Distances[index][BARN_INDEX]) {
			minDistance = Distances[index][BARN_INDEX];
			minIndex = index;
		}
	}
	char minDistanceBarn = (char) (minIndex + 65);
	printf("%c %d\n", minDistanceBarn, minDistance);

	return 0;
}

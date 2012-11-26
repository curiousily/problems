/*
 ID: v.valko1
 PROG: concom
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

#define OWNING_THRESHOLD_PERCENTAGE 50

int Owns[102][102] = { 0 };
bool Controls[102][102] = { false };

int N;

int MaxCompany = 0;

void ApplyOwnage(int company1, int company2) {

	if (Controls[company1][company2]) {
		return;
	}
	Controls[company1][company2] = true;

	for (int k = 1; k <= MaxCompany; k++) {
		Owns[company1][k] += Owns[company2][k];
		if (Owns[company1][k] > OWNING_THRESHOLD_PERCENTAGE) {
			ApplyOwnage(company1, k);
		}
	}
}

int main() {

	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);

	N = READINT;

	int i, j, p;

	for (int In = 0; In < N; In++) {
		i = READINT;
		j = READINT;
		MaxCompany = max<int>(max<int>(MaxCompany, i), j);
		p = READINT;
		Owns[i][j] = p;
	}

	for (int c1 = 1; c1 <= MaxCompany; c1++) {
		for (int c2 = 1; c2 <= MaxCompany; c2++) {

			if (Owns[c1][c2] > OWNING_THRESHOLD_PERCENTAGE) {
				ApplyOwnage(c1, c2);
			}

		}
	}

//	for (int c1 = 1; c1 <= MaxCompany; c1++) {
//		for (int c2 = 1; c2 <= MaxCompany; c2++) {
//			printf("%d %d %d \n", c1, c2, Owns[c1][c2]);
//		}
//	}

	for (int c1 = 1; c1 <= MaxCompany; c1++) {
		for (int c2 = 1; c2 <= MaxCompany; c2++) {
			if (c1 != c2 && Controls[c1][c2]) {
				printf("%d %d\n", c1, c2);
			}
		}
	}

	return 0;
}

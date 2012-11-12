/*
 ID: v.valko1
 PROG: nocows
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

int N, K;

int main() {

	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);

	N = READINT;
	K = READINT;

	int trees[101][202];
	int smallerTrees[101][202];

	trees[1][1] = 1;
	int multiplyFactor;
	for (int i = 2; i <= K; i++) {
		for (int j = 1; j <= N; j += 2) {
			for (int k = 1; k <= j - 1 - k; k += 2) {
				if (k != j - 1 - k) {
					multiplyFactor = 2;
				} else {
					multiplyFactor = 1;
				}
				trees[i][j] += multiplyFactor
						* (smallerTrees[i - 2][k] * trees[i - 1][j - 1 - k]
								+ trees[i - 1][k]
										* smallerTrees[i - 2][j - 1 - k]
								+ trees[i - 1][k] * trees[i - 1][j - 1 - k]);
				trees[i][j] %= MODULO;
			}
		}
		for (int k = 0; k <= N; k++) {
			smallerTrees[i - 1][k] += trees[i - 1][k] + smallerTrees[i - 2][k];
			smallerTrees[i - 1][k] %= MODULO;
		}
	}
	printf("%d\n", trees[K][N]);
	return 0;
}

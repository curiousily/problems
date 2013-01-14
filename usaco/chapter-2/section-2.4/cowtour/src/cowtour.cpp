/*
 ID: v.valko1
 PROG: cowtour
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

#define POSITIVE_INFINITY (1e40)

long N;
double Distances[200][200], dt[200];
long px[200], py[200];

double DistanceOf(long x1, long y1, long x2, long y2) {
	return sqrt((double) (x1 - x2) * (x1 - x2) + (double) (y1 - y2) * (y1 - y2));
}

void FindDistances() {
	long i, j, k;
	for (k = 1; k <= N; k++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (Distances[i][k] + Distances[k][j] < Distances[i][j])
					Distances[i][j] = Distances[i][k] + Distances[k][j];
			}
		}
	}
	for (i = 1; i <= N; i++) {
		Distances[i][i] = POSITIVE_INFINITY;
	}
}

int main() {

	freopen("cowtour.in", "r", stdin);
	freopen("cowtour.out", "w", stdout);

	scanf("%ld", &N);
	for (long i = 1; i <= N; i++) {
		scanf("%ld%ld", &px[i], &py[i]);
	}

	string line;
	getline(cin, line);
	for (long i = 1; i <= N; i++) {
		getline(cin, line);
		for (long j = 1; j <= N; j++) {
			if (line[j - 1] == '1') {
				Distances[i][j] = DistanceOf(px[i], py[i], px[j], py[j]);
			} else {
				Distances[i][j] = POSITIVE_INFINITY;
			}
		}
	}

	FindDistances();

	double maxFound = 0;

	for (long i = 1; i <= N; i++) {
		double localMax = 0;
		for (long j = 1; j <= N; j++) {
			if (Distances[i][j]
					> localMax&& Distances[i][j] != POSITIVE_INFINITY) {
				localMax = Distances[i][j];
			}
		}
		dt[i] = localMax;
		if (localMax > maxFound) {
			maxFound = localMax;
		}
	}
	double minimumDistance = POSITIVE_INFINITY;
	for (long i = 1; i <= N - 1; i++) {
		for (long j = i + 1; j <= N; j++) {
			if (Distances[i][j] == POSITIVE_INFINITY && i != j) {
				double tmp = DistanceOf(px[i], py[i], px[j], py[j]);
				if (dt[i] + dt[j] + tmp < minimumDistance)
					minimumDistance = dt[i] + dt[j] + tmp;
			}
		}
	}

	printf("%.6lf\n", max(minimumDistance, maxFound));

	return 0;
}

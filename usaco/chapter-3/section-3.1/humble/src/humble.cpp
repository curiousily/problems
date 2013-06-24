/*
 ID: v.valko1
 PROG: humble
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

#define MAX_INDEX 100002
#define MAX_PRIME 100

int K, N;

vector<int> Primes;
long Humbles[MAX_INDEX];
int PrimeIndex[MAX_PRIME], HumbleNumber;

int main() {

	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);

	K = READINT;
	N = READINT;

	FOR(K) {
		int number = READINT;
		Primes.push_back(number);
	}

	Humbles[HumbleNumber++] = 1;

	for (unsigned i = 0; i < Primes.size(); i++) {
		PrimeIndex[i] = 0;
	}

	while (HumbleNumber < N + 1) {
		int minPrimeIndex = -1;
		long min = 0x7FFFFFFF;

		for (unsigned i = 0; i < Primes.size(); i++) {
			while ((double) Primes[i] * Humbles[PrimeIndex[i]]
					<= Humbles[HumbleNumber - 1]) {
				PrimeIndex[i]++;
			}

			if ((double) Primes[i] * Humbles[PrimeIndex[i]] < min) {
				min = Primes[i] * Humbles[PrimeIndex[i]];
				minPrimeIndex = i;
			}
		}

		Humbles[HumbleNumber++] = min;
		PrimeIndex[minPrimeIndex]++;
	}

	printf("%ld\n", Humbles[N]);

	return 0;
}

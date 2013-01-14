/*
 ID: v.valko1
 PROG: fracdec
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

const unsigned int MAX_LENGHT_PER_LINE = 76;

int N, D;

struct Remainder {
	bool used;
	int position;
};

string Answer;
Remainder Remainders[100000];

string IntToString(int i) {
	ostringstream outstr;
	outstr << i;
	return outstr.str();
}

int main() {

	freopen("fracdec.in", "r", stdin);
	freopen("fracdec.out", "w", stdout);

	for (int i = 0; i < 100000; i++) {
		Remainders[i].used = false;
		Remainders[i].position = 0;
	}

	N = READINT;
	D = READINT;

	if (N >= D) {
		int wholePart = N / D;
		N = N % D;
		Answer = IntToString(wholePart) + ".";
	} else {
		Answer = "0.";
	}

	if (N == 0) {
		printf("%s0\n", Answer.c_str());
		return 0;
	}

	while (true) {
		if (N == 0) {
			printf("%s\n", Answer.c_str());
			return 0;
		}

		if (Remainders[N].used == true) {
			Answer.insert(Remainders[N].position, 1, '(');
			Answer += ')';

			break;
		} else {
			Remainders[N].used = true;
			Remainders[N].position = Answer.length();

			N *= 10;

			int wholePart = N / D;
			N = N % D;
			Answer += IntToString(wholePart);
		}
	}

	while (Answer.length() > MAX_LENGHT_PER_LINE) {
		printf("%s\n", Answer.substr(0, MAX_LENGHT_PER_LINE).c_str());
		Answer = Answer.substr(MAX_LENGHT_PER_LINE);
	}

	printf("%s\n", Answer.c_str());

	return 0;
}

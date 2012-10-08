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

int main() {
#ifndef ONLINE_JUDGE
	close(0);
	open("in.txt", O_RDONLY);
//          close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif

	long int i, number, result, digitNumber;
	long int rangesStart[] = { 1, 10, 100, 1000, 10000, 100000, 1000000,
			10000000 };
	long int rangesEnd[] = { -1, 9, 189, 2889, 38889, 488889, 5888889, 68888889,
			100000001 };
	while (scanf("%ld", &digitNumber) == 1) {
		for (i = 1; digitNumber > rangesEnd[i]; i++)
			;
		number = digitNumber - rangesEnd[i - 1];
		result = number % i;
		number = number / i;
		if (result == 1) {
			result = (number / rangesStart[i - 1]) % 10 + 1;
		} else if (result != 0) {
			result = (number / rangesStart[i - result]) % 10;
		} else {
			result = (number - 1) % 10;
		}
		printf("%ld\n", result);
	}

	return 0;
}

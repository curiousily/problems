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

long long N;

int main() {
#ifndef ONLINE_JUDGE
	close(0);
	open("in.txt", O_RDONLY);
//          close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif

	long n;
	while (scanf("%ld", &n) != EOF) {
		if (n < 0)
			break;
		if (n == 1)
			printf("0%%\n");
		else {
			long result = n * 25;
			printf("%ld%%\n", result);
		}
	}

	return 0;
}

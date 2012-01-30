#include <fcntl.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>
#include <ctype.h>
#include <algorithm>
#include <set>

using namespace std;

const int generatorValue = 34943;

int main() {
#ifndef ONLINE_JUDGE
	close(0);
	open("in.txt", O_RDONLY);
	//        close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
	int tc;
	long first, last;
	scanf("%d\n", &tc);
	while (tc--) {
		scanf("%ld %ld\n", &first, &last);
		long diff = last - first;
		printf("%ld\n", diff);
	}
	return 0;
}

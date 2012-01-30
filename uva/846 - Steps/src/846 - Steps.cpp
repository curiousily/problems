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

int steps(int distance) {
	if (distance == 0) {
		return 0;
	}
	int step = sqrt(distance);
	if (step * step == distance)
		step = step * 2 - 1;
	else if (step * step + step < distance)
		step = step * 2 + 1;
	else
		step = step * 2;
	return step;
}

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
		printf("%d\n", steps(last - first));
	}
	return 0;
}

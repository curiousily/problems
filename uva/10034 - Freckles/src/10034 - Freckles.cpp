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
#include <queue>

using namespace std;

#define FOREACH(var, upperLimit) \
	for(unsigned var = 0; var < upperLimit; var++)

unsigned tc, freckleCount;

int main() {
#ifndef ONLINE_JUDGE
	close(0);
	open("in.txt", O_RDONLY);
//	        close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
	scanf("%d\n", &tc);
	double x, y;
	FOREACH(i, tc) {
		scanf("%d\n", &freckleCount);
		FOREACH(freckel, freckleCount) {
			scanf("%lf %lf\n", &x, &y);
			printf("%lf %lf\n", x, y);
		}
	}
	return 0;
}

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

int W, H;
vector<int> Graph[76];

int main() {
#ifndef ONLINE_JUDGE
	close(0);
	open("in.txt", O_RDONLY);
//	        close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
	string strInput;
	while (scanf("%d %d\n", &W, &H) && (W != 0 || H != 0)) {
		for (int i = 0; i < H; i++) {
			getline(cin, strInput);
			for (unsigned j = 0; j < strInput.size(); j++) {
				Graph[i].push_back(strInput[j]);
			}
		}
		// Print Graph
//		for (int i = 0; i < H; i++) {
//			for (int j = 0; j < W; j++) {
//				printf("%c", Graph[i][j]);
//			}
//			printf("\n");
//		}
//		printf("END CASE\n");
	}
	return 0;
}

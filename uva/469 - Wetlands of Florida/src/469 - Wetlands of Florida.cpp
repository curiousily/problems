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

char graph[101][101];

int rowCount;
int colCount;
int areaSize = 0;

bool visited[101][101];

void ResetData() {
	areaSize = 0;
	for (int i = 0; i <= rowCount; i++) {
		for (int j = 0; j <= colCount; j++) {
			visited[i][j] = false;
		}
	}
}

void DFS(int row, int col) {
//	printf("visiting %d %d with value %c\n", row, col, graph[row][col]);
	visited[row][col] = true;
	areaSize++;
	for (int i = 1; i <= rowCount; i++) {
		for (int j = 1; j <= colCount; j++) {
			// all valid sides to visit
			if ((i == row - 1 && j == col) || (i == row + 1 && j == col)
					|| (i == row && j == col - 1) || (i == row && j == col + 1)
					|| (i == row - 1 && j == col - 1)
					|| (i == row - 1 && j == col + 1)
					|| (i == row + 1 && j == col - 1)
					|| (i == row + 1 && j == col + 1)) {
				if (!visited[i][j] && graph[i][j] == 'W') {
					DFS(i, j);
				}
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	close(0);
	open("in.txt", O_RDONLY);
//	        close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
	int tc;
	scanf("%d\n", &tc);
	while (tc--) {
		string str;
		getline(cin, str);
		colCount = str.size();
		rowCount = 1;
		while (str.find(' ') == string::npos) {
//			printf("found graph %s\n", str.c_str());
			for (unsigned i = 0; i < str.size(); i++) {
				graph[rowCount][i + 1] = str[i];
			}
			rowCount++;
			getline(cin, str);
		}
		// Print the graph
//		for(int i = 1; i <= rowCount; i++) {
//			for(int j = 1; j <= colCount; j++) {
//				printf("%c", graph[i][j]);
//			}
//			printf("\n");
//		}
		do {
			int rowToFind, colToFind;
			sscanf(str.c_str(), "%d %d\n", &rowToFind, &colToFind);
			ResetData();
			DFS(rowToFind, colToFind);
			printf("%d\n", areaSize);
//			printf("rowToFind = %d colToFind = %d\n", rowToFind, colToFind);
		} while (getline(cin, str) && !str.empty());
		if(tc > 0) {
			printf("\n");
		}
	}
	return 0;
}

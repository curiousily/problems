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

int pawnsInRow;

string graph[201];

int dr[] = { -1, -1, 0, 0, 1, 1 };
int dc[] = { -1, 0, -1, 1, 0, 1 };

void DfsVisit(int row, int col, char ch, char upperChar) {
	graph[row][col] = upperChar;
	int adjRow, adjCol;
	// 6 possible adj nodes
	for (int i = 0; i < 6; i++) {
		adjRow = row + dr[i];
		adjCol = col + dc[i];
		if (adjRow >= 0 && adjRow < pawnsInRow && adjCol >= 0
				&& adjCol < pawnsInRow) {
			if (graph[adjRow][adjCol] == ch) {
				DfsVisit(adjRow, adjCol, ch, upperChar);
			}
		}
	}
}

void DFS() {
	for (int i = 0; i < pawnsInRow; i++) {
		if (graph[0][i] == 'b') {
			DfsVisit(0, i, 'b', 'B');
		}
		if (graph[i][0] == 'w') {
			DfsVisit(i, 0, 'w', 'W');
		}
	}
}

char FindWinner() {
	DFS();
	for (int i = 0; i < pawnsInRow; i++) {
		if (graph[i][pawnsInRow - 1] == 'W') {
			return 'W';
		}
		if (graph[pawnsInRow - 1][i] == 'B') {
			return 'B';
		}
	}
	// the function will always return by def. of the problem
}

int main() {
#ifndef ONLINE_JUDGE
	close(0);
	open("in.txt", O_RDONLY);
//	        close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
	int gameNum = 0;
	while (scanf("%d\n", &pawnsInRow) && pawnsInRow != 0) {
		gameNum++;
		string inputLine;
		for (int row = 0; row < pawnsInRow; row++) {
			getline(cin, inputLine);
			graph[row] = inputLine;
		}
		printf("%d %c\n", gameNum, FindWinner());
	}
	return 0;
}

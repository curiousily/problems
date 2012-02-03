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

int cols, rows;
bool grid[100][100];

map<char, char> rightTurn;
map<char, char> leftTurn;

int main() {
#ifndef ONLINE_JUDGE
	close(0);
	open("in.txt", O_RDONLY);
//	        close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
	scanf("%d %d\n", &cols, &rows);
	rightTurn['N'] = 'E';
	rightTurn['E'] = 'S';
	rightTurn['S'] = 'W';
	rightTurn['W'] = 'N';
	leftTurn['N'] = 'W';
	leftTurn['W'] = 'S';
	leftTurn['S'] = 'E';
	leftTurn['E'] = 'N';
	int roboCol, roboRow;
	char orientation;
	for (int i = 0; i <= rows; i++) {
		for (int j = 0; j <= cols; j++) {
			grid[i][j] = false;
		}
	}
	while (scanf("%d %d %c\n", &roboCol, &roboRow, &orientation) != EOF) {
		string instructions;
		getline(cin, instructions);
		bool isLost = false;
		for (unsigned i = 0; i < instructions.size(); i++) {
			char instruction = instructions[i];
			if(instruction == 'L') {
				orientation = leftTurn[orientation];
			}
			if(instruction == 'R') {
				orientation = rightTurn[orientation];
			}
			if (instruction == 'F') {
				int newCol, newRow;
				if (orientation == 'N') {
					newCol = roboCol;
					newRow = roboRow + 1;
				} else if (orientation == 'S') {
					newCol = roboCol;
					newRow = roboRow - 1;
				} else if (orientation == 'W') {
					newCol = roboCol - 1;
					newRow = roboRow;
				} else {
					newCol = roboCol + 1;
					newRow = roboRow;
				}
				if(!grid[roboRow][roboCol] && (newRow < 0 || newRow > rows || newCol < 0 || newCol > cols)) {
					isLost = true;
					grid[roboRow][roboCol] = true;
					break;
				}
				if(newRow >= 0 && newRow <= rows && newCol >= 0 && newCol <= cols){
					roboCol = newCol;
					roboRow = newRow;
				}
			}
		}
		printf("%d %d %c", roboCol, roboRow, orientation);
		if(isLost) {
			printf(" LOST");
		}
		printf("\n");
	}
	return 0;
}

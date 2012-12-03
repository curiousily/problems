/*
 ID: v.valko1
 PROG: ttwo
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

#define MAX_ROWS 10
#define MAX_COLUMNS 10

bool Map[11][11] = { true };
bool Visited[11][11][4][11][11][4] = { false };

enum Orientation {
	UP, RIGHT, DOWN, LEFT
};

struct Position {
	int row, column;
};

struct Entity {
	Orientation orientation;
	Position position;
};

void Move(Entity & entity) {
	Orientation orientation = entity.orientation;
	Position position = entity.position;
	int row = position.row;
	int column = position.column;
	switch (orientation) {
	case UP:
		if (row - 1 > 0 && Map[row - 1][column]) {
			entity.position.row--;
		} else {
			entity.orientation = RIGHT;
		}
		break;
	case RIGHT:
		if (column + 1 <= MAX_COLUMNS && Map[row][column + 1]) {
			entity.position.column++;
		} else {
			entity.orientation = DOWN;
		}
		break;

	case DOWN:
		if (row + 1 <= MAX_ROWS && Map[row + 1][column]) {
			entity.position.row++;
		} else {
			entity.orientation = LEFT;
		}
		break;

	case LEFT:
		if (column - 1 > 0 && Map[row][column - 1]) {
			entity.position.column--;
		} else {
			entity.orientation = UP;
		}
		break;
	}
}

int main() {

	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);

	Entity john;
	Entity cowPair;

	for (int i = 1; i <= MAX_ROWS; i++) {
		for (int j = 1; j <= MAX_COLUMNS; j++) {
			Map[i][j] = true;
		}
	}

	string line;
	int lineNum = 0;
	while (getline(cin, line)) {
		lineNum++;
		FOREACH(i, line.size()) {
			char ch = line[i];

			switch (ch) {
			case '*':
				Map[lineNum][i + 1] = false;
				break;
			case 'F':
				john.position.row = lineNum;
				john.position.column = i + 1;
				john.orientation = UP;
				break;
			case 'C':
				cowPair.position.row = lineNum;
				cowPair.position.column = i + 1;
				cowPair.orientation = UP;
				break;
			}
		}
	}

	int minutes = 0;
	while (true) {
		minutes++;
		Move(john);
		Move(cowPair);

		Position cowPosition = cowPair.position;
		Position johnPosition = john.position;

//		for (int i = 1; i <= MAX_ROWS; i++) {
//			for (int j = 1; j <= MAX_COLUMNS; j++) {
//				if (!Map[i][j]) {
//					printf("*");
//				} else if (cowPosition.row == i && cowPosition.column == j) {
//					printf("C");
//				} else if (johnPosition.row == i && johnPosition.column == j) {
//					printf("J");
//				} else {
//					printf(".");
//				}
//			}
//			printf("\n");
//		}
//
//		printf("\n\n\n");

//		break;

		if (cowPosition.row == johnPosition.row
				&& cowPosition.column == johnPosition.column) {
			break;
		}

		if (Visited[cowPosition.row][cowPosition.column][cowPair.orientation][johnPosition.row][johnPosition.column][john.orientation]) {
			minutes = 0;
			break;
		}
		Visited[cowPosition.row][cowPosition.column][cowPair.orientation][johnPosition.row][johnPosition.column][john.orientation] =
				true;
	}

	printf("%d\n", minutes);

	return 0;
}

/*
 ID: v.valko1
 PROG: maze1
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

int W, H;
char Map[2 * 100 + 1 + 2][2 * 38 + 1 + 2];
int Distance[100 + 1][38 + 1];
bool Visited[100 + 1][38 + 1];

struct Point {
	int height;
	int width;
	int level;
	bool modify(int h, int w, int l) {
		if (h < 1 || h > H || w < 1 || w > W)
			return false;

		height = h;
		width = w;
		level = l;
		return true;
	}
};
queue<Point> q;

void InitVisited() {
	for (int m = 0; m <= H + 1; m++) {
		for (int n = 0; n <= W + 1; n++) {
			Visited[m][n] = false;
		}
	}
}

void BFS(int height, int width, int level) {
	InitVisited();
	if (Map[2 * height][2 * width] != ' ' || height < 1 || height > H
			|| width < 1 || width > W)
		return;

	struct Point p;
	p.height = height;
	p.width = width;
	p.level = level;

	q.push(p);
	struct Point pt;

	while (!q.empty()) {
		pt = q.front();
		p = q.front();
		q.pop();
		if (Visited[pt.height][pt.width])
			continue;
		Visited[pt.height][pt.width] = true;

		if (Distance[pt.height][pt.width] <= pt.level)
			continue;
		Distance[pt.height][pt.width] = pt.level;

		if (Map[2 * p.height + 1][2 * p.width] == ' ') {
			if (pt.modify(p.height + 1, p.width, p.level + 1))
				q.push(pt);
		}
		if (Map[2 * p.height - 1][2 * p.width] == ' ') {
			if (pt.modify(p.height - 1, p.width, p.level + 1))
				q.push(pt);
		}
		if (Map[2 * p.height][2 * p.width + 1] == ' ') {
			if (pt.modify(p.height, p.width + 1, p.level + 1))
				q.push(pt);
		}
		if (Map[2 * p.height][2 * p.width - 1] == ' ') {
			if (pt.modify(p.height, p.width - 1, p.level + 1))
				q.push(pt);
		}
	}
}

int main() {

	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);

	int i, j;
	char c;
	W = READINT;
	H = READINT;

	for (i = 1; i <= 2 * H + 1; i++) {
		for (j = 1; j <= 2 * W + 1; j++) {
			cin.get(c);
			if (c == 10)
				cin.get(c);
			Map[i][j] = c;
		}
	}

	for (i = 0; i <= H; i++) {
		for (j = 0; j <= W; j++) {
			Distance[i][j] = 99999;
		}
	}

	for (i = 1, j = 1; j <= W; j++) {
		if (Map[1][2 * j] == ' ') {
			BFS(1, j, 1);
		}
	}

	for (i = 2 * H + 1, j = 1; j <= W; j++) {
		if (Map[2 * H + 1][2 * j] == ' ') {
			BFS(H, j, 1);
		}
	}

	for (i = 1, j = 1; i <= H; i++) {
		if (Map[2 * i][1] == ' ') {
			BFS(i, 1, 1);
		}
	}

	for (i = 1, j = 2 * W + 1; i <= H; i++) {
		if (Map[2 * i][2 * W + 1] == ' ') {
			BFS(i, W, 1);
		}
	}

	int maxDistance = 0;
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= W; j++) {
			if (Distance[i][j] > maxDistance && Map[2 * i][2 * j] == ' ')
				maxDistance = Distance[i][j];
		}
	}

	cout << maxDistance << endl;

	return 0;
}

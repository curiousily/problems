/*
ID: v.valko1
PROG: castle
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

unsigned m, n;
vector<vector<int> > map;
vector<vector<bool> > visited;
int roomCount = 0;
int largestRoomSize = 0;
int roomSize;

void InitMap() {
    map.resize(n + 1);
    visited.resize(n + 1);
    for(unsigned i = 1; i <= n; i++) {
        map[i].resize(m + 1);
        visited[i].resize(m + 1);
    }
}

bool CanGoTo(int nPos, int mPos) {
    return !visited[nPos][mPos] && nPos > 0 && nPos <= n && mPos > 0 && mPos <= m;
}

bool CanGoLeft(int nPos, int mPos) {
    return CanGoTo(nPos, mPos - 1);
}

bool CanGoRight(int nPos, int mPos) {
    return CanGoTo(nPos, mPos + 1);
}

bool CanGoUp(int nPos, int mPos) {
    return CanGoTo(nPos - 1, mPos);
}

bool CanGoDown(int nPos, int mPos) {
    return CanGoTo(nPos + 1, mPos);
}

struct Cell {
    int n, m;
};

void BFS(int nPos, int mPos) {
    Cell c;
    c.n = nPos;
    c.m = mPos;
    queue<Cell> cellQueue;
    cellQueue.push(c);
    visited[nPos][mPos] = true;
    while(!cellQueue.empty()) {
        Cell currentCell = cellQueue.front();
        cellQueue.pop();
        if(CanGoLeft(currentCell.n, currentCell.m)) {
            Cell leftCell;
            leftCell.n = currentCell.n;
            leftCell.m = currentCell.m - 1;
        } else if(CanGoRight(currentCell.n, currentCell.m)) {
            Cell rightCell;
            rightCell.n = currentCell.n;
            rightCell.m = currentCell.m + 1;
        }
    }
}

void FindRoom(int nPos, int mPos) {
    roomSize++;
    visited[nPos][mPos] = true;
    if(CanGoLeft(nPos, mPos)) {
        FindRoom(nPos, mPos - 1);
    } else if(CanGoRight(nPos, mPos)) {
        FindRoom(nPos, mPos + 1);
    } else if(CanGoUp(nPos, mPos)) {
        FindRoom(nPos - 1, mPos);
    } else if(CanGoDown(nPos, mPos)) {
        FindRoom(nPos + 1, mPos);
    } else {
        if(roomSize > largestRoomSize)
            largestRoomSize = roomSize;
        roomCount++;
    }
}

int main()
{
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    scanf("%d %d", &m, &n);
    InitMap();
    int num;
    for(unsigned i = 1; i <= n; i++)
        for(unsigned k = 1 ; k <= m; k++) {
            scanf("%d", &num);
            map[i][k] = num;
            visited[i][k] = false;
        }
    for(unsigned i = 1; i <= n; i++) {
        for(unsigned k = 1 ; k <= m; k++) {
            printf("%d ", map[i][k]);
        }
        printf("\n");
    }
//    printf("m=%d and n=%d", m, n);
    return 0;
}

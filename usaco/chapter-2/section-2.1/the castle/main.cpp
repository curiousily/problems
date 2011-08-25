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

const int LEFT_WALL = 1;
const int UP_WALL = 2;
const int RIGHT_WALL = 4;
const int DOWN_WALL = 8;

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

bool IsInBoundaries(int nPos, int mPos) {
    return nPos > 0 && nPos <= n && mPos > 0 && mPos <= m && !visited[nPos][mPos];
}

bool HasLeftWall(int value) {
    return value % 2 == 1;
}

bool HasDownWall(int value) {
    return value >= 8;
}

bool HasUpWall(int value) {
    int realValue = value;
    if(realValue > 8)
        realValue -= 8;
    if(realValue < 2) return false;
    return true;
}

bool HasRightWall(int value) {
    int realValue = value;
    if(realValue > 8)
        realValue -= 8;
    if(realValue == 0) return true;
    if(realValue < 4) return false;
    return true;
}

bool CanGoLeft(int nPos, int mPos) {
    return IsInBoundaries(nPos, mPos - 1) && !HasLeftWall(map[nPos][mPos]);
}

bool CanGoRight(int nPos, int mPos) {
    //return IsInBoundaries(nPos, mPos + 1) && !HasRightWall(map[nPos][mPos]);
    return !HasRightWall(map[nPos][mPos]);
}

bool CanGoUp(int nPos, int mPos) {
    return IsInBoundaries(nPos - 1, mPos) && !HasUpWall(map[nPos][mPos]);
}

bool CanGoDown(int nPos, int mPos) {
    return IsInBoundaries(nPos + 1, mPos) && !HasDownWall(map[nPos][mPos]);
}

struct Cell {
    int n, m;
};

void BFS(int nPos, int mPos) {

    if(visited[nPos][mPos]) return;
    Cell c;
    c.n = nPos;
    c.m = mPos;
    printf("Entering bfs with n=%d and m=%d\n", nPos, mPos);
    queue<Cell> cellQueue;
    cellQueue.push(c);
    visited[nPos][mPos] = true;
    int roomSize = 0;
    while(!cellQueue.empty()) {
        Cell currentCell = cellQueue.front();
        cellQueue.pop();
        roomSize++;
        visited[currentCell.n][currentCell.m] = true;
        if(currentCell.n == 4 && currentCell.m == 4) {
            if(!HasRightWall(map[currentCell.n][currentCell.m])) {
                printf("Can't go from n=%d m=%d\n", currentCell.n, currentCell.m);
            }
            if(!IsInBoundaries(currentCell.n, currentCell.m + 1)) {
                printf("Can't go from n=%d m=%d\n", currentCell.n, currentCell.m);
            }
            if(!CanGoRight(currentCell.n, currentCell.m + 1)) {
                printf("Can't go from n=%d m=%d\n", currentCell.n, currentCell.m);
            }
//            printf("map %d \n", map[currentCell.n][currentCell.m]);

        }
        printf("going at n=%d and m=%d\n", currentCell.n, currentCell.m);
        if(CanGoLeft(currentCell.n, currentCell.m)) {
            printf("Going left\n");
            Cell cell;
            cell.n = currentCell.n;
            cell.m = currentCell.m - 1;
            cellQueue.push(cell);
//            if(cell.n == 1 && cell.m == 3) {
//                printf("Adding from n=%d m=%d\n", currentCell.n, currentCell.m);
//            }
        }
        if(CanGoRight(currentCell.n, currentCell.m)) {
            printf("Going right\n");
            Cell cell;
            cell.n = currentCell.n;
            cell.m = currentCell.m + 1;
            cellQueue.push(cell);
//            if(cell.n == 1 && cell.m == 3) {
//                printf("Adding from n=%d m=%d\n", currentCell.n, currentCell.m);
//            }
        }
        if(CanGoUp(currentCell.n, currentCell.m)) {
            printf("Going up\n");
            Cell cell;
            cell.n = currentCell.n - 1;
            cell.m = currentCell.m;
            cellQueue.push(cell);
//            if(cell.n == 1 && cell.m == 3) {
//                printf("Adding from n=%d m=%d\n", currentCell.n, currentCell.m);
//            }
        }
        if(CanGoDown(currentCell.n, currentCell.m)) {
            printf("Going down\n");
            Cell cell;
            cell.n = currentCell.n + 1;
            cell.m = currentCell.m;
            cellQueue.push(cell);
//            if(cell.n == 1 && cell.m == 3) {
//                printf("Adding from n=%d m=%d\n", currentCell.n, currentCell.m);
//            }
        }
    }
    printf("Romm size is %d\n", roomSize);
}

int main()
{
    freopen("castle.in", "r", stdin);
//    freopen("castle.out", "w", stdout);
    scanf("%d %d", &m, &n);
    printf("n=%d and m=%d\n", n, m);
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
            BFS(3, 4);
            return 0;
//            printf("%d ", map[i][k]);
        }
//        printf("\n");
    }
//    printf("m=%d and n=%d", m, n);
    return 0;
}

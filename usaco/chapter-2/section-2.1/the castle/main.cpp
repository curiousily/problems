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

bool IsInnerWall(int nPos, int mPos) {
    return nPos > 0 && nPos <= n && mPos > 0 && mPos <= m;
}

bool IsInBoundaries(int nPos, int mPos) {
    return nPos > 0 && nPos <= n && mPos > 0 && mPos <= m;
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
    if(realValue == 4 || realValue == 5) return false;
    if(realValue < 2) return false;
    return true;
}

bool HasRightWall(int value) {
    if(value == 8) return false;
    int realValue = value;
    if(realValue > 8)
        realValue -= 8;
    if(realValue < 4) return false;
    return true;
}

bool CanGoLeft(int nPos, int mPos) {
    return IsInBoundaries(nPos, mPos - 1) && !HasLeftWall(map[nPos][mPos]);
}

bool CanGoRight(int nPos, int mPos) {
    return IsInBoundaries(nPos, mPos + 1) && !HasRightWall(map[nPos][mPos]);
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

struct Wall {
    Cell c1, c2;
    bool isVertical;

    bool operator <(Wall const& w) const {
        return true;
    }

    bool operator==(const Wall& w) const {
      return c1.n == w.c1.n && c1.m == w.c1.m && c2.n == w.c2.n && c2.m == w.c2.m;
    }

};

struct Room {
    set<Wall> walls;
    int size;
};

vector<Room> rooms;

void BFS(int nPos, int mPos) {

    if(visited[nPos][mPos]) return;
    Room r;
    Cell c;
    c.n = nPos;
    c.m = mPos;
//    printf("Entering bfs with n=%d and m=%d\n", nPos, mPos);
    queue<Cell> cellQueue;
    cellQueue.push(c);
//    visited[nPos][mPos] = true;
    int roomSize = 0;
    while(!cellQueue.empty()) {



        Cell currentCell = cellQueue.front();
        cellQueue.pop();
        if(visited[currentCell.n][currentCell.m]) {
            continue;
        }
        roomSize++;
        visited[currentCell.n][currentCell.m] = true;

//if(!IsInnerWall(currentCell.n, currentCell.m + 1)) {
//                    printf("wtf?\n");
//                }


//        if(HasDownWall(map[currentCell.n][currentCell.m]) && IsInnerWall(currentCell.n + 1, currentCell.m)) {
//            printf("Has down inner wall\n");
//            printf("down is n=%d m=%d", currentCell.n + 1, currentCell.m);
//
//        }
//        return;

//        printf("going at n=%d and m=%d\n", currentCell.n, currentCell.m);
        if(CanGoLeft(currentCell.n, currentCell.m)) {
//            printf("Going left\n");
            Cell cell;
            cell.n = currentCell.n;
            cell.m = currentCell.m - 1;
            cellQueue.push(cell);
//            if(cell.n == 1 && cell.m == 3) {
//                printf("Adding from n=%d m=%d\n", currentCell.n, currentCell.m);
//            }
        } else if(HasLeftWall(map[currentCell.n][currentCell.m]) && IsInnerWall(currentCell.n, currentCell.m - 1)) {
            Wall w;
            w.isVertical = true;
            Cell leftCell;
            leftCell.n = currentCell.n;
            leftCell.m = currentCell.m - 1;
            w.c1 = leftCell;
            w.c2 = currentCell;
            r.walls.insert(w);
        }
        if(CanGoRight(currentCell.n, currentCell.m)) {
//            printf("Going right\n");
            Cell cell;
            cell.n = currentCell.n;
            cell.m = currentCell.m + 1;
            cellQueue.push(cell);
//            if(cell.n == 1 && cell.m == 3) {
//                printf("Adding from n=%d m=%d\n", currentCell.n, currentCell.m);
//            }
        } else if(HasRightWall(map[currentCell.n][currentCell.m]) && IsInnerWall(currentCell.n, currentCell.m + 1)) {
            Wall w;
            w.isVertical = true;
            w.c1 = currentCell;
            Cell rightCell;
            rightCell.n = currentCell.n;
            rightCell.m = currentCell.m + 1;
            w.c2 = rightCell;
            r.walls.insert(w);




        }
        if(CanGoUp(currentCell.n, currentCell.m)) {
//            printf("Going up\n");
            Cell cell;
            cell.n = currentCell.n - 1;
            cell.m = currentCell.m;
            cellQueue.push(cell);
//            if(cell.n == 1 && cell.m == 3) {
//                printf("Adding from n=%d m=%d\n", currentCell.n, currentCell.m);
//            }
        } else if(HasUpWall(map[currentCell.n][currentCell.m]) && IsInnerWall(currentCell.n - 1, currentCell.m)) {
            Wall w;
            w.isVertical = false;
            Cell upCell;
            upCell.n = currentCell.n - 1;
            upCell.m = currentCell.m;
            w.c1 = upCell;
            w.c2 = currentCell;
            r.walls.insert(w);


//            if(currentCell.n == 4 && currentCell.m == 1) {
//
//                if(HasUpWall(map[currentCell.n][currentCell.m])) {
//                    printf("wtf?\n");
//                }
//            }

        }
        if(CanGoDown(currentCell.n, currentCell.m)) {
//            printf("Going down\n");
            Cell cell;
            cell.n = currentCell.n + 1;
            cell.m = currentCell.m;
            cellQueue.push(cell);
//            if(cell.n == 1 && cell.m == 3) {
//                printf("Adding from n=%d m=%d\n", currentCell.n, currentCell.m);
//            }
        } else if(HasDownWall(map[currentCell.n][currentCell.m]) && IsInnerWall(currentCell.n + 1, currentCell.m)) {
            if(currentCell.n == 3 && currentCell.m == 1) {
                printf("wtf?\n");
            }
            Wall w;
            w.c1 = currentCell;
            w.isVertical = false;
            Cell downCell;
            downCell.n = currentCell.n + 1;
            downCell.m = currentCell.m;
            w.c2 = downCell;
            r.walls.insert(w);
        }
    }

    printf("wall count %d \n", r.walls.size());
    set<Wall>::iterator it;

    for ( it=r.walls.begin() ; it != r.walls.end(); it++ ) {
        Wall w = *it;
        if(w.isVertical)
            printf("left n=%d m=%d right n=%d m=%d\n", w.c1.n, w.c1.m, w.c2.n, w.c2.m);
        else
            printf("top n=%d m=%d down n=%d m=%d\n", w.c1.n, w.c1.m, w.c2.n, w.c2.m);
    }


    r.size = roomSize;
    rooms.push_back(r);
    roomCount++;
    if(roomSize > largestRoomSize)
        largestRoomSize = roomSize;
//    printf("Romm size is %d\n", roomSize);
}

int main()
{
    freopen("castle.in", "r", stdin);
//    freopen("castle.out", "w", stdout);
    scanf("%d %d", &m, &n);
//    printf("n=%d and m=%d\n", n, m);
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
            BFS(i, k);
//            BFS(1, 1);
//            return 0;
//            printf("%d ", map[i][k]);
        }
//        printf("\n");
    }
//    printf("m=%d and n=%d", m, n);
    printf("%d\n", roomCount);
    printf("%d\n", largestRoomSize);
    return 0;
}

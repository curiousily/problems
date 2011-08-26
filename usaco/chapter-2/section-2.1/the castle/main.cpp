/*
ID: v.valko1
PROG: castle
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXDIM 50
#define MAXN 100
#define MAXCOLOR 100
#define MAXROOM (MAXDIM*MAXDIM)

enum {    Wwest = 1,    Wnorth = 2,    Weast = 4,    Wsouth = 8};

typedef struct Square Square;
struct Square
{
    int wall;
    int numbered;
    int room;
};

int wid, ht;
Square castle[MAXDIM][MAXDIM];
int roomsize[MAXROOM];

void number(int room, int x, int y)
{
    int w;

    if (castle[x][y].numbered)
    {
        assert(castle[x][y].room == room);
        return;
    }

    castle[x][y].numbered = 1;
    castle[x][y].room = room;
    roomsize[room]++;

    w = castle[x][y].wall;

    if (x > 0 && !(w & Wwest)) number(room, x-1, y);

    if (x+1 < wid && !(w & Weast)) number(room, x+1, y);

    if (y > 0 && !(w & Wnorth)) number(room, x, y-1);

    if (y+1 < ht && !(w & Wsouth)) number(room, x, y+1);
}

int main()
{
    FILE *fin, *fout;
    int x, y, w, nroom, bigroom;
    int i, n, m, mx, my;
    char mc;

    fin = fopen("castle.in", "r");
    fout = fopen("castle.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d %d", &wid, &ht);

    /* read in wall info */
    for (y=0; y<ht; y++)
    {
        for (x=0; x<wid; x++)
        {
            fscanf(fin, "%d", &w);
            castle[x][y].wall = w;
        }
    }

    /* number rooms */
    nroom = 0;
    for (y=0; y<ht; y++)    for (x=0; x<wid; x++) if (!castle[x][y].numbered)     number(nroom++, x, y);

    /* find biggest room */
    bigroom = roomsize[0];
    for (i=1; i<nroom; i++) if (bigroom < roomsize[i])     bigroom = roomsize[i];

    /* look at best that can come of removing an east or north wall */
    m = 0;
    for (x=0; x<wid; x++)    for (y=ht-1; y>=0; y--)
        {
            if (y > 0 && castle[x][y].room != castle[x][y-1].room)
            {
                n = roomsize[castle[x][y].room] + roomsize[castle[x][y-1].room];
                if (n > m)
                {
                    m = n;
                    mx = x;
                    my = y;
                    mc = 'N';
                }
            }
            if (x+1 < wid && castle[x][y].room != castle[x+1][y].room)
            {
                n = roomsize[castle[x][y].room] + roomsize[castle[x+1][y].room];
                if (n > m)
                {
                    m = n;
                    mx = x;
                    my = y;
                    mc = 'E';
                }
            }
        }

    fprintf(fout, "%d\n", nroom);
    fprintf(fout, "%d\n", bigroom);
    fprintf(fout, "%d\n", m);
    fprintf(fout, "%d %d %c\n", my+1, mx+1, mc);
    return 0;
}


///*
//ID: v.valko1
//PROG: castle
//LANG: C++
//*/
//
//#include <iostream>
//#include <cstdio>
//#include <cstdlib>
//#include <cmath>
//#include <cstring>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <set>
//#include <queue>
//
//using namespace std;
//
//const int LEFT_WALL = 1;
//const int UP_WALL = 2;
//const int RIGHT_WALL = 4;
//const int DOWN_WALL = 8;
//
//unsigned m, n;
//vector<vector<int> > map;
//vector<vector<bool> > visited;
//int roomCount = 0;
//int largestRoomSize = 0;
//int roomSize;
//
//void InitMap() {
//    map.resize(n + 1);
//    visited.resize(n + 1);
//    for(unsigned i = 1; i <= n; i++) {
//        map[i].resize(m + 1);
//        visited[i].resize(m + 1);
//    }
//}
//
//bool IsInnerWall(int nPos, int mPos) {
//    return nPos > 0 && nPos <= n && mPos > 0 && mPos <= m;
//}
//
//bool IsInBoundaries(int nPos, int mPos) {
//    return nPos > 0 && nPos <= n && mPos > 0 && mPos <= m;
//}
//
//bool HasLeftWall(int value) {
//    return value % 2 == 1;
//}
//
//bool HasDownWall(int value) {
//    return value >= 8;
//}
//
//bool HasUpWall(int value) {
//    int realValue = value;
//    if(realValue > 8)
//        realValue -= 8;
//    if(realValue == 4 || realValue == 5) return false;
//    if(realValue < 2) return false;
//    return true;
//}
//
//bool HasRightWall(int value) {
//    if(value == 8) return false;
//    int realValue = value;
//    if(realValue > 8)
//        realValue -= 8;
//    if(realValue < 4) return false;
//    return true;
//}
//
//bool CanGoLeft(int nPos, int mPos) {
//    return IsInBoundaries(nPos, mPos - 1) && !HasLeftWall(map[nPos][mPos]);
//}
//
//bool CanGoRight(int nPos, int mPos) {
//    return IsInBoundaries(nPos, mPos + 1) && !HasRightWall(map[nPos][mPos]);
//}
//
//bool CanGoUp(int nPos, int mPos) {
//    return IsInBoundaries(nPos - 1, mPos) && !HasUpWall(map[nPos][mPos]);
//}
//
//bool CanGoDown(int nPos, int mPos) {
//    return IsInBoundaries(nPos + 1, mPos) && !HasDownWall(map[nPos][mPos]);
//}
//
//struct Cell {
//    int n, m;
//};
//
//struct Wall {
//    Cell c1, c2;
//    bool isVertical;
//
//    bool operator <(Wall const& w) const {
//        return true;
//    }
//
//    bool operator==(const Wall& w) const {
//        bool equals = c1.n == w.c1.n && c1.m == w.c1.m && c2.n == w.c2.n && c2.m == w.c2.m;
//        bool equalsSwapped = c1.n == w.c1.m && c1.m == w.c1.n && c2.n == w.c2.m && c2.m == w.c2.n;
//        return equals || equalsSwapped;
//    }
//};
//
//struct Room {
//    set<Wall> walls;
//    int size;
//};
//
//vector<Room> rooms;
//
//void BFS(int nPos, int mPos) {
//
//    if(visited[nPos][mPos]) return;
//    Room r;
//    Cell c;
//    c.n = nPos;
//    c.m = mPos;
////    printf("Entering bfs with n=%d and m=%d\n", nPos, mPos);
//    queue<Cell> cellQueue;
//    cellQueue.push(c);
////    visited[nPos][mPos] = true;
//    int roomSize = 0;
//    while(!cellQueue.empty()) {
//
//
//
//        Cell currentCell = cellQueue.front();
//        cellQueue.pop();
//        if(visited[currentCell.n][currentCell.m]) {
//            continue;
//        }
//        roomSize++;
//        visited[currentCell.n][currentCell.m] = true;
//
////if(!IsInnerWall(currentCell.n, currentCell.m + 1)) {
////                    printf("wtf?\n");
////                }
//
//
////        if(HasDownWall(map[currentCell.n][currentCell.m]) && IsInnerWall(currentCell.n + 1, currentCell.m)) {
////            printf("Has down inner wall\n");
////            printf("down is n=%d m=%d", currentCell.n + 1, currentCell.m);
////
////        }
////        return;
//
////        printf("going at n=%d and m=%d\n", currentCell.n, currentCell.m);
//        if(CanGoLeft(currentCell.n, currentCell.m)) {
////            printf("Going left\n");
//            Cell cell;
//            cell.n = currentCell.n;
//            cell.m = currentCell.m - 1;
//            cellQueue.push(cell);
////            if(cell.n == 1 && cell.m == 3) {
////                printf("Adding from n=%d m=%d\n", currentCell.n, currentCell.m);
////            }
//        } else if(HasLeftWall(map[currentCell.n][currentCell.m])) { // && IsInnerWall(currentCell.n, currentCell.m - 1)) {
//            Wall w;
//            w.isVertical = true;
//            Cell leftCell;
//            leftCell.n = currentCell.n;
//            leftCell.m = currentCell.m - 1;
//            w.c1 = leftCell;
//            w.c2 = currentCell;
//            r.walls.insert(w);
//        }
//        if(CanGoRight(currentCell.n, currentCell.m)) {
////            printf("Going right\n");
//            Cell cell;
//            cell.n = currentCell.n;
//            cell.m = currentCell.m + 1;
//            cellQueue.push(cell);
////            if(cell.n == 1 && cell.m == 3) {
////                printf("Adding from n=%d m=%d\n", currentCell.n, currentCell.m);
////            }
//        } else if(HasRightWall(map[currentCell.n][currentCell.m])) { // && IsInnerWall(currentCell.n, currentCell.m + 1)) {
//            Wall w;
//            w.isVertical = true;
//            w.c1 = currentCell;
//            Cell rightCell;
//            rightCell.n = currentCell.n;
//            rightCell.m = currentCell.m + 1;
//            w.c2 = rightCell;
//            r.walls.insert(w);
//
//
//
//
//        }
//        if(CanGoUp(currentCell.n, currentCell.m)) {
////            printf("Going up\n");
//            Cell cell;
//            cell.n = currentCell.n - 1;
//            cell.m = currentCell.m;
//            cellQueue.push(cell);
////            if(cell.n == 1 && cell.m == 3) {
////                printf("Adding from n=%d m=%d\n", currentCell.n, currentCell.m);
////            }
//        } else if(HasUpWall(map[currentCell.n][currentCell.m])) { //&& IsInnerWall(currentCell.n - 1, currentCell.m)) {
//            Wall w;
//            w.isVertical = false;
//            Cell upCell;
//            upCell.n = currentCell.n - 1;
//            upCell.m = currentCell.m;
//            w.c1 = upCell;
//            w.c2 = currentCell;
//            r.walls.insert(w);
//
//
////            if(currentCell.n == 4 && currentCell.m == 1) {
////
////                if(HasUpWall(map[currentCell.n][currentCell.m])) {
////                    printf("wtf?\n");
////                }
////            }
//
//        }
//        if(CanGoDown(currentCell.n, currentCell.m)) {
////            printf("Going down\n");
//            Cell cell;
//            cell.n = currentCell.n + 1;
//            cell.m = currentCell.m;
//            cellQueue.push(cell);
////            if(cell.n == 1 && cell.m == 3) {
////                printf("Adding from n=%d m=%d\n", currentCell.n, currentCell.m);
////            }
//        } else if(HasDownWall(map[currentCell.n][currentCell.m])) { //&& IsInnerWall(currentCell.n + 1, currentCell.m)) {
////            if(currentCell.n == 3 && currentCell.m == 1) {
////                printf("wtf?\n");
////            }
//            Wall w;
//            w.c1 = currentCell;
//            w.isVertical = false;
//            Cell downCell;
//            downCell.n = currentCell.n + 1;
//            downCell.m = currentCell.m;
//            w.c2 = downCell;
//            r.walls.insert(w);
//        }
//    }
//
////    printf("wall count %d \n", r.walls.size());
//    set<Wall>::iterator it;
//
//    for ( it=r.walls.begin() ; it != r.walls.end(); it++ ) {
//        Wall w = *it;
////        if(w.isVertical)
////            printf("left n=%d m=%d right n=%d m=%d\n", w.c1.n, w.c1.m, w.c2.n, w.c2.m);
////        else
////            printf("top n=%d m=%d down n=%d m=%d\n", w.c1.n, w.c1.m, w.c2.n, w.c2.m);
//    }
//
//
//    r.size = roomSize;
//    rooms.push_back(r);
//    roomCount++;
//    if(roomSize > largestRoomSize)
//        largestRoomSize = roomSize;
////    printf("Romm size is %d\n", roomSize);
//}
//
//int main()
//{
//    freopen("castle.in", "r", stdin);
////    freopen("castle.out", "w", stdout);
//    scanf("%d %d", &m, &n);
////    printf("n=%d and m=%d\n", n, m);
//    InitMap();
//    int num;
//    for(unsigned i = 1; i <= n; i++)
//        for(unsigned k = 1 ; k <= m; k++) {
//            scanf("%d", &num);
//            map[i][k] = num;
//            visited[i][k] = false;
//        }
//    for(unsigned i = 1; i <= n; i++) {
//        for(unsigned k = 1 ; k <= m; k++) {
////            BFS(i, k);
//            BFS(1, 1);
//            BFS(3, 4);
//            break;
////            return 0;
////            printf("%d ", map[i][k]);
//        }
//        break;
////        printf("\n");
//    }
////    printf("m=%d and n=%d", m, n);
//    printf("%d\n", roomCount);
//    printf("%d\n", largestRoomSize);
//    Room r1 = rooms[0];
//    Room r2 = rooms[1];
//
//    printf("r1 wall count %d \n", r1.walls.size());
//    printf("r2 wall count %d \n", r2.walls.size());
//
//    vector<Wall> inter;
//    vector<Wall>::iterator it;
//    it = set_intersection(r1.walls.begin(), r1.walls.end(), r2.walls.begin(), r2.walls.end(), inter.begin());
//    printf("count %d\n", inter.size());
//    return 0;
//}

#include <fcntl.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>
#include <climits>
#include <ctype.h>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define FOR(upperLimit) \
  for(unsigned i = 0; i < upperLimit; i++)

#define FOREACH(var, upperLimit) \
  for(unsigned var = 0; var < upperLimit; var++)

#define FREE true
#define OCCUPIED false

#define UP_DIRECTION +1
#define DOWN_DIRECTION -1
#define IMPOSSIBLE -1

unsigned L, R, C;

int Direction;

struct Node
{
  unsigned row, col, level;
  bool isFree;
};

Node dungeon[31][31][31];

Node Start, End;

//int
//BFSForLevel(int level)
//{
//  map<Node, int> distance;
//  distance[End] = 0;
//  queue<Node> nodeQueue;
//  nodeQueue.push(End);
//  while (!nodeQueue.empty())
//  {
//    Node node = nodeQueue.front();
//    nodeQueue.pop();
//    int dCols[] =
//      { -1, 0, 0, +1 };
//    int dRows[] =
//      { 0, -1, +1, 0 };
//    FOREACH(combinationIndex, 4)
//    {
//      int row = dRows[combinationIndex];
//      int col = dCols[combinationIndex];
//      if (col < 0 || col >= C || row < 0 || row >= R
//          || !distance.count(dungeon[node.level][row][col]))
//      {
//        continue;
//      }
//      Node neighbour = dungeon[node.level][row][col];
//      distance[neighbour] = distance[node] + 1;
//      if (neighbour.level == Start.level && neighbour.row == Start.row
//          && neighbour.col == Start.col)
//      {
//        return distance[neighbour];
//      }
//      nodeQueue.push(neighbour);
//    }
//  }
//  return IMPOSSIBLE;
//}

//void
//SetPoint(unsigned level, unsigned row, unsigned col, char cell)
//{
//  Node point;
//  if (cell == 'S')
//  {
////    point = Start;
//  }
//  else if (cell == 'E')
//  {
////    point = End;
//  }
//  else if (cell == '.')
//  {
//    point.isFree = FREE;
//  }
//  else
//  {
//    point.isFree = OCCUPIED;
//  }
//
//  point.level = level;
//  point.row = row;
//  point.col = col;
//  dungeon[level][row][col] = point;
//}

int
main()
{
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//          close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
  while (scanf("%d %d %d\n", &L, &R, &C) && (L != 0 || R != 0 || C != 0))
  {
    FOREACH(level, L)
    {
      FOREACH(row, R)
      {
        string rowString;
        cin >> rowString;
        FOREACH(col, C)
        {
          char cell = rowString[col];
//          SetPoint(level, row, col, cell);
        }
      }
      if (End.level > Start.level)
      {
//        Direction = DOWN_DIRECTION;
      }
      else if (End.level < Start.level)
      {
//        Direction = UP_DIRECTION;
      }
      else
      {
        // on the same level
//        BFSForLevel(End.level);
      }
      string emptyLine;
      cin >> emptyLine;
    }
  }
  return 0;
}

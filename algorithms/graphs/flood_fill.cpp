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

#define MAX_ELEMENTS 101

unsigned N, M;

bool visited[MAX_ELEMENTS][MAX_ELEMENTS];
bool grid[MAX_ELEMENTS][MAX_ELEMENTS];

void
FloodFill(int row, int col)
{
  if (row < 0 || row >= M || col < 0 || col >= N || visited[row][col]
      || !grid[row][col])
  {
    return;
  }
  visited[row][col] = true;
  FloodFill(row - 1, col);
  FloodFill(row + 1, col);
  FloodFill(row, col - 1);
  FloodFill(row, col + 1);
  FloodFill(row - 1, col - 1);
  FloodFill(row + 1, col - 1);
  FloodFill(row - 1, col + 1);
  FloodFill(row + 1, col + 1);
}

int
FindComponentCount()
{
  unsigned componentCount = 0;
  FOREACH(i, M)
  {
    FOREACH(j, N)
    {
      if (!visited[i][j] && grid[i][j])
      {
        componentCount++;
        FloodFill(i, j);
      }
    }
  }
  return componentCount;
}

void
ResetValues()
{
  FOREACH(i, M)
  {
    FOREACH(j, N)
    {
      grid[i][j] = false;
      visited[i][j] = false;
    }
  }
}

int
main()
{
  ResetValues();
  // fill the grid here
  printf("Component count is %d\n", FindComponentCount());
  return 0;
}
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
FindOilDepositCount()
{
  unsigned oilDepositCount = 0;
  FOREACH(i, M)
  {
    FOREACH(j, N)
    {
      if (!visited[i][j] && grid[i][j])
      {
        oilDepositCount++;
        FloodFill(i, j);
      }
    }
  }
  return oilDepositCount;
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
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//          close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
  while (scanf("%d %d\n", &M, &N) && M != 0)
  {
    ResetValues();
    FOREACH(line, M)
    {
      string strLine;
      getline(cin, strLine);
      FOREACH(ch, N)
      {
        if (strLine[ch] == '*')
        {
          grid[line][ch] = false;
        }
        else
        {
          grid[line][ch] = true;
        }
      }
    }
//    FOREACH(i, M) {
//      FOREACH(j, N) {
//        printf("%d", grid[i][j]);
//      }
//      printf("\n");
//    }
    printf("%d\n", FindOilDepositCount());
  }
  return 0;
}

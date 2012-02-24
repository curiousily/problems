#include <fcntl.h>
#include <iostream>
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

long MemoTable[11][101];
long Matrix[11][101];

unsigned M, N;

int
FindSolution(int row, int col)
{
  return 1;
}

int
main()
{
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//          close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
  while (scanf("%d %d\n", &M, &N) != EOF)
  {
    memset(MemoTable, -1, sizeof(MemoTable));
    FOREACH(row, M)
    {
      FOREACH(col, N)
      {
        Matrix[row][col] = READLONG;
      }
    }
    printf("%d\n", FindSolution(0, 0));
  }
  return 0;
}

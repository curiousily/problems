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
#define READUINT ({unsigned num;scanf("%u",&num);num;});
#define READLONG ({long num;scanf("%ld",&num);num;});
#define READSTRING ({string strLine; cin >> strLine; strLine;});
#define READLINE ({string strLine; getline(cin, strLine); strLine;});

#define INF 100000
#define NOT_COMPUTED -1

int MemoTable[55][55];

int StickLength;
int RequiredCuts;
int CutPositions[55];

int
Cost(int start, int end)
{
  return CutPositions[end] - CutPositions[start];
}

int
MinimumCuttingCost(int start, int end)
{
  if (start + 1 == end)
  {
    return 0;
  }
  if (MemoTable[start][end] != NOT_COMPUTED)
  {
    return MemoTable[start][end];
  }
  int minimumCost = INF;
  for (int i = start + 1; i < end; i++)
  {
    minimumCost = min(
        MinimumCuttingCost(start, i) + MinimumCuttingCost(i, end) + Cost(start, end),
        minimumCost);
  }
  return MemoTable[start][end] = minimumCost;
}

int
main()
{
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//          close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
  while (true)
  {
    StickLength = READINT;
    if (StickLength == 0)
    {
      break;
    }
    memset(MemoTable, NOT_COMPUTED, sizeof(MemoTable[0][0]) * 55 * 55);
    RequiredCuts = READINT;
    FOREACH(i, RequiredCuts)
    {
      CutPositions[i + 1] = READINT;
//      printf("%d\n", CutPositions[i]);
    }
    CutPositions[0] = 0;
    CutPositions[RequiredCuts + 1] = StickLength;
    printf("The minimum cutting is %d.\n", MinimumCuttingCost(0, RequiredCuts + 1));
  }

  return 0;
}

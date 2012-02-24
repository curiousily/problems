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

#define INF 100000

#define CLIMBING 60
#define HOLDING 30
#define SINKING 20

unsigned Distance;

int FlightMap[11][1010];
int MemoTable[11][1010];

int
FindFuel(int altitude, int distance, int goal)
{
  if (altitude == 0 && distance == goal)
  {
    return 0;
  }
  if (distance == goal || altitude < 0 || altitude > 9)
  {
    return INF;
  }
  int & result = MemoTable[altitude][distance];
  if (result != -1)
  {
    return result;
  }
  vector<int> options;
  int sinking = SINKING - FlightMap[altitude][distance]
      + FindFuel(altitude - 1, distance + 1, goal);
  options.push_back(sinking);
  int climbing = CLIMBING - FlightMap[altitude][distance]
      + FindFuel(altitude + 1, distance + 1, goal);
  options.push_back(climbing);
  if (!(altitude == 0 && distance != goal - 1))
  {
    int holding = HOLDING - FlightMap[altitude][distance]
        + FindFuel(altitude, distance + 1, goal);
    options.push_back(holding);
  }
  return result = *(min_element(options.begin(), options.end()));
}

int
main()
{
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//          close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
  unsigned tc = READINT;
  FOR(tc)
  {
    memset(MemoTable, -1, sizeof(MemoTable));
    Distance = READINT;
    Distance /= 100;
    for (int altitude = 9; altitude >= 0; altitude--)
    {
      FOREACH(windStrength, Distance)
      {
        FlightMap[altitude][windStrength] = READINT;
      }
    }
    printf("%d\n\n", FindFuel(0, 0, Distance));
  }
  return 0;
}


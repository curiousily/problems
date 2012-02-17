#include <fcntl.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>
#include <ctype.h>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define FOR(upperLimit) \
  for(unsigned i = 0; i < upperLimit; i++)

#define FOREACH(var, upperLimit) \
  for(unsigned var = 0; var < upperLimit; var++)

#define COUNTRIES_TO_READ 19

vector<int> AdjList[22];

int
FindDistance(int start, int end)
{
  map<int, int> distance;
  distance[start] = 0;
  queue<int> nodeQueue;
  nodeQueue.push(start);
  while (!nodeQueue.empty())
  {
    int node = nodeQueue.front();
    nodeQueue.pop();
    FOREACH(i, AdjList[node].size())
    {
      int neighbour = AdjList[node][i];
      // if it isn't already visited
      if (!distance.count(neighbour))
      {
        int distanceToNeighbour = distance[node] + 1;
        if (neighbour == end)
        {
          return distanceToNeighbour;
        }
        distance[neighbour] = distanceToNeighbour;
        nodeQueue.push(neighbour);
      }
    }
  }
  return -1;
}

void
PrintNum(int num)
{
  int digits = log10(num) + 1;
  if (digits == 1)
  {
    printf(" ");
  }
  printf("%d", num);
}

int
main()
{
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//          close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
  int tc = 0;
  while (true)
  {
    tc++;
    FOREACH(i, 21)
    {
      AdjList[i].clear();
    }
    FOREACH(countryIndex, COUNTRIES_TO_READ)
    {
      unsigned country = countryIndex + 1;

      unsigned boundaries;
      if (scanf("%d", &boundaries) == EOF)
      {
        // kids, don't try this at home!
        goto exitLabel;
      }

      FOR(boundaries)
      {
        unsigned boundary;
        scanf("%d", &boundary);
        AdjList[country].push_back(boundary);
        AdjList[boundary].push_back(country);
      }
    }

//    FOREACH(countryIndex, COUNTRIES_TO_READ)
//    {
//      printf("%d has connections to: ", countryIndex + 1);
//      FOREACH(i, AdjList[countryIndex + 1].size())
//      {
//        printf("%d ", AdjList[countryIndex + 1][i]);
//      }
//      printf("\n");
//    }
//    printf("\n\n");

    printf("Test Set #%d\n", tc);
    unsigned countryPairs;
    scanf("%d", &countryPairs);
    FOR(countryPairs)
    {
      int start, end;
      scanf("%d %d", &start, &end);
      int distance = FindDistance(start, end);
      PrintNum(start);
      printf(" to ");
      PrintNum(end);
      printf(": %d\n", distance);
    }
    printf("\n");
  }
  exitLabel: return 0;
}

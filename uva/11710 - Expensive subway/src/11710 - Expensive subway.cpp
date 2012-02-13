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

#define MAX_S 401
#define MAX_C 79801
#define MAX_WEIGHT INT_MAX

unsigned S, C;

unsigned AdjMatrix[MAX_S][MAX_S];
bool InTree[MAX_S];

unsigned StartNode;
map<string, int> StationToIndex;

const int RESULT_IMPOSSIBLE = -1;

int
FindMinimumPayment()
{
  FOREACH(i, S)
  {
    InTree[i] = false;
  }
  unsigned minWeightFound, edgeStartNode, edgeEndNode;
  unsigned edgesTraversed = 0, totalDistance = 0;
  InTree[StartNode] = true;
  while (edgesTraversed < S - 1)
  {
    minWeightFound = MAX_WEIGHT;
    FOREACH(i, S)
    {
      if (InTree[i])
      {
        FOREACH(j, S)
        {
          if (!InTree[j])
          {
            if (minWeightFound > AdjMatrix[i][j])
            {
              minWeightFound = AdjMatrix[i][j];
              edgeStartNode = i;
              edgeEndNode = j;
            }
          }
        }
      }
    }
    // No edge found
    if (minWeightFound == MAX_WEIGHT)
    {
      return RESULT_IMPOSSIBLE;
    }
    totalDistance += AdjMatrix[edgeStartNode][edgeEndNode];
    InTree[edgeEndNode] = true;
    edgesTraversed++;
  }
  return totalDistance;
}

int
main()
{
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//	        close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
  while (scanf("%d %d\n", &S, &C) && (S != 0 || C != 0))
  {
    FOREACH(i, S)
    {
      FOREACH(j, S)
      {
        AdjMatrix[i][j] = MAX_WEIGHT;
      }
    }
    FOREACH(station, S)
    {
      string stationName;
      cin >> stationName;
      StationToIndex[stationName] = station;
    }
    FOREACH(connection, C)
    {
      string station1, station2;
      int weight;
      cin >> station1 >> station2 >> weight;
      AdjMatrix[StationToIndex[station1]][StationToIndex[station2]] = weight;
      AdjMatrix[StationToIndex[station2]][StationToIndex[station1]] = weight;
    }
    string startingStation;
    cin >> startingStation;
    StartNode = StationToIndex[startingStation];

//  Print the graph
//    FOREACH(i, S)
//    {
//      FOREACH(j, S)
//      {
//        printf("%d %d with weight %d\n", i, j, AdjMatrix[i][j]);
//      }
//    }
    int minimumPayment = FindMinimumPayment();
    if (minimumPayment == RESULT_IMPOSSIBLE)
    {
      printf("Impossible\n");
    }
    else
    {
      printf("%d\n", minimumPayment);
    }
  }
  return 0;
}

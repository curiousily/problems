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

#define MAX_NODES 401
#define MAX_WEIGHT INT_MAX

unsigned Nodes;

unsigned AdjMatrix[MAX_NODES][MAX_NODES];
bool InTree[MAX_NODES];

unsigned StartNode;

const int RESULT_IMPOSSIBLE = -1;

int
FindDistance()
{
  FOREACH(i, Nodes)
  {
    InTree[i] = false;
  }
  unsigned minWeightFound, edgeStartNode, edgeEndNode;
  unsigned nodesTraversed = 0, totalDistance = 0;
  InTree[StartNode] = true;
  while (nodesTraversed < Nodes - 1)
  {
    minWeightFound = MAX_WEIGHT;
    FOREACH(i, Nodes)
    {
      if (InTree[i])
      {
        FOREACH(j, Nodes)
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
    nodesTraversed++;
  }
  return totalDistance;
}

int
main()
{
  FOREACH(i, Nodes)
  {
    FOREACH(j, Nodes)
    {
      AdjMatrix[i][j] = MAX_WEIGHT;
    }
  }
  // Fill the matrix here
  int result = FindDistance();
  if (result == RESULT_IMPOSSIBLE)
  {
    // invalid result
  }
  else
  {
    // valid result
  }
  return 0;
}

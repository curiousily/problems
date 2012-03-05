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
#define READLONG ({long num;scanf("%ld",&num);num;});
#define READSTRING ({string strLine; cin >> strLine; strLine;});
#define READLINE ({string strLine; getline(cin, strLine); strLine;});

vector<unsigned> Weights;
vector<unsigned> Values;

unsigned SolutionTable[202][202];

unsigned
FindMaxValue()
{
  // use with array starting at 1st position
  unsigned itemCount = 0;
  unsigned knapsackSize = 0;
  FOREACH(i, itemCount + 1)
  {
    SolutionTable[i][0] = 0;
  }
  FOREACH(i, knapsackSize + 1)
  {
    SolutionTable[0][i] = 0;
  }
  for (unsigned i = 1; i <= itemCount; i++)
  {
    for (unsigned w = 1; w <= knapsackSize; w++)
    {
      // item weight is bigger than the current knapsack can carry
      if (Weights[i] > w)
      {
        SolutionTable[i][w] = SolutionTable[i - 1][w];
      }
      else
      {
        SolutionTable[i][w] = max(SolutionTable[i - 1][w],
            SolutionTable[i - 1][w - Weights[i]] + Values[i]);
      }
    }
  }
  return SolutionTable[itemCount][knapsackSize];
}
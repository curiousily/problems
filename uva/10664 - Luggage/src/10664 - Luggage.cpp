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

unsigned SolutionTable[22][202];
unsigned TotalWeight;

bool
OddTotalWeight()
{
  return TotalWeight % 2 != 0;
}

bool
SuitCasesCanBeSplitted()
{
  unsigned suitCasesCount = Weights.size() - 1;
  unsigned carCanFit = TotalWeight / 2;
  FOREACH(i, suitCasesCount + 1)
  {
    SolutionTable[i][0] = 0;
  }
  FOREACH(i, carCanFit + 1)
  {
    SolutionTable[0][i] = 0;
  }
  for (unsigned i = 1; i <= suitCasesCount; i++)
  {
    for (unsigned w = 1; w <= carCanFit; w++)
    {
      if (Weights[i] > w)
      {
        SolutionTable[i][w] = SolutionTable[i - 1][w];
      }
      else
      {
        SolutionTable[i][w] = max(SolutionTable[i - 1][w],
            SolutionTable[i - 1][w - Weights[i]] + Weights[i]);
      }
    }
  }
//  printf("%d\n", SolutionTable[suitCasesCount][carCanFit]);
  return SolutionTable[suitCasesCount][carCanFit] == carCanFit;
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
  READLINE;
  FOR(tc)
  {
    Weights.clear();
    Weights.push_back(0);
    TotalWeight = 0;
    string line = READLINE;
    istringstream iss(line);
    unsigned suitCaseWeight;
    while (iss >> suitCaseWeight)
    {
      Weights.push_back(suitCaseWeight);
      TotalWeight += suitCaseWeight;
//      printf("%d\n", number);
    }
    bool canBeSplittedEqually;
    if (OddTotalWeight())
    {
      canBeSplittedEqually = false;
    }
    else
    {
      canBeSplittedEqually = SuitCasesCanBeSplitted();
    }
    if (canBeSplittedEqually)
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }
  }
  return 0;
}

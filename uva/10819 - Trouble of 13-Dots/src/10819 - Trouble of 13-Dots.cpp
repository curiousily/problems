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

#define MAX_MONEY 10500

int TotalMoney;
int ItemCount;

int Solution[MAX_MONEY];
int Prices[102];
int FavourIndexes[102];

void
InitSolution()
{
  FOREACH(i, MAX_MONEY)
  {
    Solution[i] = -1;
  }
  Solution[0] = 0;
}

int
main()
{
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//          close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
  while (scanf("%d %d", &TotalMoney, &ItemCount) != EOF)
  {
    for (int i = 1; i <= ItemCount; i++)
    {
      scanf("%d %d", &Prices[i], &FavourIndexes[i]);
    }
    InitSolution();
    for (int i = 1; i <= ItemCount; i++)
    {
      for (int j = MAX_MONEY; j >= Prices[i]; j--)
      {
        Solution[j] = max(Solution[j],
            Solution[j - Prices[i]] + FavourIndexes[i]);
      }
    }
    int answer = 0;
    for (int moneySpend = 0; moneySpend < 10201; moneySpend++)
    {
      if ((moneySpend > 2000 && TotalMoney + 200 >= moneySpend)
          || moneySpend <= TotalMoney)
      {
        answer = max(answer, Solution[moneySpend]);
      }
    }
    printf("%d\n", answer);
  }
  return 0;
}

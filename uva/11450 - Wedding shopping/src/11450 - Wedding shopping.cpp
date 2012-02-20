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

using namespace std;

#define FOR(upperLimit) \
  for(unsigned i = 0; i < upperLimit; i++)

#define FOREACH(var, upperLimit) \
  for(unsigned var = 0; var < upperLimit; var++)

unsigned M, C;

vector<vector<int> > ModelPrices;

int MemoTable[202][21];

#define MINUS_INF -100000

int
FindSolution(int money, int garment)
{
  if (money < 0)
    return MINUS_INF;
  if (garment == C)
    return 0;
  int & result = MemoTable[money][garment];
  if (result != -1)
    return result;
  int maximumMoneyToUse = MINUS_INF;
  FOREACH(model, ModelPrices[garment].size())
  {
    int modelPrice = ModelPrices[garment][model];
    maximumMoneyToUse = max(modelPrice + FindSolution(money - modelPrice, garment + 1),
        maximumMoneyToUse);
  }
  result = maximumMoneyToUse;
  return result;
}

int
main()
{
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//          close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
  unsigned tc;
  scanf("%d\n", &tc);
  FOR(tc)
  {
    ModelPrices.clear();
    memset(MemoTable, -1, sizeof(MemoTable[0][0]) * 201 * 21);
    scanf("%d %d\n", &M, &C);
    FOR(C)
    {
      unsigned models;
      scanf("%d ", &models);
      vector<int> prices;
      FOR(models)
      {
        int modelPrice;
        scanf("%d", &modelPrice);
        prices.push_back(modelPrice);
      }
      ModelPrices.push_back(prices);
    }
//    FOREACH(garment, C) {
//      FOREACH(model, ModelPrices[garment].size()) {
//        printf("%d ", ModelPrices[garment][model]);
//      }
//      printf("\n");
//    }
//    printf("\n\n\n\n");
    int result = FindSolution(M, 0);
    if (result < 0)
    {
      printf("no solution\n");
    }
    else
    {
      printf("%d\n", result);
    }
  }
  return 0;
}

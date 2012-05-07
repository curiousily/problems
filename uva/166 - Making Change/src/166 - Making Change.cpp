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

#define MAX_DIFF_COINS 6
#define MAX_VAL 200000
#define NOT_COMPUTED -1

int CoinValues[] =
  { 5, 10, 20, 50, 100, 200 };

vector<unsigned> Coins;

int TargetValue;

int MemTable[1005];

int
MinCoinsForValue(int index, int value)
{
  if (value < -500 || value > 500)
  {
    return MAX_VAL;
  }
  if (value <= 0 && index < 0)
  {
    return MemTable[-value];
  }
  if (index < 0)
  {
    return MAX_VAL;
  }
  if (!Coins[index])
  {
    return MinCoinsForValue(index - 1, value);
  }

  Coins[index]--;
  int a = MinCoinsForValue(index, value - CoinValues[index]);
  Coins[index]++;
  int b = MinCoinsForValue(index - 1, value);
  return min(1 + a, b);
}

int
main()
{
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//          close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif

  FOREACH(i, 1005)
  {
    MemTable[i] = MAX_VAL;
  }
  MemTable[0] = 0;

  FOREACH(i, 6)
  {
    for (int j = CoinValues[i]; j < 1005; j++)
    {
      MemTable[j] = min(MemTable[j], 1 + MemTable[j - CoinValues[i]]);
    }
  }

  while (true)
  {
    Coins.clear();
    bool allZero = true;
    FOREACH(i, MAX_DIFF_COINS)
    {
      unsigned coinCount = READINT;
      Coins.push_back(coinCount);
      if (coinCount != 0)
      {
        allZero = false;
      }
    }
    if (allZero)
    {
      break;
    }
    TargetValue = 0;
    int dollars, cents;
    scanf("%d.%d", &dollars, &cents);
    //    printf("%d dollars and %d cents\n", dollars, cents);
    TargetValue += cents;
    TargetValue += 100 * dollars;
    printf("%3d\n", MinCoinsForValue(5, TargetValue));
  }

  return 0;
}

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

#define NOT_COMPUTED -1
#define MAX 105

int Memo[MAX][MAX];

int N, K;

unsigned
WaysToAddUp(int remainingValue, int digitsToUse)
{
  if (remainingValue < 0 || digitsToUse < 0)
  {
    return 0;
  }
  if (Memo[remainingValue][digitsToUse] != NOT_COMPUTED)
  {
    return Memo[remainingValue][digitsToUse];
  }
  unsigned result = 0;
  for (int I = 0; I <= remainingValue; I++)
  {
    result += (WaysToAddUp(remainingValue - I, digitsToUse - 1) % 1000000);
  }
  return Memo[remainingValue][digitsToUse] = result % 1000000;
}

int
main()
{
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//          close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
  FOREACH(i, MAX)
    FOREACH(j, MAX)
      Memo[i][j] = NOT_COMPUTED;
  Memo[0][0] = 1;
  while (true)
  {
    N = READINT;
    K = READINT;
    if (N == 0 && K == 0)
    {
      break;
    }
    printf("%u\n", WaysToAddUp(N, K));
  }
  return 0;
}

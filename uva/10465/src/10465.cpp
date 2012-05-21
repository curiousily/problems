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
  for(int i = 0; i < upperLimit; i++)

#define FOREACH(var, upperLimit) \
  for(int var = 0; var < upperLimit; var++)

#define READINT ({int num;scanf("%d",&num);num;});
#define READUINT ({unsigned num;scanf("%u",&num);num;});
#define READLONG ({long num;scanf("%ld",&num);num;});
#define READSTRING ({string strLine; cin >> strLine; strLine;});
#define READLINE ({string strLine; getline(cin, strLine); strLine;});

#define NOT_COMPUTED -1

int M, N, T;

int Burgers[10010];

void
MaxBurgers()
{
  for(int i = 0; i <= T; i++)
  {
    Burgers[i] = NOT_COMPUTED;
  }
  Burgers[0] = 0;
  for (int i = min(M, N); i <= T; i++)
  {
    if (i >= N && Burgers[i - N] != NOT_COMPUTED)
    {
      Burgers[i] = max(Burgers[i], 1 + Burgers[i - N]);
    }
    if (i >= M && Burgers[i - M] != NOT_COMPUTED)
    {
      Burgers[i] = max(Burgers[i], 1 + Burgers[i - M]);
    }
  }
}

void
PrintBurgersAndBeerTime()
{
  int i = T;
  while(Burgers[i] == NOT_COMPUTED) i--;
  printf("%d %d\n", Burgers[i], T - i);
}

int
main()
{
#ifndef ONLINE_JUDGE
  close(0); open("in.txt", O_RDONLY);
//close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
  while (scanf("%d %d %d", &M, &N, &T) != EOF)
  {
    MaxBurgers();
    if (Burgers[T] != NOT_COMPUTED)
    {
      printf("%d\n", Burgers[T]);
    }
    else
    {
      PrintBurgersAndBeerTime();
    }
  }
  return 0;
}

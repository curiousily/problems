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

typedef unsigned long long ull;

ull Start, Finish;

bool
isEven(ull value)
{
  return value % 2 == 0;
}

ull
Ackermann(ull value)
{
  ull lenght = 0;
  ull curValue = value;
  if (isEven(curValue))
  {
    curValue = curValue / 2;
  }
  else
  {
    curValue = (3 * curValue) + 1;
  }
  lenght++;
  while (curValue != 1)
  {
    if (isEven(curValue))
    {
      curValue = curValue / 2;
    }
    else
    {
      curValue = (3 * curValue) + 1;
    }
    lenght++;
  }
  return lenght;
}

int
main()
{
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
  while (true)
  {
    scanf("%llu %llu", &Start, &Finish);
    if (Start == 0 && Finish == 0)
    {
      break;
    }
    if (Start > Finish)
    {
      swap(Start, Finish);
    }
    ull longestSequenceCount = 0;
    ull longestSequencePosition = 0;
    for (ull i = Start; i <= Finish; i++)
    {
      ull result = Ackermann(i);
      if (result > longestSequenceCount)
      {
        longestSequenceCount = result;
        longestSequencePosition = i;
      }
    }

    printf("Between %llu and %llu, %llu generates the longest sequence of %llu values.\n",
        Start, Finish, longestSequencePosition, longestSequenceCount);
  }
  return 0;
}

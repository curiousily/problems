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
#include <climits>

using namespace std;

#define FOR(upperLimit) \
  for(unsigned i = 0; i < upperLimit; i++)

#define FOREACH(var, upperLimit) \
  for(unsigned var = 0; var < upperLimit; var++)

#define READINT ({int num;scanf("%d",&num);num;});
#define READLONG ({long num;scanf("%ld",&num);num;});

#define MAX_ELEPHANTS 10001

struct Elephant
{
  int weight, iq, index;
};

vector<Elephant> Elephants;

int LengthTable[MAX_ELEPHANTS];
int ParentTable[MAX_ELEPHANTS];

int MaxIndex;

void
PrintElephants(int n)
{
  if (n < 0)
  {
    return;
  }
  PrintElephants(ParentTable[n]);
  printf("%d\n", Elephants[n].index);
}

int
FindElephants()
{
  unsigned length = Elephants.size();
  for (unsigned i = 0; i < length - 1; i++)
  {
    for (unsigned j = i + 1; j < length; j++)
    {
      if (Elephants[j].weight > Elephants[i].weight
          && LengthTable[i] + 1 > LengthTable[j])
      {
        LengthTable[j] = LengthTable[i] + 1;
        ParentTable[j] = i;
      }
    }
  }
  int maxLength = 0;
  FOREACH(i, length)
  {
    if (LengthTable[i] > maxLength)
    {
      maxLength = LengthTable[i];
      MaxIndex = i;
    }
  }
  return maxLength;
}

bool
SortByIQ(Elephant e1, Elephant e2)
{
  return e1.iq > e2.iq;
}

int
main()
{
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//          close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
  memset(ParentTable, -1, sizeof(ParentTable));
  int weight, iq, i = 0;
  while (scanf("%d %d\n", &weight, &iq) != EOF)
  {
    Elephant elephant;
    elephant.weight = weight;
    elephant.iq = iq;
    elephant.index = i + 1;
    Elephants.push_back(elephant);
    LengthTable[i] = 1;
    i++;
  }
  sort(Elephants.begin(), Elephants.end(), SortByIQ);
  printf("%d\n", FindElephants());
  PrintElephants(MaxIndex);
  return 0;
}

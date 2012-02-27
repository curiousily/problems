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

struct Box
{
  int height;
  int width, depth;

  int
  area()
  {
    return width * depth;
  }
};

vector<int> HeightTable;
vector<Box> Boxes;

bool
SortByDecreasingArea(Box b1, Box b2)
{
  return b1.area() > b2.area();
}

void
Init()
{
  HeightTable.clear();
  FOREACH(i, Boxes.size())
  {
    HeightTable.push_back(0);
  }
  sort(Boxes.begin(), Boxes.end(), SortByDecreasingArea);
  //    FOREACH(boxIndex, Boxes.size())
  //    {
  //      printf("area: %d\n", Boxes[boxIndex].area());
  //    }
}

bool CanBuildOnTop(unsigned j, unsigned i)
{
    return Boxes[j].width > Boxes[i].width && Boxes[j].depth > Boxes[i].depth;
}

int
FindMaximumHeight()
{
  Init();
  int maxFound = 0;
  for (unsigned i = 0; i < Boxes.size(); i++)
  {
    HeightTable[i] = Boxes[i].height;
    for (unsigned j = 0; j < i; j++)
    {
      if (CanBuildOnTop(j, i))
      {
        HeightTable[i] = max(HeightTable[i], HeightTable[j] + Boxes[i].height);
      }
      maxFound = max(maxFound, HeightTable[i]);
    }
  }
  return maxFound;
}

int MaxIndex;
int
main()
{
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//          close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif

  int testCase = 1;
  int n;
  while (scanf("%d\n", &n) && n != 0)
  {
    Boxes.clear();
    FOR(n)
    {
      int x1 = READINT;
      int x2 = READINT;
      int x3 = READINT;
      Box b;
      b.height = x1;
      b.width = x2;
      b.depth = x3;
      Boxes.push_back(b);
      b.height = x1;
      b.width = x3;
      b.depth = x2;
      Boxes.push_back(b);
      b.height = x2;
      b.width = x3;
      b.depth = x1;
      Boxes.push_back(b);
      b.height = x2;
      b.width = x1;
      b.depth = x3;
      Boxes.push_back(b);
      b.height = x3;
      b.width = x1;
      b.depth = x2;
      Boxes.push_back(b);
      b.height = x3;
      b.width = x2;
      b.depth = x1;
      Boxes.push_back(b);
    }
    printf("Case %d: maximum height = %d\n", testCase++, FindMaximumHeight());
  }
  return 0;
}

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

int Bottles;

int
MaxBottlesToDrink()
{
  int result = 0;
  int currentBottles = Bottles;
  while (currentBottles >= 3)
  {
    result += currentBottles - (currentBottles % 3);
    currentBottles = currentBottles / 3 + (currentBottles % 3);
  }
  if (currentBottles == 2)
  {
    return result + currentBottles + 1;
  }
  return result + currentBottles;
}

int
main()
{
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif

  while (scanf("%d\n", &Bottles) != EOF)
  {
    printf("%d\n", MaxBottlesToDrink());
  }
  return 0;
}

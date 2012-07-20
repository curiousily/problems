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

int
main()
{
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif

  double traveledSoFar = 0;
  double currentSpeed = 0;
  int lastChange = 0;
  string line;
  while (getline(cin, line))
  {
    if (line.find(" ") == string::npos)
    {
      int h, m, s;
      sscanf(line.c_str(), "%d:%d:%d", &h, &m, &s);
      int queryInSeconds = (h * 3600) + (m * 60) + s;
      int secondsTraveledSinceLastChange = queryInSeconds - lastChange;
      double result = currentSpeed * secondsTraveledSinceLastChange;
      traveledSoFar += (result / 1000);
      lastChange = queryInSeconds;
      cout << line;
      printf(" %.2f km\n", traveledSoFar);
    }
    else
    {
      int h, m, s, S;
      sscanf(line.c_str(), "%d:%d:%d %d", &h, &m, &s, &S);
      int queryInSeconds = (h * 3600) + (m * 60) + s;
      int secondsTraveledSinceLastChange = queryInSeconds - lastChange;

      lastChange = queryInSeconds;
      double result = currentSpeed * secondsTraveledSinceLastChange;
      traveledSoFar += (result / 1000);

      currentSpeed = ((((double) S) * 1000) / 3600);
    }
  }
  return 0;
}

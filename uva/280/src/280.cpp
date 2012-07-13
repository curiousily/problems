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

#define MAX_N 101

unsigned N;

vector<unsigned> Graph[MAX_N];
vector<unsigned> queryList;

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
    N = READINT;
    if (N == 0)
    {
      break;
    }
    FOREACH(i, N)
    {
      Graph[i].clear();
    }
    FOR(N)
    {
      int source = READINT;
      int destination = READINT;
      while (destination != 0)
      {
        Graph[source].push_back(destination);
        destination = READINT;
      }
    }
    READINT;
    queryList.clear();
    int queryCount = READINT;
    FOREACH(i, queryCount) {
      int queryNum = READINT;
      queryList.push_back(queryNum);
    }
  }
  return 0;
}


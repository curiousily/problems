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

#define MAX_N 105

int N;

vector<int> Graph[MAX_N];

bool Visited[MAX_N];

void DFS(int startNode, bool isStarting = false) {
  if(!isStarting) {
    Visited[startNode] = true;
  }
  vector<int> neighbours = Graph[startNode];
  FOREACH(i, neighbours.size()) {
    int neighbour = neighbours[i];
    if(!Visited[neighbour]) {
      DFS(neighbour);
    }
  }
}

void PrintInaccessableFrom(int queryNum) {
  FOREACH(i, N + 1) {
    Visited[i] = false;
  }
  Visited[0] = true;
  DFS(queryNum, true);
  vector<int> inaccessible;
  FOREACH(i, N + 1) {
    if(!Visited[i]) {
      inaccessible.push_back(i);
    }
  }
  printf("%d", inaccessible.size());
  FOREACH(i, inaccessible.size()) {
    printf(" %d", inaccessible[i]);
  }
  printf("\n");
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
    N = READINT;
    if (N == 0)
    {
      break;
    }
    FOREACH(i, MAX_N)
    {
      Graph[i].clear();
    }
    while(true) {
      int source = READINT;
      if(source == 0) { break;}
      int destination = READINT;
      while (destination != 0)
      {
        Graph[source].push_back(destination);
        destination = READINT;
      }
    }
    int queryCount = READINT;
    FOREACH(i, queryCount) {
      int queryNum = READINT;
      PrintInaccessableFrom(queryNum);
    }
  }
  return 0;
}


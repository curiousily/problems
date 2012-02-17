#include <fcntl.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>
#include <ctype.h>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define FOR(upperLimit) \
  for(unsigned i = 0; i < upperLimit; i++)

#define FOREACH(var, upperLimit) \
  for(unsigned var = 0; var < upperLimit; var++)

unsigned N, M;

struct Node
{
  int x, y;
  int weight;
};
bool visited[1000][1000];
int graph[1000][1000], index = 0;

int
main()
{
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//          close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif

  unsigned tc;
  scanf("%d\n", &tc);
  FOR(tc)
  {
    scanf("%d %d\n", &N, &M);
    FOREACH(row, N)
    {
      FOREACH(col, M)
      {
        scanf("%d", &graph[row][col]);
        visited[row][col] = false;
      }
    }
    Node startNode, endNode;
    startNode.x = 0;
    startNode.y = 0;
    startNode.weight = graph[0][0];
    queue<Node> nodes[10];
    nodes[index].push(startNode);
    while (true)
    {
      while (nodes[index].empty())
        index = (index + 1) % 10;
      if (visited[nodes[index].front().x][nodes[index].front().y])
      {
        nodes[index].pop();
        continue;
      }
      if (nodes[index].front().x == N - 1 && nodes[index].front().y == M - 1)
      {
        printf("%d\n", nodes[index].front().weight);
        break;
      }
      startNode = nodes[index].front();
      visited[startNode.x][startNode.y] = true;
      nodes[index].front();
      if (startNode.x + 1 < N)
      {
        endNode.x = startNode.x + 1;
        endNode.y = startNode.y;
        endNode.weight = startNode.weight + graph[endNode.x][endNode.y];
        if (!visited[endNode.x][endNode.y])
          nodes[(index + graph[endNode.x][endNode.y]) % 10].push(endNode);
      }
      if (startNode.y + 1 < M)
      {
        endNode.x = startNode.x;
        endNode.y = startNode.y + 1;
        endNode.weight = startNode.weight + graph[endNode.x][endNode.y];
        if (!visited[endNode.x][endNode.y])
          nodes[(index + graph[endNode.x][endNode.y]) % 10].push(endNode);
      }
      if (startNode.x - 1 >= 0)
      {
        endNode.x = startNode.x - 1;
        endNode.y = startNode.y;
        endNode.weight = startNode.weight + graph[endNode.x][endNode.y];
        if (!visited[endNode.x][endNode.y])
          nodes[(index + graph[endNode.x][endNode.y]) % 10].push(endNode);
      }
      if (startNode.y - 1 >= 0)
      {
        endNode.x = startNode.x;
        endNode.y = startNode.y - 1;
        endNode.weight = startNode.weight + graph[endNode.x][endNode.y];
        if (!visited[endNode.x][endNode.y])
          nodes[(index + graph[endNode.x][endNode.y]) % 10].push(endNode);
      }
    }
  }
  return 0;
}


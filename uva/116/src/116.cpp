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

int Parents[15][105];
int Matrix[15][105];
int Memo[15][105];

int Rows, Columns;

int FindMinimumWeight(int row, int column) {
  if(column > Columns) {
    return 0;
  }

  if(Memo[row][column] != NOT_COMPUTED) {
    return Memo[row][column];
  }

  vector<int> ways;

  int nextColumn = column + 1;

  int nextStraight = Matrix[row][column] + FindMinimumWeight(row, nextColumn);
  ways.push_back(nextStraight);

  int downRow = row + 1 > Rows ? 1 : row + 1;
  int nextDown = Matrix[downRow][column] + FindMinimumWeight(downRow, nextColumn);
  ways.push_back(nextDown);

  int upRow = row - 1 > 0 ? row - 1 : Rows;
  int nextUp = Matrix[upRow][column] + FindMinimumWeight(upRow, nextColumn);
  ways.push_back(nextUp);

  int minElement = *min_element(ways.begin(), ways.end());

  return Memo[row][column] = minElement;
}

int
main()
{
#ifndef ONLINE_JUDGE
  close(0); open("in.txt", O_RDONLY);
//close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
  while (scanf("%d %d\n", &Rows, &Columns) != EOF)
  {
    FOREACH(i, Rows) {
      FOREACH(j, Columns) {
        Parents[i + 1][j + 1] = NOT_COMPUTED;
        Memo[i + 1][j + 1] = NOT_COMPUTED;
        Matrix[i + 1][j + 1] = READINT;
      }
    }
    int pathStart = 0;
    int minWeight = INT_MAX;
    FOREACH(i, Rows) {
      int localMin = FindMinimumWeight(i + 1, 1);
      if(localMin < minWeight) {
        pathStart = i + 1;
        minWeight = localMin;
      }
    }
    int row = pathStart;
    FOREACH(column, Columns - 1) {
      printf("%d ", Parents[row][column + 1]);
    }
    printf("%d\n", Parents[row][Columns]);
    printf("%d\n", minWeight);
  }
  return 0;
}

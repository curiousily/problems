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

int Matrix[15][105];

int Rows, Columns;

int FindMinimumWeight(int row, int column) {
  if(column > Columns) {
    return 0;
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

  return *min_element(ways.begin(), ways.end());;
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
        Matrix[i + 1][j + 1] = READINT;
      }
    }
    int minWeight = INT_MAX;
    FOREACH(i, Rows) {
       minWeight = min(minWeight, FindMinimumWeight(i + 1, 1));
    }
    printf("%d\n", minWeight);
  }
  return 0;
}

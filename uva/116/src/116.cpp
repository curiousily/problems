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

int Rows, Columns, Parents[15][102];
void
print(int row, int column)
{

  if (column != Columns - 1)
  {
    printf("%d ", row + 1);
    print(Parents[row][column], column + 1);
  }
  else
  {
    printf("%d\n", row + 1);
  }
}
int
main()
{
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
  while (scanf("%d %d", &Rows, &Columns) != EOF)
  {
    int Matrix[Rows][Columns];
    int Memo[Rows][Columns];

    FOREACH(row, Rows)
    {
      FOREACH(column, Columns)
      {
        Matrix[row][column] = READINT;
        Memo[row][column] = INT_MAX;
      }
    }

    FOREACH(row, Rows)
    {
      Memo[row][Columns - 1] = Matrix[row][Columns - 1];
    }

    for (int column = Columns - 2; column >= 0; --column)
    {
      FOREACH(row, Rows)
      {
        for (int way = -1; way <= 1; ++way)
        {
          int currentWay = (row + way + Rows) % Rows;
          int cellValue = Matrix[row][column];
          if (Memo[row][column] >= cellValue + Memo[currentWay][column + 1])
          {
            if (Memo[row][column] > cellValue + Memo[currentWay][column + 1]
                || Parents[row][column] == NOT_COMPUTED
                || Parents[row][column] > currentWay)
              Parents[row][column] = currentWay;
            Memo[row][column] = cellValue + Memo[currentWay][column + 1];
          }
        }
      }
    }

    int minWeight = 0;
    FOREACH(row, Rows)
    {
      if (Memo[minWeight][0] > Memo[row][0])
        minWeight = row;
    }
    print(minWeight, 0);
    printf("%d\n", Memo[minWeight][0]);
  }
  return 0;
}


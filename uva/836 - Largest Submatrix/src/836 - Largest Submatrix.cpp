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
#define READLINE ({string strLine; cin >> strLine; strLine;});

int Matrix[101][101];

void
ReadRow(string & strLine, int row, unsigned n)
{
  FOREACH(i, n)
  {
    int col = i;
    char charNum = strLine[i];
    int num = atoi(&charNum);
    Matrix[row][col] = num;
  }
}

int
SUM(unsigned si, unsigned sj, unsigned ei, unsigned ej)
{
  int res = Matrix[ei][ej];
  if (sj - 1 >= 0)
    res -= Matrix[ei][sj - 1];
  if (si - 1 >= 0)
    res -= Matrix[si - 1][ej];
  if (si - 1 >= 0 && sj - 1 >= 0)
    res += Matrix[si - 1][sj - 1];
  return res;
}

int
main()
{
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//          close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif

  unsigned caseCount = READINT;
  int tc = 0;
  FOR(caseCount)
  {
    string emptyLine = READLINE;
    string strLine = READLINE;
    unsigned n = strLine.size();
    ReadRow(strLine, 0, n);
    int row = 1;
    while (!strLine.empty())
    {
      ReadRow(strLine, row, n);
      strLine = READLINE;
      row++;
    }

    unsigned i, j;
    for (i = 0; i < n; i++)
      for (j = 1; j < n; j++)
        Matrix[i][j] += Matrix[i][j - 1];
    for (i = 0; i < n; i++)
      for (j = 1; j < n; j++)
        Matrix[j][i] += Matrix[j - 1][i];
    unsigned y, x, maxFound;
    maxFound = 0;
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        for (y = i; y < n; y++)
          for (x = j; x < n; x++)
            if (SUM(i, j, y, x) == (y - i + 1) * (x - j + 1))
              maxFound = max(maxFound, (y - i + 1) * (x - j + 1));
    if (tc++)
    {
      printf("\n");
    }
    printf("%d\n", maxFound);
  }
  return 0;
}

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
  for(unsigned i = 0; i < upperLimit; i++)

#define FOREACH(var, upperLimit) \
  for(unsigned var = 0; var < upperLimit; var++)

#define READINT ({int num;scanf("%d",&num);num;});
#define READUINT ({unsigned num;scanf("%u",&num);num;});
#define READLONG ({long num;scanf("%ld",&num);num;});
#define READSTRING ({string strLine; cin >> strLine; strLine;});
#define READLINE ({string strLine; getline(cin, strLine); strLine;});

vector<int> InputSequence;

vector<int>
LisLengths(vector<int> & sequence)
{
  vector<int> lengths(sequence.size());
  int temp[sequence.size()];
  int maxLength = 1, lowerBound;
  lengths[0] = 1, temp[0] = sequence[0];

  for (unsigned i = 1; i < sequence.size(); i++)
  {
    lowerBound = lower_bound(temp, temp + maxLength, sequence[i]) - temp;
    lengths[i] = lowerBound + 1;
    if (lowerBound == maxLength)
      temp[maxLength++] = sequence[i];
    else
      temp[lowerBound] = sequence[i];
  }
  return lengths;
}

int
LenghtOfLongestWavioSequence()
{
  vector<int> lisLengths = LisLengths(InputSequence);
  reverse(InputSequence.begin(), InputSequence.end());
  vector<int> ldsLengths = LisLengths(InputSequence);
  reverse(ldsLengths.begin(), ldsLengths.begin() + InputSequence.size());

  int maxFound = -1;
  for (unsigned i = 0; i < InputSequence.size(); i++)
    maxFound = max(maxFound, min(lisLengths[i], ldsLengths[i]));

  return (maxFound * 2) - 1;
}

int
main()
{
#ifndef ONLINE_JUDGE
  close(0);
  open("in.txt", O_RDONLY);
//          close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif

  unsigned sequenceCount;
  while (scanf("%u\n", &sequenceCount) != EOF)
  {
    InputSequence.clear();
    FOR(sequenceCount)
    {
      int num = READINT;
      InputSequence.push_back(num);
    }
    printf("%d\n", LenghtOfLongestWavioSequence());
  }
  return 0;
}

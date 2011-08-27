/*
ID: v.valko1
PROG: holstein
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int vitaminCount, feedCount;

vector<int> req;
int feeds[30][30];

int minFeedsFound;
int bestFeed[30];
int currentFeed[30];

void FindFeed(int feedsTaken, int nextFeed)
{
    int i;

    for (i = 0; i < vitaminCount; i++)
        if (req[i] > 0) break;
    if (i >= vitaminCount)
    {
        minFeedsFound = feedsTaken;
        for (i = 0; i < minFeedsFound; i++)
            bestFeed[i] = currentFeed[i];
        return;
    }

    while (nextFeed < feedCount && feedsTaken + 1 < minFeedsFound)
    {
        for (i = 0; i < vitaminCount; i++)
            req[i] -= feeds[nextFeed][i];
        currentFeed[feedsTaken] = nextFeed;

        FindFeed(feedsTaken+1, nextFeed+1);

        for (i = 0; i < vitaminCount; i++)
            req[i] += feeds[nextFeed][i];

        nextFeed++;
    }
}

int main()
{
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);

    scanf("%d\n", &vitaminCount);
    req.resize(vitaminCount + 1);
    for(unsigned i = 0; i < vitaminCount; i++)
        scanf("%d", &req[i]);

    scanf("%d\n", &feedCount);
    for(unsigned i = 0; i < feedCount; i++)
        for(unsigned j = 0; j < vitaminCount; j++)
            scanf("%d", &feeds[i][j]);

    minFeedsFound = feedCount + 1;
    FindFeed(0, 0);
    printf("%d", minFeedsFound);
    for(unsigned i = 0; i < minFeedsFound; i++)
        printf(" %d", bestFeed[i] + 1);
    printf("\n");
    return 0;
}

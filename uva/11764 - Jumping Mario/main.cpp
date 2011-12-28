#include <fcntl.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <ctype.h>
#include <algorithm>
#include <set>

using namespace std;

int tc;

int main()
{
    #ifndef ONLINE_JUDGE
        close (0); open ("in.txt", O_RDONLY);
        close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
    #endif

    scanf("%d", &tc);
    int walls[51];
    int caseNum = 1;
    for(unsigned i = 0; i < tc; i++) {
        int n;
        scanf("%d", &n);
        int highJumps = 0, lowJumps = 0;
        int prev;
        scanf("%d", &prev);
        int cur;
        for(unsigned j = 1; j < n; j++) {
            scanf("%d", &cur);
            if(cur > prev) {
                highJumps++;
            }
            if(cur < prev) {
                lowJumps++;
            }
            prev = cur;
        }
        printf("Case %d: %d %d\n", caseNum, highJumps, lowJumps);
        caseNum++;
    }
    return 0;
}

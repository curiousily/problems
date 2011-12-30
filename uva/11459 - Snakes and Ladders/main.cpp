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

int main()
{
    #ifndef ONLINE_JUDGE
        close (0); open ("in.txt", O_RDONLY);
//        close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
    #endif

    int tc;
    scanf("%d\n", &tc);
    int playerCount, objectCount, rollCount;
    map<int, int> snakes, ladders;
    int p1, p2;
    int dieRow;
    while(tc--) {
        snakes.clear();
        ladders.clear();
        scanf("%d %d %d\n", &playerCount, &objectCount, &rollCount);
        while(objectCount--) {
            scanf("%d %d\n", &p1, &p2);
            // snake
            if(p1 > p2) {
                snakes[p1] = p2;
            }
            // ladder
            if(p1 < p2) {
                ladders[p1] = p2;
            }
        }
        vector<int> playerPositions;
        for(int i = 0; i < playerCount; i++) {
            playerPositions.push_back(1);
        }
        if(ladders.find(0) != ladders.end()) {
            for(unsigned i = 0; i < playerCount; i++) {
                playerPositions[i] = ladders[0];
            }
        }
        bool gameFinished = false;
        for(unsigned i = 0; i < rollCount; i++) {
            scanf("%d\n", &dieRow);
            // we should still read the rolls
            if(gameFinished) {
                continue;
            }
            int currentPlayer = i % playerCount;
            int currentPlayerPosition = playerPositions[currentPlayer];
            int newPlayerPosition = currentPlayerPosition + dieRow;
            if(newPlayerPosition >= 100) {
                playerPositions[currentPlayer] = 100;
                gameFinished = true;
                continue;
            }
            // is on snake
            if(snakes.find(newPlayerPosition) != snakes.end()) {
                newPlayerPosition = snakes[newPlayerPosition];
            }

            // is on ladder
            if(ladders.find(newPlayerPosition) != ladders.end()) {
                newPlayerPosition = ladders[newPlayerPosition];
            }
            if(newPlayerPosition >= 100) {
                playerPositions[currentPlayer] = 100;
                gameFinished = true;
                continue;
            } else {
                playerPositions[currentPlayer] = newPlayerPosition;
            }


        }
        for(unsigned i = 0; i < playerCount; i++) {
            printf("Position of player %d is %d.\n", i + 1, playerPositions[i]);
        }

    }
    return 0;
}

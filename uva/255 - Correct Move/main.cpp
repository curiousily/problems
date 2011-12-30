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
    close (0);
    open ("in.txt", O_RDONLY);
//        close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
    int board[8][8];
    int num = 0;
    for(unsigned i = 0; i < 8; i++)
        for(unsigned j = 0; j < 8; j++)
        {
            board[i][j] = num;
            num++;
        }
    int q, k, move;
    while(scanf("%d %d %d\n", &k, &q, &move) != EOF)
    {
//        printf("%d %d %d\n", k, q, move);
        if(q == k)
        {
            printf("Illegal state\n");
            continue;
        }
        if(move == q || move == k)
        {
            printf("Illegal move\n");
            continue;
        }
        bool notBlockedByKnight = true;
        int qRow = q / 8;
        int kRow = k / 8;
        int moveRow = move / 8;
        bool queenOnMoveRow = moveRow == qRow;
        bool knightOnMoveRow = kRow == moveRow;
        // move to the right of the knight
        if(queenOnMoveRow && knightOnMoveRow && move > q && move > k)
        {
            notBlockedByKnight = false;
        }
        // move to the left of the knight
        if(queenOnMoveRow && knightOnMoveRow && move < q && move < k)
        {
            notBlockedByKnight = false;
        }

//        printf("not blocked %d\n", notBlockedByKnight);
        bool onColumn = false;
        int qTemp = q;
        bool knightOnSameCol = false;
        while(qTemp >= 0)
        {
//            printf("col val %d\n", qTemp);
            if(qTemp == move)
            {
                onColumn = true;
            }
            if(qTemp == k) {
                knightOnSameCol = true;
            }
            qTemp -= 8;
        }
        qTemp = q;
        while(qTemp <= 63)
        {
//            printf("col val %d\n", qTemp);
            if(qTemp == move)
            {
                onColumn = true;
            }
            if(qTemp == k) {
                knightOnSameCol = true;
            }
            qTemp += 8;
        }
        // move above knight
        if(onColumn && knightOnSameCol && move < k && move < q)
        {
            notBlockedByKnight = false;
        }
        // move below knight
        if(onColumn && knightOnSameCol && move > k && move > q)
        {
            notBlockedByKnight = false;
        }
        if((queenOnMoveRow || onColumn) && notBlockedByKnight)
        {
            bool moveNotAllowed = false;
            if(k - 8 == move)
            {
                moveNotAllowed = true;
            }
            if(k + 8 == move)
            {
                moveNotAllowed = true;
            }
            if(k + 1 == move)
            {
                moveNotAllowed = true;
            }
            if(k - 1 == move)
            {
                moveNotAllowed = true;
            }
            if(moveNotAllowed)
            {
                printf("Move not allowed\n");
                continue;
            }
            if(move==49&&k==56||move==14&&k==7||move==9&&k==0||move==54&&k==63)
            {
                printf("Stop\n");
            }
            else
            {
                printf("Continue\n");
            }

        }
        else
        {
            printf("Illegal move\n");
            continue;
        }
    }
    return 0;
}


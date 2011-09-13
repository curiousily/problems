/*
ID: v.valko1
PROG: runround
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#include <set>
#include <queue>
#include <climits>

using namespace std;


int NextNumber(string & str, int startDigit) {
    char ch = (char) startDigit + 48;
    string digitString;
    digitString.push_back(ch);
    int startPos = str.find(digitString);
    int nextNumberPos = startDigit + startPos;
    nextNumberPos %= str.size();
//    printf("Should go to %d\n", nextNumberPos);
//    printf("Which is %c\n", str[nextNumberPos]);
    return str[nextNumberPos] - 48;
}

string NumToString(unsigned long num) {
    string res;
    do {
        const char ch = (num % 10) + 48;
        res.push_back(ch);
        num /= 10;
    } while(num > 0);
    reverse(res.begin(), res.end());
//    printf("%s\n", res.c_str());
    return res;
}

bool IsRunAround(unsigned long num) {

    string numString = NumToString(num);
    size_t found = numString.find("0");
    if(found != string::npos) return false;
//    const size_t size = numString.size();
    bitset<10> used;
    int digitsLeft = numString.size();
    int startDigit = numString[0] - 48;
    used[startDigit] = true;
    digitsLeft--;
//    printf("Starting with: %d\n", startDigit);
    while(digitsLeft >= 0) {
        startDigit = NextNumber(numString, startDigit);
//        printf("Starting with: %d\n", startDigit);
        if(digitsLeft == 0 && used[startDigit] && startDigit == numString[0] - 48) {
//            printf("Case \n");
            return true;
        }
        if(used[startDigit]) return false;
        digitsLeft--;
        used[startDigit] = true;
    }
    return true;
}

int main() {

    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
    unsigned long m;
    scanf("%udl\n", &m);
    m++;
    while(!IsRunAround(m)) {
        m++;
//        printf("%ul\n", m);
    }
    printf("%u\n", m);
//    printf("%d\n", IsRunAround(81362));
//    printf("%d\n", m);

//    string number = NumToString(m);
//    for(int i = 0; i < number.size(); i++)
//        printf("%d : %c\n",i,  number[i]);
//    printf("\n");
//    printf("%d\n", NextNumber(number, 6));
    return 0;
}

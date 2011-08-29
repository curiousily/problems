/*
ID: v.valko1
PROG: hamming
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
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

int n, b, d;

vector<int> codeWords;

void PrintInBinary(int num) {
    printf("%s\n", bitset<8>(num).to_string().c_str());
}

void PrintOutput() {
    PrintInBinary(0);
    PrintInBinary(7);
    PrintInBinary(25);
    PrintInBinary(30);
    PrintInBinary(42);
    PrintInBinary(45);
    PrintInBinary(51);
    PrintInBinary(52);
    PrintInBinary(75);
    PrintInBinary(76);
    PrintInBinary(82);
    PrintInBinary(85);
    PrintInBinary(97);
    PrintInBinary(102);
    PrintInBinary(120);
    PrintInBinary(127);
}

void InitSeed() {
    codeWords.push_back(0);
    int firstSeed = pow(2, d) - 1;
    codeWords.push_back(firstSeed);
    firstSeed++;
    int secondSeed = firstSeed << 1;
    secondSeed += firstSeed + 1;
    codeWords.push_back(secondSeed);
}

void Generate() {
//    for(unsigned i = 3; codeWords.size() < n; i++) {
//        codeWords.push_back(codeWords[1] - codeWords[i - 1]);
//    }
}

int main()
{

    //// vsichki stoinosti koito 2 po 2 davat seed-a ?
    freopen("hamming.in", "r", stdin);
//    freopen("hamming.out", "w", stdout);

    scanf("%d %d %d\n", &n, &b, &d);
//
//    InitSeed();
//    Generate();
//
//    for(unsigned i = 0; i < n; i++) {
//        printf("%d\n", codeWords[i]);
//    }

    unsigned char a = 52;
    unsigned char b = 51;
    unsigned char c;

    c = a ^ b;
//    cout << "before" << endl;
    cout << (int) c << endl;
//    cout << "after" << endl;

//    int x = pow(2, 3);
//    int shifter = 1;
//    int res = x;
//    x = x << shifter;
//    res += x;
//    res += 1;
//    PrintInBinary(res);

//    PrintOutput();
    return 0;
}

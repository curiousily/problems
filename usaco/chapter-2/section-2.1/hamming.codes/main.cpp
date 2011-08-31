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
//    firstSeed++;
//    int secondSeed = firstSeed << 1;
//    secondSeed += firstSeed + 1;
//    codeWords.push_back(secondSeed);
}

void Generate() {
//    for(unsigned i = 3; codeWords.size() < n; i++) {
//        codeWords.push_back(codeWords[1] - codeWords[i - 1]);
//    }
}

unsigned Distance(unsigned a, unsigned b) {
    unsigned dist = 0, val = a ^ b;
    while(val)
    {
        ++dist;
        val &= val - 1;
    }
    return dist;
}

void FindNext(int start) {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    bool flag = false;
    for(unsigned i = start; i < 1000 ;i++) {
        a = i;
        for(unsigned j = start; j < 1000; j++) {
            b = j;
            c = a ^ b;
            if(((int) c) == 7 && Distance(a, 7) >= 3 && Distance(b, 7) >= 3) {
                codeWords.push_back(a);
                codeWords.push_back(b);
                flag = true;
                break;
//                PrintInBinary(a);
//                PrintInBinary(b);
//                printf("dista=%d distb=%d a=%d b=%d c=%d\n", Distance(a, 7), Distance(b, 7), a, b, (int) c);
            }

        }
        if(flag) break;
    }
}

int main()
{

    //// vsichki stoinosti koito 2 po 2 davat seed-a ?
    freopen("hamming.in", "r", stdin);
//    freopen("hamming.out", "w", stdout);

    scanf("%d %d %d\n", &n, &b, &d);
//
    InitSeed();
//    Generate();
//
//    for(unsigned i = 0; i < n; i++) {
//        printf("%d\n", codeWords[i]);
//    }

    unsigned char a = 52;
    unsigned char b = 51;
    unsigned char c;

    int start = 1;
    int index = 1;
    while(codeWords.size() < n) {
        printf("Starting with %d\n", start);
        FindNext(codeWords[start]);
        index += 2;
        printf("Back is %d\n", codeWords[index]);
        start = codeWords.back() + 1;
    }

    for(unsigned i = 0; i < codeWords.size(); i++) {
//        PrintInBinary(codeWords[i]);
//        printf("%d\n", codeWords[i]);
    }

//    cout << ((int) 7 ^ 15) << endl;

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


//    FindNext(8);

//    PrintInBinary(7);
//    bool flag = false;
//    for(unsigned i = 8; i < 31 ;i++) {
//        a = i;
//        for(unsigned j = 8; j < 31; j++) {
//            b = j;
//            c = a ^ b;
//            if(((int) c) == 7 && Distance(a, 7) >= 3 && Distance(b, 7) >= 3) {
//                codeWords.push_back(a);
//                codeWords.push_back(b);
//                flag = true;
//                break;
////                PrintInBinary(a);
////                PrintInBinary(b);
////                printf("dista=%d distb=%d a=%d b=%d c=%d\n", Distance(a, 7), Distance(b, 7), a, b, (int) c);
//            }
//
//        }
//        if(flag) break;
//    }
//

//    FindNext(31);
//    flag = false;
//    for(unsigned i = 31; i < 46 ;i++) {
//        a = i;
//        for(unsigned j = 31; j < 46; j++) {
//            b = j;
//            c = a ^ b;
//            if(((int) c) == 7 && Distance(a, 7) >= 3 && Distance(b, 7) >= 3) {
//                codeWords.push_back(a);
//                codeWords.push_back(b);
//                flag = true;
//                break;
////                PrintInBinary(a);
////                PrintInBinary(b);
////                printf("dista=%d distb=%d a=%d b=%d c=%d\n", Distance(a, 7), Distance(b, 7), a, b, (int) c);
//            }
//
//        }
//        if(flag) break;
//    }


//    FindNext(46);

//    flag = false;
//    for(unsigned i = 46; i < 53 ;i++) {
//        a = i;
//        for(unsigned j = 46; j < 53; j++) {
//            b = j;
//            c = a ^ b;
//            if(((int) c) == 7 && Distance(a, 7) >= 3 && Distance(b, 7) >= 3) {
//                codeWords.push_back(a);
//                codeWords.push_back(b);
//                flag = true;
//                break;
////                PrintInBinary(a);
////                PrintInBinary(b);
////                printf("dista=%d distb=%d a=%d b=%d c=%d\n", Distance(a, 7), Distance(b, 7), a, b, (int) c);
//            }
//
//        }
//        if(flag) break;
//    }

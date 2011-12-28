/*
ID: v.valko1
PROG: prefix
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

vector<string> primitives;
string seq;
unsigned seqLength;
int maxLength = 0;

void Solve(string & genSeq, int length) {
    if(length > maxLength) {
        maxLength = length;
    }
}

int main()
{

    freopen("prefix.in", "r", stdin);
//    freopen("prefix.out", "w", stdout);
    string primitive;
    while(cin >> primitive && primitive != ".") {
        primitives.push_back(primitive);
//        printf("%s\n", primitive.c_str());
    }
    cin >> seq;
    seqLength = seq.size();
    return 0;
}

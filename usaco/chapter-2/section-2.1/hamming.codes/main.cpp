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

vector<string> codewords;

int main()
{
    freopen("hamming.in", "r", stdin);
//    freopen("hamming.out", "w", stdout);

    scanf("%d %d %d\n", &n, &b, &d);

    int a = 0;
    string rep = bitset<8>(a).to_string();
    cout << rep << endl;

    return 0;
}

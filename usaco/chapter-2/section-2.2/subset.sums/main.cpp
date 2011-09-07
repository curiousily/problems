/*
ID: v.valko1
PROG: subset
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

int main() {

    freopen("subset.in", "r", stdin);
//    freopen("subset.out", "w", stdout);
    int n;
    scanf("%d\n", &n);
    vector<int> numsToUse;
    for(unsigned i = 1; i <= n; i++)
        numsToUse.push_back(i);
    return 0;
}

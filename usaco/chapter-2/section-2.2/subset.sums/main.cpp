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

int n;
//vector<int> values;
//bool used[40];
//int subsetSum;

int AlgebraicProgressionTo(int num) {
    return (num * (num + 1)) / 2;
}

bool IsOdd(int num) {
    return num % 2 != 0;
}

//void Init() {
//    values.push_back(0);
//    for(int i = 1; i <= n; i++)
//        values.push_back(i);
//    for(int i = 1; i <= n; i++) used[false];
//}

//int solutionCount = 0;
//int solutionSum = 0;
long long m[50][10000];

long long Func(int ns, long s) {
    if(ns == 0) {
        if(s == 0) return 1;
        return 0;
    }
    if(abs(s) > AlgebraicProgressionTo(ns)) {
        return 0;
    }
    if(m[ns - 1][s - ns] == - 1) {
        m[ns - 1][s - ns] = Func(ns - 1, s - ns);
    }
    if(m[ns - 1][s + ns] == - 1) {
        m[ns - 1][s + ns] = Func(ns - 1, s + ns);
    }
    return m[ns - 1][s - ns] + m[ns - 1][s + ns];
//    return Func(n - 1, s - n) + Func(n - 1, s + n);
}

//void Solve(int nextElement) {
//
////    for(int i = 1; i <= n; i++) {
////        if(used[i])
////            printf("%d ", i);
////
////    }
////    printf("\n");
//
//    if(solutionSum == subsetSum) {
//        solutionCount++;
//        return;
//    }
//    for(int i = nextElement; i >= 1; i--) {
//        int sumToFill = subsetSum - solutionSum;
//        if(AlgebraicProgressionTo(i) < sumToFill) return;
//
//
//        if(!used[i]) {
//            if(solutionSum + i > subsetSum) {
//                continue;
//            }
//
//            used[i] = true;
//            solutionSum += i;
//            Solve(i);
//            used[i] = false;
//            solutionSum -= i;
//        }
//    }
//}
//
//void Solve() {
//    used[values.back()] = true;
//    solutionSum = values.back();
//    int nextElement = values.back() - 1;
//    Solve(nextElement);
//}

int main() {

    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);

    scanf("%d\n", &n);
    int sum = AlgebraicProgressionTo(n);
    if(IsOdd(sum)) {
        printf("0\n");
        return 0;
    }
    for(unsigned i = 0; i < 50; i++)
        for(unsigned j = 0; j < 10000; j++)
            m[i][j] = -1;
    long result = Func(n, 0) / 2;
    cout << result << endl;
//    printf("%d\n", result);
//    subsetSum = sum / 2;
//    Init();
//    Solve();
//    printf("%d\n", solutionCount);
    return 0;
}

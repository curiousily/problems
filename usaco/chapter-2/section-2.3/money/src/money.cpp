/*
 ID: v.valko1
 PROG: money
 LANG: C++
 */

#include <fcntl.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctype.h>
#include <algorithm>
#include <set>
#include <queue>
#include <climits>

using namespace std;

#define FOR(upperLimit) \
  for(unsigned i = 0; i < upperLimit; i++)

#define FOREACH(var, upperLimit) \
  for(unsigned var = 0; var < upperLimit; var++)

#define READINT ({int num;scanf("%d",&num);num;});
#define READLONG ({long num;scanf("%ld",&num);num;});
#define READSTRING ({string strLine; cin >> strLine; strLine;});
#define READLINE ({string strLine; getline(cin, strLine); strLine;});

#define MAX_COINS 27
#define MAX_SUM 10002

long long Memo[MAX_SUM];

bool Exist[MAX_SUM] = { 0 };

int CoinCount, Sum;
vector<int> Coins;

void ReadInput() {
	CoinCount = READINT;
	Sum = READINT;
	int coin;
	FOREACH(i, CoinCount) {
		coin = READINT;
		Coins.push_back(coin);
	}
}

void FindDifferentWaysToSum() {
	Memo[0] = 1;
	FOREACH(i, Coins.size()) {
		int coin = Coins[i];
		for (int j = coin; j <= Sum; j++) {
			Memo[j] += Memo[j - coin];
		}
	}
}

int main() {

	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);

	ReadInput();
	FindDifferentWaysToSum();

	printf("%lld\n", Memo[Sum]);

	return 0;
}

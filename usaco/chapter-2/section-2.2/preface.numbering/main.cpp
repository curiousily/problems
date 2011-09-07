/*
ID: v.valko1
PROG: preface
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

const string romanOneToNine[] = {"", "A", "AA", "AAA", "AB", "B", "BA", "BAA", "BAAA", "AC"};
const string romanDigits[] = {"IVX", "XLC", "CDM", "M" };

string GetRomanDigit(unsigned num, unsigned power)
{
	string result = "";
	string digit = romanOneToNine[num];
	for(unsigned i = 0; i < digit.size(); i++) {
      result.push_back(romanDigits[power][digit[i] - 'A']);
	}
  return result;
}

string DecimalToRoman(unsigned num)
{
	unsigned power;
  string result = "";
  for (power = 0; num > 0; power++, num /= 10) {
      result.insert(0, GetRomanDigit(num % 10, power));
  }
  return result;
}

int main() {

    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
    int n;
    scanf("%d\n", &n);
    int res[8];
    for(unsigned i = 1; i <= 7; i++)
        res[i] = 0;
    for(unsigned i = 1; i <= n; i++) {
        string roman = DecimalToRoman(i);
        for(unsigned j = 0; j < roman.size(); j++) {
            char ch = roman[j];
            if(ch == 'I')
                res[1]++;
            else if(ch == 'V')
                res[2]++;
            else if(ch == 'X')
                res[3]++;
            else if(ch == 'L')
                res[4]++;
            else if(ch == 'C')
                res[5]++;
            else if(ch == 'D')
                res[6]++;
            else if(ch == 'M')
                res[7]++;
        }
    }
    if(res[1] > 0) {
        printf("I %d\n", res[1]);
    }
    if(res[2] > 0) {
        printf("V %d\n", res[2]);
    }
    if(res[3] > 0) {
        printf("X %d\n", res[3]);
    }
    if(res[4] > 0) {
        printf("L %d\n", res[4]);
    }
    if(res[5] > 0) {
        printf("C %d\n", res[5]);
    }
    if(res[6] > 0) {
        printf("D %d\n", res[6]);
    }
    if(res[7] > 0) {
        printf("M %d\n", res[7]);
    }
    return 0;
}

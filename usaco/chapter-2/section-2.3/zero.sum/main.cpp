/*
ID: v.valko1
PROG: zerosum
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
vector<char> chars;

vector<string> result;

void Solve(int i)
{
    if(i == n - 1)
    {
        vector<int> nums;
        bool hasEmpty = false;
        for(unsigned j = 0; j < chars.size(); j++)
            if(chars[j] == ' ') hasEmpty = true;
        if(hasEmpty) {
            for(unsigned j = 0; j < n; j++)
                if(chars[j] == ' ') {
                    hasEmpty = true;
                    int joined = (j + 1) * 10 + (j + 2);
                    nums.push_back(joined);
                    j++;
                }
                else {
                    nums.push_back(j + 1);
                }
        }
        else
            for(unsigned j = 1; j <= n; j++)
                nums.push_back(j);

        int sum = nums[0];
        int charIndex = 0;
//            for(unsigned k = 0; k < nums.size(); k++)
//                printf("%d ", nums[k]);
//            printf("\n");
        for(unsigned j = 0; j < chars.size(); j++)
        {
            if(chars[j] == ' ') continue;
            charIndex++;
            int num = nums[charIndex];

            if(chars[j] == '+')
                sum += num;
            else if(chars[j] == '-')
                sum -= num;
        }

        if(sum == 0)
        {
//            printf("Sum is %d\n", sum);
//            printf("Char size %d\n", chars.size());
            string seq;
            for(unsigned k = 1; k < n; k++)
            {
//                    printf("%d%c", k, chars[k - 1]);
//                    printf("\n it is %c, should be %d\n", (char) k + 48, k);
                  seq.push_back((char) k + 48);
                  seq.push_back(chars[k - 1]);
            }
            seq.push_back((char) n + 48);
            result.push_back(seq);
//            printf("%d\n", n);
        }
        return;
    }

    chars[i] = '+';
    Solve(i + 1);
    chars[i] = '-';
    Solve(i + 1);
    if(i - 1 >= 0 && chars[i - 1] == ' ') {
        return;
    }
            chars[i] = ' ';
        Solve(i + 1);

}

int main()
{

    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);

    scanf("%d", &n);
    chars.resize(n - 1);
    Solve(0);
    sort(result.begin(), result.end());
    for(unsigned i = 0; i < result.size(); i++)
        printf("%s\n", result[i].c_str());
    return 0;
}

/*
ID: v.valko1
PROG: lamps
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXLAMP 6
#define LAMPMASK ((1<<MAXLAMP)-1)

int nlamp;
int nswitch;
int ison;
int known;

int poss[1<<MAXLAMP];

int flip[4] = {
    LAMPMASK,  /* flip all lights */
    LAMPMASK & 0xAA,  /* flip odd lights */
    LAMPMASK & 0x55, /* flip even lights */
    LAMPMASK & ((1<<(MAXLAMP-1))|(1<<(MAXLAMP-4))) /* lights 1, 4 */
};

/*
 * Starting with current light state ``lights'', flip exactly n switches
 * with number >= i.
 */
void
search(int lights, int i, int n)
{
    if(n == 0) {
 if((lights & known) == ison)
     poss[lights] = 1;
 return;
    }

    for(; i<4; i++)
 search(lights ^ flip[i], i+1, n-1);
}

void
printseq(FILE *fout, int lights)
{
    int i;
    char s[100+1];

    for(i=0; i<nlamp; i++)
 s[i] = (lights & (1<<(MAXLAMP-1 - i%MAXLAMP))) ? '1' : '0';
    s[nlamp] = '\0';
    fprintf(fout, "%s\n", s);
}

int
main()
{
    FILE *fin, *fout;
    int a, i, impossible;

    fin = fopen("lamps.in", "r");
    fout = fopen("lamps.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d %d", &nlamp, &nswitch);

    for(;;) {
 fscanf(fin, "%d", &a);
 if(a == -1)
     break;
 a = MAXLAMP-1 - (a-1) % MAXLAMP;
 ison |= 1<<a;
 known |= 1<<a;
    }

    for(;;) {
 fscanf(fin, "%d", &a);
 if(a == -1)
     break;
 a = MAXLAMP-1 - (a-1) % MAXLAMP;
 assert((ison & (1<<a)) == 0);
 known |= 1<<a;
    }

    if(nswitch > 4)
 if(nswitch%2 == 0)
     nswitch = 4;
 else
     nswitch = 3;

    for(; nswitch >= 0; nswitch -= 2)
     search(LAMPMASK, 0, nswitch);

    impossible = 1;
    for(i=0; i<(1<<MAXLAMP); i++) {
 if(poss[i]) {
     printseq(fout, i);
     impossible = 0;
 }
    }
    if(impossible)
 fprintf(fout, "IMPOSSIBLE\n");

    return 0;
}

//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <cmath>
//#include <cstring>
//#include <vector>
//#include <string>
//#include <bitset>
//#include <algorithm>
//#include <set>
//#include <queue>
//#include <climits>
//
//using namespace std;
//
//#define MAX_N 6
//
//int n, c;
//int k = 4;
//vector<unsigned> onLamps, offLamps;
//
//vector<bool> configuration;
//
//set<vector<bool> > configurations;
//
//void ResetConfiguration() {
//    configuration.push_back(false);
//    for(unsigned i = 0; i < MAX_N; i++)
//        configuration.push_back(true);
//}
//
//bool IsSolution(vector<bool> & conf) {
//    for(unsigned i = 0; i < onLamps.size(); i++)
//        if(!configuration[onLamps[i] % 6])
//            return false;
//    for(unsigned i = 0; i < offLamps.size(); i++)
//        if(configuration[offLamps[i] % 6])
//            return false;
//    return true;
//}
//
//void FlipAll() {
//
////        for(unsigned i = 1; i < configuration.size(); i++)
////                if(configuration[i])
////                    printf("1");
////                else
////                    printf("0");
////    printf("\n");
//
//    for(unsigned i = 1; i <= configuration.size(); i++)
//        configuration[i] = !configuration[i];
//
////    for(unsigned i = 1; i < configuration.size(); i++)
////                if(configuration[i])
////                    printf("1");
////                else
////                    printf("0");
////    printf("\n");
//}
//
//void FlipOdd() {
////    printf("Before odd\n");
////    for(unsigned i = 1; i < configuration.size(); i++)
////                if(configuration[i])
////                    printf("1");
////                else
////                    printf("0");
////    printf("\n");
//
//    for(unsigned i = 1; i <= configuration.size(); i += 2)
//        configuration[i] = !configuration[i];
//
////    printf("After odd\n");
////    for(unsigned i = 1; i < configuration.size(); i++)
////                if(configuration[i])
////                    printf("1");
////                else
////                    printf("0");
////    printf("\n");
//}
//
//void FlipEven() {
//
////    printf("Before even\n");
////    for(unsigned i = 1; i < configuration.size(); i++)
////                if(configuration[i])
////                    printf("1");
////                else
////                    printf("0");
////    printf("\n");
//
//    for(unsigned i = 2; i <= configuration.size(); i += 2)
//        configuration[i] = !configuration[i];
//
////        printf("After even\n");
////    for(unsigned i = 1; i < configuration.size(); i++)
////                if(configuration[i])
////                    printf("1");
////                else
////                    printf("0");
////    printf("\n");
//}
//
//void FlipInForm() {
//    int i = 0;
//    int k = 0;
//    while(i <= configuration.size()) {
//        i = (3 * k) + 1;
//        configuration[i] = !configuration[i];
//        k++;
//    }
//}
//
//void Solve(int level) {
//
////    printf("Running level %d\n", level);
//    if(configurations.find(configuration) != configurations.end()) return;
//    if(IsSolution(configuration))
//        configurations.insert(configuration);
//
//    if(level >= c) return;
//
//    level++;
//
//    FlipAll();
//    Solve(level);
//    FlipAll();
//
//    FlipOdd();
//    Solve(level);
//    FlipOdd();
//
//    FlipEven();
//    Solve(level);
//    FlipEven();
//
//    FlipInForm();
//    Solve(level);
//    FlipInForm();
//}
//
////bool IsOdd(int num) {
////    return num % 2 != 0;
////}
//
//int main() {
//
//    freopen("lamps.in", "r", stdin);
//    freopen("lamps.out", "w", stdout);
//    scanf("%d\n", &n);
//    scanf("%d\n", &c);
//    int num;
//    while(scanf("%d", &num) && num != -1) {
//        onLamps.push_back(num);
//    }
//    while(scanf("%d", &num) && num != -1) {
//        offLamps.push_back(num);
//    }
//
//    ResetConfiguration();
//
//    Solve(0);
//
//    if(configurations.size() == 0) {
//        printf("IMPOSSIBLE\n");
//    } else {
//        // print configs
////        printf("Possible configs %d\n", configurations.size());
//        set<vector<bool> >::iterator it;
////        for(unsigned i = 0; i < configurations.size(); i++) {
//        int confSize = n;
//        for(it = configurations.begin() ; it != configurations.end(); it++) {
//            vector<bool> conf = *it;
////            printf("Initial size %d\n", conf.size());
//            while(conf.size() < confSize) {
//                conf.insert(conf.end(), conf.begin() + 1, conf.end());
//            }
//            for(unsigned j = 1; j <= confSize; j++) {
//
////                int index = j % 6;
////                if(j > 5) index++;
////                printf("\nindex %d\n", index);
////                if(conf[index])
//                if(conf[j])
//                    printf("1");
//                else
//                    printf("0");
//            }
////                printf("%d", configurations[i][j]);
//            printf("\n");
//        }
////            cout << configurations[i] << endl;
////            printf("%s\n", configurations[i]);
//    }
//
////    printf("onLamps list size is: %d\n", onLamps.size());
////    printf("offLamps list size is: %d\n", offLamps.size());
//    return 0;
//}

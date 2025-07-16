#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

template<typename T = int>
inline T read(void);

int T[4];
long double mx = -114514.0;
basic_string < int > ans1;
basic_string < long double > ans2;

int main(){
    for(int i = 0; i <= 3; ++i)T[i] = read() - 1;
    basic_string < int > perm({0, 1, 2, 3});
    do{
        basic_string < long double > val({(long double)T[perm[0]], (long double)T[perm[1]], (long double)T[perm[2]], (long double)T[perm[3]]});
        if(val[0] * val[3] < val[1] * val[2]){
            val[1] < val[2]
                ? (val[1] = val[2] > 0 ? (val[0] * val[3] / val[2]) : 0)
                : (val[2] = val[1] > 0 ? (val[0] * val[3] / val[1]) : 0);
        }else{
            val[0] < val[3]
                ? val[0] = (val[3] > 0 ? (val[1] * val[2] / val[3]) : 0)
                : val[3] = (val[0] > 0 ? (val[1] * val[2] / val[0]) : 0);
        } 
        for(int i = 0; i <= 3; ++i)val[i] += 1.0;
        // printf("val = %.2lf %.2lf %.2lf %.2lf\n", val[0], val[1], val[2], val[3]);
        if(val[0] * val[3] + val[1] + val[2] > mx){
            mx = val[0] * val[3] + val[1] + val[2];
            ans1 = perm;
            ans2 = val;
        }

    }while(next_permutation(perm.begin(), perm.end()));

    for(int i = 1; i <= 4; ++i)printf("%d%c", ans1[i - 1] + 1, i == 4 ? '\n' : ' ');
    for(int i = 1; i <= 4; ++i)printf("%.11lf%c", (double)ans2[i - 1], i == 4 ? '\n' : ' ');

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
inline T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while(c != '-' && !isdigit(c))c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}
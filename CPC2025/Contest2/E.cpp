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

int N;

unordered_map < int, basic_string < int > > str[1100];

int main(){
    scanf("%d", &N);
    for(int i = 2; i <= N; ++i){
        printf("%d %d\n", 1, i); fflush(stdout);
        int diff; scanf("%d", &diff);
        if(!diff)exit(0);
        str[1][diff] += i;
    }
    int idx(1), cur(1);
    while(true){
        for(auto s : str[idx]){
            if(s.second.size() <= 1)continue;
            ++cur;
            int cmp = *s.second.begin();
            for(auto it = next(s.second.begin()); it != s.second.end(); ++it){
                printf("%d %d\n", cmp, *it); fflush(stdout);
                int diff; scanf("%d", &diff);
                if(!diff)exit(0);
                str[cur][diff] += *it;
            }
        }++idx;
    }
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
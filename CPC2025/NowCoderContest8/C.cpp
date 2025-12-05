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

const double GRAVITY = 9.78046;
vector < pair < int, int > > h;

int main(){
    int T = read();
    while(T--){
        int N = read(), H = read();
        h.clear();
        for(int i = 1; i <= N; ++i)h.push_back({read(), i});
        sort(h.begin(), h.end(), [&](const pair < int, int > &a, const pair < int, int > &b)->bool{
            return sqrt((double)2.0 * a.first / GRAVITY) * sqrt((double)2.0 * GRAVITY * (H - a.first))
                 < sqrt((double)2.0 * b.first / GRAVITY) * sqrt((double)2.0 * GRAVITY * (H - b.first));
        });
        for(auto it = h.begin(); it != h.end(); ++it)printf("%d%c", it->second, it == prev(h.end()) ? '\n' : ' ');
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
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to

/******************************
abbr
cvr => cover
******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

int N, M;
int V(-1);
int cvr[1100000];
// int dcvr[1100000];

// namespace Case{
    bool used[310000];
//     for(int i = 1; i <= N)
// }

int main(){
    freopen("queries.in", "r", stdin);
    freopen("queries.out", "w", stdout);
    N = read(), M = read();

    for(int i = 1; i <= N; ++i){
        int l = read(), r = read();
        // dcvr[l]++;dcvr[r + 1]--;
        V = max(V, l), V = max(V, r + 1);
        for(int j = l; j <= r; ++j)cvr[j] = i;
    }
    // for(int i = 1; i <= V; ++i)
        // cvr[i] = cvr[i - 1] + dcvr[i];
    while(M--){
        memset(used, false, (N + 1) * sizeof(bool));
        int cnt = read();
        int ans(0);
        while(cnt--){
            int p = read();
            if(cvr[p] && !used[cvr[p]]){
                used[cvr[p]] = true;
                ++ans;
            }
        }
        printf("%d\n", ans);
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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
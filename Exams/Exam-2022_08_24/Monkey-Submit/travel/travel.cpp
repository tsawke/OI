#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define PI M_PI
#define E M_E
#define npt nullptr
#define MAXJ ((1 << i) - 1)

#define MAXTIME (1.90000)
#define SUBTIME ((MAXTIME / (double)_T) * 0.90000)

// #define MAXK ((1 << i) - 1)

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef long long ll;
typedef unsigned long long unll;

template <typename T = int>
inline T read(void);
int T, _T;
int G[20][20];
// int dp[20][1 << 16];
// int dp[20][20][100 * 20];
int N, M;
bool used[20];
int ans(INT_MAX);
void Clear(void){
    memset(G, -1, sizeof(G));
    // memset(dp, 0x3f, sizeof(dp));
    memset(used, 0, sizeof(used));
    ans = INT_MAX;
}

struct que{
    int pos;
    int pri;
    bitset < 17 > used;
    que(int _pos, int _pri):pos(_pos), pri(_pri){used.reset();}
    void operator=(que x){
        this->pos = x.pos;
        this->pri = x.pri;
        this->used = x.used;
    }
};
void BFS(void){
    double begT = (double)clock() / CLOCKS_PER_SEC;
    queue < que > q;
    que top(1, 0);
    top.used[1] = true; 
    q.push(top);
    while( ( (double)clock() / CLOCKS_PER_SEC - begT ) <= SUBTIME && !q.empty()){
        // printf("BFS\n");
        for(int i = 1; i <= 100 && !q.empty(); ++i){
            auto tmp = q.front(); q.pop();
            if((int)tmp.used.count() == N && tmp.pos == 1){
                // printf("FIND ANS pos = %d, cost = %d\n", tmp.pos, tmp.pri); cout<<tmp.pri<<endl;
                ans = min(ans, tmp.pri);
                continue;
            }
            for(int j = 1; j <= N; ++j){
                auto tmpp = tmp;
                if(~G[tmpp.pos][j]){
                    tmpp.pri += G[tmpp.pos][j];
                    tmpp.used[j] = 1;
                    tmpp.pos = j;
                    q.push(tmpp);
                }
            }
        }
    }
}

// void DFS(int dep, int pos, int cost){
//     if(dep > N)return (void)(ans = min(ans, cost));
//     for(int i = 1; i <= N; ++i){
//         if(~G[pos][i] && !used[i]){
//             used
//         }
//     }
// }

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    T = read();
    _T = T;
    while(T--){
        Clear();
        // printf("TEST:  %d\n", dp[1][1]);
        N = read(), M = read();
        for(int i = 1; i <= M; ++i){
            int f = read(), t = read(), w = read();
            if(!~G[f][t])G[f][t] = G[t][f] = w;
            else G[f][t] = G[t][f] = min(G[f][t], w);
        }
        BFS();
        // printf("%.6lf", (MAXTIME / (double)T));
        printf("%d\n", ans);
        // for(int i = 1; i <= N; ++i){
        //     for(int j = 0; j <= MAXJ; ++j){
        //         // for(int k = 0; k <= MAXJ; ++k){
        //         //     dp[i][j] = min(dp[i][j], dp[i - 1][])
        //         // }
        //         for(int k = 0; k < i; ++k){
        //             if(dp[])
        //         }
        //     }
        // }
        // for(int i = 1; i <= N; ++i){
        //     for(int j = 1; j <= N; ++i){

        //     }
        // }

    }



    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    T flag(1);
    char c = getchar();
    while(!isdigit(c) && c != '-')c = getchar();
    if(c == '-')flag = 1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}

/* Examples:



*/
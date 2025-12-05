#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define INF (0x3f3f3f3f)

template < typename T = int >
inline T read(void);

int N;
int s[410];
// int dp[65][65][65][65];
int dp[410][3];
int nxt[410][3][410][3];
basic_string < int > vals[410][3];

// class BIT{
// private:
//     int tr[10];
// public:
//     int 
// }

int main(){
    freopen("stand.in", "r", stdin);
    freopen("stand.out", "w", stdout);
    memset(dp, 0x3f, sizeof dp);
    N = read();
    bool noneF(true);
    for(int i = 1; i <= N; ++i){
        char c = getchar(); while(!isalpha(c))c = getchar();
        s[i] = c == 'B' ? 0 : (c == 'G' ? 1 : 2);
        if(s[i] == 2)noneF = false;
    }
    // if(N <= 8){
    //     int ans(INF);
    //     int times(1);
    //     for(int i = 1; i <= N; ++i)times *= i;
    //     while(times--){
    //         next_permutation(s + 1, s + N + 1);

    //     }
    // }
    if(noneF){
        int ans(0);
        int lst(-1);
        for(int i = 1; i <= N; ++i){
            if(lst != s[i])lst = s[i];
            else{
                for(int j = i + 1; j <= N; ++j){
                    if(s[j] != lst){
                        int val = s[j];
                        for(int k = j; k >= i + 1; --k)s[k] = s[k - 1];
                        s[i] = val;
                        ans += (j - i);
                        lst = val;
                        break;
                    }
                    if(j == N)printf("-1\n"), exit(0);
                }
            }
        }printf("%d\n", ans);
        exit(0);
    }
    for(int i = 1; i <= N; ++i)vals[0][0] += s[i];
    int end[3] = {0, 0, 0};
    for(int c = N; c >= 1; --c){
        end[vals[0][0].at(c - 1)] = c;
        nxt[0][0][c][0] = end[0],
        nxt[0][0][c][1] = end[1],
        nxt[0][0][c][2] = end[2];
    }
    vals[1][0] = vals[1][1] = vals[1][2] = vals[0][0];
    for(int j = 0; j <= 2; ++j){
        dp[1][j] = nxt[0][0][1][j] - 1;
        vals[1][j].erase(next(vals[1][j].begin(), nxt[0][0][1][j] - 1));
        vals[1][j].insert(next(vals[1][j].begin(), 0), j);
        int end[3] = {0, 0, 0};
        for(int c = N; c >= 1; --c){
            end[vals[0][0].at(c - 1)] = c;
            nxt[1][j][c][0] = end[0],
            nxt[1][j][c][1] = end[1],
            nxt[1][j][c][2] = end[2];
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j <= 2; ++j){
            for(int k = 0; k <= 2; ++k){
                if(j == k || !nxt[i][j][i + 1][k] || dp[i][j] >= INF)continue;
                // printf("Making i = %d, j = %d, k = %d\n",i, j, k);
                if(dp[i][j] + (nxt[i][j][i + 1][k] - i) < dp[i + 1][k]){
                    
                    dp[i + 1][k] = dp[i][j] + (nxt[i][j][i + 1][k] - (i + 1));
                    vals[i + 1][k] = vals[i][j];
                    // swap(vals[i + 1][k].at(i + 1), vals[i + 1][k].)
                    vals[i + 1][k].erase(next(vals[i + 1][k].begin(), nxt[i][j][i + 1][k] - 1));
                    vals[i + 1][k].insert(next(vals[i + 1][k].begin(), i + 1 - 1), k);
                    int end[3] = {0, 0, 0};
                    for(int c = N; c >= i + 1; --c){
                        end[vals[i + 1][k].at(c - 1)] = c;
                        nxt[i + 1][k][c][0] = end[0],
                        nxt[i + 1][k][c][1] = end[1],
                        nxt[i + 1][k][c][2] = end[2];
                    }
                }
            }
        }
    }

    // for(int i = 1; i <= N; ++i)
    //     for(int j = 0; j <= 2; ++j)
    //         printf("%d%c", dp[i][j], j == 2 ? '\n' : ' ');

    int ans(INF);
    for(int i = 0; i <= 2; ++i)ans = min(ans, dp[N][i]);
    printf("%d\n", ans >= INF ? -1 : ans);


    // for(int i = 1; i <= N; ++i){
    //     for(int a = 0; a <= i; ++a){
    //         for(int b = 0; b <= i; ++b){
    //             for(int c = 0; c <= i; ++c){
    //                 if(a == b || b == c || a == c)continue;
    //                 switch(s[i + 1]){
    //                     case 0:{
    //                         if(a == i)dp[i + 1][]
    //                         break;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    int flag(1);
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

/*
20
BBGBBBGGGGFGBBGFGFBG
*/
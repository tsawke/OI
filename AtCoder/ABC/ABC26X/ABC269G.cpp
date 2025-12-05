#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template < typename T = int >
inline T read(void);

int N, M;
int w[210000], tw[210000];
int s[210000];
unordered_map < int, int > mp;
int cnt(0);
int origin(0);
int dp[2][210000];
deque < int > cur;

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    N = read(), M = read();
    for(int i = 1; i <= N; ++i){
        int a = read(), b = read();
        // tw[i] = b - a;
        mp[b - a]++;
        origin += a;
    }//sort(tw + 1, tw + N + 1);
    // tw[0] = INT_MAX;
    // for(int i = 1; i <= N; ++i){
    //     if(tw[i] != tw[i - 1])w[++cnt] = tw[i];
    //     ++s[cnt];
    // }
    memset(dp, 0x3f, sizeof dp);
    dp[0][origin] = 0;
    int i = 0;
    for(auto v : mp){i ^= 1;
        // for(int j = 0; j <= M; ++j)dp[i][j] = 0x3f3f3f3f3f3f3f3fll;
        
        // for(int t = 0; t <= M; ++t)printf("i = %d, dp[%d] = %lld\n", i, t, dp[i][t]);
        if(v.first > 0){
            w[i] = v.first, s[i] = v.second;
            for(int p = 0; p < w[i]; ++p){
                cur.clear();
                for(int j = p; j <= M; j += w[i]){
                    dp[i][j] = dp[i ^ 1][j];
                    while(!cur.empty() && j - s[i] * w[i] > cur.front())cur.pop_front();
                    if(!cur.empty())dp[i][j] = min(dp[i][j], dp[i ^ 1][cur.front()] + (j - cur.front()) / w[i]);
                    while(!cur.empty() && dp[i ^ 1][cur.back()] + (j - cur.back()) / w[i] >= dp[i ^ 1][j])cur.pop_back();
                    cur.push_back(j);
                }
            }
        }else if(v.first < 0){
            w[i] = -v.first, s[i] = v.second;
            for(int p = 0; p < w[i]; ++p){
                cur.clear();
                for(int j = M - p; j >= 0; j -= w[i]){
                    dp[i][j] = dp[i ^ 1][j];
                    while(!cur.empty() && j + s[i] * w[i] < cur.front())cur.pop_front();
                    if(!cur.empty())dp[i][j] = min(dp[i][j], dp[i ^ 1][cur.front()] + (cur.front() - j) / w[i]);
                    while(!cur.empty() && dp[i ^ 1][cur.back()] + (cur.back() - j) / w[i] >= dp[i ^ 1][j])cur.pop_back();
                    cur.push_back(j);
                }
            }
        }else
            memcpy(dp[i], dp[i ^ 1], sizeof dp[i ^ 1]);
        // for(int t = 0; t <= M; ++t)printf("i = %d, dp[%d] = %lld\n", i, t, dp[i][t]);
    }
    for(int j = 0; j <= M; ++j)printf("%d\n", dp[i][j] < 0x3f3f3f3f ? dp[i][j] : -1);
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
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

/*
37 9
0 1 2 3 4 5 6 7 9

233333 8
2 3 4 5 6 7 8 9
*/

template < typename T = int >
inline T read(void);

bitset < 10 > exist[20];

bitset < 10 > ban;

int K, T;

// basic_string < int > ends[10];
map < int, int > mp;
unordered_set < int > vis;
unordered_set < int > nums;
unordered_set < int > legal;
ll dp[20][1100000];
ll pow10[20];
ll ans(LONG_LONG_MAX);

int main(){
    freopen("digit.in", "r", stdin);
    freopen("digit.out", "w", stdout);
    pow10[0] = 1;
    for(int i = 1; i <= 18; ++i)pow10[i] = pow10[i - 1] * 10;
    memset(dp, -1, sizeof dp);
    K = read(), T = read();
    int digitK(0), tmp = K;
    while(tmp)++digitK, tmp /= 10;
    for(int i = 1; i <= T; ++i)ban[read()] = true;
    if(K == 0)printf("%d\n", ban[0] ? -1 : 0), exit(0);
    for(int i = 1; i <= 2 * K; ++i){
        int val = i;
        bool flag(true);
        while(val){
            if(ban[val % 10]){flag = false; break;}
            val /= 10;
        }if(flag)legal.insert(i);
    }
    for(int j = 1; vis.find(K * j % 10) == vis.end(); ++j){
        vis.insert(K * j % 10);
        // if(!ban[K * j % 10])nums.insert(K * j % 10), mp[K * j % 10] = K * j;
        nums.insert(K * j % 10), mp[K * j % 10] = K * j;
    }
    // dp[0][0][0] = 0;
    for(auto num : nums){
        if(ban[mp[num] % 10])continue;
        dp[1][mp[num] / 10] = mp[num];
        // printf("upd dp[%d][%d] = %d\n", 1, mp[num] / 10, mp[num]);
        if(!(mp[num] / 10) || legal.find(mp[num] / 10) != legal.end())ans = min(ans,  dp[1][mp[num] / 10]);
    }if(ans != LONG_LONG_MAX)printf("%lld\n", ans), exit(0);
    // exit(0);
    for(int i = 1; i <= 18 - digitK; ++i){
        for(auto j : nums){
            for(int k = 0; k <= 1000000; ++k){
                if(!~dp[i][k])continue;
                if(ban[(j + k % 10) % 10])continue;
                if(j + k % 10 <= 9){
                    // printf("[%d][%d][%d] => [%d][%d][%d]\n", i, j, k, i + 1, j + k % 10, k / 10 + mp[j] / 10);
                    dp[i + 1][k / 10 + mp[j] / 10] = dp[i][k] + (ll)mp[j] * pow10[i];
                    if(!(k / 10 + mp[j] / 10) || legal.find(k / 10 + mp[j] / 10) != legal.end())ans = min(ans, dp[i + 1][k / 10 + mp[j] / 10]);
                }else{
                    // printf("[%d][%d][%d] => [%d][%d][%d]\n", i, j, k, i + 1, (j + k % 10) % 10, k / 10 + mp[j] / 10 + 1);
                    dp[i + 1][k / 10 + mp[j] / 10 + 1] = dp[i][k] + (ll)mp[j] * pow10[i];
                    if(!(k / 10 + mp[j] / 10 + 1) || legal.find(k / 10 + mp[j] / 10 + 1) != legal.end())ans = min(ans, dp[i + 1][k / 10 + mp[j] / 10 + 1]);
                }
            }
        }
        if(ans != LONG_LONG_MAX)printf("%lld\n", ans), exit(0);
    }printf("-1\n");

    // int N = read();
    // for(int i = 1; i <= 10000; ++i){
    //     ll val = (ll)N * i;
    //     int cnt(0);
    //     while(val){
    //         exist[++cnt][val % 10] = true;
    //         val /= 10;
    //     }
    // }
    // for(int i = 1; i <= 10; ++i){
    //     printf("digit %d : ", i);
    //     for(int j = 0; j <= 9; ++j)if(exist[i][j])printf("%d ", j);
    //     printf("\n");
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
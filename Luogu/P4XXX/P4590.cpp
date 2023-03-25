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

#define MOD (ll)(1e9 + 7)

template < typename T = int >
inline T read(void);

int N, K;
string S;
ll dp[2][33000][3];
ll ans[20];

int main(){
    //Array len : K + 1(begin with 0), Hash len : K
    auto HashArray = [](basic_string < int > arr)->int{
        int pos(0), ret(0);
        for(auto it = arr.begin(); it != arr.end() && next(it) != arr.end(); advance(it, 1))
            ret |= (*next(it) != *it) << (pos++);
        return ret;
    };
    auto RestoreArray = [](int hash)->auto{
        basic_string < int > ret; ret += 0;
        for(int i = 0; i < K; ++i)ret += bool(hash & (1 << i)) + ret.back();
        return ret;
    };
    auto Make = [HashArray, RestoreArray](int hash, char c, int nxt_idx, int nxt_ilg, ll val)->void{
        if(!val)return;
        auto cur = RestoreArray(hash);
        basic_string < int > nxt(K + 1, 0);
        for(int i = 1; i <= K; ++i)
            nxt[i] = max({cur[i], nxt[i - 1], cur[i - 1] + (c == S.at(i - 1))});
        // printf("Making when c = %c, idx = %d, ilg = %d, val = %lld\n", c, nxt_idx, nxt_ilg, val);
        // for(auto p : nxt)printf("%d ", p);
        // printf("\n");
        auto nxt_hash = HashArray(nxt);
        // printf("Nxt : "); cout << bitset < 5 >(nxt_hash) << endl;
        (dp[nxt_idx][nxt_hash][nxt_ilg] += val) %= MOD;
    };
    N = read(), K = read();
    cin >> S;
    dp[0][0][0] = 1;
    const int Smx = (1 << K) - 1;
    for(int i = 0; i < N; ++i){
        memset(dp[!(i & 1)], 0, sizeof dp[!(i & 1)]);
        for(int S = 0; S <= Smx; ++S){
            Make(S, 'N', !(i & 1), 1, dp[i & 1][S][0]);
            Make(S, 'O', !(i & 1), 0, dp[i & 1][S][0]);
            Make(S, 'I', !(i & 1), 0, dp[i & 1][S][0]);
            Make(S, 'N', !(i & 1), 1, dp[i & 1][S][1]);
            Make(S, 'O', !(i & 1), 2, dp[i & 1][S][1]);
            Make(S, 'I', !(i & 1), 0, dp[i & 1][S][1]);
            Make(S, 'N', !(i & 1), 1, dp[i & 1][S][2]);
            Make(S, 'O', !(i & 1), 0, dp[i & 1][S][2]);
            // Make(S, 'I', !(i & 1), x, dp[i & 1][S][2]);
        }
        // printf("dp when i = %d\n", i + 1);
        // for(int S = 0; S <= Smx; ++S){
        //     cout << bitset < 5 >(S) << ":  ";
        // auto arr = RestoreArray(S);
        // for(auto a : arr)printf("%d ", a);
        // printf("  : %lld %lld %lld\n", dp[!(i & 1)][S][0], dp[!(i & 1)][S][1], dp[!(i & 1)][S][2]);
        // // printf("\n");
        // }

    }
    for(int S = 0; S <= Smx; ++S)
            (ans[RestoreArray(S).back()] += dp[N & 1][S][0] + dp[N & 1][S][1] + dp[N & 1][S][2]) %= MOD;
    for(int i = 0; i <= K; ++i)printf("%lld\n", ans[i]);
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
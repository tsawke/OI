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

#define BASE (31)

template < typename T = int >
inline T read(void);

int N, M, L;
ll ans(0);
unll hashL;
unll base_L(1);
bitset < 41 > A[21];
bitset < 41 > cur;
// bitset < 21 > pat[21];

void dfs(int dep = 1){
    if(dep > N){
        // cout << cur << endl;
        unll chash(0);
        for(int i = 1; i < L; ++i){
            (chash *= BASE) += cur[i];
        }
        for(int i = L; i <= M; ++i){
            chash *= BASE;
            chash -= base_L * cur[i - L];
            chash += cur[i];
            // printf("dep = %d, i = %d, chash = %llu\n", dep, i, chash);
            if(chash == hashL){
                // printf("chash = %llu idx = %d\n", chash, i);
                // cout << cur << endl;
                ++ans;
                return;
            }
        }
        return;
        // cout << cur << endl;
        // for(int i = 1; i <= N - L + 1; ++i)
        //     if(cur == pat[i]){++ans; return;}
        // return;
    }dfs(dep + 1), cur ^= A[dep], dfs(dep + 1);
}

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j){
            char c = getchar(); while(!isdigit(c))c = getchar();
            A[i][j] = c == '1' ? true : false;
        }
    L = read(); bitset < 41 > patt; patt.reset();
    for(int i = 1; i <= L; ++i){
        char c = getchar(); while(!isdigit(c))c = getchar();
        patt[i] = c == '1' ? true : false;
        (hashL *= BASE) += patt[i];
    }
    
    for(int i = 1; i <= L; ++i)base_L *= BASE;
    if(L > N)printf("0\n"), exit(0);
    // for(int i = 1; i <= N - L + 1; ++i)
    //     for(int j = i; j <= i + L - 1; ++j)
    //         pat[i][j] = patt[j - i + 1];
    dfs();
    printf("%lld\n", ans);
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
3 3
001
101
010
2
11
*/
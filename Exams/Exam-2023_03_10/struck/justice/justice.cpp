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

#define S(i) (S.at(i - 1))
#define BASE (31)

template < typename T = int >
inline T read(void);

ll MOD;
ll ans(0);
int N;
string S;
unll powb[1100];
unll hv[1100], rhv[1100];
unordered_map < unll, pair < ll, int > > mp;

int main(){
    freopen("justice.in", "r", stdin);
    freopen("justice.out", "w", stdout);
    cin >> S; MOD = read < ll >();
    N = S.length();
    powb[0] = 1;
    for(int i = 1; i <= 1010; ++i)powb[i] = powb[i - 1] * BASE;
    for(int i = 1; i <= N; ++i)hv[i] = hv[i - 1] * BASE + S(i);
    for(int i = N; i >= 1; --i)rhv[i] = rhv[i + 1] * BASE + S(i);
    // for(int l = 1; l <= N; ++l){
    //     for(int r = l; r <= N; ++r){

    //     }
    // }
    for(int l1 = 1; l1 <= N; ++l1){
        for(int r1 = l1; r1 <= N; ++r1){
            for(int l2 = 1; l2 <= N; ++l2){
                for(int r2 = l2; r2 <= N; ++r2){
                    unll hash1 = hv[r1] - hv[l1 - 1] * powb[r1 - l1 + 1];
                    unll hash2 = hv[r2] - hv[l2 - 1] * powb[r2 - l2 + 1];
                    unll hashv = hash1 * powb[r2 - l2 + 1] + hash2;
                    unll rhash1 = rhv[l1] - rhv[r1 + 1] * powb[r1 - l1 + 1];
                    unll rhash2 = rhv[l2] - rhv[r2 + 1] * powb[r2 - l2 + 1];
                    unll rhashv = rhash2 * powb[r1 - l1 + 1] + rhash1;
                    // printf("[%d, %d], [%d, %d], hash is %llu,  %llu\n", l1, r1, l2, r2, hashv, rhashv);
                    if(hashv == rhashv)(ans += (r1 - l1 + 1) + (r2 - l2 + 1)) %= MOD;
                }
            }
        }
    }

    // for(int l = 1; l <= N; ++l){
    //     for(int r = l; r <= N; ++r){
    //         unll hashv = hv[r] - hv[l - 1] * powb[r - l + 1];
    //         printf("v = %llu\n", hashv);
    //         auto lstv = mp[hashv];
    //         mp[hashv] = {(lstv.first + (r - l + 1)) % MOD, lstv.second + 1};
    //     }
    // }
    // for(int l = 1; l <= N; ++l){
    //     for(int r = l; r <= N; ++r){
    //         unll hashv = rhv[l] - rhv[r + 1] * powb[r - l + 1];
    //         printf("rv = %llu\n", hashv);
    //         auto ansp = mp[hashv];

    //         // mp[hashv] = {0, 0};
    //         (ans += (ansp.first + (ll)ansp.second * (r - l + 1) % MOD) % MOD) %= MOD;
    //     }
    // }
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
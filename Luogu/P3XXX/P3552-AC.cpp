#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr
uex => unexist
******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template<typename T = int>
inline T read(void);

ll str2ll(char* s, int n){
    ll ret(0), base(0);
    for(int i = n - 1; i >= 0; --i)
        ret += (1ll << (base++)) * (s[i] == '0' ? 0 : 1);
    return ret;
}
#define MOD 2737321
struct Edge{
    Edge* nxt;
    ll val;
    OPNEW;
}eData[4145149];
ROPNEW(eData);
Edge* head[2737330];
void clear(void){memset(head, 0, sizeof(head));}
void Add(ll val){
    int idx = val % MOD;
    head[idx] = new Edge{head[idx], val};
}
bool Check(ll val){
    int idx = val % MOD;
    for(auto i = head[idx]; i; i = i->nxt)
        if(i->val == val)return true;
    return false;
}

ll S, T;
int N, K;
ll cur[5100000];
int fnt(0), til(0);
void bfs(ll S, ll T){
    fnt = til = 0;
    cur[til++] = S;
    Add(S);
    while(fnt < til){
        ll tp = cur[fnt++];
        for(int base = 0; base <= N - 1; ++base){
            ll val = tp ^ (1ll << base);
            if(val == T)printf("TAK\n"), exit(0);
            if(Check(val))continue;
            else{
                Add(val);
                cur[til++] = val;
            }
        }
        if(til > N * K)return;
    }
    printf("NIE\n"); exit(0);
}
char c[65];
vector < ll > values;
int main(){
    // freopen("in.txt", "r", stdin);
    N = read(), K = read();
    scanf("%s", c); S = str2ll(c, N);
    scanf("%s", c); T = str2ll(c, N);
    if(S == T)printf("TAK\n"), exit(0);
    for(int i = 1; i <= K; ++i){
        scanf("%s", c); ll tmpp = str2ll(c, N);
        values.push_back(tmpp);
    }
    for(auto i : values)Add(i);
    bfs(S, T);
    clear();
    for(auto i : values)Add(i);
    bfs(T, S);
    printf("TAK\n");
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
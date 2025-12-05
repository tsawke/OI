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

ll str2ll(string s){
    reverse(s.begin(), s.end());
    ll ret(0), base(0);
    for(auto c : s)
        ret += (1ll << (base++)) * (c == '0' ? 0 : 1);
    return ret;
}

ll S, T;
int N, K;
unordered_set < ll > uex;
unordered_set < ll > bfsS, bfsT;
int Ssize(0), Tsize(0);
queue < ll > cur;

void bfs_S(void){
    cur.push(S), bfsS.insert(S), ++Ssize;
    while(!cur.empty()){
        ll tp = cur.front();
        cur.pop();
        for(int base = 0; base <= N - 1; ++base){
            ll val = tp ^ (1ll << base);
            if(bfsS.find(val) != bfsS.end())continue;
            else bfsS.insert(val);
            if(uex.find(val) == uex.end()){
                if(val == T){printf("TAK\n"); exit(0);}
                else cur.push(val), ++Ssize;
            }
        }
        if(Ssize > N * K)return;
    }
}
void bfs_T(void){
    while(!cur.empty())cur.pop();
    cur.push(T), bfsT.insert(T), ++Tsize;
    while(!cur.empty()){
        ll tp = cur.front();
        cur.pop();
        for(int base = 0; base <= N - 1; ++base){
            ll val = tp ^ (1ll << base);
            if(bfsT.find(val) != bfsT.end())continue;
            else bfsT.insert(val);
            if(uex.find(val) == uex.end()){
                if(val == S){printf("TAK\n"); exit(0);}
                else cur.push(val), ++Tsize;
            }
        }
        if(Tsize > N * K)return;
    }
}

int main(){
    ios::sync_with_stdio(false);
    // freopen("in.txt", "r", stdin);
    // N = read(), K = read();
    cin >> N >> K;
    string sS, sT; cin >> sS >> sT; S = str2ll(sS), T = str2ll(sT);
    for(int i = 1; i <= K; ++i){
        string tmp; cin >> tmp; ll tmpp = str2ll(tmp);
        uex.insert(tmpp);
    }
    bfs_S();
    bfs_T();
    // printf("%s\n", (Ssize > N * K && Tsize > N * K) ? "TAK" : "NIE");
    cout << ((Ssize > N * K && Tsize > N * K) ? "TAK" : "NIE") << endl;
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
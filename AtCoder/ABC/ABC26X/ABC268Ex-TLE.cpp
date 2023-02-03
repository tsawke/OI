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

#define BASE (31ll)
#define S(i) (S.at(i - 1))

template < typename T = int >
inline T read(void);

int N;
string S;
map < int, unordered_set < unll > > pat;
unll pow_base[510000];
int ans(0);

int main(){
    // freopen("in.txt", "r", stdin);
    pow_base[0] = 1;
    for(int i = 1; i <= 501000; ++i)pow_base[i] = pow_base[i - 1] * BASE;
    ios::sync_with_stdio(false);
    cin >> S;
    cin >> N;
    for(int i = 1; i <= N; ++i){
        string T;
        cin >> T;
        unll hashv(0);
        for(auto c : T)(hashv *= BASE) += c;
        pat[(int)T.length()].insert(hashv);
    }
    for(auto mp : pat){
        if(mp.first > (int)S.length())continue;
        unll cur(0);
        bool newStr(true);
        for(int i = 1; i <= mp.first - 1; ++i)(cur *= BASE) += S(i);
        for(int i = mp.first; i <= (int)S.length(); ++i){
            if(!newStr)cur -= S(i - mp.first) * pow_base[mp.first - 1];
            cur *= BASE; cur += S(i); newStr = false;
            if(mp.second.find(cur) != mp.second.end()){
                S(i) = '*', cur = 0, newStr = true, ++ans;
                if(i + mp.first > (int)S.length())break;
                for(int j = i + 1; j <= i + mp.first - 1; ++j)(cur *= BASE) += S(j);
                i = i + mp.first - 1;
            }
        }
    }printf("%d\n", ans);
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
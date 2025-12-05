#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

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

int N, K;
string S;
string ans("");

int main(){
    N = read(), K = read();
    cin >> S;
    int tot = __gcd(N, K), loop = N / tot;
    for(int s = 0; s < tot; ++s){
        string cur;
        cur += S.at(s);
        for(int tmp = (s + K) % N; tmp != s; tmp = (tmp + K) % N)cur += S.at(tmp);
        int i = 0, j = 1, k = 0;
        while(i < loop && j < loop && k < loop){
            char ci = cur.at((i + k) % loop), cj = cur.at((j + k) % loop);
            if(ci == cj)++k;
            else{
                ci > cj ? j = j + k + 1 : i = i + k + 1;
                if(i == j)++j;
                k = 0;
            }
        }ans = max(ans, cur.substr(min(i, j), loop - min(i, j) + 1) + cur.substr(0, min(i, j)));
    }string rans;
    while(tot--)rans += ans;
    cout << rans << endl;
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
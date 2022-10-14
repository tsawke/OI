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

bool readc(void){
    char c = getchar();
    while(c != 'c' && c != 'b')c = getchar();
    return c == 'c' ? true : false;
}

int N, K;
stack < int > seq;
int sum[1010000];
int cnt(0);
std::priority_queue < int, vector < int >, greater < int > > ans[1010000];
int main(){
    // freopen("in.txt", "r", stdin);
    N = read(), K = read();
    for(int i = 1; i <= N; ++i){
        bool f = readc();
        seq.push(i);
        sum[seq.size()] = sum[seq.size() - 1] + f;
        if((int)seq.size() >= K + 1 && sum[seq.size()] - sum[seq.size() - K - 1] == 1){
            ++cnt;
            for(int j = 1; j <= K + 1; ++j)ans[cnt].push(seq.top()), seq.pop();
        }
        // seq[til++] = {f, i};
        // if(f)++cblk;
        // if(til - fnt < K + 1)continue;
        // if(cblk == 1){++cnt;
        //     for(int j = 1; j <= K + 1; ++j)ans[cnt].push(seq[--til].second);
        //     cblk = 0;
        //     for(int j = til - 1, k = 1; j >= fnt && k <= K + 1; --j, ++k)if(seq[j].first)++cblk;
        // }else if(seq[til - K - 1].first)--cblk;
    }
    for(int i = cnt; i >= 1; --i){
        while(!ans[i].empty()){
            int v = ans[i].top(); ans[i].pop();
            printf("%d ", v);
        }printf("\n");
    }
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
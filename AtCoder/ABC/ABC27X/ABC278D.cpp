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



template < typename T = int >
inline T read(void);

int N, Q;
pair < ll, int > mdf[210000];
int ass, asst(-1);

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)mdf[i] = {read(), 0};
    Q = read();
    for(int i = 1; i <= Q; ++i){
        int opt = read();
        switch(opt){
            case 1:{
                int val = read();
                ass = val, asst = i;
                break;
            }
            case 2:{
                int p = read(), val = read();
                if(mdf[p].second < asst)mdf[p].first = ass;
                mdf[p].first += val, mdf[p].second = asst;
                break;
            }
            case 3:{
                int p = read();
                if(mdf[p].second < asst)mdf[p] = {ass, asst};
                printf("%lld\n", mdf[p].first);
                break;
            }
            default: break;
        }
    }
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
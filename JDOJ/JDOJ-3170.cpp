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

// mt19937 rnd(random_device{}());
// int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
// bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define LIM (31)

// template < typename T = int >
template < typename T >
inline T read(void);

int N;
bitset < 510000 > opt;
int val[510000], del[510000];
map < int, int > mp;

class LinearBasis{
private:
    int LB[40], delt[40];
public:
    void Insert(int x, int del){
        for(int i = LIM; i >= 0; --i)
            if(x & (1 << i)){
                if(LB[i]){
                    if(del > delt[i])swap(del, delt[i]), swap(x, LB[i]);
                    x ^= LB[i];
                }else{
                    LB[i] = x, delt[i] = del;
                    break;
                }
            }
    }
    void Erase(int tim){
        for(int i = LIM; i >= 0; --i)
            if(delt[i] == tim){LB[i] = delt[i] = 0; break;}
    }
    int QueryMax(void){
        int ret(0);
        for(int i = LIM; i >= 0; --i)
            if((ret ^ LB[i]) > ret)ret ^= LB[i];
        return ret;
    }
}lb;

#define read read < int >

int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        val[i] = read();
        opt[i] = val[i] > 0, val[i] = abs(val[i]);
        if(opt[i])del[i] = N + 1, mp[val[i]] = i;
        else del[mp[val[i]]] = i;
    }
    for(int i = 1; i <= N; ++i){
        if(opt[i])lb.Insert(val[i], del[i]);
        else lb.Erase(i);
        printf("%d\n", lb.QueryMax());
    }
    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

#undef read

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
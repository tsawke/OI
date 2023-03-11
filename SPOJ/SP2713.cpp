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

int N, M;
ll A[110000];

class SegTree{
private:
    ll sum[110000 << 2];
    bool flag[110000 << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Clear(int p = 1, int gl = 1, int gr = N){
        sum[p] = flag[p] = 0;
        if(gl == gr)return;
        Clear(LS, gl, MID), Clear(RS, MID + 1, gr);
    }
    void Pushup(int p){
        sum[p] = sum[LS] + sum[RS];
        flag[p] = flag[LS] & flag[RS];
    }
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return sum[p] = A[gl = gr], flag[p] = sum[p] == 0 || sum[p] == 1, void();
        Build(LS, gl, MID), Build(RS, MID + 1, gr);
        Pushup(p);
    }
    void Modify(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return sum[p] = (int)sqrt(sum[p]), flag[p] = sum[p] == 0 || sum[p] == 1, void();
        if(flag[p])return;
        if(l <= MID)Modify(l, r, LS, gl, MID);
        if(r >= MID + 1)Modify(l, r, RS, MID + 1, gr);
        Pushup(p);
    }
    ll Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return sum[p];
        if(l > gr || r < gl)return 0;
        return Query(l, r, LS, gl, MID) + Query(l, r, RS, MID + 1, gr);
    }
}st;

int main(){
    int cnt(0);
    while(true){
        N = read();
        // if(!~N)exit(0);
        printf("Case #%d:\n", ++cnt);
        for(int i = 1; i <= N; ++i)A[i] = read < ll >();
        st.Build();
        M = read();
        while(M--){
            int opt = read();
            if(opt == 0){
                int l = read(), r = read();
                st.Modify(min(l, r), max(l, r));
            }else{
                int l = read(), r = read();
                printf("%lld\n", st.Query(min(l, r), max(l, r)));
            }
        }printf("\n");
        st.Clear();
    }
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    int flag(1);
    char c = getchar();
    if(c == EOF)exit(0);
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
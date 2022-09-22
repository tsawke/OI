#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template<typename T = int>
inline T read(void);

int N, M;

struct Sec{
    int val;
    int l, r;
    Sec(int val, int l, int r):val(val), l(l), r(r){;}
    Sec(void) = default;
    Sec operator+(const Sec t){
        return Sec(
            this->val + t.val + (this->r == -1 && t.l == 1 ? 1 : 0),
            this->l ? this->l : t.l,
            t.r ? t.r : this->r
        );
    }
};

class SegTree{
    private:
        #define MID ((gl + gr) >> 1)
        #define LS (p << 1)
        #define RS (p << 1 | 1)
        Sec st[210000 << 4];
    public:
        void Pushup(int p){
            // st[p] = Sec(
            //     st[LS].val + st[RS].val + st[LS].r == -1 && st[RS].l == 1 ? 1 : 0,
            //     st[LS].l ? st[LS].l : st[RS].l,
            //     st[RS].r ? st[RS].r : st[LS].r,
            //     st[LS].pl ? st[LS].pl : st[RS].pl,
            //     st[RS].pr ? st[RS].pr : st[LS].pr
            // );
            st[p] = st[LS] + st[RS];
        }
        void Build(int p = 1, int gl = 1, int gr = N){
            if(gl == gr){
                st[p] =
                    gl == 1 ? Sec(0, -1, -1)
                            : (
                                gl == N ? Sec(0, 1, 1)
                                        : Sec(0, 0, 0)
                            );
                return;
            }
            Build(LS, gl, MID);
            Build(RS, MID + 1, gr);
            Pushup(p);
        }
        void Modify(int mp, int val, int p = 1, int gl = 1, int gr = N){
            if(gl == gr){
                st[p] = Sec(0, val, val);
                return;
            }
            if(mp <= MID)Modify(mp, val, LS, gl, MID);
            else Modify(mp, val, RS, MID + 1, gr);
            Pushup(p);
        }
        Sec Query(int l, int r, int p = 1, int gl = 1, int gr = N){
            if(l <= gl && gr <= r)return st[p];
            return
                (l <= MID ? Query(l, r, LS, gl, MID) : Sec(0, 0, 0)) +
                (r >= MID + 1 ?  Query(l, r, RS, MID + 1, gr) : Sec(0, 0, 0));
        }
}st;

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    N = read(), M = read();
    st.Build();
    while(M--){
        int opt = read();
        if(opt == 1){
            int x = read();
            char c = getchar(); while(c != 'X' && c != '(' && c != ')')c = getchar();
            st.Modify(x, c == 'X' ? 0 : (c == '(' ? -1 : 1));
        }else{
            int l = read(), r = read();
            printf("%d\n", st.Query(l, r).val);
        }
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
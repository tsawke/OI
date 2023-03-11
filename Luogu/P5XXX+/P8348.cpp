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

int main(){
    int T = read();
    while(T--){
        int a = read(), b = read(), x = read(), y = read(), k = read();
        auto Cal = [k](int &a, int &b)->void{
            while(true){
                if(a > b){
                    int cnt = (a - k) / b;
                    if(!cnt)return;
                    if(cnt & 1)a -= cnt * b, swap(a, b);
                    else a -= cnt * b;
                }else if(a < b){
                    int cnt = (b - k) / a;
                    if(!cnt)return;
                    if(cnt & 1)b -= cnt * a, swap(a, b);
                    else b -= cnt * a;
                }else return;
            }
        };
        auto Check = [&](void)->bool{
            if(a < k || b < k || x < k || y < k)return false;
            if(a == x && b == y)return true;
            Cal(a, b), Cal(x, y);
            return a == x && b == y;
        };
        printf("%s\n", Check() ? "yes" : "no");
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
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

using ll = long long;
using unll = unsigned long long;
using uint = unsigned int;
using ld = long double;

template < typename T = int >
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

struct Person{
    ll l, r;
    int id;
};

int main(){
    int T = read();
    while(T--){
        int N = read();
        ll F = read();

        vector < Person > P(N);
        for(int i = 0; i < N; ++i){
            ll L = read();
            ll R = read();
            P[i].l = L, P[i].r = R;
            P[i].id = i + 1;
        }

        vector < char > used(N + 10, 0);

        sort(P.begin(), P.end(), [](const Person &a, const Person &b)->bool{
            if(a.l == b.l)return a.r > b.r;
            return a.l < b.l;
        });

        ll now(F), ans(0);
        vector < int > order;

        for(int i = 0; i < N; ++i){
            ll L = P[i].l, R = P[i].r;
            if(L <= now){
                if(R > now){
                    ans += (R - L);
                    now = R;
                    used[P[i].id] = 1;
                    order.push_back(P[i].id);
                }
            }else{
                ans += (L - now);
                ans += (R - L);
                now = R;
                used[P[i].id] = 1;
                order.push_back(P[i].id);
            }
        }

        sort(P.begin(), P.end(), [](const Person &a, const Person &b)->bool{
            return a.r > b.r;
        });

        for(int i = 0; i < N; ++i){
            if(used[P[i].id])continue;
            ll L = P[i].l;
            ll R = P[i].r;
            ans += (R - L);
            order.push_back(P[i].id);
        }

        printf("%lld\n", ans);
        for(int i = 0; i < N; ++i)
            printf("%d%c", order[i], i + 1 == N ? '\n' : ' ');
    }

    return 0;
}

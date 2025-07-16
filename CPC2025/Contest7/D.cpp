#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

int N;
// ll A[1100000], B[1100000];
// ll sumB[1100000];
// ll siz[1100000];
// deque < pair < int, ll > > avail, exceed;
basic_string < ll > A, B;

bool Check(int lim){
    auto CA = A, CB = B;
    int cur(1);
    for(int i = 1; i <= N; ++i){
        while(cur <= N){
            if(abs(i - cur) > lim || !CB.at(i - 1))break;
            if(CA.at(cur - 1) <= CB.at(i - 1)){
                CB.at(i - 1) -= CA.at(cur - 1);
                ++cur;
            }else{
                CA.at(cur - 1) -= CB.at(i - 1);
                break;
            }
        }
    }return cur == N + 1;

    // auto ava = avail, exc = exceed;
    // while(!exc.empty()){
    //     auto [p, siz] = exc.front(); exc.pop_front();
    //     while(!ava.empty()){
    //         auto [cp, csiz] = ava.front(); ava.pop_front();
    //         // if(abs(cp - p) > (lim << 1)){
    //         //     if(cp < p)continue;
    //         //     else{
    //         //         ava.push_front({cp, csiz});
    //         //         break;
    //         //     }
    //         // }
    //         if(abs(cp - p) > lim){
    //             csiz = min(csiz, sumB[p - 1] - sumB[p - lim - 1]);
    //         }
    //         if(csiz > siz){csiz -= siz, siz = 0, ava.push_front({cp, csiz}); break;}
    //         if(csiz == siz){siz = 0; break;}
    //         siz -= csiz;
    //     }
    //     if(siz)return false;
    // }return true;
}

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)A += read < ll >();//A[i] = siz[i] = read < ll >();
    for(int i = 1; i <= N; ++i)B += read < ll >();
    // for(int i = 1; i <= N; ++i){
    //     siz[i] = (B[i] = read < ll >()) - siz[i];
    //     siz[i] > 0 ? avail.push_back({i, abs(siz[i])}) : exceed.push_back({i, abs(siz[i])});
    //     sumB[i] = sumB[i - 1] + B[i];
    // }
    int l = 0, r = N, ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        // printf("Before l = %d, r = %d, mid = %d, ans = %d\n", l, r, mid, ans);
        if(Check(mid))ans = mid, r = mid - 1;
        else l = mid + 1;
        // printf("l = %d, r = %d, mid = %d, ans = %d\n", l, r, mid, ans);
    }printf("%d\n", ans);
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
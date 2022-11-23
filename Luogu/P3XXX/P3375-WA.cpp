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

typedef unsigned __int128 u128;

#define unll u128
#define P (unll)(31)

template < typename T = int >
inline T read(void);

int len1, len2;
string S1, S2;
unll power[1100000];
unll hash1[1100000];
unll hash2[1100000];

unll Hash1(int s, int len = len2){
    return hash1[s + len - 1] - hash1[s - 1] * power[len];
}
unll Hash2(int s, int len){
    return hash2[s + len - 1] - hash2[s - 1] * power[len];
}

int main(){
    // freopen("out.txt", "w", stdout);
    cin >> S1 >> S2;
    len1 = S1.size(), len2 = S2.size();
    power[0] = 1;
    for(int i = 1; i <= 1010000; ++i)power[i] = power[i - 1] * P;
    for(int i = 1; i <= len1; ++i)hash1[i] = hash1[i - 1] * P + (unll)S1.at(i - 1);
    for(int i = 1; i <= len2; ++i)hash2[i] = hash2[i - 1] * P + (unll)S2.at(i - 1);
    for(int i = 1; i + len2 - 1 <= len1; ++i)if(Hash1(i) == hash2[len2])printf("%d\n", i);
    for(int siz = 1; siz <= len2; ++siz){
        int l = 1, r = siz - 1, ans(0);
        while(l <= r){
            int mid = (l + r) >> 1;
            if(Hash2(1, mid) == Hash2(siz - mid + 1, mid))ans = mid, l = mid + 1;
            else r = mid - 1;
        }printf("%d ", ans);
    }printf("\n");
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
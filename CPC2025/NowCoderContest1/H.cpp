#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

#define SIZ (16)
#define MASK ((1 << SIZ) - 1)

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;


template<typename T = int>
inline T read(void);

int L[1 << SIZ], R[1 << SIZ], val[1 << SIZ];
int block[1100000];
bool s[1100000];
int Left[1100000], Right[1100000];

void Reverse(int l, int r){
    int lB = l / SIZ, rB = r / SIZ;
    if(lB == rB){
        // for(int i = l % SIZ; i <= r % SIZ; ++i)block[lB] ^= (1 << i);
        block[lB] ^= ((1 << (r - l + 1)) - 1) << (l % SIZ);
        return;
    }
    for(int i = lB + 1; i <= rB - 1; ++i)block[i] ^= MASK;
    block[lB] ^= ((1 << (SIZ - l % SIZ)) - 1) << (l % SIZ);
    block[rB] ^= (1 << (r % SIZ + 1)) - 1;
    // for(int i = l % SIZ; i < SIZ; ++i)block[lB] ^= (1 << i);
    // for(int i = 0; i <= r % SIZ; ++i)block[rB] ^= (1 << i);
}

void Substr(int pos, int len, int *arr){
    for(int i = 0; i <= len / SIZ; ++i)
        arr[i] =
            (block[i + pos / SIZ] >> (pos % SIZ))
            | (block[i + pos / SIZ + 1] << (SIZ - pos % SIZ))
            & MASK;
}

ll Merge(int len){
    ll cnt(0), ret(0);
    for(int i = 0; i < len / SIZ; ++i){
        int cur = Left[i] ^ Right[i];
        if(cur){
            cnt += L[cur];
            ret += ((cnt * (cnt + 1)) >> 1) + val[cur];
            cnt = R[cur];
        }else cnt += SIZ;
    }
    int cur = Left[len / SIZ] ^ Right[len / SIZ];
    for(int i = 0; i < len % SIZ; ++i){
        if((cur >> i) & 1)
            ret += (cnt * (cnt + 1)) >> 1, cnt = 0;
        else ++cnt;
    }return ret + ((cnt * (cnt + 1)) >> 1);
}

int main(){
    for(int S = 0; S <= MASK; ++S){
        int cnt(0);
        bool exist(false);
        for(int i = 0; i < SIZ; ++i){
            if((S >> i) & 1){
                exist
                    ? (val[S] += (cnt * (cnt + 1)) >> 1)
                    : (exist = true, L[S] = cnt);
                cnt = 0;
            }else ++cnt;
        }R[S] = cnt;
    }

    int N = read(), Q = read();
    for(int i = 0; i < N; ++i){
        char c = getchar(); while(c != '0' && c != '1')c = getchar();
        s[i] = c - '0';
        block[i / SIZ] |= s[i] << (i % SIZ);
    }
    
    basic_string < int > toBeReversed;

    while(Q--){
        int opt = read();
        if(opt == 1){
            int l = read(), r = read();
            toBeReversed += {l - 1, r + 1 - 1};
        }else{
            int len = read(), a = read(), b = read();
            sort(toBeReversed.begin(), toBeReversed.end());
            for(auto it = toBeReversed.begin(); it != toBeReversed.end() && it != prev(toBeReversed.end()); advance(it, 2))
                if(*it < *next(it))Reverse(*it, *next(it) - 1);
            toBeReversed.clear();
            Substr(a - 1, len, Left), Substr(b - 1, len, Right);
            printf("%lld\n", Merge(len));
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


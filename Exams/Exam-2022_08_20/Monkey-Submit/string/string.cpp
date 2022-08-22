
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define MOD 998244353


#define abbr

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

string A, B;
int N, K;
uint hash_[110000];
uint cmpH;
uint makeHash_(string S){
    uint ret(0);
    for(auto i : S){
        ret *= 26;
        ret += i;
    }
    return ret;
}
uint kpow(uint a, uint b){
    uint ret(1), mul(a);
    while(b){
        if(b & 1)ret *= mul;
        b >>= 1;
        mul *= mul;
    }
    return ret;
}
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    N = read(), K = read();
    cin >> A >> B;
    int Q = read();
    // int tmpp(Q);
    while(Q--){
        int ans(0);
        int s = read(), t = read(), l = read(), r = read();
        int lenA(t - s + 1), lenB(r - l + 1);
        // for(int i = s; i + lenB - 1 <= t; ++i){
        //     bool ac(true);
        //     for(int j = 1; j <= l + r - 1; ++j){
        //         if(A[i + j - 1 - 1] != B[l + j - 1 - 1]){
        //             ac = false;
        //             break;
        //         }
        //     }
        //     if(ac){
        //         ans += K - i;
        //         i = i + lenB - 1;
        //     }
        // }
        // printf("%d\n", ans);

        memset(hash_, 0, sizeof(hash_));
        string sA(A.begin() + s - 1, A.begin() + t), sB(B.begin() + l - 1, B.begin() + r);
        cmpH = makeHash_(sB);
        string tmp(sA.begin(), sA.begin() + lenB - 1 + 1);

        // if(tmpp - Q == 15)
        //     cout<<sA<<endl<<sB<<endl<<tmp<<endl;

        // int hah = makeHash_(tmp);
        
        //in sA
        hash_[0] = makeHash_(tmp);
        for(int i = 1; i + lenB - 1 <= lenA - 1; ++i){
            uint hsh(hash_[i - 1]);
            hsh -= (uint)kpow(26, lenB - 1) * sA[i - 1];
            hsh *= (uint)26;
            hsh += (uint)sA[i + lenB - 1];
            hash_[i] = hsh;
        }
        for(int i = 0; i + lenB - 1 <= lenA - 1; ++i){
            if(hash_[i] == cmpH){
                ans += K - (s + i);
                i = i + lenB - 1;
            }
        }



        // hash_[0] = makeHash_(tmp);
        // for(int i = 1; i + lenB - 1 <= A.size(); ++i){
        //     uint hah(hash_[i - 1]);
        //     hah -= (uint)kpow(26, lenB - 1) * A[i - 1];
        //     hah *= (uint)26;
        //     hah += (uint)A[i + lenB - 1];
        //     hash_[i] = hah;
        // }
        // for(int i = 0; i + lenB - 1 <= lenA; ++i){
        //     if(hash_[s + i] == cmpH){
        //         ans += K - (s + i);
        //         i = i + lenB - 1;
        //     }
        // }
        // if(tmpp - Q == 15)
        // for(int i = 0; i + lenB - 1 <= lenA; ++i)printf("%u ", hash_[i]);
        // if(tmpp - Q == 15)
        // printf("\nCMP:%u\n", cmpH);
        printf("%d\n", ans);



    }
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
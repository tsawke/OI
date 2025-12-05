#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

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

int N;
const ll MOD = 998244353ll;

ll qpow(ll a, ll b, ll mod = MOD){
    if(b < 0)return 0;
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % mod;
        b >>= 1;
        mul = mul * mul % mod;
    }return ret;
}

const ll g(3), inv_g(qpow(g, MOD - 2));

enum Pattern{DFT, IDFT};

class Polynomial{
private:
    vector < int > pos;
public:
    int len;
    vector < ll > poly;
    Polynomial(void){
        this->len = 0;
        this->poly.resize(0), this->poly.shrink_to_fit();
    }
    Polynomial(int len){
        this->len = len;
        this->poly.assign(len, 0);
    }
    void Reverse(void){
        pos.resize(len);
        if(len > 0)pos[0] = 0;
        for(int i = 0; i < len; ++i)
            pos[i] = (pos[i >> 1] >> 1) | (i & 1 ? len >> 1 : 0);
        for(int i = 0; i < len; ++i)if(i < pos[i])swap(poly[i], poly[pos[i]]);
    }
    void NTT(Pattern pat){
        Reverse();
        for(int siz = 2; siz <= len; siz <<= 1){
            ll gn = qpow(pat == DFT ? g : inv_g, (MOD - 1) / siz);
            for(auto p = poly.begin(); p < next(poly.begin(), len); advance(p, siz)){
                int mid = siz >> 1; ll g(1);
                for(int i = 0; i < mid; ++i, (g *= gn) %= MOD){
                    auto tmp = g * p[i + mid] % MOD;
                    p[i + mid] = (p[i] - tmp + MOD) % MOD;
                    p[i] = (p[i] + tmp) % MOD;
                }
            }
        }
        if(pat == IDFT){
            ll inv_len = qpow(len, MOD - 2);
            for(int i = 0; i < len; ++i)(poly[i] *= inv_len) %= MOD;
        }
    }
    void Resize(int len){
        this->poly.resize(len), this->len = len;
    }
};


class Bignum{
private:
public:
    basic_string < int > nums;
    friend Bignum operator + (Bignum a, Bignum b){
        // reverse(a.nums.begin(), a.nums.end());
        // reverse(b.nums.begin(), b.nums.end());
        while(a.nums.size() < b.nums.size())a.nums += 0;
        while(b.nums.size() < a.nums.size())b.nums += 0;
        Bignum ret; bool plus(false);
        for(int i = 0; i < (int)a.nums.size(); ++i){
            a.nums.at(i) += b.nums.at(i) + plus;
            plus = false;
            if(a.nums.at(i) >= 10)
                plus = true, a.nums.at(i) %= 10;
        }
        if(plus)a.nums += 1;
        // reverse(a.nums.begin(), a.nums.end());
        return a;
    }
    friend Bignum operator * (Bignum a, Bignum b){
        // reverse(a.nums.begin(), a.nums.end());
        // reverse(b.nums.begin(), b.nums.end());
        Bignum ret;
        for(int i = 1; i <= (int)(a.nums.size() + b.nums.size()); ++i)ret.nums += 0;
        for(auto i = 0; i < (int)a.nums.size(); ++i)
            for(int j = 0; j < (int)b.nums.size(); ++j)
                ret.nums.at(i + j) += a.nums.at(i) * b.nums.at(j);
        for(int i = 0; i < (int)ret.nums.size() - 1; ++i)
            ret.nums.at(i + 1) += ret.nums.at(i) / 10, ret.nums.at(i) %= 10;
        if(ret.nums.back() >= 10)ret.nums += ret.nums.back() / 10, *prev(ret.nums.end(), 2) %= 10;
        while(ret.nums.size() > 1 && ret.nums.back() == 0)ret.nums.pop_back();
        // reverse(ret.nums.begin(), ret.nums.end());
        return ret;
    }
    friend Bignum operator / (Bignum a, ll div){
        Bignum ret;
        ll cur(0); bool flag(false);
        for(auto i : a.nums){
            cur *= 10, cur += i;
            if(cur < div && !flag)continue;
            flag = true, ret.nums += cur / div, cur %= div;
        }return ret;
    }
    void Print(void){
        for(auto v : nums)printf("%d", v);
        printf("\n");
    }
};

Bignum qpow(Bignum a, ll b){
    Bignum ret, mul(a);
    ret.nums += 1;
    while(b){
        if(b & 1)ret = ret * mul;
        b >>= 1;
        mul = mul * mul;
    }return ret;
}

int main(){

    int T = read();
    while(T--){
        string SA, SB; cin >> SA >> SB;
        Polynomial A(SA.length()), B(SB.length());
        for(int i = 0; i < A.len; ++i)A.poly[i] = int(SA[A.len - i - 1] - '0');
        for(int i = 0; i < B.len; ++i)B.poly[i] = int(SB[B.len - i - 1] - '0');
        int clen = A.len + B.len - 1;
        int base(1); while(base < clen)base <<= 1;
        A.Resize(base), B.Resize(base);
        A.NTT(DFT), B.NTT(DFT);
        for(int i = 0; i < A.len; ++i)A.poly[i] = A.poly[i] * B.poly[i] % MOD;
        A.NTT(IDFT);

        int fst1 = A.len - 1;
        while(fst1 >= 0 && A.poly[fst1] == 0)--fst1;

        vector < ll > ans;
        for(auto it = A.poly.begin(); it != next(A.poly.begin(), fst1 + 1); advance(it, 1))ans.emplace_back(*it);

        // for(int i = fst1; i >= 0; --i)printf("%lld", A.poly[i]);
        // printf("\n");

        // if(ans.size() == 0){printf("0\n"); continue;}
    
        // for(int i = 0; i < ans.size(); ++i){
        //     printf("i = %d, ans = %lld\n", i, ans[i]); fflush(stdout);
        //     if(ans[i] <= 1)continue;
        //     if(i + 4 > ans.size())ans.resize(i + 4, 0);
        //     ans[i + 4] += ans[i] >> 1;
        //     ans[i + 2] += ans[i] >> 1;
        //     ans[i] %= 2;
        // }
        auto ToNegBinary = [](vector < ll >& d)->void{
            for(int i = 0; i < d.size(); ++i){
                while(d[i] < 0 || d[i] > 1){
                    ll r = ((d[i] % 2) + 2) % 2;
                    ll q = (d[i] - r) / -2;
                    d[i] = r;
                    if(i + 1 >= d.size())d.resize(i + 2, 0);
                    d[i + 1] += q;
                }
            }
            while(d.size() > 1 && d.back() == 0)d.pop_back();
        };

        vector < ll > even, odd;
        for(int i = 0; i < ans.size(); ++i)
            (i & 1 ? odd : even).emplace_back(ans[i]);

        ToNegBinary(even);
        ToNegBinary(odd);

        int M(max(even.size(), odd.size()));
        vector < ll > res(2 * M, 0);
        for(int i = 0; i < M; ++i){
            if(i < even.size())res[i << 1] = even[i];
            if(i < odd.size())res[(i << 1) | 1] = odd[i];
        }
        while(res.size() > 1 && res.back() == 0) res.pop_back();

        if(res.empty()) puts("0");
        else{
            for(auto it = res.rbegin(); it != res.rend(); ++it)
                printf("%lld", *it);
            printf("\n");
        }

        // for(auto it = ans.rbegin(); it != ans.rend(); ++it)printf("%lld", *it);

            
    }

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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
#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define base (315)
#define MOD1 (998244353)
#define MOD2 (353448299)

template<typename T = int>
inline T read(void);

int N;
int cnt(0);
vector<uint>hash1;
vector<uint>hash2;
vector<uint>hash_;
uint kpow(int a, int b, int mod){
    uint ret(1);
    uint mul(a);
    while(b){
        if(b & 1)ret = (ret * mul) % mod;
        b >>= 1;
        mul = (mul * mul) % mod;
    }
    return ret;
}

int main(){
    // (void)!freopen("./P3370_2.in", "r", stdin);
    N = read();
    string s;
    for(int i = 1; i <= N; ++i){
        uint val1(0), val2(0);
        cin>>s;
        // int k(-1);
        for(auto i : s){
            val1 = (val1 * base) % MOD1; val2 = (val2 * base) % MOD2;
            val1 += i; val2 += i;
        }
        // hash_.push_back(val1 + val2);
        if(find(hash1.begin(), hash1.end(), val1) == hash1.end() || find(hash2.begin(), hash2.end(), val2) == hash2.end()){
            hash1.push_back(val1), hash2.push_back(val2);
            ++cnt;
        }

    }
    // sort(hash_.begin(), hash_.end());
    // for(int i = 1; i <= (int)hash_.size() - 1; ++i)if(hash_.at(i - 1) != hash_.at(i - 1 + 1))++cnt;
    printf("%d\n", cnt);


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
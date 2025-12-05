#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

namespace Default{
    mt19937 rnd(random_device{}());
    int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
    template<typename T = int>
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
    ll readBignum(ll MOD){
        ll ret(0);
        char c = getchar();
        while(!isdigit(c))c = getchar();
        while(isdigit(c)){
            ret = (ret * 10 + int(c - '0')) % MOD;
            c = getchar();
        }
        return ret;
    }
    ll readBignum(ll MOD, string num){
        ll ret(0);
        for(auto c : num){
            if(!isdigit(c))continue;
            ret = (ret * 10 + int(c - '0')) % MOD;
        }
        return ret;
    }
    ll qmul(ll x, ll y, ll MOD){
        return (__int128_t)x * y % MOD;
        // ll quot = (ld)x / MOD * y;
        // ll ret = (unll)x * y - (unll)quot * MOD;
        // return (ret + MOD) % MOD;
    }
    ll qpow(ll a, ll b, ll MOD){
        ll ret(1), mul(a);
        while(b){
            if(b & 1)ret = qmul(ret, mul, MOD);
            b >>= 1;
            mul = qmul(mul, mul, MOD);
        }
        return ret;
    }
    bool MillerRabin(ll n, bool special = false){
        int prime[20] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        if(n % 2 == 0 || n <= 2)return n == 2;
        ll power(n - 1); int cnt(0);
        while(power % 2 == 0)power /= 2, ++cnt;
        int times = special ? 1 : 12;
        while(times--){
            if(n == prime[times + 1])return true;
            ll base = prime[times + 1], res = qpow(base, power, n);
            ll nxt;
            // if(res == n - 1 || res == 1)continue;
            for(int i = 1; i <= cnt; ++i){
                nxt = qmul(res, res, n);
                if(nxt == 1 && res != 1 && res != n - 1)return false;
                res = nxt;
            }
            if(nxt != 1)return false;
        }
        return true;
    }
}

namespace Case_1_2_3{
    void Make(ll MOD = 998244353){
        int N = Default::read();
        for(int i = 1; i <= N; ++i){
            ll x = Default::readBignum(MOD - 1);
            printf("%lld\n", Default::qpow(19, x, MOD));
        }
    }
}
namespace Case_4{
    ll FindMod(void){
        string val_s("627811703016764290815178977207148434322");
        ll std_res = 642666;
        for(ll i = 1145099 + 1; i <= LLONG_MAX; ++i){
            if(i % 2 == 0 || !Default::MillerRabin(i))continue;
            ll val = Default::readBignum(i - 1, val_s);
            ll res = Default::qpow(19, val, i);
            if(res == std_res)return i;
        }
    }
    void Make(void){
        Case_1_2_3::Make(1145141ll);
    }
}
namespace Case_5{
    void Make(void){
        Case_1_2_3::Make(5211600617818708273ll);
    }
}
namespace Case_6_7{
    const int MOD(998244353);
    int ans[11000000];
    int beg(-1), siz(-1);
    void FindCirc(void){
        map < int, int > mp;
        int base(1);
        mp.insert({ans[0] = base, 0});
        for(int i = 1; true; ++i){
            if(mp.find(base = signed((unsigned)base * (unsigned)19) % MOD) != mp.end()){beg = mp[base], siz = i - mp[base]; return;}
            else mp.insert({ans[i] = base, i});
        }
    }
    void Make(void){
        FindCirc();
        int N = Default::read();
        for(int i = 1; i <= N; ++i){
            ll x = Default::read<ll>();
            if(x < beg)printf("%d\n", ans[x]);
            else printf("%d\n", ans[(x - beg) % siz + beg]);
        }
    }
}
namespace Case_8_9_10{
    void Make(void){
        int N = Default::read();
        for(int i = 1; i <= N; ++i){
            ll l = Default::read<ll>(), r = Default::read<ll>();
            for(ll x = l; x <= r; ++x){
                printf("%c", Default::MillerRabin(x) ? 'p' : '.');
            }
            printf("\n");
        }
    }
}
namespace Case_11_12_13{
    #define PRE (ll)(1e6)
    #define RPOS beg - l + 1
    void Make(void){
        vector < int > prime;
        bool vis[PRE + 10];
        int mu[PRE + 10];
        vis[1] = true, mu[1] = 1;
        for(int i = 2; i <= PRE; ++i){
            if(!vis[i]){
                vis[i] = true;
                mu[i] = -1;
                prime.push_back(i);
            }
            for(auto p : prime){
                if(p * i > PRE)break;
                vis[p * i] = true;
                mu[p * i] = i % p == 0 ? 0 : -mu[i];
                if(i % p == 0)break;
            }
        }
        int N = Default::read();
        while(N--){
            ll l = Default::read<ll>(), r = Default::read<ll>();
            if(r <= PRE){
                for(int i = l; i <= r; ++i){
                    printf("%c", mu[i] == 1 ? '+' : (mu[i] == -1 ? '-' : '0'));
                }
                printf("\n");
                continue;
            }
            int siz = r - l + 1;
            ll value[1100000];
            for(int i = 1; i <= siz; ++i)value[i] = (ll)i + l - 1;
            int mu_r[1100000];
            memset(mu_r, 0x3f, sizeof(mu_r));
            for(auto p : prime){
                ll times = l / p;
                ll beg = p * times;
                while(beg < l)beg += p;
                while(beg <= r){
                    value[RPOS] /= p;
                    if(value[RPOS] % p == 0)mu_r[RPOS] = 0;
                    mu_r[RPOS] = mu_r[RPOS] > 1 ? -1 : -mu_r[RPOS];
                    beg += p;
                }
            }
            for(int i = 1; i <= siz; ++i){
                if(mu_r[i] == 0 || value[i] == 1)continue;
                if(Default::MillerRabin(value[i], true))mu_r[i] = mu_r[i] > 1 ? -1 : -mu_r[i];
                else if(value[i] != 1 && (ll)sqrt(value[i]) * (ll)sqrt(value[i]) == value[i])mu_r[i] = 0;
                else if(mu_r[i] > 1)mu_r[i] = 1;
            }
            for(int i = 1; i <= siz; ++i)printf("%c", mu_r[i] == 1 ? '+' : (mu_r[i] == -1 ? '-' : mu_r[i] == 0 ? '0' : '?'));
            printf("\n");
        }
    }
    #undef PRE
    #undef RPOS
}
namespace Case_14_15_16{
    #define PRE (int)(1e6)
    vector < ll > prime;
    bool vis[PRE + 100];
    void Pretreat(void){
        vis[1] = true;
        for(int i = 2; i <= PRE; ++i){
            if(!vis[i])prime.push_back(i), vis[i] = true;
            for(auto p : prime){
                if(p * i > PRE)break;
                vis[p * i] = true;
                if(i % p == 0)break;
            }
        }
    }
    vector < ll > Resolve(ll x){
        #ifndef PRETREAT
        #define PRETREAT
        Pretreat();
        #endif//PRETREAT
        vector < ll > ret;
        for(auto p : prime){
            if(p * p > x)break;
            if(x % p == 0)ret.push_back(p);
            while(x % p == 0)x /= p;
        }
        if(x != 1)ret.push_back(x);
        return ret;
    }
    map < ll, ll > mp;
    ll FindMinG(ll x){
        if(mp.find(x) != mp.end())return mp[x];
        vector < ll > fact = Resolve(x - 1);
        for(ll i = 2; i <= (ll)pow(x, 0.25); ++i){
            bool flag(true);
            for(auto p : fact){
                if(Default::qpow(i, (x - 1) / p, x) == 1){flag = false; break;}
            }
            if(flag){
                mp.insert({x, i});
                return i;
            }
        }
        return -1;
    }
    void Make(void){
        int N = Default::read();
        for(int i = 1; i <= N; ++i){
            ll l = Default::read<ll>(), r = Default::read<ll>();
            ll MOD = l != 233333333ll ? Default::read<ll>() : 1515343657ll;
            if(MOD == 998244353ll || MOD == 1515343657ll){
                vector < ll > frac = Resolve(MOD - 1);
                for(ll x = l; x <= r; ++x){
                    bool flag(true);
                    for(auto p : frac)
                        if(Default::qpow(x, (MOD - 1) / p, MOD) == 1){printf("."); flag = false; break;}
                    if(flag)printf("g");
                }
                printf("\n");
                continue;
            }
            vector < ll > frac = Resolve(MOD - 1);
            ll G = FindMinG(MOD);//fprintf(stderr, "G: %lld\n", G);
            #define CMOD (13123111)
            bool mark[CMOD + 100];
            for(auto p : frac)
                for(ll j = 1; j * p <= CMOD; ++j)
                    mark[j * p] = true;
            int logg[CMOD + 100];
            memset(logg, 0, sizeof(logg));
            for(ll cur(1), base(0); base <= CMOD; ++base, cur = cur * G % CMOD)
                logg[cur] = base;
            for(ll x = l; x <= r; ++x)
                printf("%c", mark[logg[x]] ? '.' : 'g');
            printf("\n");
        }
    }
}

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    string filename; cin >> filename;
    if(!filename.compare("1_998244353"))Case_1_2_3::Make();
    if(!filename.compare("1?"))Case_4::Make();
    if(!filename.compare("1?+"))Case_5::Make();
    if(!filename.compare("1wa_998244353"))Case_6_7::Make();
    if(!filename.compare("2p"))Case_8_9_10::Make();
    if(!filename.compare("2u"))Case_11_12_13::Make();
    if(!filename.compare("2g") || !filename.compare("2g?"))Case_14_15_16::Make();

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
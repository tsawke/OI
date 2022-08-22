#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

unll M, x;
unll ans(0ull);
unll phiM;

template<typename T = int>
inline T read(void);


vector< pair<unll, int>/*<Prime, Exist>*/ >Prime;
vector< pair<unll, int>/*<Prime, Exist>*/ >exPrime;
bool notPrime[10000010] = {true, true};
void Init(void);
unll Resolve(unll);
void exRes(unll);
unll kpow(unll, unll, unll);
unll kmul(ll, ll, ll);
bool Verify(unll, unll, unll);
void Create(void);
void Cal(unll);


double CalTime(0.00000000000);
double POWT(0.0000000000000);
int main(){
    M = read<unll>(), x = read<unll>();
    Init();
    printf("________________%d\n", (int)Prime.size());
    Create();
    printf("%llu\n", ans);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    fprintf(stderr, "PowTime: %.6lf\n", POWT);
    return 0;
}
void Cal(unll _i){
    double TMP1((double)clock() / CLOCKS_PER_SEC);


    unll d = M / _i;
    unll phi(phiM);
    unll quot(_i); //quotient: M / d
    for(auto i : Prime){
        if(!i.second)continue;
        if(quot % i.first)continue;
        if(d % i.first)quot /= i.first, phi /= (i.first - 1);
        while(quot % i.first == 0)quot /= i.first, phi /= i.first;
    }
    double TMP2((double)clock() / CLOCKS_PER_SEC);
    CalTime += TMP2 - TMP1;

    unll s(phi);
    for(int i = 1; i <= (int)exPrime.size(); ++i){
        while(exPrime.at(i - 1).second && Verify(::x, s / exPrime.at(i - 1).first, d) && s > 1ull && s % exPrime.at(i - 1).first == 0){
            s /= exPrime.at(i - 1).first;

        }
    }
    ans += phi / s;


    
}
void Create(void){
    double TMPP1((double)clock() / CLOCKS_PER_SEC);
    for(int i = 1; (unll)i * i <= M; ++i){
        if(M % i == 0ull){
            Cal(i);
            if((unll)M / i != (unll)i)Cal(M / i);
        }
    }
    double TMPP2((double)clock() / CLOCKS_PER_SEC);
    fprintf(stderr, "Cal Time: %.6lf\n", (double)CalTime);
    fprintf(stderr, "Create Time: %.6lf\n", TMPP2 - TMPP1 - CalTime);
}
bool Verify(unll x, unll k, unll __MOD){
    return kpow(x, k, __MOD) == 1;
}
unll kpow(unll a, unll b, unll __MOD){
    double T1((double)clock() / CLOCKS_PER_SEC);
    ll _MOD = __MOD > LONG_LONG_MAX ? LONG_LONG_MAX : __MOD;
    unll ret(1ull);
    unll MUL(a);
    while(b){
        if(b & 1ull)ret = kmul(ret, MUL, _MOD);
        MUL = kmul(MUL, MUL, _MOD);
        b >>= 1;
    }
    double T2((double)clock() / CLOCKS_PER_SEC);
    POWT += T2 - T1;
    return ret;
}
unll kmul(ll a, ll b, ll __MOD){
    ll d = (ll)floor(a * (long double)b / __MOD + 0.5);
    ll ret = a * b - d * __MOD;
    if(ret < 0ll)ret += __MOD;
    return (unll)ret;
}
void Init(void){
    fprintf(stderr, "Init Prime Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    for(int i = 2; (unll)i * i <= M; ++i){
        if(notPrime[i])continue;
        Prime.push_back(make_pair(i, 0));
        for(auto _p : Prime){
            int p;
            tie(p, ignore) = _p;
            if((unll)p * i * p * i > M)break;
            notPrime[p * i] = true;
            if(i % p == 0)break;
        }
    }
    fprintf(stderr, "Resolve Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    phiM = Resolve(M);
    fprintf(stderr, "exResolve Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    exPrime = Prime;
    for(auto i : Prime)
        if(i.second)
            exRes(i.first - 1);
}
void exRes(unll fact){
    for(auto &i : exPrime){
        if(fact == 1 || !fact)break;
        if(i.first * i.first > fact)break;
        if(i.second)continue;
        if(fact % i.first == 0)
            ++i.second;
    }
}
unll Resolve(unll M){
    unll phi(M);
    for(auto &i : Prime)i.second = 0;
    for(auto &i : Prime){
        if(!M)break;
        bool flag(false);
        while(M % i.first == 0){
            M /= i.first;
            ++i.second;
            if(!flag){
                flag = true;
                phi /= i.first;
                phi *= i.first- 1;
            }
        }
    }
    if(M != 1){
        Prime.push_back(make_pair(M, 1));
        phi /= Prime.back().first;
        phi *= Prime.back().first - 1;
    }
    return phi;
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
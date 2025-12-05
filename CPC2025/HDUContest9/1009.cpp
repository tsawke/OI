#include <bits/stdc++.h>

typedef long long LL; typedef __int128 BigInt;
const LL mod = 998244353;

LL qpow(LL a, LL b, LL P) {
    LL res = 1; a %= P, b %= P - 1;
    while(b) {
        if(b & 1) res = res * a % P;
        a = a * a % P, b >>= 1;
    }
    return res;
}

LL P;

LL bf() {
    BigInt k = (P + 118) / 119, A = (1ll << k), B = (A << k);

    BigInt ans = 0;
    for(int i = 1; i < P; i++) ans ^= (qpow(i, P - 2, P) + A) * (i + B);

    return LL(ans % mod);
}

LL calc() {
    LL k = (P + 118) / 119, s = ((P % 4 == 1) ? (P - 1 + mod) : P) % mod;

    return (1 + qpow(8, k, mod) + s * qpow(2, k, mod) % mod + s * qpow(4, k, mod) % mod) % mod;
}

void solve() {
    scanf("%lld", &P);

    printf("%lld\n", P < 2000 ? bf() : calc());
    printf("  another %lld\n", P < 2000 ? calc() : bf());
}

int main() {
    int T; scanf("%d", &T); while(T--) solve();
    return 0;
}
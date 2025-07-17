#pragma GCC optimize("Ofast,unroll-loops,inline")
#include <bits/stdc++.h>
void input(int &x) {
    x = 0; char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
}
void input(bool *s) {
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    int i = 0;
    while(isdigit(c)) s[++i] = (c == '1'), c = getchar();
}
typedef long long LL; const int N = 1e6 + 7;
int n, q; bool s[N], flag[N]; std::vector<int> vec;
int main() {
    input(n), input(q), input(s);
    while(q--) {
        int opt, l, r, a, b; input(opt), input(l);
        if(opt == 1) {
            input(r), vec.push_back(l), vec.push_back(r + 1);
        } else {
            input(a), input(b);
            if(vec.size() < 5e4) {
                std::sort(vec.begin(), vec.end());
                int m = vec.size(), len = 0; LL ans = 0;
                for(int i = 0, x = 0, y = 0; i < l; i++) {
                    while(x < m && vec[x] <= a + i) x++;
                    while(y < m && vec[y] <= b + i) y++;
                    if((s[a + i] ^ (x & 1)) == (s[b + i] ^ (y & 1))) {
                        len++;
                    } else {
                        ans += (LL)len * (len + 1) / 2;
                        len = 0;
                    }
                }
                printf("%lld\n", ans + (LL)len * (len + 1) / 2);
            } else {
                for(int i : vec) flag[i] ^= 1;
                vec.clear(); bool cur = 0;
                for(int i = 1; i <= n; i++) {
                    cur ^= flag[i], flag[i] = 0;
                    if(cur) s[i] ^= 1;
                }
                int len = 0; LL ans = 0;
                for(int i = 0; i < l; i++) {
                    if(s[a + i] == s[b + i]) {
                        len++;
                    } else {
                        ans += (LL)len * (len + 1) / 2;
                        len = 0;
                    }
                }
                printf("%lld\n", ans + (LL)len * (len + 1) / 2);
            }
        }
    }
    return 0;
}
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

unordered_map < int, int > cntA, cntB;
int A[110000], B[110000];

int N, K;

class BIT{
private:
    ll tr[210000];
public:
    void Clear(int lim){for(int i = 0; i <= (lim << 1); ++i)tr[i] = 0;}
    int lowbit(int x){return x & -x;}
    void Modify(int x, int v){while(x <= N)tr[x] += v, x += lowbit(x);}
    ll Query(int x){ll ret(0); while(x)ret += tr[x], x -= lowbit(x); return ret;}
    void ModifyRange(int l, int r, ll v){Modify(l, v), Modify(r + 1, -v);}
}bit;

int main(){
    int T = read();
    while(T--){
        bool hasSame(false);
        cntA.clear(), cntB.clear();
        N = read(), K = read();
        bit.Clear(N);
        for(int i = 1; i <= N; ++i)++cntA[A[i] = read()];
        for(int i = 1; i <= N; ++i)++cntB[B[i] = read()];
        bool flag(true);
        for(auto [key, val] : cntA){
            if(cntB[key] != val){flag = false; break;}
            if(val > 1)hasSame = true;
        }
        if(!flag){printf("NO\n"); continue;}

        if(K == 1){
            bool flag(true);
            for(int i = 1; i <= N; ++i)
                if(A[i] != B[i]){flag = false; break;}
            if(!flag){printf("NO\n"); continue;}
        }

        if(K == N){
            auto CalPrefixFunc = [](basic_string < int > s)->vector < int >{
                int n = (int)s.size();
                vector<int> pi(n);
                for (int i = 1; i < n; i++) {
                    int j = pi[i - 1];
                    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
                    if (s[i] == s[j]) j++;
                    pi[i] = j;
                }
                return pi;
            };
            auto KMP = [&](basic_string < int > text, basic_string < int > pattern)->bool{
                basic_string < int > cur;
                cur += pattern; cur += -1; cur += text;
                // cur += {pattern, -1, text};
                int sz1 = text.size(), sz2 = pattern.size();
                vector<int> lps = CalPrefixFunc(cur);
                for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
                    if (lps[i] == sz2) return true;
                }
                return false;
            };
            basic_string < int > pat, text;
            for(int i = 1; i <= N; ++i)pat += A[i], text += B[i];
            printf("%s\n", KMP(text + text, pat) ? "YES" : "NO");
            continue;
        }

        if(hasSame || !(K & 1)){printf("YES\n"); continue;}

        vector < int > data;
        for(int i = 1; i <= N; ++i)data.push_back(A[i]);
        sort(data.begin(), data.end());
        data.erase(unique(data.begin(), data.end()), data.end());
        unordered_map < int, int > idx;
        for(auto it = data.begin(); it != data.end(); advance(it, 1))
            idx[*it] = distance(data.begin(), it) + 1;

        vector < int > pos(N + 10, 0);
        for(int i = 1; i <= N; ++i)pos[idx[B[i]]] = i;
        ll cnt(0);
        for(int i = 1; i <= N; ++i){
            cnt += bit.Query(N - pos[idx[A[i]]] + 1);
            bit.Modify(N - pos[idx[A[i]]] + 1, 1);
        }
        // printf("cnt = %d\n", cnt);
        printf("%s\n", (cnt & 1) ? "NO" : "YES");
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
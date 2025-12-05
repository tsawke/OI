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

template < typename T = int >
inline T read(void);



int main(){
    int T = read();
    while(T--){
        int N = read(); ll K = read < ll >(); int M = read();
        set < int > ban;
        auto Char2Int = [](char c)->int{
            if(isdigit(c))return int(c - '0');
            return c - 'A' + 10;
        };
        for(int i = 1; i <= M; ++i){
            char c = getchar();
            while(!isdigit(c) && !isupper(c))c = getchar();
            ban.insert(Char2Int(c));
        }
        // sort(ban.begin(), ban.end());
        basic_string < int > res;
        auto Int2Char = [](int val)->char{
            if(val <= 9)return '0' + val;
            return 'A' + (val - 10);
        };
        vector < int > cnt(N + 10, 0);
        for(auto p : ban)++cnt[p];
        for(int i = 1; i <= N; ++i)cnt[i] += cnt[i - 1];
        vector < int > nxt(N + 10, 0);
        for(int i = 1; i <= N - M - 1; ++i){
            int cur(0);
            if(cnt[i] == 0){nxt[i] = i; continue;}
            for(int j = i + 1; j <= N - 1; ++j)
                if(ban.find(j) == ban.end())
                    if(++cur == cnt[i]){nxt[i] = j; break;}
        }
        while(K > 0)res += K % (N - M), K /= (N - M);
        // for(auto it = res.rbegin(); it != res.rend(); advance(it, 1))printf("> %d\n", *it);
        for(auto it = res.rbegin(); it != res.rend(); advance(it, 1)){
            printf("%c", Int2Char(nxt[*it]));
        }printf("\n");
    }

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template < typename T >
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
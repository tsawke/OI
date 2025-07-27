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

int N;
string S;
int w[20];
int len;

bitset < 17 > bit[3100];
bitset < 17 > cur;
int cost(0);
int ans(INT_MAX);

int main(){
    int T = read();
    while(T--){
        N = read();
        cin >> S;
        for(int i = 0; i < 17; ++i)w[i] = read();
        for(int i = 0; i <= N; ++i)bit[i].reset();
        len = read();
        if(len & 1)++len;
        int cnt(0);
        for(int i = 1; i + len - 1 <= N; ++i){
            ++cnt;
            bool flag(false);
            for(int j = i; j <= i + (len >> 1) - 1; ++j){
                int p = j, q = i + len - 1 - (j - i);
                // printf("i = %d, j = %d, p = %d, q = %d, comparing %c, %c\n", i, j, p, q, S[p - 1], S[q - 1]);
                if(S[p - 1] == S[q - 1]){flag = true; break;}
                bit[cnt][S[p - 1] < S[q - 1] ? S[p - 1] - 'a' : S[q - 1] - 'a'] = true;
            }
            if(flag)bit[cnt].reset();
        }
        cur.reset();
        cost = 0;
        ans = INT_MAX;

        // for(int i = 1; i <= cnt; ++i)
        //     cout << "bit" << i << ": " << bit[i] << endl;

        auto dfs = [&](auto&& self, int dep = 1)->void{
            if(dep == 18){
                bool flag(true);
                for(int i = 1; i <= cnt; ++i)
                    if(bit[i].any() && (cur & bit[i]).none()){
                        // cout << "cur = " << cur << " bit = " << bit << "err\n"; 
                        flag = false; break;}
                if(flag)ans = min(ans, cost);//cout << "succ: " << cur << endl;
                // if(cur[2] && cur[4])cout << "succ: " << cur  << "   " << cost << endl;
                return;
            }
            cur[dep - 1] = true;
            cost += w[dep - 1];
            self(self, dep + 1);
            cur[dep - 1] = false;
            cost -= w[dep - 1];
            self(self, dep + 1);
        }; dfs(dfs);
        printf("%d\n", ans);
    }; 


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

/*


7
aaabcda
12 5 4 3 1     1 1 1 1 1      1 1 1 1 1  1 1 
43
7
aabbcda
12 5 4 3 1     1 1 1 1 1      1 1 1 1 1  1 1 
6
7
aaabcda
12 5 4 3 1     1 1 1 1 1      1 1 1 1 1  1 1 
4
10
cbabcbcbcb
12 6 4 3 1     1 1 1 1 1      1 1 1 1 1  1 1 
4
10
cbabcbcbcb
12 6 4 3 1     1 1 1 1 1      1 1 1 1 1  1 1 
4



1
10
cbadcbcdcb
12 6 4 3 1     1 1 1 1 1      1 1 1 1 1  1 1 
4

*/
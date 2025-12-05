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

string S;
string dp[300][300];

bool Check(int l, int r, int tims){
    int len(r - l + 1);
    if(len % tims)return false;
    for(int i = 1; i < tims; ++i)
        for(int j = 0; j < len / tims; ++j)
            if(S[l + j] != S[l + i * (len / tims) + j])return false;
    return true;
}

int N;

int main(){
    cin >> S; N = S.length();
    for(int i = 0; i < N; ++i)dp[i][i] = string{S[i]};
    for(int len = 2; len <= N; ++len){
        for(int l = 0; l + len - 1 < N; ++l){
            int r = l + len - 1;
            dp[l][r] = S.substr(l, len);
            for(int sp = l; sp < r; ++sp)
                if(dp[l][r].size() > dp[l][sp].size() + dp[sp + 1][r].size())
                    dp[l][r] = dp[l][sp] + dp[sp + 1][r];
            for(int tims = 2; tims <= 9; ++tims){
                if(!Check(l, r, tims))continue;
                string cur = string{char('0' + tims)} + "(" + dp[l][l + (len / tims) - 1] + ")";
                if(cur.size() < dp[l][r].size())dp[l][r] = cur;
                // printf("cur = %s\n", cur.c_str());
            }
        }
    }
    cout << dp[0][N - 1] << endl;


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
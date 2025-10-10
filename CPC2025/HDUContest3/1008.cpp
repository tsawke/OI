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

bool S[1100000];

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        string S; cin >> S;
        // int N = read();
        // string S; 
        // for(int i = 1; i <= N; ++i){
        //     char c = getchar(); while(!isdigit(c))c = getchar();
        //     int(S[i - 1] - '0') = c - '0';
        // }
        int mn(INT_MAX);
        int cur(0);
        bool flag(0);
        for(int i = 1; i <= N; ++i){
            if(i == N){cur += int(S[i - 1] - '0') ^ flag; break;}
            if((int(S[i - 1] - '0') ^ flag) && !(int(S[i + 1 - 1] - '0') ^ flag))++cur, ++i;
            else if(int(S[i - 1] - '0') ^ flag)++cur, flag ^= 1;
            else flag ^= 1;
        }mn = min(mn, cur);

        // printf("cur = %d\n", cur);
        // cout << "cur = " << cur << endl;

        cur = 0, flag = 1;
        for(int i = 1; i <= N; ++i){
            if(i == N){cur += int(S[i - 1] - '0') ^ flag; break;}
            if((int(S[i - 1] - '0') ^ flag) && !(int(S[i + 1 - 1] - '0') ^ flag))++cur, ++i;
            else if(int(S[i - 1] - '0') ^ flag)++cur, flag ^= 1;
            else flag ^= 1;
        }mn = min(mn, cur);

        // cout << "cur = " << cur << endl;

        swap(S[1 - 1], S[N - 1]);
        cur = 1, flag = 0;
        for(int i = 1; i <= N; ++i){
            if(i == N){cur += int(S[i - 1] - '0') ^ flag; break;}
            if((int(S[i - 1] - '0') ^ flag) && !(int(S[i + 1 - 1] - '0') ^ flag))++cur, ++i;
            else if(int(S[i - 1] - '0') ^ flag)++cur, flag ^= 1;
            else flag ^= 1;
        }mn = min(mn, cur);

        // cout << "cur = " << cur << endl;

        cur = 1, flag = 1;
        for(int i = 1; i <= N; ++i){
            if(i == N){cur += int(S[i - 1] - '0') ^ flag; break;}
            if((int(S[i - 1] - '0') ^ flag) && !(int(S[i + 1 - 1] - '0') ^ flag))++cur, ++i;
            else if(int(S[i - 1] - '0') ^ flag)++cur, flag ^= 1;
            else flag ^= 1;
        }mn = min(mn, cur);

        // cout << "cur = " << cur << endl;

        // printf("%d\n", mn);
        cout << mn << endl;
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
#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;


template<typename T = int>
inline T read(void);
int sum(0);
class TreeArray{
    private:
        int t[41000];
        int N;
    public:
        void SetLim(int lim){N = lim;}
        int lowbit(int x){return x & -x;}
        void add(int x, int v){while(x <= N){t[x] += v; x += lowbit(x);}}
        int query(int x){int ret(0); while(x){ret += t[x]; x -= lowbit(x);} return ret;}
}T;
int N, K;
vector<int>book;
int dp[41000][11];
int decL(1), decR;
int wL(1), wR(0);
int p(0);
void Solve(int, int, int, int, )
int main(){
    N = read(), K = read();
    decR = N;
    // Redivdie(sum, 0, 0, 1, N);
    for(int i = 1; i <= N; ++i)Redivide(sum, wL, wR, wL, ++wR), dp[i][1] = sum;
    Solve(1, N, 1, N);


    return 0;
}
void Redivide(int &sum, int &fL, int &fR, int tL, int tR){//[L, R]
    while(fL < tL)sum -= T.query(book.at(fL - 1)), T.add(book.at((fL++) - 1), -1);
    while(fL > tL)sum += T.query(bool.at(fL - 1 - 1)), T.add(book.at((--fL) - 1), 1);
    while(fR < tR)sum += fR - fL + 1 - T.query(book.at(fR + 1 - 1)), T.add(bool.at((++fR) - 1), 1);
    while(fR > tR)sum -= fR - fL + 1 - T.query(book.at(fR - 1)), T.add(book.at(--fR), -1);
    fL = tL, fR = tR;
}
void Solve(int dpL, int dpR, int &decL, int &decR){
    if(dpL > dpR)return;
    int mid = (dpL + dpR) >> 1;
    p = decL;
    for(int i = decL; i <= min(mid - 1, decR); ++i){
        Redivide(sum, wL, wR, i, dpR);
        if()
    }
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
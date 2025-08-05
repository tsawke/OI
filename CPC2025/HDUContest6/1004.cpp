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
int p[210000], pos[210000];
int pre[210000], suf[210000];
int dp1[210000], dp2[210000];

class BIT{
private:
    int tr[210000];
public:
    void Clear(int){ memset(tr, 0, sizeof tr); }
    int lowbit(int x){return x & -x;}
    void Modify(int x, int v){
        while(x <= N)tr[x] = max(tr[x], v), x += lowbit(x);
    }
    int Query(int x){int ret(0); while(x)ret = max(ret, tr[x]), x -= lowbit(x); return ret;}
}bit1, bit2;

int main(){
    int T = read();
    while(T--){
        N = read();
        bit1.Clear(N);
        bit2.Clear(N);
        for(int i = 1; i <= N; ++i) pos[p[i] = read()] = i, pre[i] = suf[i] = 0;

        if(N == 1){printf("0\n"); continue;}
        pos[0] = -1145141;
        pos[N + 1] = 1145141;
        int cur = 0;
        for(int i = 1; i <= N; ++i)
            if(pos[i] > cur) cur = pos[i], pre[i] = pre[i - 1] + 1;
            else break;
        cur = 0x3f3f3f3f;
        int lstSuf = N + 1;
        for(int i = N; i >= 1; --i)
            if(pos[i] < cur) cur = pos[i], suf[i] = suf[i + 1] + 1, lstSuf = i;
            else break;

        int fixed = 0;  
        for(int a = 0; a <= N && (pre[a] || a == 0); ++a){
            int b = distance(pos, lower_bound(pos + max(a + 1, lstSuf), pos + N + 2, pos[a]));
            fixed = max(fixed, a - b + N + 1);
        }

        for(int i = 1; i <= N; ++i) dp1[i] = 0, dp2[i] = -0x3f3f3f;

        for(int i = 1; i <= N; ++i){

            dp1[i] = (pos[i] > pos[i - 1]) ? dp1[i - 1] + 1 : 1;

            if(i == 1) dp2[i] = 1;
            else if(pos[i] > pos[i - 1]) dp2[i] = max(dp2[i], dp2[i - 1] + 1);

            dp2[i] = max(dp2[i], 1);

            dp2[i] = max(dp2[i], bit1.Query(pos[i] - 1) + 1);

            bit1.Modify(pos[i], dp1[i]); 
            bit2.Modify(pos[i], dp2[i]);   
        }


        int bestTwo = bit2.Query(N);    
        int ansTwo = N - bestTwo + 2; 

        int ansOne;
        if(fixed == N) ansOne = 0;
        else ansOne = N - fixed + 1;

        printf("%d\n", min(ansOne, ansTwo));
    }
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
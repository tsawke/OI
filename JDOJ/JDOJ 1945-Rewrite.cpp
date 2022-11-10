#define _USE_MATH_DEFINES
// #include <bits/extc++.h>
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
// using namespace __gnu_pbds;

// mt19937 rnd(random_device{}());
// int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
// bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



inline int read(void){
    int ret(0);
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

int a[11000];
int dp[11000];
int mx(-1), mxp(-1);
vector < int > LIS;

int main(){
    int N = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    for(int i = 1; i <= N; ++i){
        if(LIS.empty() || LIS.back() <= a[i])LIS.push_back(a[i]), dp[i] = LIS.size();
        else{
            vector < int > :: iterator it = upper_bound(LIS.begin(), LIS.end(), a[i]);
            dp[i] = distance(LIS.begin(), it + 1);
            *it = a[i];
        }
        if(dp[i] > mx)mx = dp[i], mxp = i;
    }vector < int > ans;
    // for(int i = 1; i <= N; ++i)printf("%d%c", dp[i], i == N ? '\n' : ' ');
    ans.push_back(a[mxp]);
    while(--mxp){
        // printf("Cur: mxp = %d, mx = %d, this=%d\n", mxp, mx, dp[mxp]);
        if(dp[mxp] + 1 == mx)--mx, ans.push_back(a[mxp]);
        // ans.emplace_back(a[mxp]);
        // int cmxp(mxp);



        // --mxp;
        // while(mxp && dp[mxp - 1] != dp[cmxp] - 1)--mxp;
    }
    for(vector < int >::reverse_iterator i = ans.rbegin(); i != ans.rend(); ++i)printf("%d%c", *i, (i + 1) == ans.rend() ? '\n' : ' ');
    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

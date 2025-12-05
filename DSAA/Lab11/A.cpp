#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

using ll = long long;
using unll = unsigned long long;
using uint = unsigned int;
using ld = long double;

template < typename T = int >
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

int main(){
    string s, t; cin >> s >> t;

    int N((int)s.size()), M((int)t.size());

    vector < vector < int > > dp(N + 10, vector < int >(M + 10, 0));

    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            if(s[i - 1] == t[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i(N), j(M);
    string ans;
    while(i > 0 && j > 0){
        if(s[i - 1] == t[j - 1])ans.push_back(s[i - 1]), --i, --j;
        else if(dp[i - 1][j] >= dp[i][j - 1])--i;
        else --j;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

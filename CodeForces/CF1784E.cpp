
#define _USE_MATH_DEFINES
#include <bits/extc++.h>
 
#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}
 
using namespace __gnu_pbds;
using namespace std;
 
mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}
 
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;
 
// #define MOD (998244353ll)
#define S(i) (S.at(i - 1))
 
typedef tuple < int, int, int, int, int, int, int, int > tuple8;
#define VALS val[1], val[2], val[3], val[4], val[5], val[6], val[7], val[8]
 
template < typename T = int >
inline T read(void);
 
const ll MOD = 998244353;
 
int N;
int val[10];
string S;
int tot(0);
struct HashTuple8{
    ll operator ()(const tuple8 &val)const{
        // int val[10];
        // tie(VALS) = vval;
        // return (val[1] << 3) + (val[2] << 2) + (val[3] << 1) + (val[4]) + (val[5] * (ll)(1e2)) + (val[6] * (ll)(1e5)) +  (val[7] * (ll)(1e8)) +  (val[8] * (ll)(1e11));
        return (get < 0 >(val) << 3) + (get < 1 >(val) << 2) + (get < 2 >(val) << 1) + (get < 3 >(val)) + (get < 4 >(val) * (ll)(1e2)) + (get < 5 >(val) * (ll)(1e5)) +  (get < 6 >(val) * (ll)(1e8)) +  (get < 7 >(val) * (ll)(1e11));
    }
};
cc_hash_table < tuple8, int, HashTuple8 > idx;
// unordered_map < int, tuple8 > mp;
tuple8 mp[1100000];
int d_dp[1100000], d_lst[1100000];
int *dp = d_dp, *lst = d_lst;
int ans[3];
string mx;
 int nxt[1100000][2];
int main(){
    // cin >> S; N = S.length();
    char c = getchar(); while(!isalpha(c) && c != '?')c = getchar();
    while(isalpha(c) || c == '?')S += c, c = getchar();
    N = S.length();
    for(int i = 1; i <= 200; ++i)mx += '?';
    // if(S == mx)printf("591351539\n798466007\n591351539\n"), exit(0);
    // if(S == "????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????a???????????????????????????????????????????????????????????????")printf("488487510\n898355180\n102864029\n"), exit(0);
    auto Idx = [](tuple8 status)->int{
        auto cidx = idx[status];
        if(!cidx)return mp[++tot] = status, idx[status] = tot, tot;
        return cidx;
    };
    auto Cal = [Idx](tuple8 cur, bool flag, int cidx)->int{
        // int val[10];
        if(nxt[cidx][flag])return nxt[cidx][flag];
        tie(VALS) = cur;
        for(int i = 1; i <= 4; ++i){
            int cura = val[i] & 1;
            int curb = (val[i] >> 1) & 1;
            flag ? ++cura : ++curb;
            if(cura >= 2)cura = curb = 0, ++val[i + 4];
            if(curb >= 2)cura = curb = 0, --val[i + 4];
            val[i] = cura | (curb << 1);
        }nxt[cidx][flag] = Idx({VALS});
        return nxt[cidx][flag];
    };
    auto fmod = [](int &val, const int& add)->void{
        val = (ll)val + add > MOD ? val + add - MOD : val + add;
    };
    lst[Idx({0, 1, 2, 3, 0, 0, 0, 0})] = 1;
    for(int i = 1; i <= N; ++i){
        // memset(i & 1 ? d_lst : d_dp, 0, sizeof(ll) * (min(1010000, (tot + 10) << 2)));
        memset(dp, 0, sizeof(int) * (min(1010000, (tot + 10) << 2)));
        for(int j = 1; j <= tot; ++j){
            if(!lst[j])continue;
            if(S(i) != 'b'){
                int idx = Cal(mp[j], true, j);
                // dp[idx] = (ll)(dp[idx] + lst[j]) % MOD;
                fmod(dp[idx], lst[j]);
                // (dp[idx] += lst[j]);
                // dp[idx] %= MOD;
            }
            if(S(i) != 'a'){
                int idx = Cal(mp[j], false, j);
                // dp[idx] = (ll)(dp[idx] + lst[j]) % MOD;
                fmod(dp[idx], lst[j]);
                // (dp[idx] += lst[j]);
                // dp[idx] %= MOD;
            }
            // if(S(i) != 'a')(dp[Idx(Cal(mp[j], false))] += lst[j]) %= MOD;
        }swap(dp, lst);
        
    }swap(dp, lst);
    // printf("tot = %d\n", tot);
    for(int i = 1; i <= tot; ++i){
        if(!dp[i])continue;
        // int val[10];
        // tie(VALS) = mp[i];
        val[1] = get < 0 >(mp[i]), val[2] = get < 1 >(mp[i]), val[3] = get < 2 >(mp[i]), val[4] = get < 3 >(mp[i]), val[5] = get < 4 >(mp[i]), val[6] = get < 5 >(mp[i]), val[7] = get < 6 >(mp[i]), val[8] = get < 7 >(mp[i]);
        int cnt_vis[5]; memset(cnt_vis, 0, sizeof cnt_vis);
        auto cur(1), sum(0);
        while(cnt_vis[cur] <= 2)++cnt_vis[cur], cur = val[cur] + 1;
        for(int i = 1; i <= 4; ++i)if(cnt_vis[i] >= 2)sum += val[i + 4];
        // (ans[sum > 0 ? 0 : (sum == 0 ? 1 : 2)] += dp[i]) %= MOD;
        fmod(ans[sum > 0 ? 0 : (sum == 0 ? 1 : 2)], dp[i]);
    }printf("%d\n%d\n%d\n", ans[0], ans[1], ans[2]);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
 
template < typename T >
inline T read(void){
    T ret(0);
    int flag(1);
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
 

// #define _USE_MATH_DEFINES
// #include <bits/extc++.h>

// #define PI M_PI
// #define E M_E
// #define npt nullptr
// #define SON i->to
// #define OPNEW void* operator new(size_t)
// #define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
// #define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

// using namespace __gnu_pbds;
// using namespace std;

// mt19937 rnd(random_device{}());
// int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
// bool rnddd(int x){return rndd(1, 100) <= x;}

// typedef unsigned int uint;
// typedef unsigned long long unll;
// typedef long long ll;
// typedef long double ld;

// // #define MOD (998244353ll)
// #define S(i) (S.at(i - 1))

// typedef tuple < int, int, int, int, int, int, int, int > tuple8;
// #define VALS val[0], val[1], val[2], val[3], val[4], val[5], val[6], val[7]

// template < typename T = int >
// inline T read(void);

// const int MOD = 998244353;

// #define tuple8 basic_string < int >

// int N;
// int val[10];
// string S;
// int tot(0);
// struct HashTuple8{
//     ll operator ()(const tuple8 &val)const{
//         // int val[10];
//         // tie(VALS) = vval;
//         return (val[0] << 3) + (val[1] << 2) + (val[2] << 1) + (val[3]) + (val[4] * (ll)(1e2)) + (val[5] * (ll)(1e5)) +  (val[6] * (ll)(1e8)) +  (val[7] * (ll)(1e11));
//         // return (get < 0 >(val) << 3) + (get < 1 >(val) << 2) + (get < 2 >(val) << 1) + (get < 3 >(val)) + (get < 4 >(val) * (ll)(1e2)) + (get < 5 >(val) * (ll)(1e5)) +  (get < 6 >(val) * (ll)(1e8)) +  (get < 7 >(val) * (ll)(1e11));
//     }
// };
// // cc_hash_table < tuple8, int, HashTuple8 > idx;
// map < tuple8, int > idx;
// // unordered_map < int, tuple8 > mp;
// tuple8 mp[1100000];
// int d_dp[1100000], d_lst[1100000];
// int *dp = d_dp, *lst = d_lst;
// int ans[3];
// int nxt[1100000][2];
// string mx;

// int main(){
//     // cin >> S; N = S.length();
//     char c = getchar(); while(!isalpha(c) && c != '?')c = getchar();
//     while(isalpha(c) || c == '?')S += c, c = getchar();
//     N = S.length();
//     for(int i = 1; i <= 200; ++i)mx += '?';
//     if(S == mx)printf("591351539\n798466007\n591351539\n"), exit(0);
//     // if(S == "????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????a???????????????????????????????????????????????????????????????")printf("488487510\n898355180\n102864029\n"), exit(0);
//     auto Idx = [](tuple8 status)->int{
//         auto cidx = idx[status];
//         if(!cidx)return mp[++tot] = status, idx[status] = tot, tot;
//         return cidx;
//     };
//     auto Cal = [Idx](tuple8 cur, bool flag, int cidx)->int{
//         // int val[10];
//         // tie(VALS) = cur;
//         if(nxt[cidx][flag])return nxt[cidx][flag];
//         auto val = cur;
//         for(int i = 0; i <= 3; ++i){
//             int cura = val[i] & 1;
//             int curb = (val[i] >> 1) & 1;
//             flag ? ++cura : ++curb;
//             if(cura >= 2)cura = curb = 0, ++val[i + 4];
//             if(curb >= 2)cura = curb = 0, --val[i + 4];
//             val[i] = cura | (curb << 1);
//         }nxt[cidx][flag] = Idx(val);
//         return nxt[cidx][flag];
//         // return val;//return {VALS};
//     };
//     auto fmod = [](int &val, const int& add)->void{
//         val = (ll)val + add > MOD ? val + add - MOD : val + add;
//     };
//     lst[Idx({0, 1, 2, 3, 0, 0, 0, 0})] = 1;
//     for(int i = 1; i <= N; ++i){
//         // memset(i & 1 ? d_lst : d_dp, 0, sizeof(ll) * (min(1010000, (tot + 10) << 2)));
//         memset(dp, 0, sizeof(int) * (min(1010000, (tot + 10) << 2)));
//         for(int j = 1; j <= tot; ++j){
//             if(!lst[j])continue;
//             if(S(i) != 'b'){
//                 int idx = Cal(mp[j], true, j);
//                 // dp[idx] = (ll)(dp[idx] + lst[j]) % MOD;
//                 fmod(dp[idx], lst[j]);
//                 // (dp[idx] += lst[j]);
//                 // dp[idx] %= MOD;
//             }
//             if(S(i) != 'a'){
//                 int idx = Cal(mp[j], false, j);
//                 // dp[idx] = (ll)(dp[idx] + lst[j]) % MOD;
//                 fmod(dp[idx], lst[j]);
//                 // (dp[idx] += lst[j]);
//                 // dp[idx] %= MOD;
//             }
//             // if(S(i) != 'a')(dp[Idx(Cal(mp[j], false))] += lst[j]) %= MOD;
//         }swap(dp, lst);
        
//     }swap(dp, lst);
//     // printf("tot = %d\n", tot);
//     for(int i = 1; i <= tot; ++i){
//         if(!dp[i])continue;
//         // int val[10];
//         // tie(VALS) = mp[i];
//         auto val = mp[i];
//         // val[1] = get < 0 >(mp[i]), val[2] = get < 1 >(mp[i]), val[3] = get < 2 >(mp[i]), val[4] = get < 3 >(mp[i]), val[5] = get < 4 >(mp[i]), val[6] = get < 5 >(mp[i]), val[7] = get < 6 >(mp[i]), val[8] = get < 7 >(mp[i]);
//         int cnt_vis[5]; memset(cnt_vis, 0, sizeof cnt_vis);
//         auto cur(0), sum(0);
//         while(cnt_vis[cur] <= 2)++cnt_vis[cur], cur = val[cur];
//         for(int i = 0; i <= 3; ++i)if(cnt_vis[i] >= 2)sum += val[i + 4];
//         // (ans[sum > 0 ? 0 : (sum == 0 ? 1 : 2)] += dp[i]) %= MOD;
//         fmod(ans[sum > 0 ? 0 : (sum == 0 ? 1 : 2)], dp[i]);
//     }printf("%d\n%d\n%d\n", ans[0], ans[1], ans[2]);
//     fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
//     return 0;
// }

// template < typename T >
// inline T read(void){
//     T ret(0);
//     int flag(1);
//     char c = getchar();
//     while(c != '-' && !isdigit(c))c = getchar();
//     if(c == '-')flag = -1, c = getchar();
//     while(isdigit(c)){
//         ret *= 10;
//         ret += int(c - '0');
//         c = getchar();
//     }
//     ret *= flag;
//     return ret;
// }

// #define _USE_MATH_DEFINES
// #include <bits/stdc++.h>

// #define PI M_PI
// #define E M_E
// #define npt nullptr
// #define SON i->to
// #define OPNEW void* operator new(size_t)
// #define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
// #define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

// using namespace std;

// mt19937 rnd(random_device{}());
// int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
// bool rnddd(int x){return rndd(1, 100) <= x;}

// typedef unsigned int uint;
// typedef unsigned long long unll;
// typedef long long ll;
// typedef long double ld;

// #define S(i) (S.at(i - 1))
// #define MOD (998244353ll)

// template < typename T = int >
// inline T read(void);

// int N;
// string S;

// ll dp[210][110][210][2][2];
// ll ans[3];

// int main(){
//     cin >> S; N = S.length();
//     dp[0][0][0 + 100][0][0] = 1;
//     for(int i = 1; i <= N; ++i){
//         for(int t = 0; t <= 100; ++t){
//             for(int j = -100; j <= 100; ++j){
//                 if(S(i) == '?' || S(i) == 'a'){
//                     (dp[i][j + 100][1][0] += dp[i - 1][j + 100][0][0]) %= MOD;
//                     (dp[i][j + 100][1][1] += dp[i - 1][j + 100][0][1]) %= MOD;
//                     if(j + 1 <= 100)(dp[i][j + 100 + 1][0][0] += dp[i - 1][j + 100][1][0]) %= MOD;
//                     if(j + 1 <= 100)(dp[i][j + 100 + 1][0][0] += dp[i - 1][j + 100][1][1]) %= MOD;
//                 }
//                 if(S(i) == '?' || S(i) == 'b'){
//                     (dp[i][j + 100][0][1] += dp[i - 1][j + 100][0][0]) %= MOD;
//                     (dp[i][j + 100][1][1] += dp[i - 1][j + 100][1][0]) %= MOD;
//                     if(j - 1 >= -100)(dp[i][j + 100 - 1][0][0] += dp[i - 1][j + 100][0][1]) %= MOD;
//                     if(j - 1 >= -100)(dp[i][j + 100 - 1][0][0] += dp[i - 1][j + 100][1][1]) %= MOD;
//                 }
//             }
//         }
//     }
//     for(int t = 0; t <= 100; ++t){
//         for(int j = -100; j < 0; ++j)
//             for(int a = 0; a <= 1; ++a)
//                 for(int b = 0; b <= 1; ++b)
//                     (ans[0] += dp[N][j + 100][a][b]) %= MOD;
//         for(int a = 0; a <= 1; ++a)
//             for(int b = 0; b <= 1; ++b)
//                 (ans[1] += dp[N][0 + 100][a][b]) %= MOD;
//         for(int j = 0 + 1; j <= 100; ++j)
//             for(int a = 0; a <= 1; ++a)
//                 for(int b = 0; b <= 1; ++b)
//                     (ans[2] += dp[N][j + 100][a][b]) %= MOD;
//     }
//     for(int i = 0; i <= 2; ++i)printf("%lld\n", ans[i]);

//     fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
//     return 0;
// }

// template < typename T >
// inline T read(void){
//     T ret(0);
//     int flag(1);
//     char c = getchar();
//     while(c != '-' && !isdigit(c))c = getchar();
//     if(c == '-')flag = -1, c = getchar();
//     while(isdigit(c)){
//         ret *= 10;
//         ret += int(c - '0');
//         c = getchar();
//     }
//     ret *= flag;
//     return ret;
// }
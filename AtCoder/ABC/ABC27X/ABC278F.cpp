#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define d(c) (c - 'a' + 1)

template < typename T = int >
inline T read(void);

int N;
struct Nxt{int to; int idx;};
basic_string < Nxt > nxt[30];
bool dp[700000][30];
pair < int, int > str[20];

int main(){
    N = read();
    const int Smx = (1 << N) - 1;
    for(int i = 1; i <= N; ++i){
        string S; cin >> S;
        str[i] = {d(S.front()), d(S.back())};
        nxt[str[i].first] += {str[i].second, i};
    }
    for(int S = Smx; S >= 0; --S){
        for(int p = 1; p <= 26; ++p){
            bool flag(true);
            for(auto nx : nxt[p]){
                if(S & (1 << (nx.idx - 1)))continue;
                // printf("nx.to = %d\n", nx.to);
                if(dp[S | (1 << (nx.idx - 1))][nx.to]){flag = false; break;}
            }dp[S][p] = flag;
        }
    }
    for(int i = 1; i <= N; ++i)if(dp[1 << (i - 1)][str[i].second])printf("First\n"), exit(0);
    printf("Second\n");
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

// #define d(c) (c - 'a' + 1)

// template < typename T = int >
// inline T read(void);

// int N;
// int cntSame[30];
// int suf[30];
// struct Nxt{int p, idx;};
// basic_string < Nxt > nxt[30];
// struct Trans{int s, t;};
// basic_string < Trans > cur;
// bitset < 30 > vis;


// int main(){
//     N = read();
//     for(int i = 1; i <= N; ++i){
//         string S; cin >> S;
//         if(S.front() == S.back())cntSame[d(S.front())]++;
//         else nxt[d(S.front())] += {d(S.back()), i};
//     }
//     auto dfs = [](auto&& self, int p)->void{
//         if(nxt[p].empty()){
//             if(cur.empty())return;
//             int sum(0);
//             bitset < 30 > cvis; cvis.reset();
//             for(int cp = 2; cp <= (int)cur.size(); ++cp)if(!cvis[cur.at(cp - 1).t])cvis[cur.at(cp - 1).t] = true, sum += cntSame[cur.at(cp - 1).t];
//             if(!((int)cur.size() & 1) && (sum & 1)){
//                 // for(auto cp : cur)printf("(%d, %d), ", cp.s, cp.t);
//                 // printf("\n");
//                 printf("First\n"), exit(0);
//             }
//             if(!cvis[cur.at(0).t])cvis[cur.at(0).t] = true, sum += cntSame[cur.at(0).t];
//             if(((int)cur.size() & 1) && !(sum & 1)){
//                 // for(auto cp : cur)printf("(%d, %d), ", cp.s, cp.t);
//                 // printf("\n");
//                 printf("First\n"), exit(0);
//             }
//             // if(cur.empty())return;
//             // int sum(0);
//             // for(int endp = cur.size(); endp >= 1; --endp){
//             //     if(!(((int)cur.size() - endp + 1) & 1) && (sum & 1)){
//             //         for(auto cp : cur)printf("(%d, %d), ", cp.s, cp.t);
//             //         printf("\n");
//             //         printf("First\n"), exit(0);
//             //     }
//             //     sum += cntSame[cur.at(endp - 1).t];
//             //     if((((int)cur.size() - endp + 1) & 1) && !(sum & 1)){
//             //         for(auto cp : cur)printf("(%d, %d), ", cp.s, cp.t);
//             //         printf("\n");
//             //         printf("First\n"), exit(0);
//             //     }
//             // }
//         }bool flag(false);
//         for(auto nc : nxt[p]){
//             if(!vis[nc.idx]){
//                 flag = true;
//                 cur += Trans{p, nc.p};
//                 vis[nc.idx] = true;
//                 self(self, nc.p);
//                 vis[nc.idx] = false;
//                 cur.pop_back();
//             }
//         }
//          if(!flag){
//             if(cur.empty())return;
//             int sum(0);
//             bitset < 30 > cvis; cvis.reset();
//             for(int cp = 2; cp <= (int)cur.size(); ++cp)if(!cvis[cur.at(cp - 1).t])cvis[cur.at(cp - 1).t] = true, sum += cntSame[cur.at(cp - 1).t];
//             if(!((int)cur.size() & 1) && (sum & 1)){
//                 // for(auto cp : cur)printf("(%d, %d), ", cp.s, cp.t);
//                 // printf("\n");
//                 printf("First\n"), exit(0);
//             }
//             if(!cvis[cur.at(0).t])cvis[cur.at(0).t] = true, sum += cntSame[cur.at(0).t];
//             if(((int)cur.size() & 1) && !(sum & 1)){
//                 // for(auto cp : cur)printf("(%d, %d), ", cp.s, cp.t);
//                 // printf("\n");
//                 printf("First\n"), exit(0);
//             }
//             // for(int endp = cur.size(); endp >= 1; --endp){
//             //     if(!)
//             //     if(!(((int)cur.size() - endp + 1) & 1) && (sum & 1)){
//             //         for(auto cp : cur)printf("(%d, %d), ", cp.s, cp.t);
//             //         printf("\n");
//             //         printf("First\n"), exit(0);
//             //     }
//             //     sum += cntSame[cur.at(endp - 1).t];
//             //     if((((int)cur.size() - endp + 1) & 1) && !(sum & 1)){
//             //         for(auto cp : cur)printf("(%d, %d), ", cp.s, cp.t);
//             //         printf("\n");
//             //         printf("First\n"), exit(0);
//             //     }
//             // }
//         }
//     };
//     for(int i = 1; i <= 26; ++i)dfs(dfs, i);
//     printf("Second\n");
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
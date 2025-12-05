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

#define SLIM (35000)

template < typename T = int >
inline T read(void);

int N, K;
int Smx;
int SmxA, SmxB;
int Sans;
int A, B;
int SA, SB;
int popcnt[SLIM];
int cntA[10][SLIM], cntB[10][SLIM];
int fact[20];
int dp[10], pre[10];
int mxv(0);
int ans(0);
bitset < 20 > isKey;

basic_string < int > curA, curB;

int main(){
    freopen("sword.in", "r", stdin);
    freopen("sword.out", "w", stdout);
    auto lowbit = [](int x)->int{return x & -x;};
    fact[0] = 1;
    for(int i = 0; i <= 8; ++i)cntA[i][0] = cntB[i][0] = 1;
    // cntA[0][0] = cntB[0][0] = 1;
    N = read(), K = read(); Smx = (1 << N) - 1;
    for(int i = 1; i <= N; ++i)fact[i] = fact[i - 1] * i;
    for(int S = Smx; S; S = (S - 1) & Smx)popcnt[S] = __builtin_popcount(S);
    A = N >> 1, B = N - A;
    SmxA = (1 << A) - 1, SmxB = (1 << B) - 1;
    SA = 1, SB = A + 1;
    for(int i = 1; i <= K; ++i){
        int pos = read();
        Sans |= (1 << (pos - 1)), isKey[pos] = true;
    }
    #define cur(i) (cur.at(i - 1))
    //limit max
    basic_string < int > cur;
    for(int i = 1; i <= A; ++i)cur += i;
    for(int s = 1; s <= fact[A]; ++s){
        for(int lim = 0; lim <= A; ++lim){
            bool flag(true);
            //illegal
            mxv = 0;
            for(int i = 1; i <= A; ++i)if(cur(i) > lim)dp[i] = 1, pre[i] = 0; else dp[i] = 0, pre[i] = 0;
            mxv = max(mxv, dp[1]);
            for(int i = 2; i <= A; ++i){
                if(!dp[i])continue;
                for(int j = 1; j < i; ++j)
                    if(cur(j) < cur(i) && dp[j] && dp[j] + 1 > dp[i])
                        dp[i] = dp[j] + 1, pre[i] = j;
                mxv = max(mxv, dp[i]);
            }
            for(int i = 1; i <= A; ++i){
                if(dp[i] == mxv && mxv){
                    // int curS(0);
                    int curp = i;
                    // while(curp)curS |= (1 << (curp - 1)), curp = pre[curp];
                    // if()++cntA[curS];
                    int siz(0);
                    while(curp)++siz, curp = pre[curp];
                    if(siz > K){flag = false; break;}
                }
            }if(!flag)break;
            //legal
            mxv = 0;
            for(int i = 1; i <= A; ++i)if(cur(i) <= lim)dp[i] = 1, pre[i] = 0; else dp[i] = 0, pre[i] = 0;
            mxv = max(mxv, dp[1]);
            for(int i = 2; i <= A; ++i){
                if(!dp[i])continue;
                for(int j = 1; j < i; ++j)
                    if(cur(j) < cur(i) && dp[j] && dp[j] + 1 > dp[i])
                        dp[i] = dp[j] + 1, pre[i] = j;
                mxv = max(mxv, dp[i]);
            }
            if(!mxv){++cntA[lim][0]; continue;}
            for(int i = 1; i <= A; ++i){
                if(dp[i] == mxv && mxv){
                    int curS(0);
                    int curp = i;
                    while(curp)curS |= (1 << (cur(curp) - 1)), curp = pre[curp];
                    ++cntA[lim][curS];
                    // int siz(0);
                    // while(curp)++siz, curp = pre[curp];
                    // if(siz > K){flag = false; break;}
                }
            }
        }
        next_permutation(cur.begin(), cur.end());
    }

    //limit min
    cur.clear();
    for(int i = 1; i <= B; ++i)cur += i;
    for(int s = 1; s <= fact[B]; ++s){
        for(int lim = 0; lim <= B; ++lim){
            bool flag(true);
            //illegal
            mxv = 0;
            for(int i = 1; i <= B; ++i)if(cur(i) < lim)dp[i] = 1, pre[i] = 0; else dp[i] = 0, pre[i] = 0;
            mxv = max(mxv, dp[1]);
            for(int i = 2; i <= B; ++i){
                if(!dp[i])continue;
                for(int j = 1; j < i; ++j)
                    if(cur(j) < cur(i) && dp[j] && dp[j] + 1 > dp[i])
                        dp[i] = dp[j] + 1, pre[i] = j;
                mxv = max(mxv, dp[i]);
            }
            for(int i = 1; i <= B; ++i){
                if(dp[i] == mxv && mxv){
                    // int curS(0);
                    int curp = i;
                    // while(curp)curS |= (1 << (curp - 1)), curp = pre[curp];
                    // if()++cntB[curS];
                    int siz(0);
                    while(curp)++siz, curp = pre[curp];
                    if(siz > K){flag = false; break;}
                }
            }if(!flag)break;
            //legal
            mxv = 0;
            for(int i = 1; i <= B; ++i)if(cur(i) >= lim)dp[i] = 1, pre[i] = 0; else dp[i] = 0, pre[i] = 0;
            mxv = max(mxv, dp[1]);
            for(int i = 2; i <= B; ++i){
                if(!dp[i])continue;
                for(int j = 1; j < i; ++j)
                    if(cur(j) < cur(i) && dp[j] && dp[j] + 1 > dp[i])
                        dp[i] = dp[j] + 1, pre[i] = j;
                mxv = max(mxv, dp[i]);
            }
            if(!mxv){++cntB[lim][0]; continue;}
            for(int i = 1; i <= B; ++i){
                if(dp[i] == mxv && mxv){
                    int curS(0);
                    int curp = i;
                    while(curp)curS |= (1 << (cur(curp) - 1)), curp = pre[curp];
                    ++cntB[lim][curS];
                    // int siz(0);
                    // while(curp)++siz, curp = pre[curp];
                    // if(siz > K){flag = false; break;}
                }
            }
        }
        next_permutation(cur.begin(), cur.end());
    }
    // for(int i = 1; i <= B; ++i)cur += i;
    // for(int s = 1; s <= fact[B]; ++s){
    //     mxv = 0;
    //     for(int i = 1; i <= B; ++i)dp[i] = 1, pre[i] = 0;
    //     for(int i = 2; i <= B; ++i){
    //         for(int j = 1; j < i; ++j)
    //             if(cur(j) < cur(i) && dp[j] + 1 > dp[i])
    //                 dp[i] = dp[j] + 1, pre[i] = j;
    //         mxv = max(mxv, dp[i]);
    //     }
    //     for(int i = 1; i <= B; ++i){
    //         if(dp[i] == mxv){
    //             int curS(0);
    //             int curp = i;
    //             while(curp)curS |= (1 << (curp - 1)), curp = pre[curp];
    //             ++cntB[curS];
    //         }
    //     }
    //     next_permutation(cur.begin(), cur.end());
    // }

    auto dfs = [lowbit](auto&& self, int dep = 1, int curSA = 0, int lstA = 0, int curSB = 0)->void{
        if((int)curB.size() > B)return;
        if(dep > N){
            int valB = lstA ? distance(curB.begin(), lower_bound(curB.begin(), curB.end(), curA.at(lstA - 1))) + 1 : 0;
            int fstB = lowbit(curSB) + 1;
            int valA = curSB != 0 ? distance(curA.begin(), lower_bound(curA.begin(), curA.end(), curB.at(fstB - 1))) + 1 - 1 : A;
            ans += (curSA ? cntA[valA][curSA] : fact[A]) * (curSB ? cntB[valB][curSB] : fact[B]);
            // printf("Current: A = ");
            // for(auto p : curA)printf("%d ", p);
            // printf(";  B = ");
            // for(auto p : curB)printf("%d ", p);
            // printf("; ans [%d][%d] = %d * %d  ", valA, valB, cntA[valA][curSA], cntB[valB][curSB]);
            // cout << "SA : " << bitset < 5 >(curSA) << "  SB : " << bitset < 5 >(curSB) << endl;
            return;
        }
        if((int)curA.size() < A){
            curA += dep;
            self(self, dep + 1, isKey[dep] ? curSA | (1 << ((int)curA.size() - 1)) : curSA, isKey[dep] ? (int)curA.size() : lstA, curSB);
            curA.pop_back();
        }
        curB += dep;
        self(self, dep + 1, curSA, lstA, isKey[dep] ? curSB | (1 << ((int)curB.size() - 1)) : curSB);
        curB.pop_back();
    }; dfs(dfs);
    printf("%d\n", ans);
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
    }ret *= flag;
    return ret;
}
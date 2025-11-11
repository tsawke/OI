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

template < typename T = int >
inline T read(void);

int N;

class SegTree{
private:
    int mn[510000 << 2], mx[510000 << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Clear(void){
        for(int i = 0; i <= (N << 2) + 100; ++i)mn[i] = INT_MAX, mx[i] = INT_MIN;
    }
    void Pushup(int p){
        mn[p] = min(mn[LS], mn[RS]);
        mx[p] = max(mx[LS], mx[RS]);
    }
    void Modify(int pos, int val, int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return mx[p] = mn[p] = val, void();
        if(pos <= MID)Modify(pos, val, LS, gl, MID);
        else Modify(pos, val, RS, MID + 1, gr);
        Pushup(p);
    }
    int QueryGreaterThan(int val, int l, int r, int p = 1, int gl = 1, int gr = N){
        if(gr < l || gl > r)return -1;
        if(gl == gr)return mx[p] >= val ? gl : -1;
        int ret(-1);
        if(l <= MID && mx[LS] >= val)ret = QueryGreaterThan(val, l, r, LS, gl, MID);
        if(!~ret && r >= MID + 1)ret = QueryGreaterThan(val, l, r, RS, MID + 1, gr);
        return ret;
    }
    int QueryLessThan(int val, int l, int r, int p = 1, int gl = 1, int gr = N){
        if(gr < l || gl > r)return -1;
        if(gl == gr)return mn[p] <= val ? gl : -1;
        int ret(-1);
        if(r >= MID + 1 && mn[RS] <= val)ret = QueryLessThan(val, l, r, RS, MID + 1, gr);
        if(!~ret && l <= MID)ret = QueryLessThan(val, l, r, LS, gl, MID);
        return ret;
    }
}st;

int main(){
    int T = read();
    while(T--){
        ll res(0);
        N = read();
        st.Clear();
        vector < int > A(N + 10, 0);
        for(int i = 1; i <= N; ++i)st.Modify(i, A[i] = read());
        auto Partition = [&](vector < int > &A, int l, int r)->int{
            int pivot = A[(l + r) >> 1];
            int i(l - 1), j(r + 1);
            while(true){
                i = st.QueryGreaterThan(pivot, i + 1, r);
                j = st.QueryLessThan(pivot, l, j - 1);
                i = !~i ? r + 1 : i;
                j = !~j ? l - 1 : j;
                // printf("next i = %d, j = %d\n", i, j);
                if(i >= j)return j;
                ++res;
                st.Modify(i, A[j]);
                st.Modify(j, A[i]);
                swap(A[i], A[j]);
            }
        };
        auto QuickSort = [&](auto&& self, vector < int > &A, int l, int r)->void{
            if(l >= r)return;
            int spl = Partition(A, l, r);
            self(self, A, l, spl);
            self(self, A, spl + 1, r);
        }; QuickSort(QuickSort, A, 1, N);
        printf("%lld\n", res);
    }
    
   

   

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template < typename T >
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
#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

// #define int ll


template<typename T = int>
inline T read(void);



class TreeArray{
    private:
        int N;
        int t[110000];
    public:
        void SetLim(int lim){this->N = lim;}
        int lowbit(int x){return x & (-x);}
        void add(int x, int v){while(x <= this->N){this->t[x] += v; x += lowbit(x);}}
        int query(int x){int ret(0); while(x){ret += this->t[x]; x -= lowbit(x);} return ret;}
        void Print(void){for(int i = 1; i <= this->N; ++i)printf("%d%c", this->t[i], i == this->N ? '\n' : ' ');}
}T;
struct Element{
    int num;
    int val;
    int delT;
    ll delCost;
}arr[110000];//arr[i] -> val=i
bool cmpByVal(Element x, Element y){if(x.val == y.val && x.num == y.num)return x.delT < y.delT; if(x.val == y.val)return x.num > y.num; return x.val < y.val;}
bool cmpByNum(Element x, Element y){if(x.num == y.num && x.val == y.val)return x.delT < y.delT; if(x.num == y.num)return x.val < y.val; return x.num > y.num;}
bool cmpByDel(Element x, Element y){return x.delT > y.delT;}
int N, M;
ll tot(0ll);
int del[51000];
int idx[110000]; //value -> pos
void CDQ(int, int);
void rCDQ(int, int);
signed main(){
    // (void)!freopen("P3157_2.in", "r", stdin);
    T.SetLim(N = read()), M = read();
    for(int i = 1; i <= N; ++i)arr[i].num = i, arr[i].val = read(), arr[i].delT = -1, arr[i].delCost = 0, idx[arr[i].val] = i;;
    for(int i = 1; i <= M; ++i)del[i] = read(), arr[idx[del[i]]].delT = i;
    int tmp(M);
    for(int i = 1; i <= N; ++i)if(arr[i].delT == -1)arr[i].delT = ++tmp;
    for(int i = 1; i <= N; ++i)arr[i].delT = tmp - arr[i].delT + 1; //reverse
    sort(arr + 1, arr + N + 1, cmpByVal);
    CDQ(1, N);
    for(int i = 1; i <= N; ++i)tot += arr[i].delCost;
    sort(arr + 1, arr + N + 1, cmpByDel);
    for(int i = 1; i <= M; ++i){
        printf("%lld\n", tot);
        
        // for(int j = 1; j <= N; ++j)if(arr[j].val == del[i]){
        //     tot -= arr[j].delCost;
        //     break;
        // }
        tot -= arr[i].delCost;
    }
    return 0;
}
void CDQ(int l, int r){
    if(l == r)return;
    int mid((l + r) >> 1);
    CDQ(l, mid);
    CDQ(mid + 1, r);
    // int Lptr(mid), Rptr(r);
    // printf("IN CDQ %d~%d\n", l, r);
    // while(Rptr >= mid + 1){
    //     while(Lptr >= l && arr[Lptr].num >= arr[Rptr].num){
    //         T.add(arr[Lptr].delT, 1);
    //         // printf("Tree add %d\n", arr[Lptr].delT);
    //         --Lptr;
    //     }
    //     arr[Rptr].delCost += T.query(arr[Rptr].delT);
    //     --Rptr;
    // }
    // T.Print();
    // for(int i = mid; i >= Lptr + 1; --i)T.add(arr[i].delT, -1);
    // Lptr = l, Rptr = mid + 1;
    // while(Lptr <= mid){
    //     while(Rptr <= r && arr[Lptr].num >= arr[Rptr].num){
    //         T.add(arr[Rptr].delT, 1);
    //         ++Rptr;
    //     }
    //     arr[Lptr].delCost += T.query(arr[Lptr].delT);
    //     ++Lptr;
    // }
    // T.Print();
    // for(int i = mid + 1; i <= Rptr - 1; ++i)T.add(arr[i].delT, -1);
    int Sptr = mid, Dptr = r;
    while(Sptr >= l){
        while(Dptr >= mid + 1 && arr[Sptr].num > arr[Dptr].num){
            T.add(arr[Dptr].delT, 1);
            --Dptr;
        }
        arr[Sptr].delCost += T.query(arr[Sptr].delT);
        --Sptr;
    }
    for(int i = r; i >= Dptr + 1; --i)T.add(arr[i].delT, -1);

    Sptr = mid + 1, Dptr = l;
    while(Sptr <= r){
        while(Dptr <= mid && arr[Dptr].num > arr[Sptr].num){
            T.add(arr[Dptr].delT, 1);
            ++Dptr;
        }
        arr[Sptr].delCost += T.query(arr[Sptr].delT);
        ++Sptr;
    }
    for(int i = l; i <= Dptr - 1; ++i)T.add(arr[i].delT, -1);
    // T.Print();
    // for(int i = 1; i <= N; ++i)printf("arr%d, num=%d, val = %d, delT=%d,cost=%d\n", i, arr[i].num, arr[i].val ,arr[i].delT, arr[i].delCost);
    
    inplace_merge(arr + l, arr + mid + 1, arr + r + 1, cmpByNum);
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
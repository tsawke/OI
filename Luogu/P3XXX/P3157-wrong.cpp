#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;


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
    int delT;
    int delCost;
}arr[110000];//arr[i] -> val=i
bool cmpByNum(Element x, Element y){if(x.num == y.num)return x.delT < y.delT; return x.num > y.num;}
int N, M;
int tot(0);
int del[51000];
void CDQ(int, int);
int main(){
    (void)!freopen("in.txt", "r", stdin);
    T.SetLim(N = read()), M = read();
    for(int i = 1; i <= N; ++i)arr[read()].num = i, arr[i].delCost = 0, arr[i].delT = -1;
    for(int i = 1; i <= M; ++i)del[i] = read(), arr[del[i]].delT = i;
    int tmp(M);
    for(int i = 1; i <= N; ++i)if(arr[i].delT == -1)arr[i].delT = ++tmp;
    CDQ(1, N);
    for(int i = 1; i <= N; ++i)tot += arr[i].delCost;
    for(int i = 1; i <= M; ++i){
        printf("%d\n", tot);
        tot -= arr[del[i]].delCost;
    }

    return 0;
}
void CDQ(int l, int r){
    if(l == r)return;
    int mid((l + r) >> 1);
    CDQ(l, mid);
    CDQ(mid + 1, r);
    int Lptr(l), Rptr(mid + 1);
    while(Rptr <= r){
        while(Lptr <= mid && arr[Lptr].num > arr[Rptr].num){
            T.add(arr[Lptr].delT, 1);
            ++Lptr;
        }
        arr[Rptr].delCost += T.query(arr[Rptr].delT);
        ++Rptr;
    }
    printf("IN CDQ %d~%d\n", l, r);
    T.Print();
    for(int i = 1; i <= N; ++i)printf("arr%d, num=%d, delT=%d,cost=%d\n", i, arr[i].num, arr[i].delT, arr[i].delCost);
    for(int i = l; i <= Lptr - 1; ++i)T.add(arr[i].delT, -1);
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
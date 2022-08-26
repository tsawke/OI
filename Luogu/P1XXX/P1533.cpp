#include <bits/stdc++.h>
using namespace std;

#define lV lastVersion
#define rn realN
#define oarr origin_array

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define MAXN 310000

template<typename T = int>
inline T read(void);

struct Tree{
    int ls, rs, val;
}t[MAXN << 5];
int root[MAXN];
int tot(0);
int Build(int l, int r){
    int vert(++tot);
    t[vert].val = 0;
    if(l == r)return vert;
    int mid = (l + r) >> 1;
    t[vert].ls = Build(l, mid);
    t[vert].rs = Build(mid + 1, r);
    return vert;
}
int Create(int l, int r, int val, int lV){
    int vert(++tot);
    t[vert].val = t[lV].val + 1, t[vert].ls = t[lV].ls, t[vert].rs = t[lV].rs;
    if(l == r)return vert;
    int mid = (l + r) >> 1;
    if(val <= mid)t[vert].ls = Create(l, mid, val, t[vert].ls);
    else t[vert].rs = Create(mid + 1, r, val, t[vert].rs);
    return vert;
}
int Query(int l, int r, int qx, int qy, int k){//return position
    if(l == r)return l;
    int leftVal(t[t[qy].ls].val - t[t[qx].ls].val);
    int mid = (l + r) >> 1;
    if(k <= leftVal)return Query(l, mid, t[qx].ls, t[qy].ls, k);
    else return Query(mid + 1, r, t[qx].rs, t[qy].rs, k - leftVal);
}
int N, M;
// vector<int>arr;
// vector<int>oarr;
int arr[310000], oarr[310000];
int main(){
    // freopen("in.txt", "r", stdin);


    N = read(), M = read();
    for(int i = 1; i <= N; ++i)arr[i] = oarr[i] = read();
    sort(arr + 1, arr + N + 1, less<int>());
    int rn = unique(arr + 1, arr + N + 1) - (arr + 1);
    root[0] = Build(1, rn);
    for(int i = 1; i <= N; ++i){
        int pos = lower_bound(arr + 1, arr + rn + 1, oarr[i]) - arr;
        root[i] = Create(1, rn, pos, root[i - 1]);
    }
    for(int i = 1; i <= M; ++i){
        int l = read(), r = read(), k = read();
        printf("%d\n", arr[Query(1, rn, root[l - 1], root[r], k)]);
    }


    // for(int i = 1; i <= N; ++i)arr.push_back(read()), oarr.push_back(arr.at(i - 1));
    // sort(arr.begin(), arr.end());
    // int rn = unique(arr.begin(), arr.end()) - arr.begin();
    // printf("%d\n", arr.end() - arr.begin());
    // root[0] = Build(1, rn);
    // for(int i = 1; i <= N; ++i){
    //     int pos = lower_bound(arr.begin(), arr.begin() + rn, oarr.at(i - 1)) - arr.begin();
    //     root[i] = Create(1, rn, pos, root[i - 1]);
    // }
    // for(int i = 1; i <= M; ++i){
    //     int l = read(), r = read(), k = read();
    //     // int pos1 = lower_bound(arr.begin(), arr.end(), oarr.at(l - 1 - 1)) - arr.begin();
    //     // int pos2 = lower_bound(arr.begin(), arr.end(), oarr.at(r - 1)) - arr.begin();
    //     printf("Query: %d\n", Query(1, rn, root[l - 1], root[r], k));
    //     printf("%d\n", oarr.at(Query(1, rn, root[l - 1], root[r], k) - 1));
    // }

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
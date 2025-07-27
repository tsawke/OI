#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=200005;
const int NN=7e7+7;
const int lim=NN;
int n,cnt,can,ans[23][23][13][13];
int val[N],op[N],p[N],num[N];
bool b[NN],tf;
int wr[233][233];


struct HashPair{
    auto operator()(const pair < int, int > &p) const{
        return hash < int >{}(p.first) ^ hash < int >{}(p.second);
    }
};
unordered_map < pair < int, int >, int, HashPair > mat[20];

void Init(){
//	cout<<"start"<<endl;

mat[1].insert({{1, 1}, 1}),mat[1].insert({{1, 2}, 0}),mat[1].insert({{1, 3}, 0}),mat[1].insert({{1, 4}, 0}),mat[1].insert({{1, 5}, 0}),mat[1].insert({{1, 6}, 0}),mat[1].insert({{1, 7}, 0}),mat[1].insert({{1, 8}, 0}),mat[1].insert({{1, 9}, 0}),mat[1].insert({{1, 10}, 0});
mat[1].insert({{2, 1}, 0}),mat[1].insert({{2, 2}, 1}),mat[1].insert({{2, 3}, 0}),mat[1].insert({{2, 4}, 0}),mat[1].insert({{2, 5}, 0}),mat[1].insert({{2, 6}, 0}),mat[1].insert({{2, 7}, 0}),mat[1].insert({{2, 8}, 0}),mat[1].insert({{2, 9}, 0}),mat[1].insert({{2, 10}, 0});
mat[1].insert({{3, 1}, 0}),mat[1].insert({{3, 2}, 0}),mat[1].insert({{3, 3}, 1}),mat[1].insert({{3, 4}, 0}),mat[1].insert({{3, 5}, 0}),mat[1].insert({{3, 6}, 0}),mat[1].insert({{3, 7}, 0}),mat[1].insert({{3, 8}, 0}),mat[1].insert({{3, 9}, 0}),mat[1].insert({{3, 10}, 0});
mat[1].insert({{4, 1}, 0}),mat[1].insert({{4, 2}, 0}),mat[1].insert({{4, 3}, 0}),mat[1].insert({{4, 4}, 1}),mat[1].insert({{4, 5}, 0}),mat[1].insert({{4, 6}, 0}),mat[1].insert({{4, 7}, 0}),mat[1].insert({{4, 8}, 0}),mat[1].insert({{4, 9}, 0}),mat[1].insert({{4, 10}, 0});
mat[1].insert({{5, 1}, 0}),mat[1].insert({{5, 2}, 0}),mat[1].insert({{5, 3}, 0}),mat[1].insert({{5, 4}, 0}),mat[1].insert({{5, 5}, 1}),mat[1].insert({{5, 6}, 0}),mat[1].insert({{5, 7}, 0}),mat[1].insert({{5, 8}, 0}),mat[1].insert({{5, 9}, 0}),mat[1].insert({{5, 10}, 0});
mat[1].insert({{6, 1}, 0}),mat[1].insert({{6, 2}, 0}),mat[1].insert({{6, 3}, 0}),mat[1].insert({{6, 4}, 0}),mat[1].insert({{6, 5}, 0}),mat[1].insert({{6, 6}, 1}),mat[1].insert({{6, 7}, 0}),mat[1].insert({{6, 8}, 0}),mat[1].insert({{6, 9}, 0}),mat[1].insert({{6, 10}, 0});
mat[1].insert({{7, 1}, 0}),mat[1].insert({{7, 2}, 0}),mat[1].insert({{7, 3}, 0}),mat[1].insert({{7, 4}, 0}),mat[1].insert({{7, 5}, 0}),mat[1].insert({{7, 6}, 0}),mat[1].insert({{7, 7}, 1}),mat[1].insert({{7, 8}, 0}),mat[1].insert({{7, 9}, 0}),mat[1].insert({{7, 10}, 0});
mat[1].insert({{8, 1}, 0}),mat[1].insert({{8, 2}, 0}),mat[1].insert({{8, 3}, 0}),mat[1].insert({{8, 4}, 0}),mat[1].insert({{8, 5}, 0}),mat[1].insert({{8, 6}, 0}),mat[1].insert({{8, 7}, 0}),mat[1].insert({{8, 8}, 1}),mat[1].insert({{8, 9}, 0}),mat[1].insert({{8, 10}, 0});
mat[1].insert({{9, 1}, 0}),mat[1].insert({{9, 2}, 0}),mat[1].insert({{9, 3}, 0}),mat[1].insert({{9, 4}, 0}),mat[1].insert({{9, 5}, 0}),mat[1].insert({{9, 6}, 0}),mat[1].insert({{9, 7}, 0}),mat[1].insert({{9, 8}, 0}),mat[1].insert({{9, 9}, 1}),mat[1].insert({{9, 10}, 0});
mat[1].insert({{10, 1}, 0}),mat[1].insert({{10, 2}, 0}),mat[1].insert({{10, 3}, 0}),mat[1].insert({{10, 4}, 0}),mat[1].insert({{10, 5}, 0}),mat[1].insert({{10, 6}, 0}),mat[1].insert({{10, 7}, 0}),mat[1].insert({{10, 8}, 0}),mat[1].insert({{10, 9}, 0}),mat[1].insert({{10, 10}, 1});
mat[2].insert({{1, 1}, 0}),mat[2].insert({{1, 2}, 1}),mat[2].insert({{1, 3}, 1}),mat[2].insert({{1, 4}, 0}),mat[2].insert({{1, 5}, 0}),mat[2].insert({{1, 6}, 0}),mat[2].insert({{1, 7}, 0}),mat[2].insert({{1, 8}, 0}),mat[2].insert({{1, 9}, 0}),mat[2].insert({{1, 10}, 0});
mat[2].insert({{2, 1}, 1}),mat[2].insert({{2, 2}, 0}),mat[2].insert({{2, 3}, 1}),mat[2].insert({{2, 4}, 0}),mat[2].insert({{2, 5}, 0}),mat[2].insert({{2, 6}, 0}),mat[2].insert({{2, 7}, 0}),mat[2].insert({{2, 8}, 0}),mat[2].insert({{2, 9}, 0}),mat[2].insert({{2, 10}, 0});
mat[2].insert({{3, 1}, 1}),mat[2].insert({{3, 2}, 1}),mat[2].insert({{3, 3}, 0}),mat[2].insert({{3, 4}, 0}),mat[2].insert({{3, 5}, 0}),mat[2].insert({{3, 6}, 0}),mat[2].insert({{3, 7}, 0}),mat[2].insert({{3, 8}, 0}),mat[2].insert({{3, 9}, 0}),mat[2].insert({{3, 10}, 0});
mat[2].insert({{4, 1}, 0}),mat[2].insert({{4, 2}, 0}),mat[2].insert({{4, 3}, 0}),mat[2].insert({{4, 4}, 1}),mat[2].insert({{4, 5}, 0}),mat[2].insert({{4, 6}, 0}),mat[2].insert({{4, 7}, 0}),mat[2].insert({{4, 8}, 0}),mat[2].insert({{4, 9}, 0}),mat[2].insert({{4, 10}, 0});
mat[2].insert({{5, 1}, 0}),mat[2].insert({{5, 2}, 0}),mat[2].insert({{5, 3}, 0}),mat[2].insert({{5, 4}, 0}),mat[2].insert({{5, 5}, 1}),mat[2].insert({{5, 6}, 0}),mat[2].insert({{5, 7}, 0}),mat[2].insert({{5, 8}, 0}),mat[2].insert({{5, 9}, 0}),mat[2].insert({{5, 10}, 0});
mat[2].insert({{6, 1}, 0}),mat[2].insert({{6, 2}, 0}),mat[2].insert({{6, 3}, 0}),mat[2].insert({{6, 4}, 0}),mat[2].insert({{6, 5}, 0}),mat[2].insert({{6, 6}, 1}),mat[2].insert({{6, 7}, 0}),mat[2].insert({{6, 8}, 0}),mat[2].insert({{6, 9}, 0}),mat[2].insert({{6, 10}, 0});
mat[2].insert({{7, 1}, 0}),mat[2].insert({{7, 2}, 0}),mat[2].insert({{7, 3}, 0}),mat[2].insert({{7, 4}, 0}),mat[2].insert({{7, 5}, 0}),mat[2].insert({{7, 6}, 0}),mat[2].insert({{7, 7}, 1}),mat[2].insert({{7, 8}, 0}),mat[2].insert({{7, 9}, 0}),mat[2].insert({{7, 10}, 0});
mat[2].insert({{8, 1}, 0}),mat[2].insert({{8, 2}, 0}),mat[2].insert({{8, 3}, 0}),mat[2].insert({{8, 4}, 0}),mat[2].insert({{8, 5}, 0}),mat[2].insert({{8, 6}, 0}),mat[2].insert({{8, 7}, 0}),mat[2].insert({{8, 8}, 1}),mat[2].insert({{8, 9}, 0}),mat[2].insert({{8, 10}, 0});
mat[2].insert({{9, 1}, 0}),mat[2].insert({{9, 2}, 0}),mat[2].insert({{9, 3}, 0}),mat[2].insert({{9, 4}, 0}),mat[2].insert({{9, 5}, 0}),mat[2].insert({{9, 6}, 0}),mat[2].insert({{9, 7}, 0}),mat[2].insert({{9, 8}, 0}),mat[2].insert({{9, 9}, 1}),mat[2].insert({{9, 10}, 0});
mat[2].insert({{10, 1}, 0}),mat[2].insert({{10, 2}, 0}),mat[2].insert({{10, 3}, 0}),mat[2].insert({{10, 4}, 0}),mat[2].insert({{10, 5}, 0}),mat[2].insert({{10, 6}, 0}),mat[2].insert({{10, 7}, 0}),mat[2].insert({{10, 8}, 0}),mat[2].insert({{10, 9}, 0}),mat[2].insert({{10, 10}, 1});
mat[3].insert({{1, 1}, 0}),mat[3].insert({{1, 2}, 0}),mat[3].insert({{1, 3}, 1}),mat[3].insert({{1, 4}, 1}),mat[3].insert({{1, 5}, 0}),mat[3].insert({{1, 6}, 0}),mat[3].insert({{1, 7}, 0}),mat[3].insert({{1, 8}, 0}),mat[3].insert({{1, 9}, 0}),mat[3].insert({{1, 10}, 0});
mat[3].insert({{2, 1}, 0}),mat[3].insert({{2, 2}, 1}),mat[3].insert({{2, 3}, 0}),mat[3].insert({{2, 4}, 1}),mat[3].insert({{2, 5}, 0}),mat[3].insert({{2, 6}, 0}),mat[3].insert({{2, 7}, 0}),mat[3].insert({{2, 8}, 0}),mat[3].insert({{2, 9}, 0}),mat[3].insert({{2, 10}, 0});
mat[3].insert({{3, 1}, 1}),mat[3].insert({{3, 2}, 0}),mat[3].insert({{3, 3}, 0}),mat[3].insert({{3, 4}, 1}),mat[3].insert({{3, 5}, 0}),mat[3].insert({{3, 6}, 0}),mat[3].insert({{3, 7}, 0}),mat[3].insert({{3, 8}, 0}),mat[3].insert({{3, 9}, 0}),mat[3].insert({{3, 10}, 0});
mat[3].insert({{4, 1}, 1}),mat[3].insert({{4, 2}, 1}),mat[3].insert({{4, 3}, 1}),mat[3].insert({{4, 4}, 0}),mat[3].insert({{4, 5}, 0}),mat[3].insert({{4, 6}, 0}),mat[3].insert({{4, 7}, 0}),mat[3].insert({{4, 8}, 0}),mat[3].insert({{4, 9}, 0}),mat[3].insert({{4, 10}, 0});
mat[3].insert({{5, 1}, 0}),mat[3].insert({{5, 2}, 0}),mat[3].insert({{5, 3}, 0}),mat[3].insert({{5, 4}, 0}),mat[3].insert({{5, 5}, 1}),mat[3].insert({{5, 6}, 0}),mat[3].insert({{5, 7}, 0}),mat[3].insert({{5, 8}, 0}),mat[3].insert({{5, 9}, 0}),mat[3].insert({{5, 10}, 0});
mat[3].insert({{6, 1}, 0}),mat[3].insert({{6, 2}, 0}),mat[3].insert({{6, 3}, 0}),mat[3].insert({{6, 4}, 0}),mat[3].insert({{6, 5}, 0}),mat[3].insert({{6, 6}, 1}),mat[3].insert({{6, 7}, 0}),mat[3].insert({{6, 8}, 0}),mat[3].insert({{6, 9}, 0}),mat[3].insert({{6, 10}, 0});
mat[3].insert({{7, 1}, 0}),mat[3].insert({{7, 2}, 0}),mat[3].insert({{7, 3}, 0}),mat[3].insert({{7, 4}, 0}),mat[3].insert({{7, 5}, 0}),mat[3].insert({{7, 6}, 0}),mat[3].insert({{7, 7}, 1}),mat[3].insert({{7, 8}, 0}),mat[3].insert({{7, 9}, 0}),mat[3].insert({{7, 10}, 0});
mat[3].insert({{8, 1}, 0}),mat[3].insert({{8, 2}, 0}),mat[3].insert({{8, 3}, 0}),mat[3].insert({{8, 4}, 0}),mat[3].insert({{8, 5}, 0}),mat[3].insert({{8, 6}, 0}),mat[3].insert({{8, 7}, 0}),mat[3].insert({{8, 8}, 1}),mat[3].insert({{8, 9}, 0}),mat[3].insert({{8, 10}, 0});
mat[3].insert({{9, 1}, 0}),mat[3].insert({{9, 2}, 0}),mat[3].insert({{9, 3}, 0}),mat[3].insert({{9, 4}, 0}),mat[3].insert({{9, 5}, 0}),mat[3].insert({{9, 6}, 0}),mat[3].insert({{9, 7}, 0}),mat[3].insert({{9, 8}, 0}),mat[3].insert({{9, 9}, 1}),mat[3].insert({{9, 10}, 0});
mat[3].insert({{10, 1}, 0}),mat[3].insert({{10, 2}, 0}),mat[3].insert({{10, 3}, 0}),mat[3].insert({{10, 4}, 0}),mat[3].insert({{10, 5}, 0}),mat[3].insert({{10, 6}, 0}),mat[3].insert({{10, 7}, 0}),mat[3].insert({{10, 8}, 0}),mat[3].insert({{10, 9}, 0}),mat[3].insert({{10, 10}, 1});
mat[4].insert({{1, 1}, 0}),mat[4].insert({{1, 2}, 1}),mat[4].insert({{1, 3}, 1}),mat[4].insert({{1, 4}, 0}),mat[4].insert({{1, 5}, 0}),mat[4].insert({{1, 6}, 0}),mat[4].insert({{1, 7}, 0}),mat[4].insert({{1, 8}, 0}),mat[4].insert({{1, 9}, 0}),mat[4].insert({{1, 10}, 0});
mat[4].insert({{2, 1}, 1}),mat[4].insert({{2, 2}, 0}),mat[4].insert({{2, 3}, 1}),mat[4].insert({{2, 4}, 0}),mat[4].insert({{2, 5}, 0}),mat[4].insert({{2, 6}, 0}),mat[4].insert({{2, 7}, 0}),mat[4].insert({{2, 8}, 0}),mat[4].insert({{2, 9}, 0}),mat[4].insert({{2, 10}, 0});
mat[4].insert({{3, 1}, 1}),mat[4].insert({{3, 2}, 1}),mat[4].insert({{3, 3}, 0}),mat[4].insert({{3, 4}, 0}),mat[4].insert({{3, 5}, 0}),mat[4].insert({{3, 6}, 0}),mat[4].insert({{3, 7}, 0}),mat[4].insert({{3, 8}, 0}),mat[4].insert({{3, 9}, 0}),mat[4].insert({{3, 10}, 0});
mat[4].insert({{4, 1}, 0}),mat[4].insert({{4, 2}, 0}),mat[4].insert({{4, 3}, 0}),mat[4].insert({{4, 4}, 0}),mat[4].insert({{4, 5}, 1}),mat[4].insert({{4, 6}, 1}),mat[4].insert({{4, 7}, 0}),mat[4].insert({{4, 8}, 0}),mat[4].insert({{4, 9}, 0}),mat[4].insert({{4, 10}, 0});
mat[4].insert({{5, 1}, 0}),mat[4].insert({{5, 2}, 0}),mat[4].insert({{5, 3}, 0}),mat[4].insert({{5, 4}, 1}),mat[4].insert({{5, 5}, 0}),mat[4].insert({{5, 6}, 1}),mat[4].insert({{5, 7}, 0}),mat[4].insert({{5, 8}, 0}),mat[4].insert({{5, 9}, 0}),mat[4].insert({{5, 10}, 0});
mat[4].insert({{6, 1}, 0}),mat[4].insert({{6, 2}, 0}),mat[4].insert({{6, 3}, 0}),mat[4].insert({{6, 4}, 1}),mat[4].insert({{6, 5}, 1}),mat[4].insert({{6, 6}, 0}),mat[4].insert({{6, 7}, 0}),mat[4].insert({{6, 8}, 0}),mat[4].insert({{6, 9}, 0}),mat[4].insert({{6, 10}, 0});
mat[4].insert({{7, 1}, 0}),mat[4].insert({{7, 2}, 0}),mat[4].insert({{7, 3}, 0}),mat[4].insert({{7, 4}, 0}),mat[4].insert({{7, 5}, 0}),mat[4].insert({{7, 6}, 0}),mat[4].insert({{7, 7}, 1}),mat[4].insert({{7, 8}, 0}),mat[4].insert({{7, 9}, 0}),mat[4].insert({{7, 10}, 0});
mat[4].insert({{8, 1}, 0}),mat[4].insert({{8, 2}, 0}),mat[4].insert({{8, 3}, 0}),mat[4].insert({{8, 4}, 0}),mat[4].insert({{8, 5}, 0}),mat[4].insert({{8, 6}, 0}),mat[4].insert({{8, 7}, 0}),mat[4].insert({{8, 8}, 1}),mat[4].insert({{8, 9}, 0}),mat[4].insert({{8, 10}, 0});
mat[4].insert({{9, 1}, 0}),mat[4].insert({{9, 2}, 0}),mat[4].insert({{9, 3}, 0}),mat[4].insert({{9, 4}, 0}),mat[4].insert({{9, 5}, 0}),mat[4].insert({{9, 6}, 0}),mat[4].insert({{9, 7}, 0}),mat[4].insert({{9, 8}, 0}),mat[4].insert({{9, 9}, 1}),mat[4].insert({{9, 10}, 0});
mat[4].insert({{10, 1}, 0}),mat[4].insert({{10, 2}, 0}),mat[4].insert({{10, 3}, 0}),mat[4].insert({{10, 4}, 0}),mat[4].insert({{10, 5}, 0}),mat[4].insert({{10, 6}, 0}),mat[4].insert({{10, 7}, 0}),mat[4].insert({{10, 8}, 0}),mat[4].insert({{10, 9}, 0}),mat[4].insert({{10, 10}, 1});
mat[5].insert({{1, 1}, 0}),mat[5].insert({{1, 2}, 1}),mat[5].insert({{1, 3}, 0}),mat[5].insert({{1, 4}, 1}),mat[5].insert({{1, 5}, 1}),mat[5].insert({{1, 6}, 0}),mat[5].insert({{1, 7}, 0}),mat[5].insert({{1, 8}, 0}),mat[5].insert({{1, 9}, 0}),mat[5].insert({{1, 10}, 0});
mat[5].insert({{2, 1}, 1}),mat[5].insert({{2, 2}, 0}),mat[5].insert({{2, 3}, 1}),mat[5].insert({{2, 4}, 1}),mat[5].insert({{2, 5}, 1}),mat[5].insert({{2, 6}, 0}),mat[5].insert({{2, 7}, 0}),mat[5].insert({{2, 8}, 0}),mat[5].insert({{2, 9}, 0}),mat[5].insert({{2, 10}, 0});
mat[5].insert({{3, 1}, 0}),mat[5].insert({{3, 2}, 1}),mat[5].insert({{3, 3}, 1}),mat[5].insert({{3, 4}, 1}),mat[5].insert({{3, 5}, 0}),mat[5].insert({{3, 6}, 0}),mat[5].insert({{3, 7}, 0}),mat[5].insert({{3, 8}, 0}),mat[5].insert({{3, 9}, 0}),mat[5].insert({{3, 10}, 0});
mat[5].insert({{4, 1}, 1}),mat[5].insert({{4, 2}, 1}),mat[5].insert({{4, 3}, 0}),mat[5].insert({{4, 4}, 0}),mat[5].insert({{4, 5}, 0}),mat[5].insert({{4, 6}, 0}),mat[5].insert({{4, 7}, 0}),mat[5].insert({{4, 8}, 0}),mat[5].insert({{4, 9}, 0}),mat[5].insert({{4, 10}, 0});
mat[5].insert({{5, 1}, 0}),mat[5].insert({{5, 2}, 1}),mat[5].insert({{5, 3}, 1}),mat[5].insert({{5, 4}, 0}),mat[5].insert({{5, 5}, 1}),mat[5].insert({{5, 6}, 0}),mat[5].insert({{5, 7}, 0}),mat[5].insert({{5, 8}, 0}),mat[5].insert({{5, 9}, 0}),mat[5].insert({{5, 10}, 0});
mat[5].insert({{6, 1}, 0}),mat[5].insert({{6, 2}, 0}),mat[5].insert({{6, 3}, 0}),mat[5].insert({{6, 4}, 0}),mat[5].insert({{6, 5}, 0}),mat[5].insert({{6, 6}, 1}),mat[5].insert({{6, 7}, 0}),mat[5].insert({{6, 8}, 0}),mat[5].insert({{6, 9}, 0}),mat[5].insert({{6, 10}, 0});
mat[5].insert({{7, 1}, 0}),mat[5].insert({{7, 2}, 0}),mat[5].insert({{7, 3}, 0}),mat[5].insert({{7, 4}, 0}),mat[5].insert({{7, 5}, 0}),mat[5].insert({{7, 6}, 0}),mat[5].insert({{7, 7}, 1}),mat[5].insert({{7, 8}, 0}),mat[5].insert({{7, 9}, 0}),mat[5].insert({{7, 10}, 0});
mat[5].insert({{8, 1}, 0}),mat[5].insert({{8, 2}, 0}),mat[5].insert({{8, 3}, 0}),mat[5].insert({{8, 4}, 0}),mat[5].insert({{8, 5}, 0}),mat[5].insert({{8, 6}, 0}),mat[5].insert({{8, 7}, 0}),mat[5].insert({{8, 8}, 1}),mat[5].insert({{8, 9}, 0}),mat[5].insert({{8, 10}, 0});
mat[5].insert({{9, 1}, 0}),mat[5].insert({{9, 2}, 0}),mat[5].insert({{9, 3}, 0}),mat[5].insert({{9, 4}, 0}),mat[5].insert({{9, 5}, 0}),mat[5].insert({{9, 6}, 0}),mat[5].insert({{9, 7}, 0}),mat[5].insert({{9, 8}, 0}),mat[5].insert({{9, 9}, 1}),mat[5].insert({{9, 10}, 0});
mat[5].insert({{10, 1}, 0}),mat[5].insert({{10, 2}, 0}),mat[5].insert({{10, 3}, 0}),mat[5].insert({{10, 4}, 0}),mat[5].insert({{10, 5}, 0}),mat[5].insert({{10, 6}, 0}),mat[5].insert({{10, 7}, 0}),mat[5].insert({{10, 8}, 0}),mat[5].insert({{10, 9}, 0}),mat[5].insert({{10, 10}, 1});
mat[6].insert({{1, 1}, 0}),mat[6].insert({{1, 2}, 1}),mat[6].insert({{1, 3}, 1}),mat[6].insert({{1, 4}, 0}),mat[6].insert({{1, 5}, 0}),mat[6].insert({{1, 6}, 0}),mat[6].insert({{1, 7}, 0}),mat[6].insert({{1, 8}, 0}),mat[6].insert({{1, 9}, 0}),mat[6].insert({{1, 10}, 0});
mat[6].insert({{2, 1}, 1}),mat[6].insert({{2, 2}, 0}),mat[6].insert({{2, 3}, 1}),mat[6].insert({{2, 4}, 0}),mat[6].insert({{2, 5}, 0}),mat[6].insert({{2, 6}, 0}),mat[6].insert({{2, 7}, 0}),mat[6].insert({{2, 8}, 0}),mat[6].insert({{2, 9}, 0}),mat[6].insert({{2, 10}, 0});
mat[6].insert({{3, 1}, 1}),mat[6].insert({{3, 2}, 1}),mat[6].insert({{3, 3}, 0}),mat[6].insert({{3, 4}, 0}),mat[6].insert({{3, 5}, 0}),mat[6].insert({{3, 6}, 0}),mat[6].insert({{3, 7}, 0}),mat[6].insert({{3, 8}, 0}),mat[6].insert({{3, 9}, 0}),mat[6].insert({{3, 10}, 0});
mat[6].insert({{4, 1}, 0}),mat[6].insert({{4, 2}, 0}),mat[6].insert({{4, 3}, 0}),mat[6].insert({{4, 4}, 0}),mat[6].insert({{4, 5}, 0}),mat[6].insert({{4, 6}, 1}),mat[6].insert({{4, 7}, 1}),mat[6].insert({{4, 8}, 0}),mat[6].insert({{4, 9}, 0}),mat[6].insert({{4, 10}, 0});
mat[6].insert({{5, 1}, 0}),mat[6].insert({{5, 2}, 0}),mat[6].insert({{5, 3}, 0}),mat[6].insert({{5, 4}, 0}),mat[6].insert({{5, 5}, 1}),mat[6].insert({{5, 6}, 0}),mat[6].insert({{5, 7}, 1}),mat[6].insert({{5, 8}, 0}),mat[6].insert({{5, 9}, 0}),mat[6].insert({{5, 10}, 0});
mat[6].insert({{6, 1}, 0}),mat[6].insert({{6, 2}, 0}),mat[6].insert({{6, 3}, 0}),mat[6].insert({{6, 4}, 1}),mat[6].insert({{6, 5}, 0}),mat[6].insert({{6, 6}, 0}),mat[6].insert({{6, 7}, 1}),mat[6].insert({{6, 8}, 0}),mat[6].insert({{6, 9}, 0}),mat[6].insert({{6, 10}, 0});
mat[6].insert({{7, 1}, 0}),mat[6].insert({{7, 2}, 0}),mat[6].insert({{7, 3}, 0}),mat[6].insert({{7, 4}, 1}),mat[6].insert({{7, 5}, 1}),mat[6].insert({{7, 6}, 1}),mat[6].insert({{7, 7}, 0}),mat[6].insert({{7, 8}, 0}),mat[6].insert({{7, 9}, 0}),mat[6].insert({{7, 10}, 0});
mat[6].insert({{8, 1}, 0}),mat[6].insert({{8, 2}, 0}),mat[6].insert({{8, 3}, 0}),mat[6].insert({{8, 4}, 0}),mat[6].insert({{8, 5}, 0}),mat[6].insert({{8, 6}, 0}),mat[6].insert({{8, 7}, 0}),mat[6].insert({{8, 8}, 1}),mat[6].insert({{8, 9}, 0}),mat[6].insert({{8, 10}, 0});
mat[6].insert({{9, 1}, 0}),mat[6].insert({{9, 2}, 0}),mat[6].insert({{9, 3}, 0}),mat[6].insert({{9, 4}, 0}),mat[6].insert({{9, 5}, 0}),mat[6].insert({{9, 6}, 0}),mat[6].insert({{9, 7}, 0}),mat[6].insert({{9, 8}, 0}),mat[6].insert({{9, 9}, 1}),mat[6].insert({{9, 10}, 0});
mat[6].insert({{10, 1}, 0}),mat[6].insert({{10, 2}, 0}),mat[6].insert({{10, 3}, 0}),mat[6].insert({{10, 4}, 0}),mat[6].insert({{10, 5}, 0}),mat[6].insert({{10, 6}, 0}),mat[6].insert({{10, 7}, 0}),mat[6].insert({{10, 8}, 0}),mat[6].insert({{10, 9}, 0}),mat[6].insert({{10, 10}, 1});
mat[7].insert({{1, 1}, 0}),mat[7].insert({{1, 2}, 1}),mat[7].insert({{1, 3}, 1}),mat[7].insert({{1, 4}, 0}),mat[7].insert({{1, 5}, 1}),mat[7].insert({{1, 6}, 0}),mat[7].insert({{1, 7}, 0}),mat[7].insert({{1, 8}, 0}),mat[7].insert({{1, 9}, 0}),mat[7].insert({{1, 10}, 0});
mat[7].insert({{2, 1}, 1}),mat[7].insert({{2, 2}, 0}),mat[7].insert({{2, 3}, 1}),mat[7].insert({{2, 4}, 1}),mat[7].insert({{2, 5}, 1}),mat[7].insert({{2, 6}, 0}),mat[7].insert({{2, 7}, 1}),mat[7].insert({{2, 8}, 0}),mat[7].insert({{2, 9}, 0}),mat[7].insert({{2, 10}, 0});
mat[7].insert({{3, 1}, 1}),mat[7].insert({{3, 2}, 0}),mat[7].insert({{3, 3}, 1}),mat[7].insert({{3, 4}, 1}),mat[7].insert({{3, 5}, 1}),mat[7].insert({{3, 6}, 1}),mat[7].insert({{3, 7}, 0}),mat[7].insert({{3, 8}, 0}),mat[7].insert({{3, 9}, 0}),mat[7].insert({{3, 10}, 0});
mat[7].insert({{4, 1}, 1}),mat[7].insert({{4, 2}, 0}),mat[7].insert({{4, 3}, 1}),mat[7].insert({{4, 4}, 0}),mat[7].insert({{4, 5}, 0}),mat[7].insert({{4, 6}, 0}),mat[7].insert({{4, 7}, 0}),mat[7].insert({{4, 8}, 0}),mat[7].insert({{4, 9}, 0}),mat[7].insert({{4, 10}, 0});
mat[7].insert({{5, 1}, 1}),mat[7].insert({{5, 2}, 0}),mat[7].insert({{5, 3}, 0}),mat[7].insert({{5, 4}, 0}),mat[7].insert({{5, 5}, 1}),mat[7].insert({{5, 6}, 0}),mat[7].insert({{5, 7}, 0}),mat[7].insert({{5, 8}, 0}),mat[7].insert({{5, 9}, 0}),mat[7].insert({{5, 10}, 0});
mat[7].insert({{6, 1}, 1}),mat[7].insert({{6, 2}, 1}),mat[7].insert({{6, 3}, 0}),mat[7].insert({{6, 4}, 1}),mat[7].insert({{6, 5}, 0}),mat[7].insert({{6, 6}, 0}),mat[7].insert({{6, 7}, 0}),mat[7].insert({{6, 8}, 0}),mat[7].insert({{6, 9}, 0}),mat[7].insert({{6, 10}, 0});
mat[7].insert({{7, 1}, 1}),mat[7].insert({{7, 2}, 1}),mat[7].insert({{7, 3}, 0}),mat[7].insert({{7, 4}, 0}),mat[7].insert({{7, 5}, 0}),mat[7].insert({{7, 6}, 1}),mat[7].insert({{7, 7}, 0}),mat[7].insert({{7, 8}, 0}),mat[7].insert({{7, 9}, 0}),mat[7].insert({{7, 10}, 0});
mat[7].insert({{8, 1}, 0}),mat[7].insert({{8, 2}, 0}),mat[7].insert({{8, 3}, 0}),mat[7].insert({{8, 4}, 0}),mat[7].insert({{8, 5}, 0}),mat[7].insert({{8, 6}, 0}),mat[7].insert({{8, 7}, 0}),mat[7].insert({{8, 8}, 1}),mat[7].insert({{8, 9}, 0}),mat[7].insert({{8, 10}, 0});
mat[7].insert({{9, 1}, 0}),mat[7].insert({{9, 2}, 0}),mat[7].insert({{9, 3}, 0}),mat[7].insert({{9, 4}, 0}),mat[7].insert({{9, 5}, 0}),mat[7].insert({{9, 6}, 0}),mat[7].insert({{9, 7}, 0}),mat[7].insert({{9, 8}, 0}),mat[7].insert({{9, 9}, 1}),mat[7].insert({{9, 10}, 0});
mat[7].insert({{10, 1}, 0}),mat[7].insert({{10, 2}, 0}),mat[7].insert({{10, 3}, 0}),mat[7].insert({{10, 4}, 0}),mat[7].insert({{10, 5}, 0}),mat[7].insert({{10, 6}, 0}),mat[7].insert({{10, 7}, 0}),mat[7].insert({{10, 8}, 0}),mat[7].insert({{10, 9}, 0}),mat[7].insert({{10, 10}, 1});
mat[8].insert({{1, 1}, 0}),mat[8].insert({{1, 2}, 1}),mat[8].insert({{1, 3}, 1}),mat[8].insert({{1, 4}, 0}),mat[8].insert({{1, 5}, 0}),mat[8].insert({{1, 6}, 0}),mat[8].insert({{1, 7}, 0}),mat[8].insert({{1, 8}, 0}),mat[8].insert({{1, 9}, 0}),mat[8].insert({{1, 10}, 0});
mat[8].insert({{2, 1}, 1}),mat[8].insert({{2, 2}, 0}),mat[8].insert({{2, 3}, 1}),mat[8].insert({{2, 4}, 0}),mat[8].insert({{2, 5}, 0}),mat[8].insert({{2, 6}, 0}),mat[8].insert({{2, 7}, 0}),mat[8].insert({{2, 8}, 0}),mat[8].insert({{2, 9}, 0}),mat[8].insert({{2, 10}, 0});
mat[8].insert({{3, 1}, 1}),mat[8].insert({{3, 2}, 1}),mat[8].insert({{3, 3}, 0}),mat[8].insert({{3, 4}, 0}),mat[8].insert({{3, 5}, 0}),mat[8].insert({{3, 6}, 0}),mat[8].insert({{3, 7}, 0}),mat[8].insert({{3, 8}, 0}),mat[8].insert({{3, 9}, 0}),mat[8].insert({{3, 10}, 0});
mat[8].insert({{4, 1}, 0}),mat[8].insert({{4, 2}, 0}),mat[8].insert({{4, 3}, 0}),mat[8].insert({{4, 4}, 0}),mat[8].insert({{4, 5}, 1}),mat[8].insert({{4, 6}, 1}),mat[8].insert({{4, 7}, 0}),mat[8].insert({{4, 8}, 0}),mat[8].insert({{4, 9}, 0}),mat[8].insert({{4, 10}, 0});
mat[8].insert({{5, 1}, 0}),mat[8].insert({{5, 2}, 0}),mat[8].insert({{5, 3}, 0}),mat[8].insert({{5, 4}, 1}),mat[8].insert({{5, 5}, 0}),mat[8].insert({{5, 6}, 1}),mat[8].insert({{5, 7}, 0}),mat[8].insert({{5, 8}, 0}),mat[8].insert({{5, 9}, 0}),mat[8].insert({{5, 10}, 0});
mat[8].insert({{6, 1}, 0}),mat[8].insert({{6, 2}, 0}),mat[8].insert({{6, 3}, 0}),mat[8].insert({{6, 4}, 1}),mat[8].insert({{6, 5}, 1}),mat[8].insert({{6, 6}, 0}),mat[8].insert({{6, 7}, 0}),mat[8].insert({{6, 8}, 0}),mat[8].insert({{6, 9}, 0}),mat[8].insert({{6, 10}, 0});
mat[8].insert({{7, 1}, 0}),mat[8].insert({{7, 2}, 0}),mat[8].insert({{7, 3}, 0}),mat[8].insert({{7, 4}, 0}),mat[8].insert({{7, 5}, 0}),mat[8].insert({{7, 6}, 0}),mat[8].insert({{7, 7}, 0}),mat[8].insert({{7, 8}, 1}),mat[8].insert({{7, 9}, 1}),mat[8].insert({{7, 10}, 0});
mat[8].insert({{8, 1}, 0}),mat[8].insert({{8, 2}, 0}),mat[8].insert({{8, 3}, 0}),mat[8].insert({{8, 4}, 0}),mat[8].insert({{8, 5}, 0}),mat[8].insert({{8, 6}, 0}),mat[8].insert({{8, 7}, 1}),mat[8].insert({{8, 8}, 0}),mat[8].insert({{8, 9}, 1}),mat[8].insert({{8, 10}, 0});
mat[8].insert({{9, 1}, 0}),mat[8].insert({{9, 2}, 0}),mat[8].insert({{9, 3}, 0}),mat[8].insert({{9, 4}, 0}),mat[8].insert({{9, 5}, 0}),mat[8].insert({{9, 6}, 0}),mat[8].insert({{9, 7}, 1}),mat[8].insert({{9, 8}, 1}),mat[8].insert({{9, 9}, 0}),mat[8].insert({{9, 10}, 0});
mat[8].insert({{10, 1}, 0}),mat[8].insert({{10, 2}, 0}),mat[8].insert({{10, 3}, 0}),mat[8].insert({{10, 4}, 0}),mat[8].insert({{10, 5}, 0}),mat[8].insert({{10, 6}, 0}),mat[8].insert({{10, 7}, 0}),mat[8].insert({{10, 8}, 0}),mat[8].insert({{10, 9}, 0}),mat[8].insert({{10, 10}, 1});
mat[9].insert({{1, 1}, 0}),mat[9].insert({{1, 2}, 0}),mat[9].insert({{1, 3}, 1}),mat[9].insert({{1, 4}, 1}),mat[9].insert({{1, 5}, 0}),mat[9].insert({{1, 6}, 0}),mat[9].insert({{1, 7}, 0}),mat[9].insert({{1, 8}, 0}),mat[9].insert({{1, 9}, 0}),mat[9].insert({{1, 10}, 0});
mat[9].insert({{2, 1}, 0}),mat[9].insert({{2, 2}, 1}),mat[9].insert({{2, 3}, 0}),mat[9].insert({{2, 4}, 1}),mat[9].insert({{2, 5}, 0}),mat[9].insert({{2, 6}, 0}),mat[9].insert({{2, 7}, 0}),mat[9].insert({{2, 8}, 0}),mat[9].insert({{2, 9}, 0}),mat[9].insert({{2, 10}, 0});
mat[9].insert({{3, 1}, 1}),mat[9].insert({{3, 2}, 0}),mat[9].insert({{3, 3}, 0}),mat[9].insert({{3, 4}, 1}),mat[9].insert({{3, 5}, 0}),mat[9].insert({{3, 6}, 0}),mat[9].insert({{3, 7}, 0}),mat[9].insert({{3, 8}, 0}),mat[9].insert({{3, 9}, 0}),mat[9].insert({{3, 10}, 0});
mat[9].insert({{4, 1}, 1}),mat[9].insert({{4, 2}, 1}),mat[9].insert({{4, 3}, 1}),mat[9].insert({{4, 4}, 0}),mat[9].insert({{4, 5}, 0}),mat[9].insert({{4, 6}, 0}),mat[9].insert({{4, 7}, 0}),mat[9].insert({{4, 8}, 0}),mat[9].insert({{4, 9}, 0}),mat[9].insert({{4, 10}, 0});
mat[9].insert({{5, 1}, 0}),mat[9].insert({{5, 2}, 0}),mat[9].insert({{5, 3}, 0}),mat[9].insert({{5, 4}, 0}),mat[9].insert({{5, 5}, 0}),mat[9].insert({{5, 6}, 0}),mat[9].insert({{5, 7}, 1}),mat[9].insert({{5, 8}, 1}),mat[9].insert({{5, 9}, 0}),mat[9].insert({{5, 10}, 0});
mat[9].insert({{6, 1}, 0}),mat[9].insert({{6, 2}, 0}),mat[9].insert({{6, 3}, 0}),mat[9].insert({{6, 4}, 0}),mat[9].insert({{6, 5}, 0}),mat[9].insert({{6, 6}, 1}),mat[9].insert({{6, 7}, 0}),mat[9].insert({{6, 8}, 1}),mat[9].insert({{6, 9}, 0}),mat[9].insert({{6, 10}, 0});
mat[9].insert({{7, 1}, 0}),mat[9].insert({{7, 2}, 0}),mat[9].insert({{7, 3}, 0}),mat[9].insert({{7, 4}, 0}),mat[9].insert({{7, 5}, 1}),mat[9].insert({{7, 6}, 0}),mat[9].insert({{7, 7}, 0}),mat[9].insert({{7, 8}, 1}),mat[9].insert({{7, 9}, 0}),mat[9].insert({{7, 10}, 0});
mat[9].insert({{8, 1}, 0}),mat[9].insert({{8, 2}, 0}),mat[9].insert({{8, 3}, 0}),mat[9].insert({{8, 4}, 0}),mat[9].insert({{8, 5}, 1}),mat[9].insert({{8, 6}, 1}),mat[9].insert({{8, 7}, 1}),mat[9].insert({{8, 8}, 0}),mat[9].insert({{8, 9}, 0}),mat[9].insert({{8, 10}, 0});
mat[9].insert({{9, 1}, 0}),mat[9].insert({{9, 2}, 0}),mat[9].insert({{9, 3}, 0}),mat[9].insert({{9, 4}, 0}),mat[9].insert({{9, 5}, 0}),mat[9].insert({{9, 6}, 0}),mat[9].insert({{9, 7}, 0}),mat[9].insert({{9, 8}, 0}),mat[9].insert({{9, 9}, 1}),mat[9].insert({{9, 10}, 0});
mat[9].insert({{10, 1}, 0}),mat[9].insert({{10, 2}, 0}),mat[9].insert({{10, 3}, 0}),mat[9].insert({{10, 4}, 0}),mat[9].insert({{10, 5}, 0}),mat[9].insert({{10, 6}, 0}),mat[9].insert({{10, 7}, 0}),mat[9].insert({{10, 8}, 0}),mat[9].insert({{10, 9}, 0}),mat[9].insert({{10, 10}, 1});
mat[10].insert({{1, 1}, 0}),mat[10].insert({{1, 2}, 1}),mat[10].insert({{1, 3}, 1}),mat[10].insert({{1, 4}, 0}),mat[10].insert({{1, 5}, 0}),mat[10].insert({{1, 6}, 0}),mat[10].insert({{1, 7}, 0}),mat[10].insert({{1, 8}, 0}),mat[10].insert({{1, 9}, 0}),mat[10].insert({{1, 10}, 0});
mat[10].insert({{2, 1}, 1}),mat[10].insert({{2, 2}, 0}),mat[10].insert({{2, 3}, 1}),mat[10].insert({{2, 4}, 0}),mat[10].insert({{2, 5}, 0}),mat[10].insert({{2, 6}, 0}),mat[10].insert({{2, 7}, 0}),mat[10].insert({{2, 8}, 0}),mat[10].insert({{2, 9}, 0}),mat[10].insert({{2, 10}, 0});
mat[10].insert({{3, 1}, 1}),mat[10].insert({{3, 2}, 1}),mat[10].insert({{3, 3}, 0}),mat[10].insert({{3, 4}, 0}),mat[10].insert({{3, 5}, 0}),mat[10].insert({{3, 6}, 0}),mat[10].insert({{3, 7}, 0}),mat[10].insert({{3, 8}, 0}),mat[10].insert({{3, 9}, 0}),mat[10].insert({{3, 10}, 0});
mat[10].insert({{4, 1}, 0}),mat[10].insert({{4, 2}, 0}),mat[10].insert({{4, 3}, 0}),mat[10].insert({{4, 4}, 0}),mat[10].insert({{4, 5}, 1}),mat[10].insert({{4, 6}, 0}),mat[10].insert({{4, 7}, 1}),mat[10].insert({{4, 8}, 1}),mat[10].insert({{4, 9}, 0}),mat[10].insert({{4, 10}, 0});
mat[10].insert({{5, 1}, 0}),mat[10].insert({{5, 2}, 0}),mat[10].insert({{5, 3}, 0}),mat[10].insert({{5, 4}, 1}),mat[10].insert({{5, 5}, 0}),mat[10].insert({{5, 6}, 1}),mat[10].insert({{5, 7}, 1}),mat[10].insert({{5, 8}, 1}),mat[10].insert({{5, 9}, 0}),mat[10].insert({{5, 10}, 0});
mat[10].insert({{6, 1}, 0}),mat[10].insert({{6, 2}, 0}),mat[10].insert({{6, 3}, 0}),mat[10].insert({{6, 4}, 0}),mat[10].insert({{6, 5}, 1}),mat[10].insert({{6, 6}, 1}),mat[10].insert({{6, 7}, 1}),mat[10].insert({{6, 8}, 0}),mat[10].insert({{6, 9}, 0}),mat[10].insert({{6, 10}, 0});
mat[10].insert({{7, 1}, 0}),mat[10].insert({{7, 2}, 0}),mat[10].insert({{7, 3}, 0}),mat[10].insert({{7, 4}, 1}),mat[10].insert({{7, 5}, 1}),mat[10].insert({{7, 6}, 0}),mat[10].insert({{7, 7}, 0}),mat[10].insert({{7, 8}, 0}),mat[10].insert({{7, 9}, 0}),mat[10].insert({{7, 10}, 0});
mat[10].insert({{8, 1}, 0}),mat[10].insert({{8, 2}, 0}),mat[10].insert({{8, 3}, 0}),mat[10].insert({{8, 4}, 0}),mat[10].insert({{8, 5}, 1}),mat[10].insert({{8, 6}, 1}),mat[10].insert({{8, 7}, 0}),mat[10].insert({{8, 8}, 1}),mat[10].insert({{8, 9}, 0}),mat[10].insert({{8, 10}, 0});
mat[10].insert({{9, 1}, 0}),mat[10].insert({{9, 2}, 0}),mat[10].insert({{9, 3}, 0}),mat[10].insert({{9, 4}, 0}),mat[10].insert({{9, 5}, 0}),mat[10].insert({{9, 6}, 0}),mat[10].insert({{9, 7}, 0}),mat[10].insert({{9, 8}, 0}),mat[10].insert({{9, 9}, 1}),mat[10].insert({{9, 10}, 0});
mat[10].insert({{10, 1}, 0}),mat[10].insert({{10, 2}, 0}),mat[10].insert({{10, 3}, 0}),mat[10].insert({{10, 4}, 0}),mat[10].insert({{10, 5}, 0}),mat[10].insert({{10, 6}, 0}),mat[10].insert({{10, 7}, 0}),mat[10].insert({{10, 8}, 0}),mat[10].insert({{10, 9}, 0}),mat[10].insert({{10, 10}, 1});
mat[11].insert({{1, 1}, 1}),mat[11].insert({{1, 2}, 1}),mat[11].insert({{1, 3}, 1}),mat[11].insert({{1, 4}, 0}),mat[11].insert({{1, 5}, 1}),mat[11].insert({{1, 6}, 0}),mat[11].insert({{1, 7}, 0}),mat[11].insert({{1, 8}, 0}),mat[11].insert({{1, 9}, 0}),mat[11].insert({{1, 10}, 0});
mat[11].insert({{2, 1}, 1}),mat[11].insert({{2, 2}, 1}),mat[11].insert({{2, 3}, 1}),mat[11].insert({{2, 4}, 1}),mat[11].insert({{2, 5}, 1}),mat[11].insert({{2, 6}, 1}),mat[11].insert({{2, 7}, 0}),mat[11].insert({{2, 8}, 0}),mat[11].insert({{2, 9}, 1}),mat[11].insert({{2, 10}, 0});
mat[11].insert({{3, 1}, 1}),mat[11].insert({{3, 2}, 0}),mat[11].insert({{3, 3}, 1}),mat[11].insert({{3, 4}, 0}),mat[11].insert({{3, 5}, 0}),mat[11].insert({{3, 6}, 1}),mat[11].insert({{3, 7}, 1}),mat[11].insert({{3, 8}, 1}),mat[11].insert({{3, 9}, 1}),mat[11].insert({{3, 10}, 0});
mat[11].insert({{4, 1}, 0}),mat[11].insert({{4, 2}, 1}),mat[11].insert({{4, 3}, 1}),mat[11].insert({{4, 4}, 0}),mat[11].insert({{4, 5}, 0}),mat[11].insert({{4, 6}, 1}),mat[11].insert({{4, 7}, 0}),mat[11].insert({{4, 8}, 1}),mat[11].insert({{4, 9}, 0}),mat[11].insert({{4, 10}, 1});
mat[11].insert({{5, 1}, 1}),mat[11].insert({{5, 2}, 0}),mat[11].insert({{5, 3}, 1}),mat[11].insert({{5, 4}, 1}),mat[11].insert({{5, 5}, 0}),mat[11].insert({{5, 6}, 1}),mat[11].insert({{5, 7}, 0}),mat[11].insert({{5, 8}, 0}),mat[11].insert({{5, 9}, 1}),mat[11].insert({{5, 10}, 1});
mat[11].insert({{6, 1}, 1}),mat[11].insert({{6, 2}, 0}),mat[11].insert({{6, 3}, 1}),mat[11].insert({{6, 4}, 1}),mat[11].insert({{6, 5}, 0}),mat[11].insert({{6, 6}, 0}),mat[11].insert({{6, 7}, 1}),mat[11].insert({{6, 8}, 0}),mat[11].insert({{6, 9}, 0}),mat[11].insert({{6, 10}, 0});
mat[11].insert({{7, 1}, 1}),mat[11].insert({{7, 2}, 0}),mat[11].insert({{7, 3}, 0}),mat[11].insert({{7, 4}, 0}),mat[11].insert({{7, 5}, 1}),mat[11].insert({{7, 6}, 0}),mat[11].insert({{7, 7}, 1}),mat[11].insert({{7, 8}, 0}),mat[11].insert({{7, 9}, 0}),mat[11].insert({{7, 10}, 1});
mat[11].insert({{8, 1}, 0}),mat[11].insert({{8, 2}, 1}),mat[11].insert({{8, 3}, 0}),mat[11].insert({{8, 4}, 1}),mat[11].insert({{8, 5}, 0}),mat[11].insert({{8, 6}, 0}),mat[11].insert({{8, 7}, 1}),mat[11].insert({{8, 8}, 0}),mat[11].insert({{8, 9}, 1}),mat[11].insert({{8, 10}, 1});
mat[11].insert({{9, 1}, 1}),mat[11].insert({{9, 2}, 1}),mat[11].insert({{9, 3}, 1}),mat[11].insert({{9, 4}, 0}),mat[11].insert({{9, 5}, 0}),mat[11].insert({{9, 6}, 1}),mat[11].insert({{9, 7}, 0}),mat[11].insert({{9, 8}, 1}),mat[11].insert({{9, 9}, 1}),mat[11].insert({{9, 10}, 1});
mat[11].insert({{10, 1}, 1}),mat[11].insert({{10, 2}, 1}),mat[11].insert({{10, 3}, 0}),mat[11].insert({{10, 4}, 0}),mat[11].insert({{10, 5}, 1}),mat[11].insert({{10, 6}, 0}),mat[11].insert({{10, 7}, 0}),mat[11].insert({{10, 8}, 1}),mat[11].insert({{10, 9}, 1}),mat[11].insert({{10, 10}, 0});
mat[12].insert({{1, 1}, 0}),mat[12].insert({{1, 2}, 1}),mat[12].insert({{1, 3}, 1}),mat[12].insert({{1, 4}, 0}),mat[12].insert({{1, 5}, 0}),mat[12].insert({{1, 6}, 0}),mat[12].insert({{1, 7}, 0}),mat[12].insert({{1, 8}, 0}),mat[12].insert({{1, 9}, 0}),mat[12].insert({{1, 10}, 0});
mat[12].insert({{2, 1}, 1}),mat[12].insert({{2, 2}, 0}),mat[12].insert({{2, 3}, 1}),mat[12].insert({{2, 4}, 0}),mat[12].insert({{2, 5}, 0}),mat[12].insert({{2, 6}, 0}),mat[12].insert({{2, 7}, 0}),mat[12].insert({{2, 8}, 0}),mat[12].insert({{2, 9}, 0}),mat[12].insert({{2, 10}, 0});
mat[12].insert({{3, 1}, 1}),mat[12].insert({{3, 2}, 1}),mat[12].insert({{3, 3}, 0}),mat[12].insert({{3, 4}, 0}),mat[12].insert({{3, 5}, 0}),mat[12].insert({{3, 6}, 0}),mat[12].insert({{3, 7}, 0}),mat[12].insert({{3, 8}, 0}),mat[12].insert({{3, 9}, 0}),mat[12].insert({{3, 10}, 0});
mat[12].insert({{4, 1}, 0}),mat[12].insert({{4, 2}, 0}),mat[12].insert({{4, 3}, 0}),mat[12].insert({{4, 4}, 0}),mat[12].insert({{4, 5}, 1}),mat[12].insert({{4, 6}, 1}),mat[12].insert({{4, 7}, 0}),mat[12].insert({{4, 8}, 0}),mat[12].insert({{4, 9}, 0}),mat[12].insert({{4, 10}, 0});
mat[12].insert({{5, 1}, 0}),mat[12].insert({{5, 2}, 0}),mat[12].insert({{5, 3}, 0}),mat[12].insert({{5, 4}, 1}),mat[12].insert({{5, 5}, 0}),mat[12].insert({{5, 6}, 1}),mat[12].insert({{5, 7}, 0}),mat[12].insert({{5, 8}, 0}),mat[12].insert({{5, 9}, 0}),mat[12].insert({{5, 10}, 0});
mat[12].insert({{6, 1}, 0}),mat[12].insert({{6, 2}, 0}),mat[12].insert({{6, 3}, 0}),mat[12].insert({{6, 4}, 1}),mat[12].insert({{6, 5}, 1}),mat[12].insert({{6, 6}, 0}),mat[12].insert({{6, 7}, 0}),mat[12].insert({{6, 8}, 0}),mat[12].insert({{6, 9}, 0}),mat[12].insert({{6, 10}, 0});
mat[12].insert({{7, 1}, 0}),mat[12].insert({{7, 2}, 0}),mat[12].insert({{7, 3}, 0}),mat[12].insert({{7, 4}, 0}),mat[12].insert({{7, 5}, 0}),mat[12].insert({{7, 6}, 0}),mat[12].insert({{7, 7}, 0}),mat[12].insert({{7, 8}, 0}),mat[12].insert({{7, 9}, 1}),mat[12].insert({{7, 10}, 1});
mat[12].insert({{8, 1}, 0}),mat[12].insert({{8, 2}, 0}),mat[12].insert({{8, 3}, 0}),mat[12].insert({{8, 4}, 0}),mat[12].insert({{8, 5}, 0}),mat[12].insert({{8, 6}, 0}),mat[12].insert({{8, 7}, 0}),mat[12].insert({{8, 8}, 1}),mat[12].insert({{8, 9}, 0}),mat[12].insert({{8, 10}, 1});
mat[12].insert({{9, 1}, 0}),mat[12].insert({{9, 2}, 0}),mat[12].insert({{9, 3}, 0}),mat[12].insert({{9, 4}, 0}),mat[12].insert({{9, 5}, 0}),mat[12].insert({{9, 6}, 0}),mat[12].insert({{9, 7}, 1}),mat[12].insert({{9, 8}, 0}),mat[12].insert({{9, 9}, 0}),mat[12].insert({{9, 10}, 1});
mat[12].insert({{10, 1}, 0}),mat[12].insert({{10, 2}, 0}),mat[12].insert({{10, 3}, 0}),mat[12].insert({{10, 4}, 0}),mat[12].insert({{10, 5}, 0}),mat[12].insert({{10, 6}, 0}),mat[12].insert({{10, 7}, 1}),mat[12].insert({{10, 8}, 1}),mat[12].insert({{10, 9}, 1}),mat[12].insert({{10, 10}, 0});
mat[13].insert({{1, 1}, 1}),mat[13].insert({{1, 2}, 0}),mat[13].insert({{1, 3}, 1}),mat[13].insert({{1, 4}, 0}),mat[13].insert({{1, 5}, 0}),mat[13].insert({{1, 6}, 1}),mat[13].insert({{1, 7}, 1}),mat[13].insert({{1, 8}, 1}),mat[13].insert({{1, 9}, 1}),mat[13].insert({{1, 10}, 1});
mat[13].insert({{2, 1}, 0}),mat[13].insert({{2, 2}, 1}),mat[13].insert({{2, 3}, 0}),mat[13].insert({{2, 4}, 0}),mat[13].insert({{2, 5}, 1}),mat[13].insert({{2, 6}, 0}),mat[13].insert({{2, 7}, 0}),mat[13].insert({{2, 8}, 1}),mat[13].insert({{2, 9}, 0}),mat[13].insert({{2, 10}, 0});
mat[13].insert({{3, 1}, 0}),mat[13].insert({{3, 2}, 1}),mat[13].insert({{3, 3}, 0}),mat[13].insert({{3, 4}, 1}),mat[13].insert({{3, 5}, 0}),mat[13].insert({{3, 6}, 1}),mat[13].insert({{3, 7}, 1}),mat[13].insert({{3, 8}, 1}),mat[13].insert({{3, 9}, 1}),mat[13].insert({{3, 10}, 1});
mat[13].insert({{4, 1}, 1}),mat[13].insert({{4, 2}, 0}),mat[13].insert({{4, 3}, 0}),mat[13].insert({{4, 4}, 0}),mat[13].insert({{4, 5}, 0}),mat[13].insert({{4, 6}, 0}),mat[13].insert({{4, 7}, 1}),mat[13].insert({{4, 8}, 0}),mat[13].insert({{4, 9}, 0}),mat[13].insert({{4, 10}, 0});
mat[13].insert({{5, 1}, 0}),mat[13].insert({{5, 2}, 1}),mat[13].insert({{5, 3}, 1}),mat[13].insert({{5, 4}, 0}),mat[13].insert({{5, 5}, 1}),mat[13].insert({{5, 6}, 0}),mat[13].insert({{5, 7}, 1}),mat[13].insert({{5, 8}, 0}),mat[13].insert({{5, 9}, 0}),mat[13].insert({{5, 10}, 0});
mat[13].insert({{6, 1}, 0}),mat[13].insert({{6, 2}, 0}),mat[13].insert({{6, 3}, 0}),mat[13].insert({{6, 4}, 1}),mat[13].insert({{6, 5}, 0}),mat[13].insert({{6, 6}, 0}),mat[13].insert({{6, 7}, 1}),mat[13].insert({{6, 8}, 0}),mat[13].insert({{6, 9}, 1}),mat[13].insert({{6, 10}, 1});
mat[13].insert({{7, 1}, 1}),mat[13].insert({{7, 2}, 1}),mat[13].insert({{7, 3}, 1}),mat[13].insert({{7, 4}, 1}),mat[13].insert({{7, 5}, 1}),mat[13].insert({{7, 6}, 0}),mat[13].insert({{7, 7}, 1}),mat[13].insert({{7, 8}, 0}),mat[13].insert({{7, 9}, 1}),mat[13].insert({{7, 10}, 0});
mat[13].insert({{8, 1}, 1}),mat[13].insert({{8, 2}, 1}),mat[13].insert({{8, 3}, 0}),mat[13].insert({{8, 4}, 0}),mat[13].insert({{8, 5}, 0}),mat[13].insert({{8, 6}, 1}),mat[13].insert({{8, 7}, 0}),mat[13].insert({{8, 8}, 0}),mat[13].insert({{8, 9}, 1}),mat[13].insert({{8, 10}, 0});
mat[13].insert({{9, 1}, 1}),mat[13].insert({{9, 2}, 1}),mat[13].insert({{9, 3}, 1}),mat[13].insert({{9, 4}, 1}),mat[13].insert({{9, 5}, 0}),mat[13].insert({{9, 6}, 0}),mat[13].insert({{9, 7}, 0}),mat[13].insert({{9, 8}, 1}),mat[13].insert({{9, 9}, 1}),mat[13].insert({{9, 10}, 0});
mat[13].insert({{10, 1}, 1}),mat[13].insert({{10, 2}, 1}),mat[13].insert({{10, 3}, 1}),mat[13].insert({{10, 4}, 0}),mat[13].insert({{10, 5}, 1}),mat[13].insert({{10, 6}, 1}),mat[13].insert({{10, 7}, 1}),mat[13].insert({{10, 8}, 0}),mat[13].insert({{10, 9}, 0}),mat[13].insert({{10, 10}, 1});
mat[14].insert({{1, 1}, 0}),mat[14].insert({{1, 2}, 1}),mat[14].insert({{1, 3}, 1}),mat[14].insert({{1, 4}, 0}),mat[14].insert({{1, 5}, 0}),mat[14].insert({{1, 6}, 0}),mat[14].insert({{1, 7}, 0}),mat[14].insert({{1, 8}, 0}),mat[14].insert({{1, 9}, 0}),mat[14].insert({{1, 10}, 0});
mat[14].insert({{2, 1}, 1}),mat[14].insert({{2, 2}, 0}),mat[14].insert({{2, 3}, 1}),mat[14].insert({{2, 4}, 0}),mat[14].insert({{2, 5}, 0}),mat[14].insert({{2, 6}, 0}),mat[14].insert({{2, 7}, 0}),mat[14].insert({{2, 8}, 0}),mat[14].insert({{2, 9}, 0}),mat[14].insert({{2, 10}, 0});
mat[14].insert({{3, 1}, 1}),mat[14].insert({{3, 2}, 1}),mat[14].insert({{3, 3}, 0}),mat[14].insert({{3, 4}, 0}),mat[14].insert({{3, 5}, 0}),mat[14].insert({{3, 6}, 0}),mat[14].insert({{3, 7}, 0}),mat[14].insert({{3, 8}, 0}),mat[14].insert({{3, 9}, 0}),mat[14].insert({{3, 10}, 0});
mat[14].insert({{4, 1}, 0}),mat[14].insert({{4, 2}, 0}),mat[14].insert({{4, 3}, 0}),mat[14].insert({{4, 4}, 0}),mat[14].insert({{4, 5}, 1}),mat[14].insert({{4, 6}, 1}),mat[14].insert({{4, 7}, 0}),mat[14].insert({{4, 8}, 1}),mat[14].insert({{4, 9}, 0}),mat[14].insert({{4, 10}, 0});
mat[14].insert({{5, 1}, 0}),mat[14].insert({{5, 2}, 0}),mat[14].insert({{5, 3}, 0}),mat[14].insert({{5, 4}, 1}),mat[14].insert({{5, 5}, 0}),mat[14].insert({{5, 6}, 1}),mat[14].insert({{5, 7}, 1}),mat[14].insert({{5, 8}, 1}),mat[14].insert({{5, 9}, 0}),mat[14].insert({{5, 10}, 1});
mat[14].insert({{6, 1}, 0}),mat[14].insert({{6, 2}, 0}),mat[14].insert({{6, 3}, 0}),mat[14].insert({{6, 4}, 1}),mat[14].insert({{6, 5}, 0}),mat[14].insert({{6, 6}, 1}),mat[14].insert({{6, 7}, 1}),mat[14].insert({{6, 8}, 1}),mat[14].insert({{6, 9}, 1}),mat[14].insert({{6, 10}, 0});
mat[14].insert({{7, 1}, 0}),mat[14].insert({{7, 2}, 0}),mat[14].insert({{7, 3}, 0}),mat[14].insert({{7, 4}, 1}),mat[14].insert({{7, 5}, 0}),mat[14].insert({{7, 6}, 1}),mat[14].insert({{7, 7}, 0}),mat[14].insert({{7, 8}, 0}),mat[14].insert({{7, 9}, 0}),mat[14].insert({{7, 10}, 0});
mat[14].insert({{8, 1}, 0}),mat[14].insert({{8, 2}, 0}),mat[14].insert({{8, 3}, 0}),mat[14].insert({{8, 4}, 1}),mat[14].insert({{8, 5}, 0}),mat[14].insert({{8, 6}, 0}),mat[14].insert({{8, 7}, 0}),mat[14].insert({{8, 8}, 1}),mat[14].insert({{8, 9}, 0}),mat[14].insert({{8, 10}, 0});
mat[14].insert({{9, 1}, 0}),mat[14].insert({{9, 2}, 0}),mat[14].insert({{9, 3}, 0}),mat[14].insert({{9, 4}, 1}),mat[14].insert({{9, 5}, 1}),mat[14].insert({{9, 6}, 0}),mat[14].insert({{9, 7}, 1}),mat[14].insert({{9, 8}, 0}),mat[14].insert({{9, 9}, 0}),mat[14].insert({{9, 10}, 0});
mat[14].insert({{10, 1}, 0}),mat[14].insert({{10, 2}, 0}),mat[14].insert({{10, 3}, 0}),mat[14].insert({{10, 4}, 1}),mat[14].insert({{10, 5}, 1}),mat[14].insert({{10, 6}, 0}),mat[14].insert({{10, 7}, 0}),mat[14].insert({{10, 8}, 0}),mat[14].insert({{10, 9}, 1}),mat[14].insert({{10, 10}, 0});
mat[15].insert({{1, 1}, 0}),mat[15].insert({{1, 2}, 0}),mat[15].insert({{1, 3}, 1}),mat[15].insert({{1, 4}, 1}),mat[15].insert({{1, 5}, 0}),mat[15].insert({{1, 6}, 0}),mat[15].insert({{1, 7}, 0}),mat[15].insert({{1, 8}, 0}),mat[15].insert({{1, 9}, 0}),mat[15].insert({{1, 10}, 0});
mat[15].insert({{2, 1}, 0}),mat[15].insert({{2, 2}, 1}),mat[15].insert({{2, 3}, 0}),mat[15].insert({{2, 4}, 1}),mat[15].insert({{2, 5}, 0}),mat[15].insert({{2, 6}, 0}),mat[15].insert({{2, 7}, 0}),mat[15].insert({{2, 8}, 0}),mat[15].insert({{2, 9}, 0}),mat[15].insert({{2, 10}, 0});
mat[15].insert({{3, 1}, 1}),mat[15].insert({{3, 2}, 0}),mat[15].insert({{3, 3}, 0}),mat[15].insert({{3, 4}, 1}),mat[15].insert({{3, 5}, 0}),mat[15].insert({{3, 6}, 0}),mat[15].insert({{3, 7}, 0}),mat[15].insert({{3, 8}, 0}),mat[15].insert({{3, 9}, 0}),mat[15].insert({{3, 10}, 0});
mat[15].insert({{4, 1}, 1}),mat[15].insert({{4, 2}, 1}),mat[15].insert({{4, 3}, 1}),mat[15].insert({{4, 4}, 0}),mat[15].insert({{4, 5}, 0}),mat[15].insert({{4, 6}, 0}),mat[15].insert({{4, 7}, 0}),mat[15].insert({{4, 8}, 0}),mat[15].insert({{4, 9}, 0}),mat[15].insert({{4, 10}, 0});
mat[15].insert({{5, 1}, 0}),mat[15].insert({{5, 2}, 0}),mat[15].insert({{5, 3}, 0}),mat[15].insert({{5, 4}, 0}),mat[15].insert({{5, 5}, 0}),mat[15].insert({{5, 6}, 1}),mat[15].insert({{5, 7}, 0}),mat[15].insert({{5, 8}, 1}),mat[15].insert({{5, 9}, 1}),mat[15].insert({{5, 10}, 0});
mat[15].insert({{6, 1}, 0}),mat[15].insert({{6, 2}, 0}),mat[15].insert({{6, 3}, 0}),mat[15].insert({{6, 4}, 0}),mat[15].insert({{6, 5}, 1}),mat[15].insert({{6, 6}, 0}),mat[15].insert({{6, 7}, 1}),mat[15].insert({{6, 8}, 1}),mat[15].insert({{6, 9}, 1}),mat[15].insert({{6, 10}, 0});
mat[15].insert({{7, 1}, 0}),mat[15].insert({{7, 2}, 0}),mat[15].insert({{7, 3}, 0}),mat[15].insert({{7, 4}, 0}),mat[15].insert({{7, 5}, 0}),mat[15].insert({{7, 6}, 1}),mat[15].insert({{7, 7}, 1}),mat[15].insert({{7, 8}, 1}),mat[15].insert({{7, 9}, 0}),mat[15].insert({{7, 10}, 0});
mat[15].insert({{8, 1}, 0}),mat[15].insert({{8, 2}, 0}),mat[15].insert({{8, 3}, 0}),mat[15].insert({{8, 4}, 0}),mat[15].insert({{8, 5}, 1}),mat[15].insert({{8, 6}, 1}),mat[15].insert({{8, 7}, 0}),mat[15].insert({{8, 8}, 0}),mat[15].insert({{8, 9}, 0}),mat[15].insert({{8, 10}, 0});
mat[15].insert({{9, 1}, 0}),mat[15].insert({{9, 2}, 0}),mat[15].insert({{9, 3}, 0}),mat[15].insert({{9, 4}, 0}),mat[15].insert({{9, 5}, 0}),mat[15].insert({{9, 6}, 1}),mat[15].insert({{9, 7}, 1}),mat[15].insert({{9, 8}, 0}),mat[15].insert({{9, 9}, 1}),mat[15].insert({{9, 10}, 0});
mat[15].insert({{10, 1}, 0}),mat[15].insert({{10, 2}, 0}),mat[15].insert({{10, 3}, 0}),mat[15].insert({{10, 4}, 0}),mat[15].insert({{10, 5}, 0}),mat[15].insert({{10, 6}, 0}),mat[15].insert({{10, 7}, 0}),mat[15].insert({{10, 8}, 0}),mat[15].insert({{10, 9}, 0}),mat[15].insert({{10, 10}, 1});
}

void does(int sx,int sy,int k) {
	//cout<<"does sx="<<sx<<" sy="<<sy<<" k="<<k<<endl;
	for (int i=1;i<=10;i++) {
		for (int j=1;j<=10;j++) {
			ans[sx][sy][i][j]=mat[k][{i,j}];
		}
	}
}

void dfs1(int x,int sum,int pre) {
	if (sum>lim) {
		return ;
	}
	if (b[sum]) return ;
//	cout<<"sum="<<sum<<endl;
	b[sum]=1;
	if (x==20) {
		return ;
	}
	for (int i=pre;i<=can;i++) {
		dfs1(x+1,sum*i,i);
	}
	return ;	
} 

void dfs2(int x,int now) {
	if (tf) return ;
	if (x<0) return ;
	if (x==0) {
		for (int i=1;i<=now;i++) op[i]=p[i];
		for (int i=now+1;i<=19;i++) op[i]=0;
		tf=1;
		return ;
	}	
	if (now==20-1) {
		return ;
	}	
	int start;
	if (x>lim) start=cnt;
			else start=lower_bound(num+1,num+cnt+1,x)-num;
	for (int i=start;i>=1;i--) {
		p[now+1]=i;
		dfs2(x-num[i],now+1);		
		p[now+1]=0;
	}
}

void divide(int x) {
	int t=0;
	for (int i=15;i>=2;i--) {
		while (x%i==0) p[++t]=i,x/=i;
	}
	for (int i=t+1;i<=19;i++) p[i]=1;
}
signed main(){
	

	freopen("sc.out","w",stdout);
	
	
	// ios::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);
	
	Init();
//	cout<<"init!"<<endl;
	cin>>n;  //separate to 19 parts
	can=15; tf=0;
	dfs1(0,1,2);
	cnt=1;
	num[1]=1;
	for (int i=1;i<=lim;i++) {
		if (b[i]) num[++cnt]=i;
	}
	dfs2(n,0);
		
	//	cout<<"cnt="<<cnt<<endl;
	//	for (int i=1;i<=19;i++) cout<<op[i]<<" "; cout<<endl;
		int s=0;
		for (int i=1;i<=19;i++) s+=num[op[i]];
	//	cout<<"s="<<s<<endl;
		for (int i=1;i<=19;i++) {
	//		cout<<" i="<<i<<endl;
			int sx=1,sy=i,tot=0;
			for (int j=1;j<=19;j++) p[j]=0;
			if (num[op[i]]==0) continue;
			divide(num[op[i]]);
			while (sx<=20&&sy<=20) {
				does(sx,sy,p[++tot]);
				sx++,sy++;
			}
			if (sx==21&&sy==21) continue;
			sx--,sy--;
			sx++; sy=1;
			while (sx<=20&&sy<=20) {
				does(sx,sy,p[++tot]);
				sx++,sy++;
			}
		}
	cout<<200<<endl;
	for (int sx=1;sx<=20;sx++) {
		for (int sy=1;sy<=20;sy++) {
			for (int i=1;i<=10;i++) {
				for (int j=1;j<=10;j++) {
				//	cout<<"sx="<<sx<<" sy="<<sy<<" i="<<i<<" j="<<j<<" ans="<<ans[sx][sy][i][j]<<endl;
					wr[10*(sx-1)+i][10*(sy-1)+j]=ans[sx][sy][i][j];
                    int cx = 10*(sx-1)+i, cy = 10*(sy-1)+j;
                    if(cx == cy)printf("> cx == cy = %d, cur = %d\n", cx, wr[10*(sx-1)+i][10*(sy-1)+j]);

				}
			}
		}
	}
	for (int i=1;i<=200;i++) {
		for (int j=1;j<=200;j++) {
			cout<<wr[i][j]<<" ";
		}
		cout<<endl;
	}


	return 0;
}


/*

//�� [i,j] ���ʾ�� [k*(i-1) ~ k*i-1] [k*(j-1) ~ k*j-1]

ans[i][j]:



1000000000

998244353

398244353  

432532

*/

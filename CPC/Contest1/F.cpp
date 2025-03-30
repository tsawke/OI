#include<bits/stdc++.h>
using namespace std;
int n;
const int N=3e5+5;
int a[N];
bool vis[N];
priority_queue<int>q[2];
signed main() {
    int T;
    cin >> T;
    while(T--) {
        scanf("%d",&n);
        for(int i=1;i<=n*2-1;++i) scanf("%d",&a[i]),vis[a[i]]=1;
        
    }
    return 0;
}
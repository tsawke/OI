#pragma GCC optimize("Ofast")


#include <bits/stdc++.h>
using namespace std;


template<typename T = int>
inline T read(void);


const int N = 2e6 + 7;
// namespace ST {
// 	int f[N][22], lg2[N];
// 	void init(int n, int *a) {
// 		lg2[0] = -1;
// 		for(int i = 1; i <= n; i++) lg2[i] = lg2[i / 2] + 1, f[i][0] = a[i];
// 		for(int i = 1; i <= 21; i++) for(int l = 1; l + (1 << i) - 1 <= n; l++) {
// 			f[l][i] = max(f[l][i - 1], f[l + (1 << (i - 1))][i - 1]);
// 		}
// 	}
// 	int query(int l, int r) {
// 		int len = lg2[r - l + 1];
// 		return max(f[l][len], f[r - (1 << len) + 1][len]);
// 	}
// }
namespace bit {
	int t[N], n;
	void init(int nn) {
		n = nn, memset(t, 0, sizeof(int) * (n + 1));
	}
	void add(int x, int v) {
		while(x <= n) {
			t[x] += v;
			x += x & -x;
		}
	}
	int sum(int x) {
		int s = 0;
		while(x) {
			s += t[x];
			x -= x & -x;
		}
		return s;
	}
}
int n, a[N], stk[N], reply[N * 4], lst[N], pre[N];
std::vector<std::tuple<int, int, int>> qry[N];
void heavyrain() {
	n = read();
	int ans = 0, id = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
        pre[i] = max(pre[i - 1], a[i]);
	}
    lst[n + 1] = 0;
    for(int i = n; i; i--) {
        lst[i] = max(lst[i + 1], a[i]);
    }
	for(int i = 1; i <= n; i++) {
		if(lst[i] == a[i]) ans = max(ans, n - i + 1);
		else {
			int l = i + 1, r = n;
			while(l < r) {
				int mid = (l + r + 1) >> 1;
				if(lst[mid] > a[i]) l = mid;
				else r = mid - 1;
			}
            // cout << "(" << i << ", " << l << ")\n";
			qry[i].emplace_back(a[i], ++id, -1);
			qry[l].emplace_back(a[i], id, 1);
		}
		if(pre[i] == a[i]) ans = max(ans, i);
		else {
			int l = 1, r = i - 1;
			while(l < r) {
				int mid = (l + r) >> 1;
				if(pre[mid] > a[i]) r = mid;
				else l = mid + 1;
			}
            // cout << "(" << l << ", " << i << ")\n";
			qry[l].emplace_back(a[i], ++id, -1);
			qry[i].emplace_back(a[i], id, 1);
		}
	}
	bit::init(n);
	for(int i = 1; i <= n; i++) {
		bit::add(a[i], 1);
		for(auto [x, id, det] : qry[i]) {
			reply[id] += det * bit::sum(x - 1);
		}
	}
	for(int i = 1; i <= id; i++) {
		ans = std::max(ans, reply[i] + 2);
        // cout << "  " << reply[i] << "\n";
	}
	cout << ans << "\n";
}




signed main(){
    int T = read();
	while (T--) heavyrain();
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
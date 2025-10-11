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



template<typename T = int>
inline T read(void);

int l, r;
int tot;
int cur, id[500];
vector<pair<int, int>> e[500];
int getid(int de){
	while (cur <= de){
		tot++;
		if (cur > 0){
			e[tot].emplace_back(id[cur - 1], 0);
			e[tot].emplace_back(id[cur - 1], 1);
		}
		id[cur++] = tot;
	}
	return id[de];
}
int dfs(int de, int l, int r, int s, int t){
	if (s <= l && r <= t)
		return getid(de);
	int p = ++tot, mid = (l + r) >> 1;
	if (s < mid) e[p].emplace_back(dfs(de - 1, l, mid, s, t), 0);
	if (t > mid) e[p].emplace_back(dfs(de - 1, mid, r, s, t), 1);
	return p;
}
int main(){
	int L = read(), R = read();

    auto dfs = 

	cin >> l >> r;
	tot = 1;
	for (int i = 0; i <= 20; i++){
		int l2 = (1 << i), r2 = (1 << (i + 1));
		l2 = max(l2, l);
		r2 = min(r2, r + 1);
		if (l2 < r2) e[1].emplace_back(dfs(i, (1 << i), 1 << (i + 1), l2, r2), 1);
	}
	cout << tot << endl;
	for (int i = 1; i <= tot; i++){
		cout << e[i].size() << ' ';
		for (auto [v, x] : e[i])
			cout << v << ' ' << x << ' ';
		cout << endl;
	}
	return 0;
}

int main(){
        

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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
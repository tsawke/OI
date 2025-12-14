#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Person {
    int l, r, id;
};

struct Cmp {
    bool operator()(const Person &x, const Person &y) const {
        if (x.r == y.r) return x.l > y.l;
        return x.r > y.r;
    }
};

void solve() {
    int n;
    long long k;
    cin >> n >> k;

    vector<Person> g(n);
    long long totalCost = 0;

    for (int i = 0; i < n; i++) {
        cin >> g[i].l >> g[i].r;
        totalCost += (g[i].r - g[i].l);
        g[i].id = i + 1;
    }

    sort(g.begin(), g.end(), [](const Person &x, const Person &y) {
        if (x.l == y.l) return x.r > y.r;
        return x.l < y.l;
    });

    priority_queue<Person, vector<Person>, Cmp> heap;
    vector<int> ans;
    vector<Person> covered;
    ans.reserve(n);

    long long pos = k;
    int ptr = 0;

    while ((int)ans.size() + (int)covered.size() < n) {
        while (ptr < n && g[ptr].l <= pos) {
            heap.push(g[ptr]);
            ptr++;
        }

        if (heap.empty()) {
            if (ptr < n) {
                totalCost += (g[ptr].l - pos);
                pos = g[ptr].l;
            }
            continue;
        }

        vector<Person> lap;
        while (!heap.empty() && heap.top().r <= pos) {
            lap.push_back(heap.top());
            heap.pop();
        }
        
        if (heap.empty()) {
            for (auto &p : lap) covered.push_back(p);
            continue;
        }

        Person cur = heap.top();
        heap.pop();

        vector<Person> willLap;
        while (!heap.empty() && heap.top().r <= cur.r) {
            willLap.push_back(heap.top());
            heap.pop();
        }

        sort(lap.begin(), lap.end(), [](const Person &x, const Person &y) {
            return x.r < y.r;
        });
        for (auto &p : lap) ans.push_back(p.id);

        sort(willLap.begin(), willLap.end(), [](const Person &x, const Person &y) {
            return x.r < y.r;
        });
        for (auto &p : willLap) ans.push_back(p.id);

        ans.push_back(cur.id);
        pos = cur.r;
    }

    sort(covered.begin(), covered.end(), [](const Person &x, const Person &y) {
        return x.r > y.r;
    });
    for (auto &p : covered) {
        ans.push_back(p.id);
    }

    cout << totalCost << "\n";
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
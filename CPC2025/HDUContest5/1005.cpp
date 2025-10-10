#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct TupleHash
{
    size_t operator()(const tuple<int, int, int, int> &t) const noexcept
    {
        auto [a, b, c, d] = t;
        // splitmix64 mixer
        auto splitmix64 = [](uint64_t x)
        {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        };
        uint64_t h1 = splitmix64((uint64_t)a + 0x9e3779b97f4a7c15);
        uint64_t h2 = splitmix64((uint64_t)b + 0x9e3779b97f4a7c15);
        uint64_t h3 = splitmix64((uint64_t)c + 0x9e3779b97f4a7c15);
        uint64_t h4 = splitmix64((uint64_t)d + 0x9e3779b97f4a7c15);
        return h1 ^ (h2 << 1) ^ (h3 << 2) ^ (h4 << 3);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int k1, k2, k3, k4;
        cin >> k1;
        vector<ll> val1(k1 + 1);
        for (int i = 1; i <= k1; i++)
            cin >> val1[i];
        cin >> k2;
        vector<ll> val2(k2 + 1);
        for (int i = 1; i <= k2; i++)
            cin >> val2[i];
        cin >> k3;
        vector<ll> val3(k3 + 1);
        for (int i = 1; i <= k3; i++)
            cin >> val3[i];
        cin >> k4;
        vector<ll> val4(k4 + 1);
        for (int i = 1; i <= k4; i++)
            cin >> val4[i];

        sort(val1.begin() + 1, val1.end(), greater<ll>());
        sort(val2.begin() + 1, val2.end(), greater<ll>());
        sort(val3.begin() + 1, val3.end(), greater<ll>());
        sort(val4.begin() + 1, val4.end(), greater<ll>());

        vector<ll> pre1(k1 + 1, 0), pre2(k2 + 1, 0), pre3(k3 + 1, 0), pre4(k4 + 1, 0);
        for (int i = 1; i <= k1; i++)
            pre1[i] = pre1[i - 1] + val1[i];
        for (int i = 1; i <= k2; i++)
            pre2[i] = pre2[i - 1] + val2[i];
        for (int i = 1; i <= k3; i++)
            pre3[i] = pre3[i - 1] + val3[i];
        for (int i = 1; i <= k4; i++)
            pre4[i] = pre4[i - 1] + val4[i];

        vector<int> boxes;
        boxes.reserve(a + b + c + d);
        for (int i = 0; i < a; i++)
            boxes.push_back(1);
        for (int i = 0; i < b; i++)
            boxes.push_back(2);
        for (int i = 0; i < c; i++)
            boxes.push_back(3);
        for (int i = 0; i < d; i++)
            boxes.push_back(4);

        unordered_map<tuple<int, int, int, int>, ll, TupleHash> dp_curr, dp_next;
        dp_curr.reserve(1024);
        dp_next.reserve(1024);
        dp_curr.clear();
        dp_curr[{0, 0, 0, 0}] = 0;

        for (int box : boxes)
        {
            dp_next.clear();
            dp_next.reserve(dp_curr.size() * 2);
            for (auto &[state, total_val] : dp_curr)
            {
                auto [u1, u2, u3, u4] = state;
                auto &carry = dp_next[state];
                if (carry < total_val)
                    carry = total_val;

                if (box == 1)
                {
                    if (u1 + 1 <= k1)
                    {
                        tuple<int, int, int, int> ns = {u1 + 1, u2, u3, u4};
                        ll delta = pre1[u1 + 1] - pre1[u1];
                        ll nv = total_val + delta;
                        auto &e = dp_next[ns];
                        if (e < nv)
                            e = nv;
                    }
                }
                else if (box == 2)
                {
                    if (u2 + 1 <= k2)
                    {
                        tuple<int, int, int, int> ns = {u1, u2 + 1, u3, u4};
                        ll delta = pre2[u2 + 1] - pre2[u2];
                        ll nv = total_val + delta;
                        auto &e = dp_next[ns];
                        if (e < nv)
                            e = nv;
                    }
                    if (u1 + 2 <= k1)
                    {
                        tuple<int, int, int, int> ns = {u1 + 2, u2, u3, u4};
                        ll delta = pre1[u1 + 2] - pre1[u1];
                        ll nv = total_val + delta;
                        auto &e = dp_next[ns];
                        if (e < nv)
                            e = nv;
                    }
                }
                else if (box == 3)
                {
                    if (u3 + 1 <= k3)
                    {
                        tuple<int, int, int, int> ns = {u1, u2, u3 + 1, u4};
                        ll delta = pre3[u3 + 1] - pre3[u3];
                        ll nv = total_val + delta;
                        auto &e = dp_next[ns];
                        if (e < nv)
                            e = nv;
                    }
                    if (u2 + 1 <= k2 && u1 + 1 <= k1)
                    {
                        tuple<int, int, int, int> ns = {u1 + 1, u2 + 1, u3, u4};
                        ll delta = (pre2[u2 + 1] - pre2[u2]) + (pre1[u1 + 1] - pre1[u1]);
                        ll nv = total_val + delta;
                        auto &e = dp_next[ns];
                        if (e < nv)
                            e = nv;
                    }
                    if (u1 + 3 <= k1)
                    {
                        tuple<int, int, int, int> ns = {u1 + 3, u2, u3, u4};
                        ll delta = pre1[u1 + 3] - pre1[u1];
                        ll nv = total_val + delta;
                        auto &e = dp_next[ns];
                        if (e < nv)
                            e = nv;
                    }
                }
                else if (box == 4)
                {
                    if (u4 + 1 <= k4)
                    {
                        tuple<int, int, int, int> ns = {u1, u2, u3, u4 + 1};
                        ll delta = pre4[u4 + 1] - pre4[u4];
                        ll nv = total_val + delta;
                        auto &e = dp_next[ns];
                        if (e < nv)
                            e = nv;
                    }
                    if (u2 + 2 <= k2)
                    {
                        tuple<int, int, int, int> ns = {u1, u2 + 2, u3, u4};
                        ll delta = pre2[u2 + 2] - pre2[u2];
                        ll nv = total_val + delta;
                        auto &e = dp_next[ns];
                        if (e < nv)
                            e = nv;
                    }
                    if (u2 + 1 <= k2 && u1 + 2 <= k1)
                    {
                        tuple<int, int, int, int> ns = {u1 + 2, u2 + 1, u3, u4};
                        ll delta = (pre2[u2 + 1] - pre2[u2]) + (pre1[u1 + 2] - pre1[u1]);
                        ll nv = total_val + delta;
                        auto &e = dp_next[ns];
                        if (e < nv)
                            e = nv;
                    }
                    if (u1 + 4 <= k1)
                    {
                        tuple<int, int, int, int> ns = {u1 + 4, u2, u3, u4};
                        ll delta = pre1[u1 + 4] - pre1[u1];
                        ll nv = total_val + delta;
                        auto &e = dp_next[ns];
                        if (e < nv)
                            e = nv;
                    }
                }
            }
            dp_curr.swap(dp_next);
        }

        ll ans = 0;
        for (auto &[state, v] : dp_curr)
        {
            ans = max(ans, v);
        }
        cout << ans << "\n";
    }

    return 0;
}

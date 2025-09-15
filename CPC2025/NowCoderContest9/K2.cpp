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

struct Rope{
    int x, y;
    int l2;
};

vector<Rope> rops;

int N;
const double INF = 1e100;
const int EXTRA_RANDOM_SEEDS = 8;

int main(){
    N = read();
    rops.reserve(N);

    vector<pair<double,double>> seeds;
    seeds.push_back({0.0, 0.0});

    long long totx = 0, toty = 0;
    for(int i = 0; i < N; ++i){
        int x = read(), y = read(), l2 = read();
        rops.push_back(Rope{x, y, l2});
        totx += x; toty += y;
    }
    seeds.push_back({double(totx)/max(1,N), double(toty)/max(1,N)});
    seeds.push_back({-128.0, -128.0});
    seeds.push_back({-128.0,  128.0});
    seeds.push_back({ 128.0, -128.0});
    seeds.push_back({ 128.0,  128.0});
    for(int i = 0; i < EXTRA_RANDOM_SEEDS; ++i)
        seeds.push_back({rndd(-128,128), rndd(-128,128)});

    auto CalZ2_full = [&](double x, double y, int* idx = nullptr)->double{
        double best = INF;
        int best_id = -1;
        for(int i = 0; i < (int)rops.size(); ++i){
            double dx = x - rops[i].x;
            double dy = y - rops[i].y;
            double v = (double)rops[i].l2 - (dx*dx + dy*dy);
            if(v < best){
                best = v; best_id = i;
            }
        }
        if(idx) *idx = best_id;
        return best;
    };

    auto CalZ2_with_early_reject = [&](double x, double y, double reject_threshold, bool &early_rejected)->double{
        double best = INF;
        early_rejected = false;
        for(int i = 0; i < (int)rops.size(); ++i){
            double dx = x - rops[i].x;
            double dy = y - rops[i].y;
            double v = (double)rops[i].l2 - (dx*dx + dy*dy);
            if(v < best){
                best = v;
                if(best <= reject_threshold){
                    early_rejected = true;
                    return best;
                }
            }
        }
        return best;
    };

    auto MaxF_and_grad = [&](double x, double y, double &gx, double &gy)->double{
        double mx = -INF;
        for(int i = 0; i < (int)rops.size(); ++i){
            double dx = x - rops[i].x;
            double dy = y - rops[i].y;
            double t = dx*dx + dy*dy - (double)rops[i].l2;
            if(t > mx) mx = t;
        }
        double eps = 1e-12 + 1e-9 * (fabs(mx) + 1.0);
        gx = 0.0; gy = 0.0;
        int cnt = 0;
        for(int i = 0; i < (int)rops.size(); ++i){
            double dx = x - rops[i].x;
            double dy = y - rops[i].y;
            double t = dx*dx + dy*dy - (double)rops[i].l2;
            if(mx - t <= eps){
                gx += 2.0 * dx;
                gy += 2.0 * dy;
                ++cnt;
            }
        }
        if(cnt) { gx /= cnt; gy /= cnt; }
        return mx;
    };

    double bestX = 0.0, bestY = 0.0;
    double bestZ2 = -INF;

    auto SimulateAnneal = [&]()->void{
        uniform_real_distribution<double> U01(0.0,1.0);
        auto rnd01 = [&]()->double{return U01(rnd);};
        auto rndStep = [&](double T)->double{ return (rnd01()*2.0 - 1.0) * T; };

        const double T0   = 64.0;
        const double TMIN = 1e-5;
        const double COOL = 0.92;
        const int    TRIES_PER_T = 14;

        for(auto [sx, sy] : seeds){
            double x = sx, y = sy;
            double cur = CalZ2_full(x, y, nullptr);
            double T = T0;

            while(T > TMIN){
                for(int tt = 0; tt < TRIES_PER_T; ++tt){
                    double tx = x + rndStep(T);
                    double ty = y + rndStep(T);
                    double u = rnd01();
                    if(u <= 1e-300) u = 1e-300;
                    double accept_threshold = cur + T * log(u);
                    bool early_rej = false;
                    double nxt = CalZ2_with_early_reject(tx, ty, accept_threshold, early_rej);
                    if(!early_rej){
                        if(nxt >= cur || nxt > accept_threshold){
                            x = tx; y = ty; cur = nxt;
                        }
                    }
                }
                T *= COOL;
            }

            double step = 64.0;
            for(int it = 0; it < 4000; ++it){
                double gx, gy;
                MaxF_and_grad(x, y, gx, gy);
                double g = hypot(gx, gy);
                if(g < 1e-14) break;
                x -= gx / g * step;
                y -= gy / g * step;
                step *= 0.997;
                if(step < 1e-9) break;
            }

            cur = CalZ2_full(x, y, nullptr);
            if(cur > bestZ2){
                bestZ2 = cur; bestX = x; bestY = y;
            }
        }
    };

    SimulateAnneal();

    double bestZ = -sqrt(bestZ2 < 0.0 ? 0.0 : bestZ2);
    printf("%.9lf %.9lf %.9lf\n", bestX, bestY, bestZ);
    return 0;
}

template<typename T>
inline T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while(c != '-' && !isdigit(c)) c = getchar();
    if(c == '-') flag = -1, c = getchar();
    while(isdigit(c)){
        ret = ret * 10 + int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}

#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("no-stack-protector")

#include <bits/stdc++.h>
using namespace std;

// Constraints: n<=6, m<=5
// Use long double for precision
using ld = long double;
const ld EPS = 1e-12;
int T, n, m;
ld Xs, Ys;
ld acoef[6];      // acoef[1..m]
ld aa[6];         // reversed coefficients for poly eval
int per[7];

struct B { ld h, w; } bb[7], b[7];

// Evaluate P(x) = a_m x^m + ... + a_1 x
inline ld polyEval(ld x) {
    ld res = 0;
    for (int i = 0; i <= m; ++i) {
        res = res * x + aa[i];
    }
    return res;
}

// Adaptive Simpson for arc length sqrt(1 + (P')^2)
inline ld f_arc(ld x) {
    // derivative from aa: aa[0] x^m + ... + aa[m]
    // P'(x) = sum_{i=0..m-1} aa[i] * (m-i) * x^{m-i-1}
    ld d = 0;
    for (int i = 0; i < m; ++i) {
        d = d * x + aa[i] * (m - i);
    }
    return sqrtl(1 + d*d);
}

inline ld simpson_seg(ld l, ld r) {
    ld m = 0.5L*(l + r);
    return (f_arc(l) + 4*f_arc(m) + f_arc(r)) * (r - l) / 6;
}

ld adaptiveSimpson_rec(ld l, ld r, ld eps, ld A) {
    ld m = 0.5L*(l + r);
    ld L = simpson_seg(l, m);
    ld R = simpson_seg(m, r);
    if (fabsl(L + R - A) < 15*eps) return L + R + (L+R - A)/15;
    return adaptiveSimpson_rec(l, m, eps/2, L)
         + adaptiveSimpson_rec(m, r, eps/2, R);
}

inline ld arcLen(ld l, ld r) {
    if (fabsl(r - l) < EPS) return 0;
    ld A = simpson_seg(l, r);
    return adaptiveSimpson_rec(l, r, 1e-9L, A);
}

inline ld distE(ld x1, ld y1, ld x2, ld y2) {
    ld dx = x2 - x1;
    ld dy = y2 - y1;
    return sqrtl(dx*dx + dy*dy);
}

// find smallest t>sx s.t. P(t) >= y0 + k*(t-sx)
inline ld findLOS(ld sx, ld y0, ld k) {
    auto f = [&](ld t){ return polyEval(t) - (y0 + k*(t - sx)); };
    ld lo = sx, hi = sx + 1;
    while (f(hi) < 0) hi = sx + (hi - sx)*2;
    for (int it=0; it<60; ++it) {
        ld mid = 0.5L*(lo + hi);
        if (f(mid) < 0) lo = mid;
        else hi = mid;
    }
    return hi;
}

// binary search for horizontal distance constraint
double distBS(ld sx, ld sy, ld d) {
    ld lo = sx, hi = sx + d;
    for (int i=0;i<60;++i) {
        ld mid = 0.5L*(lo + hi);
        if (distE(sx, sy, mid, polyEval(mid)) < d) lo = mid;
        else hi = mid;
    }
    return lo;
}

void printSci(ld x) {
    if (fabsl(x) < 1e-18L) { printf("0.0000e+0\n"); return; }

    static char s[25];
    sprintf(s,"%.4Le",x);
    for(int i:{0,1,2,3,4,5,6,7}) printf("%c",s[i]);
    printf("%c",s[strlen(s)-1]);
    printf("\n");
}

int main(){
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %Lf %Lf", &n, &m, &Xs, &Ys);
        for (int i=1;i<=m;i++) scanf("%Lf", &acoef[i]);
        // build aa
        aa[0] = acoef[m];
        for (int i=1;i<=m;i++) aa[i] = acoef[m-i];
        aa[m] = 0; // constant term a0=0
        for (int i=1;i<=n;i++) {
            scanf("%Lf %Lf", &bb[i].h, &bb[i].w);
            per[i]=i;
        }
        ld best = 1e100L;
        do {
            for (int i=1;i<=n;i++) b[i]=bb[per[i]];
            ld nowx = 0;
            ld lastX = 0;
            vector<ld> cum(n+1);
            cum[1] = 0;
            bool bad = false;
            for (int i=1;i<n;i++) {
                // horizontal constraint
                ld t1 = distBS(nowx, polyEval(nowx), max(b[i].h, b[i+1].h));
                // LOS constraint
                ld y0 = polyEval(nowx) + b[i].h;
                ld k = (Ys - y0)/(Xs - nowx);
                ld t2 = findLOS(nowx, y0, k);
                nowx = max(t1, t2);
                if (isnan(nowx)) { bad=true; break; }
                ld delta = arcLen(lastX, nowx);
                cum[i+1] = cum[i] + delta;
                lastX = nowx;
            }
            if (bad) continue;
            ld total = 0;
            for (int i=1;i<=n;i++) total += b[i].w * cum[i];
            best = min(best, total);
        } while (next_permutation(per+1, per+n+1));
        printSci(best); 
    }
    return 0;
}

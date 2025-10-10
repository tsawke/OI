from bisect import bisect_right

def PruneFrontier(vec):
    if not vec:
        return vec
    vec.sort(key=lambda x: (x[0], -x[1]))
    res, best = [], -1
    for c, v in vec:
        if v > best:
            best = v
            res.append((c, v))
    return res

def Solve(N, M, A, B, val):
    p = [0] * (M + 1)
    p[1] = 1
    for i in range(2, M + 1): ##
        p[i] = p[i - 1] * 3
    sump = [0] * (M + 1)
    for i in range(1, M + 1):
        sump[i] = sump[i - 1] + p[i]

    aLimit = int(A)
    if m == 1:
        return sum(val[1][1:])
    if aLimit >= n * (p[m] - 1):
        return sum(val[m][1:])

    bCap = min(B, 2 * (m - 1))

    def CostSb(s, b):
        if s == 1:
            return 0 if b == 0 else None
        if b > 2 * (s - 1):
            return None
        base = p[s] - 1
        q, r = divmod(b, 2)
        if q:
            base -= 2 * (sump[s - 1] - sump[s - 1 - q])
        if r:
            idx = s - q - 1
            if idx < 1:
                return None
            base -= p[idx]
        return base

    dp = [[] for _ in range(B + 1)]
    dp[0] = [(0, 0)]

    for j in range(1, n + 1):
        opt = [[] for _ in range(bCap + 1)]
        for bu in range(bCap + 1):
            sMin = bu // 2 + 1
            if sMin <= m:
                cand = [(c, val[s][j]) for s in range(sMin, m + 1)
                        if (c := CostSb(s, bu)) is not None and c <= aLimit]
                if cand:
                    opt[bu] = PruneFrontier(cand)

        ndp = [[] for _ in range(B + 1)]
        for bPrev in range(B + 1):
            L = dp[bPrev]
            if not L:
                continue
            lCosts = [lc for lc, _ in L]
            minL = lCosts[0]
            for bu in range(min(B - bPrev, bCap) + 1):
                R = opt[bu]
                if not R:
                    continue
                for rc, rv in R:
                    if minL + rc > aLimit:
                        break
                    idx = bisect_right(lCosts, aLimit - rc)
                    for k in range(idx):
                        lc, lv = L[k]
                        ndp[bPrev + bu].append((lc + rc, lv + rv))
        for b in range(B + 1):
            if ndp[b]:
                ndp[b] = PruneFrontier(ndp[b])
        dp = ndp

    ans = 0
    for b in range(B + 1):
        for _, v in dp[b]:
            if v > ans:
                ans = v
    return ans

def main():
    T = int(input().strip())
    out = []
    for _ in range(T):
        N, M, A, B = input().split()
        N, M, B = int(N), int(M), int(B);
        val = [[0] * (N + 1) for _ in range(M + 1)]
        for i in range(1, M + 1):
            row = list(map(int, input().split()))
            for j in range(1, N + 1):
                val[i][j] = row[j - 1]
        out.append(str(Solve(N, M, A, B, val)))
    print("\n".join(out))

if __name__ == "__main__":
    main()
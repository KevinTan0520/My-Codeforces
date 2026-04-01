#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128_t;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        i64 h, d;
        cin >> h >> d;
        auto feasible = [&](i64 R)->bool {
            i64 s = min(d, R + 1);
            i64 q = d / s;
            i64 r = d % s;
            i128 sumsq = (i128)r * (i128)(q + 1) * (i128)(q + 1) + (i128)(s - r) * (i128)q * (i128)q;
            i128 S = (sumsq + (i128)d) / 2;
            i128 avail = (i128)h + (i128)R - 1;
            return S <= avail;
        };
        i64 lo = 0, hi = d, best = d;
        while (lo <= hi) {
            i64 mid = (lo + hi) >> 1;
            if (feasible(mid)) {
                best = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        cout << (d + best) << endl;
    }
    return 0;
}

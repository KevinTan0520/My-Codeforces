#include <bits/stdc++.h>
using namespace std;
bool chk(long long x, long long b, int p, long long val) {
    if (x == 0) return true;
    long long base = 1;
    for (int i = 0; i < p; i++) {
        if (base > val / b + 1) {
            return x < b;
        }
        base *= b;
    }
    while (x > 0) {
        if (x % base >= b) return false;
        x /= base;
    }
    return true;
}
long long calc(long long b, int p, long long lim) {
    long long s = 0, pwr = 1;
    for (int i = 0; i < p; i++) {
        s += pwr;
        if (s > lim) return lim + 1;
        if (i < p - 1) {
            if (pwr > lim / b + 1) pwr = lim + 1;
            else pwr *= b;
        }
    }
    return s;
}
void solve() {
    long long n;
    cin >> n;
    vector<long long> divs;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i * i != n) divs.push_back(n / i);
        }
    }
    long long ans = 0;
    for (int i = 0; i < divs.size(); i++) {
        long long d = divs[i];
        if (d < 3) continue;
        // if (n / d < d - 1) ans++;
        for (int p = 2; p <= 40; p++) {
            if (p < 62 && (1LL << p) - 1 > d) break;
            long long est = pow(d, 1.0 / (p - 1));
            for (long long b = max(2ll, est - 1); b <= est + 1; b++) {
                if (calc(b, p, n) == d) {
                    if (chk(n / d, b, p, n)) ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
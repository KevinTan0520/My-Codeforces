#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
vector<long long> b, fac, inv, p2(30), cnt(30);
long long qpow(long long x, long long n) {
    if (n == 1) return x % mod;
    long long res = qpow(x, n / 2) % mod;
    if (n & 1) return res * res % mod * x % mod;
    return res * res % mod;
}
long long C(long long n, long long m) {
    if (m > n || m < 0) return 0;
    return fac[n] * inv[n - m] % mod * inv[m] % mod;
}
void solve() {
    int n;
    cin >> n;
    b.resize(n + 1); fac.resize(n + 1); inv.resize(n + 1);
    fac[0] = 1;
    p2[0] = 1;
    inv[0] = 1;
    for (int i = 0; i <= 29 ; i++) cnt[i] = 0; 
    for (int i = 1; i <= 29; i++) {
        p2[i] = p2[i - 1] * 2 % mod;
    }
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = qpow(fac[i], mod - 2) % mod;
    }

    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = n; i > 0; i--) {
        for (int j = 0; j <= 29; j++) {
            if (b[i] >> j & 1) {
                cnt[j] = i;
                for (int k = 1; k <= i; k++) {
                    long long sub = p2[j] * C(i, k) % mod;
                    b[k] -= sub;
                    if (b[k] < 0) b[k] += mod;
                }
            }
        }
    }
    vector<long long> a(n + 1, 0);
    for (int i = 0; i <= 29; i++) {
        for (int j = 1; j <= cnt[i]; j++) {
            a[j] += p2[i];
            //a[j] %= mod;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return;
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
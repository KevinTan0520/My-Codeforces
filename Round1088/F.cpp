#include <bits/stdc++.h>
using namespace std;

const int mod = 676767677;

long long qpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return r;
}

vector<long long> fac(1, 1), ifac(1, 1);

void ensure_fac(int n) {
    int old = (int)fac.size() - 1;
    if (old >= n) return;

    fac.resize(n + 1);
    for (int i = old + 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;

    ifac.resize(n + 1);
    ifac[n] = qpow(fac[n], mod - 2);
    for (int i = n; i >= old + 1; i--) ifac[i - 1] = ifac[i] * i % mod;
}

long long C(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    ensure_fac(n);
    return fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}

int n, m;
long long ans;
vector<long long> A, preA, prePreA, B, preB, D, preD;

long long get_cross_sum(int L, int R) {
    if (L <= 0 || R <= 0) return 0;
    int t = L + R - 1;
    long long res = prePreA[t];
    res = (res - prePreA[R - 1] + mod) % mod;
    res = (res - prePreA[L - 1] + mod) % mod;
    return res;
}

void dfs_all(int l, int r, int dep) {
    if (l > r) return;
    int mid = (l + r) >> 1;

    int L = mid - l + 1;
    int R = r - mid + 1;
    long long add = get_cross_sum(L, R);
    ans = (ans + 1LL * dep % mod * add % mod) % mod;

    dfs_all(l, mid - 1, dep + 1);
    dfs_all(mid + 1, r, dep + 1);
}

void dfs_prefix(int l, int r, int dep) {
    if (l > r) return;
    int mid = (l + r) >> 1;

    long long seg = (preB[r] - preB[mid - 1] + mod) % mod;
    ans = (ans + 1LL * dep % mod * seg % mod) % mod;

    dfs_prefix(l, mid - 1, dep + 1);
}

void dfs_suffix(int l, int r, int dep) {
    if (l > r) return;
    int mid = (l + r) >> 1;

    long long seg = (preD[mid] - preD[l - 1] + mod) % mod;
    ans = (ans + 1LL * dep % mod * seg % mod) % mod;

    dfs_suffix(mid + 1, r, dep + 1);
}

void solve() {
    cin >> n >> m;
    ensure_fac(n + m + 5);

    A.assign(n + 1, 0);
    preA.assign(n + 1, 0);
    prePreA.assign(n + 1, 0);

    B.assign(n + 1, 0);
    preB.assign(n + 1, 0);

    D.assign(n + 1, 0);
    preD.assign(n + 1, 0);

    for (int len = 1; len <= n; len++) {
        A[len] = C(m + n - len - 2, m - 3);
        preA[len] = (preA[len - 1] + A[len]) % mod;
    }
    for (int i = 1; i <= n; i++) {
        prePreA[i] = (prePreA[i - 1] + preA[i]) % mod;
    }

    for (int r = 1; r <= n; r++) {
        B[r] = C(m + n - r - 2, m - 2);
        preB[r] = (preB[r - 1] + B[r]) % mod;
    }

    for (int l = 1; l <= n; l++) {
        D[l] = C(m + l - 3, m - 2);
        preD[l] = (preD[l - 1] + D[l]) % mod;
    }

    ans = 0;
    dfs_all(1, n, 1);
    dfs_prefix(1, n, 1);
    dfs_suffix(1, n, 1);

    cout << ans % mod << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
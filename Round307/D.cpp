#include <bits/stdc++.h>
using namespace std;

long long n, k, l, m;

struct Matrix{
    int n, m;
    vector<vector<long long>> val;
};

Matrix mul(Matrix a, Matrix b) {
    if (a.m != b.n) return {-1, -1, {}};
    Matrix res;
    res.val.resize(a.n);
    res.n = a.n, res.m = b.m;
    for (int i = 0; i < a.n; i++) {
        for (int j = 0; j < b.m; j++) {
            res.val[i].push_back(0);
            for (int k = 0; k < a.m; k++) {
                res.val[i][j] += a.val[i][k] * b.val[k][j] % m;
                res.val[i][j] %= m;
            }
        }
    }
    return res;
}

Matrix mat_qpow(Matrix a, long long n) {
    if (n == 1) return a;
    long long mid = n >> 1;
    Matrix res = mat_qpow(a, mid);
    if (n % 2) return mul(mul(res, res), a);
    return mul(res, res);
}

long long qpow(int a, long long n){
    if (n == 1) return a;
    long long mid = n >> 1;
    long long res = qpow(a, mid) % m;
    if (n % 2) return res * res % m * a % m;
    return res * res % m;
}

void solve() {
    cin >> n >> k >> l >> m;
    Matrix A = {2, 2, {{1ll, 1ll}, {1ll, 0ll}}}, s = {2, 1, {{3}, {2}}};
    long long dp_n, p2_n = qpow(2, n);
    if (n > 2) {
        dp_n = mul(mat_qpow(A, n - 2), s).val[0][0];
    }
    else {
        if (n == 1) dp_n = 2;
        else dp_n = 3;
    }
    vector<unsigned long long> p2;
    p2.push_back(1);
    for (int i = 1; i <= min(63ll, l); i++) p2.push_back(p2[i - 1] << 1);
    if ((l < 60 && p2[l] - 1 < k) || m == 1) {
        cout << 0 << endl;
        return;
    }
    long long ans = 1;
    for (int i = 0; i < l; i++) {
        if((k >> i) & 1ll) {
            ans *= ((p2_n + m) - dp_n % m) % m;
        }
        else ans *= dp_n % m;
        ans %= m;
    }
    cout << ans << endl;
    return;
}
int main() {
    solve();
    return 0;
}
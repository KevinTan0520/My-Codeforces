#include <bits/stdc++.h>
using namespace std;
long long __lcm(long long a, long long b) {
    return a * b / __gcd(a, b);
}
void solve() {
    int n;
    vector<long long> a, b, g, a1;
    cin >> n;
    a.resize(n);
    b.resize(n);
    g.resize(n);
    a1.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 1; i < n; i++) {
        g[i] = __gcd(a[i], a[i - 1]);
    }
    int ans = 0;
    if (g[1] < a[0]) ans++;
    //a1[0] = g[0];
    for (int i = 1; i < n - 1; i++) {
        if (__lcm(g[i + 1], g[i]) < a[i]) ans++;
    }
    if (g[n - 1] < a[n - 1]) ans++;
    cout << ans << endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
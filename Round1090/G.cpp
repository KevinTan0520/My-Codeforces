#include <bits/stdc++.h>
using namespace std;
const int mod = 676767677;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 2), b(n + 2), c(m + 1, 0), pre(m + 1, 0);
    b[0] = b[n + 1] = m + 1;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        c[b[i]]++;
    }
    pre[0] = 0;
    for (int i = 1; i <= m; i++) {
        pre[i] = pre[i - 1] + c[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) {
            a[i] = 1;
            continue;
        }
        if (min(b[i - 1], b[i + 1]) >= b[i]) {
            a[i] = 0;
            cout << 0 << endl;
            return;
        }
        int r = pre[b[i]], l = 1;
        if (b[i] >= min(b[i - 1], b[i + 1]) + 2)
            l = pre[b[i] - 1] + 1;
        a[i] = r - l + 1;
        if (a[i] <= 0) {
            cout << a[i] << endl;
            return;
        }
    }
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * a[i] % mod;
    }
    cout << ans << endl;
    return;
} 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
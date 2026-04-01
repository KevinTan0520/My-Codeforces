#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

int t;

void solve() {
    int n;
    cin >> n;
    vector<int> c, p;
    for (int i = 0; i < n; i++) {
        int c0, p0;
        cin >> c0 >> p0;
        c.push_back(c0);
        p.push_back(p0);
    }
    vector<double> ans(MAXN);
    ans[n] = 0.0;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = max(ans[i + 1], c[i] + (1.0 - p[i] / 100.0) * ans[i + 1]);
    }
    cout << fixed << setprecision(10) << ans[0] << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
bool cmp(int a, int b) {
    return a > b;
}
void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n + 1, 0), d(m + 1, 0);
    int pos = 1, cur = 1, k = n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= l; i++) {
        d[min(m, k + 1)]++;
        if (a[cur] == i) {
            sort(&d[1], &d[m + 1], cmp);
            d[1] = 0;
            k--;
            cur = min(cur + 1, n);
        }
        sort(&d[1], &d[m + 1], cmp);
        // cout << "< ";
        // for (int i = 1; i <= m; i++) {
        //     cout << d[i] << " ";
        // }
        // cout << ">\n";
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = max(ans, d[i]);
    }
    cout << ans << endl;
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
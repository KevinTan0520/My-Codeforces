#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    vector<int> a, pos, vis, f, pre;
    cin >> n;
    a.resize(n + 1);
    pos.resize(n + 1);
    vis.resize(n + 1);
    f.resize(n + 1);
    pre.resize(n + 1);
    pre[0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
        if (a[i] <= i) ans++;
    }
    // for (int i = 2; i <= n; i++) {

    // }
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
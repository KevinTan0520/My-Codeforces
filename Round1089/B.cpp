#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    vector<int> a, pos, vis;
    cin >> n;
    a.resize(n + 1);
    pos.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
        vis[i] = 0;
    }
    int ans = 0, minn = n + 1;
    for (int i = n; i > 0; i--) {
        int f = pos[i];
        if (f <= i && !vis[f]) {
            ans++;
            vis[f] = 1;
        }

    }
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
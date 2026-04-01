#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    queue<int> q;
    vector<int> vis(n + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        ans++;
        q.push(i);
        vis[i] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int j = 0; j < e[u].size(); j++) {
                int v = e[u][j];
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
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
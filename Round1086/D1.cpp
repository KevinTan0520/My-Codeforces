#include <bits/stdc++.h>
using namespace std;
const int MAXN = 550;
int t, a[MAXN][MAXN];
bool check(int n, const vector<pair<int, int>>& e) {
    if (e.size() != n - 1) return false;

    vector<vector<int>> adj(n + 1), adj2(n + 1);

    for (int i = 0; i < e.size(); i++) {
        adj[e[i].first].push_back(e[i].second);
        adj2[e[i].first].push_back(e[i].second);
        adj2[e[i].second].push_back(e[i].first);
    }

    int cnt = 0;
    vector<int> vis2(n + 1, 0);
    queue<int> q2;
    q2.push(1);
    vis2[1] = 1;
    while (!q2.empty()) {
        int u = q2.front();
        q2.pop();
        cnt++;
        for (int v : adj2[u]) {
            if (!vis2[v]) {
                vis2[v] = 1;
                q2.push(v);
            }
        }
    }
    if (cnt != n) return false;

    for (int i = 1; i <= n; i++) {
        vector<int> vis(n + 1, 0);
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int j = 0; j < adj[u].size(); j++) {
                int v = adj[u][j];
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        for (int j = 1; j <= n; j++) {
            if (vis[j] != a[i][j]) return false;
        }
    }
    return true;
}
void solve() {
    int n;
    cin >> n;
    string s;
    memset(a, 0, sizeof(a));
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= n; j++) {
            a[i][j] = s[j - 1] - '0';
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (!a[i][j]) continue;
            bool flag = true;
            for (int k = 1; k <= n; k++) {
                if (i == k || j == k) continue;
                if (a[i][k] && a[k][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cnt++;
                ans.push_back({i, j});
            }
        }
    }
    if (check(n, ans)) {
        cout << "Yes" << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].first << ' ' << ans[i].second << endl;
        }
    }
    else cout << "No" << endl;
    return;
}
int main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
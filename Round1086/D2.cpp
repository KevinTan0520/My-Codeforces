#include <bits/stdc++.h>
using namespace std;

const int MAXN = 8005;
int t;

struct Node {
    int id;
    int cnt;
    bool operator<(const Node & other) const {
        return cnt > other.cnt;
    }
};

bitset<MAXN> adj[MAXN], adj_orig[MAXN];
int p[MAXN], rk[MAXN];

void solve() {
    int n;
    cin >> n;

    vector<Node> nodes(n);
    vector<string> s(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        nodes[i].id = i;
        nodes[i].cnt = 0;
        for (int j = 0; j < s[i].length(); j++) {
            if (s[i][j] == '1') {
                nodes[i].cnt++;
            }
        }
    }

    sort(nodes.begin(), nodes.end());

    for (int i = 0; i < n; i++) {
        p[i] = nodes[i].id;
        rk[nodes[i].id] = i;
    }

    for (int i = 0; i < n; i++) {
        if (s[i][i] == '0') {
            cout << "No" << "\n";
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        adj[i].reset();
        adj_orig[i].reset();
        int u = p[i];
        for (int j = 0; j < n; j++) {
            if (s[u][j] == '1') {
                adj[i][rk[j]] = 1;
                adj_orig[i][rk[j]] = 1;
            }
        }
    }

    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++) {
        adj[i][i] = 0;
        for (int v = adj[i]._Find_first(); v < MAXN; v = adj[i]._Find_first()) {
            if (v >= n) break;

            ans.push_back({p[i] + 1, p[v] + 1});
            if ((adj_orig[v] & ~adj[i]).any()) {
                cout << "No" << "\n";
                return;
            }

            adj[i] &= ~adj_orig[v];
            adj[i][v] = 0;
        }
    }

    if (ans.size() != n - 1) {
        cout << "No" << "\n";
        return;
    }

    vector<vector<int>> g(n + 1);
    for (auto& edge : ans) {
        g[edge.first].push_back(edge.second);
        g[edge.second].push_back(edge.first);
    }
    
    int connected_cnt = 0;
    vector<int> vis(n + 1, 0);
    queue<int> q;
    
    q.push(1);
    vis[1] = 1;
    connected_cnt++;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                connected_cnt++;
                q.push(v);
            }
        }
    }

    if (connected_cnt == n) {
        cout << "Yes" << "\n";
        for (auto& edge : ans) {
            cout << edge.first << ' ' << edge.second << "\n";
        }
    }
    else {
        cout << "No" << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
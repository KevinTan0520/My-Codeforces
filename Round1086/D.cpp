#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;

int t;
int state[MAXN][MAXN];
vector<int> deg;

bool cmp(int a, int b) {
    return deg[a] > deg[b];
}

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> p(n);
    deg.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        p[i] = i;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '1') cnt ++;
        }
        deg[i] = cnt;
    }

    sort(p.begin(), p.end(), cmp);
    vector<pair<int, int>> e;

    vector<vector<int>> adj(n);

    for (int i = 1; i < n; i++) {
        int u = p[i];
        int prt = -1;
        for (int j = i - 1; j >= 0; j--) {
            int v = p[j];
            if (s[v][u] == '1') {
                prt = v;
                break;
            }
        }
        if (prt == -1) {
            cout << "NO" << endl;
            return;
        }

        e.push_back({prt, u});
        adj[prt].push_back(u);
    }

    vector<int> subsize(n, 1);
    for (int i = n - 1; i >= 0; i--) {
        int u = p[i];
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];
            subsize[u] += subsize[v];
        }
        int flag = (s[u][u] == '1') ? subsize[u] : subsize[u] - 1;
        if (deg[u] != flag) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < e.size(); i++) {
        cout << e[i].first + 1 << ' ' << e[i].second + 1 << endl;
    }
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
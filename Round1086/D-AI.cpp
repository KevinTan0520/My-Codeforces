#include <bits/stdc++.h>
using namespace std;

// 使用全局 deg 方便排序
vector<int> deg;

bool cmp(int a, int b) {
    return deg[a] < deg[b]; // 升序排列
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<string> s(n);
    deg.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        int cnt = 0;
        for (char c : s[i]) {
            if (c == '1') cnt++;
        }
        deg[i] = cnt;
    }

    vector<pair<int, int>> ans_edges;

    for (int u = 0; u < n; u++) {
        vector<int> parents;
        for (int v = 0; v < n; v++) {
            if (u == v) continue;
            if (s[v][u] == '1') {
                parents.push_back(v);
            }
        }
        // 按度数从小到大排序，优先选“近”的父节点
        sort(parents.begin(), parents.end(), cmp);

        vector<int> chosen;
        for (int v : parents) {
            bool redundant = false;
            // 检查 v 是否能到达任何已经选中的 father
            // 如果 v 能到 existing，说明 v 是 existing 的祖先，不是直接父亲
            for (int existing : chosen) {
                if (s[v][existing] == '1') {
                    redundant = true;
                    break;
                }
            }
            if (!redundant) {
                chosen.push_back(v);
                ans_edges.push_back({v, u});
            }
        }
    }

    if (ans_edges.size() != n - 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (auto& p : ans_edges) {
            cout << p.first + 1 << " " << p.second + 1 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}
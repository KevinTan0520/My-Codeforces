#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
bool flag;
struct DSU {
    int size;
    vector<int> fa, fixed;
    void init(int x) {
        size = x;
        for (int i = 0; i <= x; i++) {
            fa.push_back(i);
            fixed.push_back(0);
        }
        return;
    }
    int find(int v) {
        if (fa[v] == v) return v;
        return fa[v] = find(fa[v]);
    }
    bool combine(int x, int y) {
        int u = find(x), v = find(y);
        if (u == v) {
            return true;
        }
        if (u < v) swap(u, v);
        fa[u] = v;
        if (fixed[u] && fixed[v] && fixed[u] != fixed[v]) {
            flag = false;
        }
        return false;
    }
    void force(int u, int x) {
        u = find(u);
        if (fixed[u] == 0) fixed[u] = x;
        else {
            if (fixed[u] != x) {
                flag = false;
            }
        }
        return;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    flag = true;
    vector<int> a(n + 1), b(n + 1), cnt(n + 1, 0);
    DSU dsu;
    dsu.init(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = k + 1; i <= n && flag; i++) {
        if (a[i] == a[i - k]) {
            dsu.combine(i, i - k);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] != -1) dsu.force(i, b[i]);
    }
    for (int i = k + 1; i <= n && flag; i++) {
        
        if (a[i] != a[i - k]) {
            dsu.force(i, a[i]);
            dsu.force(i - k, a[i - k]);
        }
    }
    for (int i = 1; i <= k && flag; i++) {
        cnt[a[i]]++;
    }
    for (int i = 1; i <= k && flag; i++) {
        int val;
        if (b[i] != -1) val = b[i];
        else val = dsu.fixed[dsu.find(i)];
        if (val != 0) {
            cnt[val]--;
            if (cnt[val] < 0) flag = false;
        }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return;
}
int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
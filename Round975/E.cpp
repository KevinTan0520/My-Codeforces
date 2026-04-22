#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
void dfs(int u, int fa, int d, vector<int> e[], vector<int>& dep, vector<int>& sub_dep) {
    dep[u] = d;
    sub_dep[u] = d;
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (v != fa) {
            dfs(v, u, d + 1, e, dep, sub_dep);
            sub_dep[u] = max(sub_dep[u], sub_dep[v]);
        }
    }
}
void solve() {
    int n;
    cin >> n;
    vector<int> e[n + 1], deg(n + 1), dep(n + 1), tot(n + 1, 0), pre_tot(n + 1, 0), cnt_fa(n + 1, 0), sub_dep(n + 1, 0);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    dfs(1, 0, 1, e, dep, sub_dep);
    int max_dep = 0;
    for (int i = 1; i <= n; i++) {
        max_dep = max(max_dep, dep[i]);
    }
    // for (int i = 1; i <= n; i++) {
    //     printf("Node %d 's deepest son has depth %d\n", i, sub_dep[i]);
    // }
    // cout << "max_dep = " << max_dep << endl;
    for (int i = 1; i <= n; i++) {
        tot[dep[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cnt_fa[sub_dep[i]]++;
    }
    for (int i = 1; i <= max_dep; i++) {
        pre_tot[i] = pre_tot[i - 1] + tot[i];
    }
    // for (int i = 1; i <= max_dep; i++) {
    //     printf("at dep %d, cnt_fa = %d, tot = %d\n", i, cnt_fa[i], dep[i]);
    // }
    int cum = 0, ans = n;
    for (int i = 1; i <= max_dep; i++) {
        ans = min(ans, pre_tot[max_dep] - pre_tot[i] + cum);
        cum += cnt_fa[i];
    }
    cout << ans << endl;
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
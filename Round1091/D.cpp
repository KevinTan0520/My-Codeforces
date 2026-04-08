#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    vector<int> a, p, dif, pre;
    cin >> n >> k;
    a.resize(n + 1);
    p.resize(k + 1);
    dif.resize(n + 2);
    pre.resize(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> p[i];
    dif[1] = a[1] ^ a[p[1]];
    dif[n + 1] = a[n] ^ a[p[1]];
    for (int i = 2; i <= n; i++) dif[i] = a[i] ^ a[i - 1];
    pre[0] = 0;
    for (int i = 1; i <= n + 1; i++) {
        pre[i] = pre[i - 1] + dif[i];
    }
    int sum = pre[n + 1] - pre[0], maxx = pre[p[1]] - pre[0];
    for (int i = 1; i < k; i++) {
        maxx = max(maxx, pre[p[i + 1]] - pre[p[i]]);
    }
    maxx = max(maxx, pre[n + 1] - pre[p[k]]);
    cout << max(sum / 2, maxx) << endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
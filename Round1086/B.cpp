#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5010;

int t;
int n, k, p, m;

int a[MAXN];

void solve() {
    cin >> n >> k >> p >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int win = a[p];
    int cnt = win;
    if (p > k) {
        vector<int> pre;
        for (int i = 1; i < p; i++) {
            pre.push_back(a[i]);
        }
        sort(pre.begin(), pre.end());
        for (int i = 0; i < p - k; i++) {
            cnt += pre[i];
        }
    }
    if (cnt > m) {
        cout << 0 << endl;
        return;
    }
    ans++;
    m -= cnt;
    vector<int> cycle;
    for (int i = 1; i <= n; i++) {
        if (i == p) continue;
        cycle.push_back(a[i]);
    }
    sort(cycle.begin(), cycle.end());
    cnt = win;
    for (int i = 0; i < n - k; i++) {
        cnt += cycle[i];
    }
    ans += m / cnt;
    cout << ans << endl;
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
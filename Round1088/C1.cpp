#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1), b(n + 1), pos(n + 1), cnt(n + 1, 0), vis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
        cnt[a[i]]++;
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] != -1) {
            cnt[b[i]]--;
            vis[b[i]] = 1;
            if (cnt[b[i]] < 0 && flag) {
                cout << "NO" << endl;
                flag = false;
            }
        }
    }
    if (!flag) return;
    if (n == k) {
        cout << "YES" << endl;
        return;
    }
    for (int i = 1; i <= n - k && flag; i++) {
        if (a[i] != b[i] && b[i] != -1) flag = false;
        if (a[i] == b[i]) {
            vis[b[i]] = 1;
            continue;
        }
        if (vis[a[i]]) {
            flag = false;
        }
        else {
            b[i] = a[i];
            vis[a[i]] = 1;
        }
    }
    for (int i = k + 1; i <= n && flag; i++) {
        if (a[i] != b[i] && b[i] != -1) flag = false;
        if (a[i] == b[i]) {
            vis[b[i]] = 1;
            continue;
        }
        if (vis[a[i]]) {
            flag = false;
        }
        else {
            b[i] = a[i];
            vis[a[i]] = 1;
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
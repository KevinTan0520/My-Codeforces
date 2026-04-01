#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    string s;
    cin >> n >> s;
    int cur = 0;
    vector<int> vis(n, 0);
    vis[cur] = 1;
    for (int i = 0; i < n; i++) {
        if (s[cur] == 'R') cur++;
        else cur--;
        vis[cur] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) cnt++;
    }
    cout << cnt << endl;
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
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int lst = -1, cnt = 0, maxx = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != lst) {
            maxx = max(maxx, cnt);
            cnt = 1;
        }
        else cnt++;
        lst = a[i];
    }
    maxx = max(maxx, cnt);
    //cout << maxx << endl;
    if (maxx >= m) cout << "NO\n";
    else cout << "YES\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
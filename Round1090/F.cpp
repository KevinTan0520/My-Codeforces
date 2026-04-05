#include <bits/stdc++.h>
using namespace std;
void solve() {
    int x, y, n;
    cin >> x >> y;
    n = x + y;
    vector<vector<int>> e(n + 1);
    if (x > y || (n % 2 == 0 && x == 0)) {
        cout << "NO\n";
        return; 
    }
    int t = x - (1 - n % 2);
    for (int i = 0; i < t; i++) {
        e[1].push_back(2 + 2 * i);
        e[2 + 2 * i].push_back(3 + 2 * i);
    }
    for (int i = 2 + 2 * t; i <= n; i++) {
        e[1].push_back(i);
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < e[i].size(); j++) {
            cout << i << ' ' << e[i][j] << endl;
        }
    }
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
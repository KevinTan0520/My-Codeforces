#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cout << "? " << 2 * i - 1  << ' ' << 2 * i << endl;
        int res;
        cin >> res;
        if (res) {
            cout << "! " << 2 * i << endl;
            return;
        }
    }
    cout << "? 1 3\n";
    int res1, res2;
    cin >> res1;
    cout << "? 1 4\n";
    cin >> res2;
    if (res1 || res2) {
        cout << "! 1" << endl;
        return;
    }
    cout << "! 2" << endl;
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
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(&a[1], &a[n + 1]);
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i + 1]) {
            cout << "-1\n";
            return;
        }
    }
    for (int i = n; i >= 1; i--) cout << a[i] << ' ';
    cout << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
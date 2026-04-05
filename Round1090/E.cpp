#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    vector<int> a;
    cin >> n;
    a.resize(n + 1);
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = max(ans, a[i] ^ a[j]);
        }
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
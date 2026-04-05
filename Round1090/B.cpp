#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a[10];
    int maxx = -70;
    int sum = 0;
    for (int i = 0; i < 7; i++) {
        cin >> a[i];
        sum += a[i];
        maxx = max(maxx, a[i]);
    }
    cout << maxx - (sum - maxx) << endl;
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
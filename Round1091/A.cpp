#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, k, p = 0;
    cin >> n >> k;
    vector<int> a(600, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) p += a[i];
    if (p % 2 != 0) cout << "YES\n";
    else {
        if (k * n % 2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
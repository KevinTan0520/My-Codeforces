#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
void solve() {
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        if (n < 3) cout << n << ' ';
        else cout << "2 ";
    }
    cout << endl;
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
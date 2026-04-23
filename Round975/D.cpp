#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(&a[1], &a[n + 1], cmp);
    int lmax = 0, rmin = n + 1;
    for (int i = 1; i <= n; i++) {
        lmax = max(lmax, a[i].second - a[i].first + 1);
        rmin = min(rmin, a[i].second + a[i].first - 1);
    }
    if (lmax > rmin) {
        cout << "0\n";
        return;
    }
    int l = a[1].second, r = a[1].second;
    for (int i = 2; i <= n; i++) {
        l = min(l, a[i].second);
        r = max(r, a[i].second);
        if (r - l + 1 > a[i].first) {
            cout << "0\n";
            return;
        }
    }
    cout << rmin - lmax + 1 << endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
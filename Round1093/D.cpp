#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    int l = 1, r = 2 * n + 1;
    vector<int> ans(3);
    while (l < r) {
        int mid = (l + r) >> 1;
        cout << "? " << mid << ' ';
        for (int i = 1; i <= mid; i++) {
            cout << i << ' ';
        }
        cout << endl;
        int len = mid, cnt;
        cin >> cnt;
        if ((len - cnt) % 2 == 0) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    ans[2] = l;
    l = 1, r = ans[2] - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        cout << "? " << mid + 1 << ' ';
        for (int i = 1; i <= mid; i++) {
            cout << i << ' ';
        }
        cout << ans[2] << endl;
        int len = mid + 1, cnt;
        cin >> cnt;
        if ((len - cnt) % 2 == 0) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    ans[1] = l;
    l = 1, r = ans[1] - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        cout << "? " << mid + 2 << ' ';
        for (int i = 1; i <= mid; i++) {
            cout << i << ' ';
        }
        cout << ans[1] << ' ' << ans[2] << endl;
        int len = mid + 2, cnt;
        cin >> cnt;
        if ((len - cnt) % 2 == 0) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    ans[0] = l;
    cout << "! " << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
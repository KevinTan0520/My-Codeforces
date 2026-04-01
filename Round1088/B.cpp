#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int mod = 676767677;
void solve() {
    int x, y;
    cin >> x >> y;
    int minn = 1, sum = x - y;
    if (sum == 0) {
        cout << 1 << endl;
        while (x--) cout << "1 ";
        while (y--) cout << "-1 ";
        cout << endl;
        return;
    }
    sum = abs(sum);
    minn = 0;
    for (int i = 1; i <= sum; i++) {
        if (sum % i == 0) minn++;
        minn %= mod;
    }
    cout << minn << endl;
    while (x--) cout << "1 ";
    while (y--) cout << "-1 ";
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
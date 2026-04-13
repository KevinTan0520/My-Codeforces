#include <bits/stdc++.h>
using namespace std;
void solve() {
    long long a, b, c, ans = 0, minn;
    cin >> a >> b >> c;
    minn = min(a, c);
    ans += 4 * minn;
    a -= minn, c -= minn;
    minn = min(a / 2, b);
    ans += 7 * minn;
    a -= minn * 2, b -= minn;
    if (a && b) {
        ans += 5;
        a--, b--;
    }
    if (a > 0) {
        ans += (a * 2 + 1);
        a = 0;
    }
    cout << ans + (a + b + c) * 3 << endl;
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
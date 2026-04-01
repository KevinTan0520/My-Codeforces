#include <bits/stdc++.h>
using namespace std;
long long Gcd(long long a, long long b) {
    if (a < b) {
        swap(a, b);
    }
    if (b == 0) {
        return a;
    }
    return Gcd(b, a % b);
}
long long Lcm(long long a, long long b) {
    return a / Gcd(a, b) * b;
}
void solve() {
    long long a, b, c, m, ans;
    cin >> a >> b >> c >> m;
    long long lcmab = Lcm(a, b), lcmbc = Lcm(b, c), lcmac = Lcm(a, c), lcmabc = Lcm(a, Lcm(b, c));
    ans = 6 * (m / a - m / lcmab - m / lcmac + m / lcmabc) + 3 * (m / lcmab + m / lcmac - 2 * (m / lcmabc)) + 2 * (m / lcmabc);
    cout << ans << " ";
    ans = 6 * (m / b - m / lcmab - m / lcmbc + m / lcmabc) + 3 * (m / lcmbc + m / lcmab - 2 * (m / lcmabc)) + 2 * (m / lcmabc);
    cout << ans << " ";
    ans = 6 * (m / c - m / lcmac - m / lcmbc + m / lcmabc) + 3 * (m / lcmac + m / lcmbc - 2 * (m / lcmabc)) + 2 * (m / lcmabc);
    cout << ans << endl;
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
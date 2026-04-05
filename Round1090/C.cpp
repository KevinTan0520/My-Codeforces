#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    n *= 3;
    int l = 1, r = n;
    for (int i = 1; i <= n / 3; i++) {
        cout << l << ' ' << r << ' ' << r - 1 << ' ';
        l++;
        r -= 2;
    }
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
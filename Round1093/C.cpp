#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long p, q, a, b;
    cin >> p >> q;
    long long s = 2 * p + 4 * q + 1;
    bool flag = false;
    for (long long i = 3; i * i <= s; i++) {
        if (s % i) continue;
        long long j = s / i;
        if (i >= 3 && j >= 3 && abs(i - j) <= 2 * p) {
            flag = true;
            a = i / 2, b = j / 2;
            break;
        }
    }
    if (!flag) cout << "-1\n";
    else cout << a << ' ' << b << '\n';
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
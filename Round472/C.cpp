#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    vector<int> m, t;
    cin >> n;
    m.resize(n);
    t.resize(n);
    for (int i = 0; i < n; i++) cin >> m[i];
    int cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        cur = max(max(0, cur - 1), m[i] + 1);
        t[i] = cur;
    }
    cur = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cur = max(cur, t[i]);
        ans += cur - (m[i] + 1);
    }
    //for (int i = 0; i < n; i++) ans -= (m[i] + 1);
    cout << ans << endl;
    return 0;
}
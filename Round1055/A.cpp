#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
void solve() {
    set<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }
    cout << s.size() * 2 - 1 << endl;
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
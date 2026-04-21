#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
void solve(){
    string s;
    cin >> s;
    int n = s.length();
    vector<int> a(n + 1), dif(n + 1);
    for (int i = 0; i < n; i++) {
        a[i + 1] = s[i] - 'a';
    }
    int cnt = 0;
    for (int i = 1; i < n; i++) dif[i] = (a[i] != a[i + 1]);
    for (int i = 1; i < n; i++) {
        if (dif[i] == 0) cnt++;
    }
    if (cnt <= 2) cout << "YES\n";
    else cout << "NO\n";
    return;
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
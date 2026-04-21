#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
void solve(){
    long long x, y;
    cin >> x >> y;
    y -= x;
    if (y > x) cout << "YES\n";
    else cout << "NO\n";
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
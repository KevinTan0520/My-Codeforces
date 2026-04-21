#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int Mod = 998244353;
void solve(){
    long long n, x;
    cin >> n >> x;
    long long l_1 = (x + 2) / 4 % Mod, l_0 = x / 4 % Mod + 1;
    long long r_1 = (n + 3) / 4 % Mod + Mod - (x + 2) / 4 % Mod, r_0 = (n + 1) / 4 % Mod + Mod - (x) / 4 % Mod;
    long long ans = l_1 * r_1 % Mod + l_0 * r_0 % Mod;
    cout << ans % Mod << endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
void solve() {
    long long n, rK, cK, rD, cD;
    cin >> n >> rK >> cK >> rD >> cD;
    long long ans1 = 1e9 + 10, ans2 = 1e9 + 10, ans = 0;
    if (rK == rD) {
        if (cK - cD == 1) {
            cout << n - cD << endl;
            return;
        }
        if (cK - cD == -1) {
            cout << cD << endl;
            return;
        }
        if (cK > cD) {
            ans = max(ans, n - cD);
        }
        else {
            ans = max(ans, cD);
        }
    }
    if (cK == cD) {
        if (rK - rD == 1) {
            cout << n - rD << endl;
            return;
        }
        if (rK - rD == -1) {
            cout << rD << endl;
            return;
        }
        if (rK > rD) {
            ans = max(ans, n - rD);
        }
        else {
            ans = max(ans, rD);
        }
    }
    if (rK > rD) {
        if (cK > cD) {
            ans = max(ans, max(n - cD, n - rD));
        }
        else {
            ans = max(ans, max(cD, n - rD));
        }
    }
    else {
        if (cK > cD) {
            ans = max(ans, max(n - cD, rD));
        }
        else {
            ans = max(ans, max(cD, rD));
        }
    }
    cout << ans << endl;
    return ;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
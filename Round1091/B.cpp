#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    vector<int> a;
    int p;
    cin >> n >> k;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> p;
    int cntl = 1, cntr = 1;
    int cur = a[p];
    for (int i = p - 1; i >= 1; i--) {
        if (a[i] != cur) {
            cur = a[i];
            cntl++;
        }
    }
    cur = a[p];
    for (int i = p + 1; i <= n; i++) {
        if (a[i] != cur) {
            cur = a[i];
            cntr++;
        }
    } 
    if (a[1] == a[p]) cntl--;
    if (a[n] == a[p]) cntr--;
    cout << max(cntl, cntr) << endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
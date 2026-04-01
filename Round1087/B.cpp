#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        int cnt0 = 0, cnt1 = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) cnt1++;
            if (a[j] < a[i]) cnt0++;
        }
        ans[i] = max(cnt0, cnt1);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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
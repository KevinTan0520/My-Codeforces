#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

int t;
int a[MAXN][MAXN];
void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n * n + 1);
    for (int i = 0; i <= n * n; i++) {
        cnt[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            cnt[a[i][j]]++;
        }
    }
    int maxVal = 0;
    for (int i = 1; i <= n * n; i++) {
        maxVal = max(maxVal, cnt[i]);
    }

    if (maxVal > n * n - n) {
        cout << "NO" << endl;
    }
    else cout << "YES" << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
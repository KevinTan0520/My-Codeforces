#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int n;
    vector<pair<int, int>> p;
    cin >> n;
    p.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    long long ans = 1ll * n * (n - 1) * (n - 2) / 6;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if ((p[j].second - p[i].second) * (p[k].first - p[i].first) == (p[k].second - p[i].second) * (p[j].first - p[i].first)) {
                    ans--;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
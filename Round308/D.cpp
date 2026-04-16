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
        vector<pair<int, int>> l;
        for (int j = i + 1; j <= n; j++) {
            int dx = p[j].first - p[i].first, dy = p[j].second - p[i].second;
            int g = __gcd(dx, dy);
            dx /= g, dy /= g;
            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }
            l.push_back({dx, dy});
        }
        sort(l.begin(), l.end());
        int cnt = 0;
        for (int j = 0; j < l.size(); j++) {
            cnt++;
            if (j == l.size() - 1 || l[j] != l[j + 1]) {
                ans -= 1ll * cnt * (cnt - 1) / 2;
                cnt = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
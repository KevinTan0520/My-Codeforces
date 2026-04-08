#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    vector<int> p, d, q;
    cin >> n;
    p.resize(n + 1);
    q.resize(n + 1);
    d.resize(n + 1);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> d[i];
    list<int> l;
    for (int i = n; i >= 1; i--) {
        int tot = 0;
        for (auto it = l.begin(); it != l.end(); it++) {
            int pos = *it;
            if (p[pos - 1] > p[i - 1]) tot++;
        }
        if (tot < d[i - 1]) {
            cout << "-1\n";
            return;
        }
        int cnt = 0;
        auto it = l.begin();
        while (it != l.end() && cnt < tot - d[i - 1]) {
            if (p[*it - 1] > p[i - 1]) cnt++;
            it++;
        }
        l.insert(it, i);
    }
    int val = 1;
    for (auto it = l.begin(); it != l.end(); it++, val++) {
        int pos = *it;
        q[pos] = val;
    }
    for (int i = 1; i <= n; i++) cout << q[i] << ' ';
    cout << endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
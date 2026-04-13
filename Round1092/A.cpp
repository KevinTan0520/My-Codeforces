#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> cap(k + 2), b(n + 1), cnt(k + 2, 0), op;
    vector<queue<int>> cur(k + 2);
    bool flag = 1;
    for (int i = 1; i <= k; i++) {
        cin >> cap[i];
        if (cap[i] == 0) {
            flag = 0;
        }
    }
    if (!flag) {
        cout << "-1\n";
        return;
    }
    cap[k + 1] = INT_MAX;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        cur[b[i]].push(i);
    }
    while (cur[k + 1].size() < n) {
        while (!cur[k].empty()) {
            cur[k + 1].push(cur[k].front());
            op.push_back(cur[k].front());
            cur[k].pop();
        }
        for (int i = k; i > 1; i--) {
            while (cur[i].size() < cap[i] && !cur[i - 1].empty()) {
                cur[i].push(cur[i - 1].front());
                op.push_back(cur[i - 1].front());
                cur[i - 1].pop();
            }
        }
    }
    cout << op.size() << endl;
    for (int i = 0; i < op.size(); i++) cout << op[i] << ' ';
    cout << endl;
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
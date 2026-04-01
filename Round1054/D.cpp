#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int>& pos) {
    if (pos.empty()) return 0;
    int k = pos.size();
    vector<long long> q(k);
    for (int i = 0; i < k; i++) q[i] = pos[i] - i;
    sort(q.begin(), q.end());
    long long median = q[k / 2];
    long long res = 0;
    for (auto x : q) res += llabs(x - median);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        string s; 
        cin >> s;
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a.push_back(i + 1);
            else b.push_back(i + 1);
        }
        cout << min(solve(a), solve(b)) << endl;
    }
}

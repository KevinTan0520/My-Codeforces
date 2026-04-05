#include <bits/stdc++.h>
using namespace std;
vector<long long> p;
vector<int> vis(200010);
void get_prime() {
    for (int i = 2; i <= 2e5; i++) {
        if (!vis[i]) {
            p.push_back(i);
            for (long long j = i; (long long) j * i <= 2e5; j++) vis[(long long) j * i] = 1;
        }
    }
    return;
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << (long long) p[i - 1] * p[i] << ' ';
    }
    cout << endl;
    return;
}
int main() {
    int t;
    cin >> t;
    get_prime();
    while (t--) solve();
    return 0;
}
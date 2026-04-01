#include <bits/stdc++.h>
using namespace std;
void solve() {
    long long n, c, k;
    vector<long long> a;
    cin >> n >> c >> k;
    for (int i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i] <= c) {
            long long tmp = min(k, c - a[i]);
            k -= tmp;
            a[i] += tmp;
            c += a[i];
        }
    }
    //cout << "output "; 
    cout << c << endl;
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
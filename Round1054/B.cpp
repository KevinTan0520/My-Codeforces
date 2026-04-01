#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        vector<int> a;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n / 2; i++) {
            ans = max(ans, abs(a[i * 2] - a[i * 2 + 1]));
        }
        cout << ans <<endl;
    }
    return 0;
}
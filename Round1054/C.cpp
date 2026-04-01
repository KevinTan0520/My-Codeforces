#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        map<int, int> m;
        m.clear();
        int n, k, ans1 = 0, ans2 = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            m[tmp]++;
        }
        for (int i = 0; i < k; i++) {
            if (m.find(i) == m.end()) {
                ans1++;
            }
        }
        if (m.find(k) != m.end()) {
            ans2 += m[k];
        }
        cout << max(ans1, ans2) << endl;
    }
    return 0;
}
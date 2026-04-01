#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, l, r;
        cin >> n >> k >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        map<int, int> freqx, freqy;
        int x = 0, y = 0, cntx = 0, cnty = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                freqx[a[i - 1]]--;
                if (freqx[a[i - 1]] == 0) {
                    cntx--;
                }
                freqy[a[i - 1]]--;
                if (freqy[a[i - 1]] == 0) {
                    cnty--;
                }
            }

            while (x < n && cntx < k) {
                freqx[a[x]]++;
                if (freqx[a[x]] == 1) {
                    cntx++;
                }
                x++;
            }

            while (y < n && (cnty < k || freqy[a[y]] > 0)) {
                freqy[a[y]]++;
                if (freqy[a[y]] == 1) {
                    cnty++;
                }
                y++;
            }

            if (cntx == k) {
                int left = max(x - 1, i + l - 1);
                int right = min(y - 1, i + r - 1);
                if (left <= right) {
                    ans += right - left + 1;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0, cnt1 = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == -1) cnt1++;
            if (a == 0) ans++;
        }
        if (cnt1 % 2 == 1) ans += 2;
        cout << ans <<endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int t, n, a[MAXN], b[MAXN];
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            // if (a[i] != b[i] && a[i] ^ a[i + 1] != b[i] && a[i] ^ b[i + 1] != b[i]) {
            //     flag = false;
            //     break;
            // }
            if (a[i] == b[i]) {
                continue;
            }
            if (i < n - 1 && (a[i] ^ a[i + 1]) == b[i] ) {
                continue;
            }
            if (i < n - 1 && (a[i] ^ b[i + 1]) == b[i]) {
                continue;
            }
            flag = false;
        }
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
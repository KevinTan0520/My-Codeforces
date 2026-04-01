#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
int t, n, a[MAXN], b[MAXN], dif[MAXN], posSum, negSum, ans;
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        posSum = 0;
        negSum = 0;
        ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            dif[i] = a[i] - b[i];
            if (dif[i] > 0) {
                posSum += dif[i];
            }
            else {
                negSum +=dif[i];
            }
        }
        ans = posSum + 1;
        cout << ans << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
void solve(){
    int n, cnt = 0;
    string s1, s2;
    cin >> n >> s1 >> s2;
    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i]) continue;
        if (i == n - 1) {
            cnt++;
            continue;
        }
        int flag = (s1[i] != s1[i + 1]) + (s2[i] != s2[i + 1]);
        if (flag == 0) {
            i++;
            continue;
        }
        if (flag == 1) {
            cnt++;
            i++;
            continue;
        }
        if (flag == 2) {
            cnt++;
            continue;
        }
    }
    cout << cnt << endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
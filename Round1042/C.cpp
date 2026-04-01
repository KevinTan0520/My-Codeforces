#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int n, k, q;
int s[MAXN], t[MAXN];
multiset <int> ms;
int main() {
    cin >> q;
    while (q--) {
        cin >> n >> k;
        ms.clear();
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            ms.insert(s[i] % k);
        }
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }
        for (int i = 0; i < n; i++) {
            auto it = ms.find(t[i] % k);
            bool flag = false;
            if (it != ms.end()) {
                ms.erase(it);
                flag = true;
            }
            else {
                it = ms.find((k - t[i] % k) % k);
                if (it != ms.end()) {
                    ms.erase(it);
                    flag = true;
                }
            }
            if (!flag) {
                //cout << "NO" <<endl;
                break;
            }
        }
        if (ms.empty()) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" <<endl;
        }
    }
    return 0;
}
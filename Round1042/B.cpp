#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int t, n;
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 2) {
            cout << "-1 2" << endl;
            continue;
        }
        if (n % 2 == 0) {
            for (int i = 1; i < n; i++) {
                if (i % 2 == 0) {
                    cout << "3 ";
                }
                else {
                    cout << "-1 ";
                }
            }
            cout << "2" << endl;
            continue;
        }
        for (int i = 1; i < n; i++) {
            if (i % 2 == 0) {
                cout << "3 ";
            }
            else {
                cout << "-1 ";
            }
        }
        cout << "-1" << endl;
    }
    return 0;
}
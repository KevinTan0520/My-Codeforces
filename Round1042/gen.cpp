#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
int n, a[MAXN], b[MAXN], m[MAXN][MAXN];
int main() {
    while (cin >> n) {
        srand(time(0));
        for (int i = 0; i < n; i++) {
            a[i] = rand() % 2;
            b[i] = rand() % 2;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] = a[i] ^ b[j];
                cout << m[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
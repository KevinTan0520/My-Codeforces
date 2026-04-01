#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int t, mat[MAXN][MAXN];
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0}, dir = 1;
int main() {

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mat[i][j] = -1;
            }
        }
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        dir = 0;
        int px = (n + 1) / 2, py = (n + 1) / 2;
        for (int i = 0; i < n * n; i++) {
            mat[px][py] = i;
            int tmp = (dir + 1) % 4;
            if (mat[px + dx[tmp]][py + dy[tmp]] == -1) {
                dir = tmp;
            }
            px += dx[dir];
            py += dy[dir];
            //dir = (dir + 1) % 4;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << mat[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
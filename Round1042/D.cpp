#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int t, n;
vector <int> e[MAXN];
int deg[MAXN];
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            e[i].clear();
            deg[i] = 0;
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            e[u].push_back(v);
            e[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        if (n == 2) {
            cout << 0 <<endl;
            continue;
        }
        int leafCnt = 0, ans = MAXN;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) leafCnt++;
        }
        for (int i = 0; i < n; i++) {
            int tmpLeafCnt = 0;
            for (int j = 0; j < e[i].size(); j++) {
                if (deg[e[i][j]] == 1) {
                    tmpLeafCnt++;
                }
            }
            if (deg[i] == 1) {
                tmpLeafCnt++;
            }
            //cout << leafCnt << ' ' << tmpLeafCnt <<endl;
            ans = min(ans, leafCnt - tmpLeafCnt);
        }
        cout << ans <<endl;
    }
    return 0;
}   
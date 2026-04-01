#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
map<vector<int>, int> memo;

int solve(vector<int> arr) {
    if (arr.empty()) return 0;
    if (arr.size() % 3 != 0) return INF;
    if (memo.count(arr)) return memo[arr];
    
    int res = INF;
    int m = arr.size();
    
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                if (arr[i] == arr[j] && arr[j] == arr[k]) {
                    int cost = min(k - j, j - i);
                    vector<int> next;
                    for (int p = 0; p < m; p++) {
                        if (p != i && p != j && p != k) {
                            next.push_back(arr[p]);
                        }
                    }
                    res = min(res, cost + solve(next));
                }
            }
        }
    }
    
    return memo[arr] = res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        // 预处理所有长度≤18的子数组
        const int MAX_PRECOMPUTE = 18;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -2));
        
        for (int l = 1; l <= n; l++) {
            for (int r = l; r <= n && r - l + 1 <= MAX_PRECOMPUTE; r++) {
                if ((r - l + 1) % 3 != 0) {
                    dp[l][r] = -1;
                } else {
                    vector<int> sub(r - l + 1);
                    for (int i = 0; i < r - l + 1; i++) {
                        sub[i] = a[l + i];
                    }
                    int ans = solve(sub);
                    dp[l][r] = (ans >= INF ? -1 : ans);
                }
            }
        }
        
        while (q--) {
            int l, r;
            cin >> l >> r;
            
            int len = r - l + 1;
            if (len % 3 != 0) {
                cout << -1 << "\n";
            } else if (len <= MAX_PRECOMPUTE) {
                cout << dp[l][r] << "\n";
            } else {
                // 对于长区间，实时计算
                vector<int> sub(len);
                for (int i = 0; i < len; i++) {
                    sub[i] = a[l + i];
                }
                int ans = solve(sub);
                cout << (ans >= INF ? -1 : ans) << "\n";
            }
        }
        
        memo.clear();
    }
    
    return 0;
}
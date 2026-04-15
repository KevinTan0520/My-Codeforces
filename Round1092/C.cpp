#include <bits/stdc++.h>
using namespace std;
void solve() {
    long long n, k, p, q;
    if (!(cin >> n >> k >> p >> q)) return;
    
    vector<long long> a(n + 1);
    // 预处理四种可能值的状态前缀和
    // ps[0]: 原值, ps[1]: %p, ps[2]: %q, ps[3]: %p%q (取最小收益方向)
    vector<vector<long long>> ps(4, vector<long long>(n + 1, 0));
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ps[0][i] = ps[0][i - 1] + a[i];
        ps[1][i] = ps[1][i - 1] + (a[i] % p);
        ps[2][i] = ps[2][i - 1] + (a[i] % q);
        // 交错时，取两种模运算顺序中收益更大的（值更小的）
        ps[3][i] = ps[3][i - 1] + min((a[i] % p) % q, (a[i] % q) % p);
    }

    const long long INF = 1e18;
    // dp[i][sp][sq]: sp, sq 属于 {0, 1}，1 表示该模运算当前处于激活状态(且已满足长度>=k)
    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(2, vector<long long>(2, INF)));

    dp[0][0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        // --- 1. 延续状态与关闭区间 ---
        // dp[i][0][0]: 当前不进行任何模运算，可由上一位关闭 p, q 或保持关闭转移
        dp[i][0][0] = min({dp[i-1][0][0], dp[i-1][1][0], dp[i-1][0][1], dp[i-1][1][1]}) + a[i];
        
        // dp[i][1][0]: 当前仅开启 p，可由上一位保持 p 开启，或在此刻关闭 q
        dp[i][1][0] = min({dp[i-1][1][0], dp[i-1][1][1]}) + (a[i] % p);
        
        // dp[i][0][1]: 当前仅开启 q，可由上一位保持 q 开启，或在此刻关闭 p
        dp[i][0][1] = min({dp[i-1][0][1], dp[i-1][1][1]}) + (a[i] % q);
        
        // dp[i][1][1]: 当前 p 和 q 都在激活中
        dp[i][1][1] = dp[i-1][1][1] + min((a[i] % p) % q, (a[i] % q) % p);

        // --- 2. 开启新区间 (强制跳转 k 长度) ---
        if (i >= k) {
            // 尝试开启 p 维度 (q 状态保持不变或刚好结束)
            // 开启 p 时，必须从 dp[i-k][0][sq] 状态跨越 k 步跳过来
            long long base_sq0 = min(dp[i-k][0][0], dp[i-k][0][1]); // 开启 p, 此时 q 是关闭的
            if (base_sq0 != INF) {
                dp[i][1][0] = min(dp[i][1][0], base_sq0 + (ps[1][i] - ps[1][i - k]));
            }
            long long base_sq1 = dp[i-k][0][1]; // 开启 p, 此时 q 已经开启了
            if (base_sq1 != INF) {
                dp[i][1][1] = min(dp[i][1][1], base_sq1 + (ps[3][i] - ps[3][i - k]));
            }

            // 尝试开启 q 维度 (p 状态保持不变或刚好结束)
            long long base_sp0 = min(dp[i-k][0][0], dp[i-k][1][0]); 
            if (base_sp0 != INF) {
                dp[i][0][1] = min(dp[i][0][1], base_sp0 + (ps[2][i] - ps[2][i - k]));
            }
            long long base_sp1 = dp[i-k][1][0];
            if (base_sp1 != INF) {
                dp[i][1][1] = min(dp[i][1][1], base_sp1 + (ps[3][i] - ps[3][i - k]));
            }
            
            // 尝试同时开启 p 和 q (从两者都关闭的状态跳转)
            long long base_both = min({dp[i-k][0][0], dp[i-k][1][0], dp[i-k][0][1], dp[i-k][1][1]});
            if (base_both != INF) {
                dp[i][1][1] = min(dp[i][1][1], base_both + (ps[3][i] - ps[3][i - k]));
            }
        }
    }

    // 最终结果在第 n 个元素的所有可能状态中取最小值
    long long ans = min({dp[n][0][0], dp[n][1][0], dp[n][0][1], dp[n][1][1]});
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
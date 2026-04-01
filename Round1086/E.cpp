#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

void add(int &a, int b) { a = (a + b) % MOD; }

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> X(n + 1);
    for (int i = 1; i <= n; i++) cin >> X[i];

    vector<int> L(n + 2, 0);
    // Precompute L[j]: minimum required value for P_j due to future constraints
    for (int k = 1; k <= n; k++) {
        if (X[k] != -1) {
            int v = X[k];
            // If X[k] >= k, it's impossible since P_k must be < k
            if (v >= k) {
                // Logic will handle invalid states, but we can verify here loosely
            }
            // Constraint: for all j in (v, k), P_j >= v
            for (int j = v + 1; j < k; j++) {
                L[j] = max(L[j], v);
            }
        }
    }

    if (L[1] > 0) {
        cout << 0 << "\n";
        return;
    }

    // dp[c] = number of ways such that there are c active candidates >= L_i
    vector<int> dp(n + 5, 0);
    dp[1] = 1; // At start of step 1, candidate {0} is available.

    vector<int> next_dp(n + 5);
    vector<int> diff(n + 5);

    for (int i = 1; i <= n; i++) {
        fill(next_dp.begin(), next_dp.end(), 0);
        fill(diff.begin(), diff.end(), 0);

        int added = (i >= L[i+1] ? 1 : 0);

        if (X[i] != -1) {
            int v = X[i];
            // Basic validity checks
            if (v >= i || v < L[i]) {
                cout << 0 << "\n";
                return;
            }

            // We need active set size c such that range [L_i, L_i + c - 1] contains v.
            int min_c = v - L[i] + 1;
            
            int ways = 0;
            for (int c = min_c; c <= i; c++) {
                add(ways, dp[c]); 
            } 
            
            // Survivors: max(0, v - L[i+1] + 1)
            int survivors = max(0, v - L[i + 1] + 1);
            int next_count = survivors + added;

            if (next_count < (int)next_dp.size()) {
                next_dp[next_count] = (int)ways;
            }

        } else {
             // X[i] == -1
             if (L[i+1] >= L[i]) {
                 int Loss = L[i+1] - L[i];
                 for (int c = 1; c <= i; c++) {
                     if (dp[c] == 0) continue;
                     
                     // Range 1: kept count r <= Loss. Survivors >= L[i+1] is 0.
                     int low_range = min(c, Loss);
                     if (low_range > 0) {
                         long long val = (long long)dp[c] * low_range % MOD;
                         add(next_dp[added], (int)val);
                     }
                     
                     // Range 2: kept count r > Loss. Survivors is r - Loss.
                     if (c > Loss) {
                         // Map r in [Loss+1, c] -> survivors r - Loss -> new count r - Loss + added
                         // Indices in next_dp: [1 + added, c - Loss + added]
                         int start_idx = 1 + added; 
                         int end_idx = c - Loss + added;
                         
                         add(diff[start_idx], dp[c]);
                         int sub = (MOD - dp[c]) % MOD;
                         add(diff[end_idx + 1], sub);
                     }
                 }
             } else {
                 int Gain = L[i] - L[i+1];
                 for (int c = 1; c <= i; c++) {
                     if (dp[c] == 0) continue;
                     // All choices valid. Survivors = r + Gain.
                     // Indices in next_dp: [1 + Gain + added, c + Gain + added]
                     int start_idx = 1 + Gain + added;
                     int end_idx = c + Gain + added;
                     
                     add(diff[start_idx], dp[c]);
                     int sub = (MOD - dp[c]) % MOD;
                     add(diff[end_idx + 1], sub);
                 }
             }
             
             // Process difference array
             int current_add = 0;
             for (int k = 0; k < (int)next_dp.size(); k++) {
                 add(current_add, diff[k]);
                 add(next_dp[k], current_add);
             }
        }
        dp = next_dp;
    }
    
    int ans = 0;
    for (int x : dp) add(ans, x);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while(t--) solve();
    }
    return 0;
}
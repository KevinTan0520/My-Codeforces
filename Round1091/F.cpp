#include <bits/stdc++.h>
using namespace std;
vector<int> p2;

int popcount(int x) {
    int cnt = 0;
    while (x) {
        if (x & 1) cnt++;
        x /= 2;
    }
    return cnt;
}
long long cntK(long long X, long long lim, vector<int>& p2) {
    if (lim < 0) return 0;
    const int B = 20;
    vector<int> cnt(B + 1, 0);
    for (int i = 0; i < B; i++) {
        cnt[i + 1] = cnt[i] + ((((X >> i) & 1) == 0) ? 1 : 0);
    } 
    long long ans = 0;
    for (int i = B - 1; i >= 0; i--) {
        if ((lim >> i) & 1) {
            ans += p2[cnt[i]];
            if ((X >> i) & 1) {
                return ans;
            }
        }
    }
    return ans + 1;
}
void solve() {
    long long x1, x2, minn = LONG_LONG_MAX, ans;
    cin >> x1 >> x2;
    for (int i = 0; i < x1; i++) {
        int val = x2 - 1 - i;
        long long cnt, res;
        if (val < 0) {
            res = 0;
        }
        else {
            int lim = (x2 - 1 - i) / 2;
            cnt = cntK(i, lim, p2);
            res = cnt * p2[popcount(i)];
        }
        
        if (res < minn) {
            ans = i;
            minn = res;
        }
    }
    cout << 1 << ' ' << x1 - ans << endl;
    return; 
}


int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    p2.push_back(1);
    for (int i = 1; i < 31; i++) {
        p2.push_back(p2[i - 1] * 2);
    }
    while (t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
void solve() {
    int n;
    cin >> n;
    vector<int> a, pre(n), suf(n);
    for (int i = 0; i < n; i++) {
        int res;
        cin >> res;
        a.push_back(res);
    }
    set<int> st;
    st.clear();
    for (int i = 1; i <= n; i++) st.insert(i);
    for (int i = 0; i < n - 1; i++) {
        auto it = st.upper_bound(a[i]);
        if (it != st.begin()) {
            it--;
            st.erase(*it);
        }
        pre[i] = n - st.size();
    }
    st.clear();
    for (int i = 1; i <= n; i++) st.insert(i);
    for (int i = n - 1; i > 0; i--) {
        auto it = st.upper_bound(a[i]);
        if (it != st.begin()) {
            it--;
            st.erase(*it);
        }
        suf[i] = n - st.size();
    }
    long long cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        cnt += min(pre[i], suf[i + 1]);
    }
    cout << cnt << endl;
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<double, double> a, pair<double, double> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int main() {
    int n, w;
    cin >> n >> w;
    vector<pair<double, double>> a;
    vector<double> st, ed;
    for (int i = 0; i < n; i++) {
        int x, v;
        cin >> x >> v;
        x = abs(x), v = abs(v);
        a.push_back({(double) x / (v + w), (double) x / (v - w)});
        st.push_back(a[i].first);
        ed.push_back(a[i].second);
    }
    sort(a.begin(), a.end(), cmp);
    sort(ed.begin(), ed.end());
    long long tot = n * (n - 1) / 2;
    for (int i = 0; i < n; i++) {
        int l = a[i].first;
        auto it = lower_bound(ed.begin(), ed.end(), l);
        int cnt = it - ed.begin();
        tot -= cnt;
    }
    cout << tot << endl;
    return 0;
}
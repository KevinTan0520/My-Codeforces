#include <bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator() (pair<char, int> a, pair<char, int> b) {
        return a.second < b.second;
    }
};
void solve() {
    int r, g, b;
    cin >> r >> g >> b;
    priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> q;
    vector<char> ans;
    q.push({'R', r});
    q.push({'G', g});
    q.push({'B', b});
    int cnt = 0;
    while(!q.empty() && cnt <= 3) {
        pair<char, int> p = q.top();
        q.pop();
        if (ans.size() - 1 >= 0 && p.first != ans[ans.size() - 1] && ans.size() - 3 >= 0 && p.first != ans[ans.size() - 3]) {
            ans.push_back(p.first);
            p.second--;
            cnt = 0;
        }
        else {
            cnt++;
        }
        if (p.second != 0) {
            q.push(p);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    cout << endl;
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
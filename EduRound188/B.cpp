#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

struct Node { 
    int val, id;
};

struct cmp {
    bool operator() (Node a, Node b) {
        if (a. val == b.val) return a.id < b.id;
        return a.val < b.val;
    }
};

Node make_node(int x, int y) {
    Node res;
    res.id = x;
    res.val = y;
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    priority_queue<Node, vector<Node>, cmp> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        q.push(make_node(i, a[i]));
    }
    int cnt = 0;
    while (!q.empty()) {
        Node tmp = q.top();
        cnt++;
        q.pop();
        while (q.top().id > tmp.id && !q.empty()) {
            q.pop();
        }
    }
    cout << cnt << endl;
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
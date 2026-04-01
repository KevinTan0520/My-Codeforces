#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct Node {
    vector<int> cand; // 最多两个候选
};

Node mergeNode(const Node& A, const Node& B) {
    Node res;
    vector<int> tmp = A.cand;
    tmp.insert(tmp.end(), B.cand.begin(), B.cand.end());

    map<int,int> cnt;
    for (int x : tmp) {
        if (cnt.count(x)) cnt[x]++;
        else if ((int)cnt.size() < 2) cnt[x] = 1;
        else {
            for (auto it = cnt.begin(); it != cnt.end();) {
                if (--(it->second) == 0) it = cnt.erase(it);
                else ++it;
            }
        }
    }
    for (auto &p : cnt) res.cand.push_back(p.first);
    return res;
}

struct SegTree {
    int n;
    vector<Node> seg;
    SegTree(int n, vector<int>& a) : n(n) {
        seg.resize(4*n);
        build(1,1,n,a);
    }
    void build(int id,int l,int r,vector<int>& a) {
        if(l==r) { seg[id].cand={a[l]}; return; }
        int mid=(l+r)/2;
        build(id*2,l,mid,a);
        build(id*2+1,mid+1,r,a);
        seg[id]=mergeNode(seg[id*2],seg[id*2+1]);
    }
    Node query(int id,int l,int r,int ql,int qr) {
        if(ql<=l && r<=qr) return seg[id];
        int mid=(l+r)/2;
        if(qr<=mid) return query(id*2,l,mid,ql,qr);
        else if(ql>mid) return query(id*2+1,mid+1,r,ql,qr);
        else {
            Node L=query(id*2,l,mid,ql,qr);
            Node R=query(id*2+1,mid+1,r,ql,qr);
            return mergeNode(L,R);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n,q; cin >> n >> q;
        vector<int> a(n+1);
        for (int i=1;i<=n;i++) cin >> a[i];

        unordered_map<int, vector<int>> pos;
        pos.reserve(n*2);
        for (int i=1;i<=n;i++) pos[a[i]].push_back(i);

        SegTree st(n,a);

        while (q--) {
            int l,r; cin >> l >> r;
            Node res = st.query(1,1,n,l,r);
            int len = r-l+1;
            int th = len/3;

            vector<int> ans;
            for (int x:res.cand) {
                auto &vec = pos[x];
                int cnt = upper_bound(vec.begin(), vec.end(), r)
                        - lower_bound(vec.begin(), vec.end(), l);
                if (cnt > th) ans.push_back(x);
            }
            cout << "OUTPUT ";
            if (ans.empty()) cout << -1 << "\n";
            else {
                sort(ans.begin(), ans.end());
                for (int i=0;i<(int)ans.size();i++) {
                    if(i) cout << " ";
                    cout << ans[i];
                }
                cout << "\n";
            }
        }
    }
}

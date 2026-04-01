#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
long long merge_sort(vector<int> &a, vector<int> &tmp, int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) >> 1;
    long long cnt = 0;
    cnt += merge_sort(a, tmp, l, mid);
    cnt += merge_sort(a, tmp, mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        }
        else {
            tmp[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int t = l; t <= r; t++) {
        a[t] = tmp[t];
    }
    return cnt;
}
long long count_inv(vector<int> &a) {
    vector<int> tmp(a.size());
    return merge_sort(a, tmp, 0, a.size() - 1);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> a, odd_arr, even_arr, ans, cnt_arr;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int ai;
            cin >> ai;
            a.push_back(ai);
            if (i % 2) {
                odd_arr.push_back(ai);
            }
            else {
                even_arr.push_back(ai);
            }
        }
        sort(odd_arr.begin(), odd_arr.end());
        sort(even_arr.begin(), even_arr.end());
        int p1 = 0, p2 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                ans.push_back(odd_arr[p1++]);
                cnt_arr.push_back(ans[i]);
            }
            else {
                ans.push_back(even_arr[p2++]);
                cnt_arr.push_back(ans[i]);
            }
        }
        int cnt1 = count_inv(a), cnt2 = count_inv(cnt_arr);
        if (cnt1 % 2 != cnt2 % 2) {
            swap(ans[n - 1], ans[n - 3]);
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}